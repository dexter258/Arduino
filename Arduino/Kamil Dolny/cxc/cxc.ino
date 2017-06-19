#include<EEPROM.h>
#include <Wire.h>
#include <SPI.h>
#include "Adafruit_MCP23017.h"
#include "time.h"
#include "memory.h"
#include "errors.h"
#include "garret.h"
#include "start.h"
#include "button.h"
#include "pyrotechnics.h"
#include "booster_engine.h"
#include "abort.h"
#include "event.h"
#include "redundant.h"
#include <SoftwareServo.h>

//ZMIENNE
SoftwareServo servo;
byte controlButton[5] = {0, 0, 0, 0, 0};
bool gameOverSend = false;
bool gameOverSendPrev = false;
byte errorSendPrev;

//TRYB DEBUGOWANOA
bool debug = false;

bool debugSound = false;
bool debugInput = false;
byte debugGames =10;

byte error = 0;
byte passedGames = 0;
byte passedGamesPrev = 0;
byte passedGamesPrevSend = 0;
byte passedGamesTotalPrev = 0;
bool sendInfoToSymbols = false;
bool sendInfoToSimon = false;
bool sendInfoToLabirynth = false;
bool sendInfoToButton = false;

bool labirynthPass = false;

byte errorPrev = 0;
bool simonPass = false;
bool symbolsPass = false;
bool sendingInfo = false;
bool abortPassPrev = false;
bool garretPassPrev = false;
long startTime = 0;
long stopTime = 0;
bool startTimeFlag = false;
byte numberLCD = 0;
bool flagChangeLCD = false;
String lcdTime = "";
void setup() {

  setMinutes = EEPROM.read(1);
  language = EEPROM.read(0);
  randomSeed(analogRead(A8));
  SPI.begin();
  SPI.setBitOrder(LSBFIRST);                //LSBFIRST or MSBFIRST
  SPI.setDataMode(SPI_MODE3);               //CPOL=1 CPHA=1
  SPI.setClockDivider(SPI_CLOCK_DIV64);  //
  delay(20);
  //pinMode(46, OUTPUT);
  servo.attach(46);
  //servo.setMaximumPulse(2200);





  Serial.begin(9600);
  Serial1.begin(9600); // Labirynt
  Serial2.begin(9600); // drugie arduino
  Serial3.begin(9600); // Symbols
  Serial2.println("D5"); // reset Deuter
  delay(50);
  Serial2.println("B4"); // Wygaszenie paska button
  resetAllGames();
  long startT = 0, stopT = 0;
  bool flagServo = false;
  do {
    if (flagServo == false) {
      startT = millis();
      flagServo = true;
    }
    stopT = millis();
    servo.write(0);
    SoftwareServo::refresh();
    //Serial.println("tekst");
  } while (stopT - startT < 5000);
  initBoosterEnginePanel();
  initInfoPanel();
  initStartPanel();

  digitalWrite(48, LOW);
  char c;
  for (const char * p = "F000000000000000000000000000000K" ; c = *p; p++) {
    SPI.transfer (c);
    delay(5);
  }

  digitalWrite(48, HIGH);


  initGarretPanel();
  initButtonPanel();
  initEventPanel();
  initTimePanel();
  initMemoryPanel();
  initErrorsPanel();
  initAbortPanel();
  setGarretNumbers(10, 10, 10);
  readEngineButtons();
  initRedundant();
  //setErrors(2);

  //delay(5000);
  timer_t.attach(1, 200, checkGarret);
  timer_t.attach(2, 200, sendButtons);
  // timer_t.attach(3, 20, refreshServo);
}
String infoButtons = "";


void checkSerialPorts() {
  String msg = "";

  passedGamesPrev = passedGames;

  if (Serial2.available() > 0) { // Pobieranie danych z portu szeregowego
    while (Serial2.available() > 0) { // pobieraj tak długo aż bufor będzie pusty
      msg += char(Serial2.read());
      delay(5);
    }
    if (msg[0] == 'S') {
      passedGames++;
      simonPass = true;
      tekstLedsGame[9] = '2';
    }
    else if (msg[0] == 'E') {
      error++;
    }
    else {
      infoButtons = msg;

    }

    if (debugInput == true) Serial.println(msg);

  }
  msg = "";
  if (Serial1.available() > 0) { // Pobieranie danych z portu szeregowego
    while (Serial1.available() > 0) { // pobieraj tak długo aż bufor będzie pusty
      msg += char(Serial1.read());
      delay(5);
    }

    if (msg[0] == 'P') {
      passedGames++;
      labirynthPass = true;
      tekstLedsGame[4] = '2';
    }
    else if (msg[0] == 'E') {
      error++;
    }
  }

  msg = "";
  if (Serial3.available() > 0) { // Pobieranie danych z portu szeregowego
    while (Serial3.available() > 0) { // pobieraj tak długo aż bufor będzie pusty
      msg += char(Serial3.read());
      delay(5);
    }

    if (msg[0] == 'P') {
      passedGames++;
      symbolsPass = true;
      tekstLedsGame[2] = '2';
    }
    else if (msg[0] == 'E') {
      error++;
    }
  }

  msg = "";
  String temp;
  if (Serial.available() > 0) { // Pobieranie danych z portu szeregowego
    while (Serial.available() > 0) { // pobieraj tak długo aż bufor będzie pusty
      msg += char(Serial.read());
      delay(5);
    }
    for (byte i = 0; i < 5; i++) {
      temp = "";
      temp += msg[i];
      controlButton[i] = byte(temp.toInt());
    }


  }

}
long startTx = 0, stopTx = 0;
bool flagServox = false;
bool flagFinish = false;
long startFinish = 0, stopFinish = 0;

bool flagRedu = false;
bool flagF1 = false;
bool flagF2 = false;
bool flagStar = false;
bool flagHash = false;
void loop() {



  if (readRKey() == false) {
    if(flagChangeLCD == true){
      lcd_red.clear();
      flagChangeLCD = false;
      flagRedu = false;
    }
    checkSerialPorts();
    setButtons(infoButtons);
    readEngineButtons();
    games();
    //setEngineLeds();


    timer_t.process();


    if (passedGames > passedGamesPrev) {
      if (debug == true) {
        Serial.println("Punkty = " + String(passedGames));
      }

      digitalWrite(48, LOW);

      char c;
      for (const char * p = tekstLedsGame ; c = *p; p++) {
        SPI.transfer (c);
        delayMicroseconds(2000);
      }
      digitalWrite(48, HIGH);
    }
    if (flagFinish == false && passedGames >= 3) {
      startFinish = millis();
      flagFinish = true;
      allowMeasureTime = false;
      lcd_Start.clear();
      if (language  == 1) {
        lcd_Start.setCursor(0, 0);
        lcd_Start.print(" GRATULACJE ");
        lcd_Start.setCursor(0, 1);
        lcd_Start.print("  KOD TO ");
        lcd_Start.setCursor(0, 2);
        lcd_Start.print(" 7 6 2 4 1 5");
        lcd_Start.setCursor(0, 3);
        lcd_Start.print("          ");
      }
      else {
        lcd_Start.setCursor(0, 0);
        lcd_Start.print("Taken over control");
        lcd_Start.setCursor(0, 1);
        lcd_Start.print("Detected failures:");
        lcd_Start.setCursor(0, 2);
        lcd_Start.print("NO FUEL HYPER");
        lcd_Start.setCursor(0, 3);
        lcd_Start.print("DAMAGED ENGINE");
      }
    }
    if (flagFinish == true) stopFinish = millis();

    if (stopFinish - startFinish > 10000 && flagServox == false) {
      do {
        if (flagServox == false) {
          startTx = millis();
          flagServox = true;
        }
        stopTx = millis();
        servo.write(180);
        SoftwareServo::refresh();
        Serial.println("tekst");
      } while (stopTx - startTx < 5000);
    }

    if (startTimeFlag == false) {
      startTime = millis();
    }

    stopTime = millis();

    if (error > errorPrev) {
      setErrors(error);
       Serial2.println("E");
    }



    if ((error == 3 && error > errorPrev) || gameOver == true) {
      startTimeFlag = true;
      gameOverSend = true;
      allowMeasureTime = false;
      resetAllGames();
    }

    errorPrev = error;
    if (stopTime - startTime > 10000) {
      gameOverSend = false;
      startTimeFlag = false;
      //resetAllGames();
      restartGame = true;
      passedGames = 0;
      sendInfoToSymbols = false;
      sendInfoToSimon = false;
      sendInfoToLabirynth = false;
      sendInfoToButton = false;
      readStartButton();
      //randomNumber();
      error = 0;
      setErrors(error);
      errorPrev = 0;
      gameOver = false;


    }
  }
  else {
      flagChangeLCD = true;
    char customKey = customKeypad.getKey();

    
    if (flagRedu == false || customKey == 'Q') {
      lcd_red.clear();
      lcd_red.setCursor(0, 0);
      lcd_red.print("Wybierz:");
      lcd_red.setCursor(0, 1);
      lcd_red.print("F1  F2  #");
      flagRedu = true;
      flagF1 = false;
      flagF2 = false;
      flagHash = false;
      numberLCD = 0;

    }
    if (customKey == 'F') {
      flagF1 = true;
      lcd_red.clear();
      lcd_red.setCursor(0, 0);
      lcd_red.print("Jezyk polski?");
      lcd_red.setCursor(0, 1);
      lcd_red.print("Potwierdz Ent");
    }
    else if (customKey == 'G') {
      flagF2 = true;
      lcd_red.clear();
      lcd_red.setCursor(0, 0);
      lcd_red.print("Jezyk angielski?");
      lcd_red.setCursor(0, 1);
      lcd_red.print("Potwierdz Ent");
    }
    else if (customKey == '#' ) {
      flagHash = true;
      lcd_red.clear();
      lcd_red.setCursor(0, 0);
      lcd_red.print("Czas:");

    }

    if (flagF1 == true && customKey == 'E') {
      EEPROM.write(0, 1);
      language = 1;
      flagF1 = false;
      flagRedu = false;
      restartGame = true;
    }
    else if (flagF2 == true && customKey == 'E') {
      EEPROM.write(0, 2);
      language = 2;
      flagF2 = false;
      flagRedu = false;
      restartGame = true;
    }
    else if (flagHash == true && customKey) {
      if (customKey == 'E') {
        EEPROM.write(1, byte(lcdTime.toInt()));
        setMinutes = byte(lcdTime.toInt());
        flagHash = false;
        flagRedu = false;
        restartGame = true;
      }
      else {
        if (customKey != '#') {
          lcdTime += customKey;
          lcd_red.setCursor(numberLCD, 1);
          lcd_red.print(customKey);
          numberLCD++;
        }
      }
    }
  }
}

void resetAllGames() {
  //Garret

  sendingInfo = true;

  for (byte i = 0; i < 3; i++) {
    garretNumberButton[i] = 0; // Wyzerowanie liczb w garret
  }

  setGarretNumbers(10, 10, 10); // wyłączenie liczników
  garretPass = false;
  garretFlag = false;

  // Symbols

  symbolsPass = false;
  sendInfoToSymbols = false;
  Serial3.println("R");

  // ENGINE
  enginePass = false;

  for (byte i = 0; i < 3; i++) {
    przelaczony[i]=false;
     passLevelEngine[i] = false;
}

  // Labirynth
  labirynthPass = false;
  sendInfoToLabirynth = false;
  Serial1.println("R");
  //Pyrotechnics

  pyroPass = false;
//pyroFirst=false;
  // MEMORY

  setNumbersMemory(10, 10, 10, 10, 10);
  //setMemoryLevel(0);
  memoryPass = false;
  memoryFlag = true;
  memoryLevel = 1;
  setMemoryLevel(0);
  //

  //BUTTON

  buttonPass = false;
  lcd_button.clear();
  sendInfoToButton = false;
  Serial2.println("B" + String(4));
  delay(50);

  //ABORT
 abortPass = false;
  //SIMON SAYS
  simonPass = false;
  sendInfoToSimon = false;
  Serial2.println("S0");
  delay(50);



  sendingInfo = false;
}
void setButtons(String info) {

  //Zczytanie wartości przyciskow Garret
  readGarretButtons(info);
  readButtonButton(info);
  readPyroButtons(info);
  readAbortButtons(info);
  readEventButtons(info);


}


void games() {
  if ((gameStarted == false || restartGame == true) && gameOverSend == false) {
  
    readStartButton(); // Sprawdzenie czy przekręcono kluczyk start
  }

  if ((gameStarted == true || debugGames != 10) && gameOverSend == false) { // Jeśli przekręcono kluczyk start

    //======GARRET GAME======//

    if (startGames[0] == true && garretPass == false || debugGames == 0) {

      if (garretFlag == false) {
        setGarretNumbers(0, 0, 0);
        garretFlag = true;
      }
      if ( readAcceptGarret()) {

        garretGame();

      }

      if (garretPass == true) {
        tekstLedsGame[1] = '2';
        setGarretNumbers(10, 10, 10);
      }
    }
    //END GARRET GAME

    //======SYMBOLS GAME=====//
    if (startGames[1] == true  && symbolsPass == false || debugGames == 1) {

      if (sendInfoToSymbols == false) {
        Serial3.println("1");
        sendInfoToSymbols = true;

      }

    }
    //END SYMBOLS GAME

    //======ENGINE GAME======//
    if (startGames[2] == true && enginePass == false || debugGames == 2) {

      if (enginePass == false) {
        engineGame();
      }

      if (enginePass == true) {
        passedGames++;
        mcp2.digitalWrite(12, LOW);
        mcp2.digitalWrite(13, LOW);
        mcp2.digitalWrite(14, LOW);
        tekstLedsGame[3] = '2';
      }

    }
    //END ENGINE GAME

    //======LABIRYNTH GAME======//
    if (startGames[3] == true && labirynthPass == false || debugGames == 3) {

      if (sendInfoToLabirynth == false) {
        Serial1.println("1");
        sendInfoToLabirynth = true;
      }

    }
    //END LABIRYNTH GAME

    //======PYROTECHNICS GAME======//
    if (startGames[4] == true && pyroPass == false || debugGames == 4 ) {
      if (pyroPass == false) {
        pyrotechnicsGame();
      }

      if (pyroPass == true) {
        passedGames++;
        tekstLedsGame[5] = '2';
        if (debug == true) Serial.println("Zaliczone pyro");
      }

    }
    //END PYROTECHNICS GAME

    //======MEMORY GAME======//
    if (startGames[5] == true && memoryPass == false || debugGames == 5) {
      if (memoryPass == false) {
        memoryGame();
      }
      if (memoryPass == true) {
        passedGames ++;
        tekstLedsGame[6] = '2';
      }

    }
    //END MEMORY GAME

    //======BUTTON GAME======//
    if (startGames[6] == true && buttonPass == false || debugGames == 6) {

      if (sendInfoToButton == false) {
        sendingInfo = true;
        delay(50);
        randomButtonTextColor();
        delay(50);
        sendingInfo = false;
        sendInfoToButton = true;
      }
      if (buttonPass == false) {

        buttonGame();
        if (buttonPass == true) {
          lcd_button.clear();
          //lcd_button.setCursor(0, 0);
          //lcd_button.print("Zaliczono");
          sendingInfo = true;
          delay(50);
          Serial2.println("B" + String(4));
          delay(50);
          sendingInfo = false;
          tekstLedsGame[7] = '2';
        }
      }
    }

    //END BUTTON GAME

    //======ABORT GAME======//
    if (startGames[7] == true  && abortPass == false || debugGames == 7) {
      if (abortPass == false) {
        abortGame();
      }

      if (abortPass == true) {
        passedGames++;
        tekstLedsGame[8] = '2';
      }
    }
    //END ABORT GAME

    //======SIMON SAYS GAME======//
    if (startGames[8] == true || debugGames == 8) {

      if (sendInfoToSimon == false) {
        sendingInfo = true;
        delay(50);
        if (mainInfoText[randomMainInfo][3] == "Y") {
          Serial2.println("S1Y");
        }
        else {
          Serial2.println("S1N");
        }
        sendingInfo = false;
        sendInfoToSimon = true;
      }

    }

    //END SIMON SAYS GAME
  }
}



void sendButtons() {

  String temp = "R";
  char temp2[43];
  //Błąd
  if (errorSendPrev < error) {
    temp += "1";
  }
  else {
    temp += "0";
  }
  errorSendPrev = error;

  //Pyrotechnics
  for (byte i = 0; i < 7; i++) {
    temp += String(pyroButtonFirst[i]);
  }

  // ENGINE
  for (byte i = 0; i < 3; i++) {
    temp += String(engineButtonFirst[i]);
  }

  // BOOSTER

  for (byte i = 0; i < 9 ; i++) {
    temp += String(boosterButton[i]);
  }


  //EVENT

  for (byte i = 0; i < 10; i++) {
    temp += String(eventButton[i]);
  }

  //CONTROL

  for (byte i = 0; i < 5; i++) {
    temp += String(controlButton[i]);
  }

  // DZWIĘK ROZWIĄZANIA ZAGADKI

  if (passedGames > passedGamesPrevSend) {
    temp += "1";
  }
  else {
    temp += "0";
  }

  passedGamesPrevSend = passedGames;

  //ABORT

  if (abortPass == true && abortPassPrev != abortPass) {
    temp += "1";
  }
  else {
    temp += "0";
  }

  abortPassPrev = abortPass;

  // GARRET
  if (garretPass == true && garretPassPrev != garretPass) {
    temp += "1";
  }
  else {
    temp += "0";
  }
  garretPassPrev = garretPass;

  //GAME OVER
  if (gameOverSend == true) {
    temp += "1";
  }
  else {
    temp += "0";
  }

  //gameOverSendPrev = gameOverSend;

  //MISSION COMPLETE
  if (passedGames == 3 && passedGamesTotalPrev != passedGames) {
    temp += "1";
  }
  else {
    temp += "0";
  }
  passedGamesTotalPrev = passedGames;
  //if (debug == true) Serial.println(temp);

  temp += "K";

  temp.toCharArray(temp2, 43);


  //temp2[31] = 'K';
  //temp2[42] = '\0';

  digitalWrite(48, LOW);

  char c;
  for (const char * p = temp2 ; c = *p; p++) {
    SPI.transfer (c);
    delayMicroseconds(2000);
  }



  //SPI.transfer ('K');
  digitalWrite(48, HIGH);

  if (debugSound == true) Serial.println(temp2);
}


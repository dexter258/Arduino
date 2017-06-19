#include "info.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd_Start(12, 9, 5, 4, 3, 2);
byte language = 1;
byte timeSetLCD = 5;
extern bool debug;
boolean pierwszy_raz=true;
extern bool allowMeasureTime;

extern byte minutes, seconds;

extern void setTime(byte minutes, byte seconds);

byte randomGames[3] = {0, 0, 0};

// zmienne odpowiadające za start gry oraz za ponowne losowanie gier
bool gameStarted = false;
bool restartGame = false;

//Zmienne odpowiadające za wybór gry
bool startGames[9] = {false, false, false, false, false, false, false, false, false};

//Zmienne do których wpisywane są informacje losowym wyborze informacji wyświetlanych na wyświetlaczach LCD
byte randomMainInfo;
byte randomAddInfo;

//Zmienne w których zapisywane są informacje o STATUS I i STATUS II
byte status1[15];
byte status2[15];

//Zmienna w której przechowywana jest informacja o tym ile jest aktywnych statusów w STATUSII
byte amountActiveStatus2;

//Zmienna w której przechowywana jest informacja o tym ile jest awaryjnych statusów w STATUS II
byte amountErrorStatus2;


//Zmienan w której przechowywana jest informacja o tym jaką kombinacje kolorow wybrano w DEUTER
byte deuterRandom;

// Zmienne tekstowe z do wyświetlania na LCD
// NUMER SERYJNY, PIERWSZA LICZBA, DRUGA LICZBA, CZY JEST SAMOGŁOSKA, CZY KOŃCZY SIĘ PARZYSTĄ LICZBĄ, CZY podzielny przez 3, czy zawiera litere K
String mainInfoText[10][7] = {{"JKB85A", "8", "5", "Y", "N", "N", "Y"},
                              {"R17K6", "1", "6", "N", "Y", "Y", "Y"},
                              {"TUE12", "1", "2", "Y", "Y", "N", "N"},
                              {"P6Y27", "6", "7", "N", "N", "Y", "N"},
                              {"14F8HJ", "1", "8", "N", "N", "N", "N"},
                              {"U71ST", "7", "1", "Y", "N", "N", "N"},
                              {"Q19X8", "1", "8", "N", "Y", "Y", "N"},
                              {"W44KL", "4", "4", "N", "N", "N", "Y"},
                              {"KIV28", "2", "8", "Y", "Y", "N", "Y"},
                              {"H15S4", "1", "4", "N", "Y", "N", "N"}
};

String modules[9] = { {"GARRET"},
  {"SYMBOLS"},
  {"ENGINE"},
  {"LABIRYNTH"},
  {"PYROTECHNICS"},
  {"MEMORY"},
  {"BUTTON"},
  {"ABORT"},
  {"SIMON SAYS"}
};



String additionalInfoText[4] = {{"CAR"},
  {"FRK"},
  {"FKW"},
  {"NSA"}
};


// Inicjalizacja panelu START

void initStartPanel() {
  lcd_Start.begin(20, 4);

  pinMode(41, OUTPUT);

  digitalWrite(41, LOW);

  pinMode(43, INPUT_PULLUP);

  pinMode(48, OUTPUT);
  digitalWrite(48, HIGH);

}

//Wybieranie losowych informacji
void setRandomGames() {

  // Losowanie trzech gier
  if (pierwszy_raz==true){
    do {
      randomGames[0] = random(0, 8);
    }while (randomGames[0]==3);  
  }
  else randomGames[0] = random(0, 8);
  do {
    if (pierwszy_raz==true){
      do {
      randomGames[1] = random(0, 8);
    }while (randomGames[1]==3);  
    }
    else    randomGames[1] = random(0, 8);
  } while (randomGames[0] == randomGames[1]);

  do {
    if (pierwszy_raz==true){
      do {
      randomGames[2] = random(0, 8);
    }while (randomGames[2]==3);  
    }
    else      randomGames[2] = random(0, 8);
  } while (randomGames[0] == randomGames[2] || randomGames[1] == randomGames[2]);

  if (debug == true) {
    for (byte i = 0; i < 3; i++) {
      Serial.println("Wylosowano = " + String(randomGames[i]));
    }

  }
pierwszy_raz=false;
  for (byte i = 0; i < 9; i++) {
    startGames[i] = false;
  }

  for (byte i = 0; i < 3; i++) {
    for (byte j = 0; j < 9; j++) {
      if (randomGames[i] == j) {
        startGames[j] = true;
      }
    }
  }

  //Losowanie iformacji na wyświetlaczu głównym
  randomMainInfo = random(0, 10);

  //Losowanie informacji na wyświetlaczu dodatkowym
  randomAddInfo = random(0, 4);

  //Wyświetlanie na dużym wyświetlaczu informacji o tym jakie moduły nalezy dezaktywowac
  lcd_Start.clear();
  lcd_Start.setCursor(0, 0);
  if(language ==1)lcd_Start.print("Dezaktywuj moduly:");
  else {
    lcd_Start.print("Deactivate modules:");
  }
  


  for (byte i = 0; i < 3; i++) {
    lcd_Start.setCursor(0, i + 1);
    lcd_Start.print(modules[randomGames[i]]);
  }

  //Wyswietlanie wylosowanej informacji na wyświetlaczu glownym
  lcd_Info.clear();
  lcd_Info.setCursor(0, 0);
  lcd_Info.print(mainInfoText[randomMainInfo][0]);

  //Wyświetlanie wylosowanej informacji na wyświetlaczu dodatkowym
  lcd_additional.clear();
  lcd_additional.setCursor(0, 0);
  lcd_additional.print(additionalInfoText[randomAddInfo]);

  //Wyzerowanie zmiennej w której znajduja się informacje o aktywnych polach w STATUS II
  amountActiveStatus2 = 0;
  amountErrorStatus2 = 0;
  for (byte i = 0; i < 15; i ++) {
    status1[i] = random(0, 3);
    status2[i] = random(0, 3);
    
    if (amountActiveStatus2 >= 9 && status2[i] == 1) {       //ilosc aktywnych wskaźników ma byc mniejsza rowna 9
      do {
        status2[i] = random(0, 3);
      } while (status2[i] == 1);
    }
    
if (i>=13 && amountActiveStatus2 <2 && status2[i] != 1) {       //ilosc aktywnych wskaźników ma byc wieksza niz 2
      do {
        status2[i] = random(0, 3);
      } while (status2[i] != 1);
    }
    
    if (status2[i] == 1) {
      amountActiveStatus2++;
    }
    else if (status2[i] == 2) {
      amountErrorStatus2++;
    }
    if (debug == true) Serial.println("Status 1 = " + String(status1[i]) + "   Status 2 = " + String(status2[i]));
  }

  deuterRandom = random(0, 5);



  if (debug == true) Serial.println("Deuter = " + String(deuterRandom));
}

// Funkcja tworząca string do wyslania po ISP informacji o tym aktywnych STATUSACh i wybranych grach
String sendInfoToSecondPanel(byte status1[15], byte status2[15], byte randomGames[3]) {

  String temp;
  temp = "F";
  for (byte i = 0; i < 15; i ++) {
    temp += String(status1[i]);
  }

  for (byte i = 0; i < 15; i ++) {
    temp += String(status2[i]);
  }

  for (byte i = 0; i < 3; i++) {
    temp += String(randomGames[i]);
  }
  temp = temp + "K";
  return temp;
}

String sendInfoToSecondArduino(byte deuter) {
  return String(deuter);
}

// Funkcja służąca do sprawdzania czy został przekręcony kluczk
char tekstLedsGame[12];
void readStartButton() {
  char charBuf[33];/* = "F121201020012020122011111202010K";*/
                         
  String tekst;
  if ((digitalRead(43) == HIGH && gameStarted == false) || restartGame == true ) {
    allowMeasureTime = true;
    gameStarted = true;
    restartGame = false;
//  readPyroButtons(info);
    minutes = 0;
    seconds = 0;
    //Wybieranie losowych gier
    setRandomGames();
    setTime(setMinutes, 0);
    //Zapalenie zielonej lampki w kluczyku
    digitalWrite(41, HIGH);
    String temp = "";

    //Wyslanie informacji do drugiego uC o wylosowanych kolorach Deuter
    temp = "D" + String(deuterRandom);
    Serial2.println(temp);
    
    tekst = sendInfoToSecondPanel(status1, status2, randomGames);
    tekst.toCharArray(charBuf, 33);


    charBuf[31] = 'K';
    charBuf[32] = '\0';
    delay(500);
    digitalWrite(48, LOW);

    char c;
    for (const char * p = charBuf ; c = *p; p++) {
      SPI.transfer (c);
      delayMicroseconds(2000);
    }



    //SPI.transfer ('K');
    digitalWrite(48, HIGH);
    delay(50);
    tekst = "";
    tekst = "L";
    for(byte i = 0; i < 9; i++){
      tekst += String(startGames[i]);
    }
    tekst += "K";
    tekst.toCharArray(tekstLedsGame, 12);
     //tekstLedsGame[1] = '2';
    digitalWrite(48, LOW);

    //char c;
    for (const char * p = tekstLedsGame ; c = *p; p++) {
      SPI.transfer (c);
      delayMicroseconds(2000);
    }



    //SPI.transfer ('K');
    digitalWrite(48, HIGH);

    

    if (debug == true) Serial.println(charBuf);
    if (debug == true) {
      //Serial.println(sendInfoToSecondPanel(status1, status2, randomGames));
      for (byte i = 0; i < 9; i++) {
        //Serial.println("Active game " + String(i) + " = " + String(startGames[i]));
      }
    }
  }


}


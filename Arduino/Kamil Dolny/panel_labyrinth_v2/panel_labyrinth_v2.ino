#include "labirynth.h"

void setup() {
  initLabyrinthPanel();

  //randomLabirynth();
Serial1.begin(9600);
Serial.begin(9600);
}




bool finishGame = false;
bool startGame = false;
void loop() {
  String msg = "";

  if (error > errorPrev) {
      Serial1.println("E");

    }
        errorPrev = error;
  if (Serial1.available() > 0) { // Pobieranie danych z portu szeregowego
    while (Serial1.available() > 0) { // pobieraj tak długo aż bufor będzie pusty
      msg += char(Serial1.read());
      delay(5);
    }
    
    

    
    if (msg[0] == '1') {
      startGame = true;
      randomLabirynth();
    }
    else if (msg[0] == 'R') {
      startGame = false;
      currentPosition[0][0] = 15;
      currentPosition[1][0] = 15;
      xR =1; 
      yR = 1;

    }
  }
    msg = "";
  if (Serial.available() > 0) { // Pobieranie danych z portu szeregowego
    while (Serial.available() > 0) { // pobieraj tak długo aż bufor będzie pusty
      msg += char(Serial.read());
      delay(5);
    }
    
    

    
    if (msg[0] == '1') {
      startGame = true;
      finishGame = false;      
      randomLabirynth();
    }
    else if (msg[0] == 'R') {
      startGame = false;
      finishGame = false;
      currentPosition[0][0] = 15;
      currentPosition[1][0] = 15;
      xR =1; 
      yR = 1;
    }
  }

  if (startGame == true) {
    
    //Serial.println("X= " + String(analogRead(A1)) + "  Y = " + String(analogRead(A2)));
    if (currentPosition[0][0] == 1 && currentPosition[1][0] == 1 && finishGame == false) {
      finish();
      finishGame = true;
      Serial1.println("P");
      startGame = false;
    }
    else if (finishGame == false) {
      setBlue(labirynthCombination[randomLab][0], labirynthCombination[randomLab][1]);
      setBlue(labirynthCombination[randomLab][2], labirynthCombination[randomLab][3]);
      setGreen(8, 8);
      setRed(xR, yR);
    }


    readJoystick();

    if (directionLab != 0) {

      if (randomLab == 0 )changePosition(directionLab, firstLab);
      else if (randomLab == 1 ) changePosition(directionLab, secondLab);
      else if (randomLab == 2 )  changePosition(directionLab, thirdLab);
      else if (randomLab == 3 ) changePosition(directionLab, fourthLab);
      else if (randomLab == 4 ) changePosition(directionLab, fifthLab);
      else if (randomLab == 5 ) changePosition(directionLab, sixthLab);
    }

    
  }
  else{
    mcp.writeGPIOAB(0xF00F);
  }

}

void finish() {
  mcp1.writeGPIOAB(0xFFFF);
  for (byte i = 0; i < 3; i++) {
    mcp.writeGPIOAB(0xFF0);
    delay(100);
    mcp.writeGPIOAB(0x0);
    delay(100);
  }
  mcp.writeGPIOAB(0xF00F);
}


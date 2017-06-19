
#include <Wire.h>    // Required for I2C communication
#include "deuter.h"
#include "simonSays.h"
#include "garret.h"
#include "pyrotechnics.h"
#include "button.h"

bool allowSimon = false; // zmienna do uruchomienia gry simonSays
int bte = B01;
void setup() {


  Serial.begin(9600);
  //Serial.println("test1");
  initDeuterPanel();
  //Serial.println("test2");
  initSimonSaysPanel();
  //Serial.println("test3");
  initGarretPanel();
  //Serial.println("test4");
  initButtonPanel();
  //Serial.println("test5");
  initPyroPanel();
  //Serial.println("test6");
  setGarretNumber(10);
  //Serial.println("test7");

  //setColorButton(buttonColor[1]);
  
}




void loop() {

  checkSerialPort(); // Sprawdzanie czy przyszło żądania o wysłanie danych lub zapis danych

  readSimonButton(); // Odczyt położenia przycisków Simon Says
  readGarretButton(); // Odczyt położenia przycisków garret
  readPyroButtons(); // Odczyt położenia przycisków Pyrotechnics
  readAbortButtons(); // Odczyt położenia przycisków Abort
  readEventButtons(); // Odczyt położenie przycisków eventSequence i przycisku Button

  //Gra Simon Says
  if (allowSimon == true) {
    simonSaysGame();
  }

  if(errors > errorsPrev){
    delay(50);
    Serial.println("E");
    delay(50);
  }

  errorsPrev = errors;

}


void checkSerialPort() {
  String msg = "";

  timer_t.process();

  if (Serial.available() > 0) { // Pobieranie danych z portu szeregowego
    while (Serial.available() > 0) { // pobieraj tak długo aż bufor będzie pusty
      msg += char(Serial.read());
      delay(5);
    }

    String temp = "";
    if (msg[0] == 'G') {
      Serial.println(returnButtons());
    }
    else if(msg[0] =='E'){
      errors++;
      errorsPrev = errors;
    }

    else if (msg[0] == 'g') {

      if (msg[1] == 'n') {
        setGarretNumber(10);
      }
      else {
        temp += msg[1];

        setGarretNumber(temp.toInt());
      }
    }


    else if (msg[0] == 'B') {
      temp += msg[1];

      setColorButton(buttonColor[temp.toInt()]);
    }

    else if (msg[0] == 'D') {
      temp += msg[1];

      setDeuterColorVariant(byte(temp.toInt()));
    }
    else if (msg[0] == 'S') {
      if (msg[1] == '0') {
        allowSimon = false;
        setNewColors = false;
        ilosc = 2;
        itteration = 1;
        simonLevel = 0;
        errors = 0; 
        errorsPrev = 0;
        for (byte i = 0; i < 4; i++) {              

          pcf5.digitalWrite(i + 4, HIGH);
          pcf6.digitalWrite(i, LOW);
          
        }
      }
      else if (msg[1] == '1') {
        allowSimon = true;
        setNewColors =true;
        errors = 0;
        errorsPrev = 0;

        {
          if (msg[2] == 'Y') {
            vowel = true;
          }
          else {
            vowel = false;
          }
        }
      }
    }


  }
}

String returnButtons() {

  String temp = "";
  for (byte i = 0; i < 3; i++) {
    if (garretButton[i] == true) {
      temp += "1";
    }
    else {
      temp += "0";
    }
  }

  for (byte i = 0; i < 7; i++) {
    if (pyroButton[i] == true) {
      temp += "1";
    }
    else {
      temp += "0";
    }
  }

  for (byte i = 0; i < 3; i++) {
    if (abortButton[i] == true) {
      temp += "1";
    }
    else {
      temp += "0";
    }
  }

  for (byte i = 0; i < 5; i++) {
    if (eventButton[i] == true) {
      temp += "1";
    }


    else {
      temp += "0";
    }
  }


  return temp;

}




#include "Timers.h"
#include "simonSaysLogic.h"
Timers<2> timer_t;

extern bool allowSimon;

bool setNewColors = true;
byte itteration = 1;




bool wait = false;
bool zapalono = false;

bool abortButton[3] = {false, false, false};
bool simonFlag = false;

void setSimonLeds() {


  if (allowSimon == true) {
    if (again == true && simonLevel < 11 ) {
      if (zapalono == false ) {
        for (byte i = 0; i < itteration; i++) {

          pcf5.digitalWrite(randomColor[i], LOW);



        }
        itteration++;
      }

      if (zapalono == true) {
        for (byte i = 0; i < itteration; i++) {

          pcf5.digitalWrite(randomColor[i], HIGH);



        }

        zapalono = false;
        wait = true;
        itteration = 1;
        again = false;
      }

      if (wait == false && itteration == ilosc) {
        zapalono = true;
      }
      else {
        wait = false;
      }

    }
  }
}

void showAgain() {

  if (allowSimon == true) again = true;

}

void additt() {
  itteration ++;
  if (itteration > 4)
    itteration = 1;
}
void initSimonSaysPanel() {

  randomSeed(analogRead(A0));
  pcf5.begin(0x25);
  pcf6.begin(0x26);

  for (byte i = 0; i < 4; i++) {
    pcf5.pinMode(i, INPUT_PULLUP);
    pcf5.pinMode(i + 4, OUTPUT);
    pcf6.pinMode(i, OUTPUT);

    pcf5.digitalWrite(i + 4, HIGH);
    pcf6.digitalWrite(i, LOW);
  }

  for (byte i = 0; i < 3; i++) {
    pcf6.pinMode(i + 4, INPUT_PULLUP);
  }


  timer_t.attach(0, 500, setSimonLeds);
  timer_t.attach(1, 5000, showAgain);
  //delay(5000);
  simonButton.redPrev = pcf5.digitalRead(3);
  simonButton.greenPrev = pcf5.digitalRead(2);
  simonButton.orangePrev = pcf5.digitalRead(0);
  simonButton.bluePrev = pcf5.digitalRead(1);

  //Serial.println("Start");
}





void simonSaysGame() {
  if (setNewColors == true) {
    randomColors();

    setNewColors = false;
  }

  simonLogicGame();


}

void readAbortButtons() {
  for (byte i = 0; i < 3; i ++) {
    if (pcf6.digitalRead(i + 4) == LOW) {
      abortButton[i] = true;
    }
    else abortButton[i] = false;
  }
}


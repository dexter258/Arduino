#include <LiquidCrystal.h>

LiquidCrystal lcd_button(12, 8, 5, 4, 3, 2);

String buttonText[4] = {"Hold", "Press", "Abort", "Detonate"};
byte randomTextButton;
byte randomColorButton;

extern bool debugInput;
extern byte error;
extern byte randomAddInfo;
extern byte setMinutes;
extern byte minutes;
extern byte seconds;

bool pressedButton;
bool flagButton = false;
long startButton , stopButton;

bool buttonPass = false;

void randomButtonTextColor() {
  lcd_button.clear();
  lcd_button.setCursor(0, 0);

  randomTextButton = random(0, 4);
  randomColorButton = random(0, 4);
  lcd_button.print(buttonText[randomTextButton]);
  String temp = "B" + String(randomColorButton);
  if (debug == true) Serial.println(temp);


  Serial2.println(temp);

  delay(100);
}

void initButtonPanel() {
  lcd_button.begin(16, 2);
  //lcd_button.setCursor(0,0);
  //lcd_button.print("Witaj Button");
  //randomButtonTextColor();
}



// Do poprawy
bool checkTime(char number) {
  String minute = "";
  String second = "";
  if ((setMinutes - minutes - 1) < 10) {
    minute = "0" + String(setMinutes - minutes - 1);
  }
  else {
    minute = String(setMinutes - minutes - 1);
  }
  if ((60 - seconds) < 10) {
    second = "0" + String(60 - seconds);
  }
  else {
    second = String(60 - seconds);
  }

  if (number == minute[0] || number == minute[1] || number == second[0] || number == second[1]) {
    return true;
  }

  return false;

}

void buttonGame() {

  // Przypadek gdy wyswietla się HOLD
  if (randomTextButton == 0) {
    if (pressedButton == true && flagButton == false) {
      flagButton = true;
      startButton = millis();
      if (debug == true) Serial.println("Test1");
    }
    else if (pressedButton == false && flagButton == true) {
      flagButton = false;
      stopButton = millis();
      if (debug == true) Serial.println("Test2");

      if ((stopButton - startButton) < 1000) {
        buttonPass = true;
        passedGames++;
        if (debug == true) Serial.println("Test3");
      }
      else {
        error++;
        randomButtonTextColor();
        //Serial2.print("B" + String(randomColorButton));
        if (debug == true) Serial.println("Test4");
        delay(100);
      }

    }
  }


  // Przypadek gdy wyswietli sie PRESS
  else if (randomTextButton == 1 && randomAddInfo == 0) {

    if (pressedButton == true && flagButton == false) {
      flagButton = true;
      startButton = millis();
      if (debug == true) Serial.println("Test5");
    }
    else if (pressedButton == false && flagButton == true) {
      flagButton = false;
      stopButton = millis();
      if (debug == true) Serial.println("Test6");

      if ((stopButton - startButton) > 4000 && (stopButton - startButton) < 6000 ) {
        buttonPass = true;
        passedGames++;
        if (debug == true) Serial.println("Test7");
      }
      else {
        error++;
        randomButtonTextColor();
        //Serial2.print("B" + String(randomColorButton));
        delay(100);
        if (debug == true) Serial.println("Test8");
      }
    }
  }

  else {
    if (pressedButton == true && flagButton == false) {
      flagButton = true;
      if (debug == true) Serial.println("Test9");

    }
    else if (pressedButton == false && flagButton == true && randomAddInfo == 1 && checkTime('4') && randomColorButton == 2) {
      flagButton = false;
      buttonPass = true;
      passedGames++;
      if (debug == true) Serial.println("Test10");
    }
    else if (pressedButton == false && flagButton == true && randomColorButton == 1 && checkTime('8')) {
      flagButton = false;
      buttonPass = true;
      passedGames++;
      if (debug == true) Serial.println("Test11");
    }
    else if (pressedButton == false && flagButton == true && randomColorButton == 3 && checkTime('5')) {
      flagButton = false;
      buttonPass = true;
      passedGames++;
      if (debug == true) Serial.println("Test12");
    }

    else if (pressedButton == false && flagButton == true && checkTime('1')) {
      flagButton = false;
      buttonPass = true;
      passedGames++;
      if (debug == true) Serial.println("Test13");
    }

    else if (pressedButton == false && flagButton == true) {
      error++;
      flagButton = false;
      randomButtonTextColor();
      if (debug == true) Serial.println("Test14");
      //Serial2.print("B" + String(randomColorButton));
      delay(100);
    }




  }

}


void readButtonButton(String info){
  String temp1;
  
  temp1 = "";
  
  temp1 += info[17];

  pressedButton = bool(temp1.toInt());

  if (debugInput == true && pressedButton == true) Serial.println("OK");

}


#include "Timers.h"
extern bool debug;

Adafruit_MCP23017 mcp, mcp1;

//Definiowane timerów
Timers<4> timer_t;

//Zmienna odpowiadające za wyświetlanie odpowiedniego czasu
byte minutes = 0 , seconds = 0;
bool gameOver = false;
// Początkowa wartość czasu
byte setMinutes = 5;

bool allowMeasureTime = false;

bool firstNumber[10][8] = {      {LOW, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}, // zero
  {LOW, LOW, LOW, LOW, HIGH, LOW, LOW, HIGH}, // jeden
  {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH, LOW}, // dwa
  {HIGH, LOW, LOW, HIGH, HIGH, LOW, HIGH, HIGH}, // trzy
  {HIGH, LOW, HIGH, LOW, HIGH, LOW, LOW, HIGH}, // cztery
  {HIGH, LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH}, // pięć
  {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH, HIGH}, // sześć
  {LOW, LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH}, // siedem
  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}, // osiem
  {HIGH, LOW, HIGH, HIGH, HIGH, LOW, HIGH, HIGH}, //dziewięć
};


bool secondNumber[10][7] = {     {LOW, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}, // zero
  {LOW, LOW, LOW, HIGH, LOW, LOW, HIGH}, // jeden
  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, LOW}, // dwa
  {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH}, // trzy
  {HIGH, HIGH, LOW, HIGH, LOW, LOW, HIGH}, // cztery
  {HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH}, // pięć
  {HIGH, HIGH, HIGH, LOW, HIGH, HIGH, HIGH}, // sześć
  {LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH}, // siedem
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}, // osiem
  {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH}, //dziewięć
};

//Funkcja odpowadająca za wyświetlanie czasu
void setTime(byte minutes, byte seconds) {
  String temp1 = "", temp2;


  if (minutes < 10) {
    for (byte j = 0; j < 7; j++) {
      mcp.digitalWrite(j + 9, secondNumber[minutes][j]);
      mcp.digitalWrite(j, LOW);
      mcp.digitalWrite(7, LOW);
    }
  }
  else {
    temp1 = String(minutes)[0];
    temp2 = String(minutes)[1];

    for (byte j = 0; j < 8; j++) {
      mcp.digitalWrite(j, firstNumber[temp1.toInt()][j]);
    }

    for (byte j = 0; j < 7; j++) {
      mcp.digitalWrite(j + 9, secondNumber[temp2.toInt()][j]);
    }

  }

  if (seconds < 10) {
    for (byte j = 0; j < 7; j++) {
      mcp1.digitalWrite(j + 9, secondNumber[seconds][j]);
      mcp1.digitalWrite(j + 1, secondNumber[0][j]);
    }
  }
  else {
    temp1 = String(seconds)[0];
    temp2 = String(seconds)[1];

    for (byte j = 0; j < 7; j++) {
      mcp1.digitalWrite(j + 1, secondNumber[temp1.toInt()][j]);
    }

    for (byte j = 0; j < 7; j++) {
      mcp1.digitalWrite(j + 9, secondNumber[temp2.toInt()][j]);
    }

  }
}

//Funkcja wywoływana co sekudnę i zmienjaąca czas
void measureTime() {
  if (allowMeasureTime == true) {
    if (setMinutes - minutes - 1 == 0 && 60 - seconds == 0) {
      setTime(0, 0);
      gameOver = true;
    }
    else {
      seconds ++;
      if (seconds > 60) {
        seconds = 0;
        seconds ++;
        minutes ++;
      }


      setTime(setMinutes - minutes - 1, 60 - seconds);
    }
  }

}



// Inicjalizacja penlu TIME/CZAS
void initTimePanel() {

  mcp.begin(0);
  mcp1.begin(1);
  for (int i = 0; i < 16; i++) {
    mcp.pinMode(i, OUTPUT);
    mcp1.pinMode(i, OUTPUT);
    mcp.digitalWrite(i, LOW);
    mcp1.digitalWrite(i, LOW);
  }
  //Ustawienie początkowego czasu
  //setTime(setMinutes, 0);
  timer_t.attach(0, 1000, measureTime);

}


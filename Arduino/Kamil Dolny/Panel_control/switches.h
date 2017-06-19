#include "Adafruit_MCP23017.h"
Adafruit_MCP23017 mcp0;

bool switchesRed[5];
byte switchesBlue[5];


void readSwitches() {


  for (byte i = 0; i < 5; i++) {
    if (mcp0.digitalRead(i+10) == LOW) {
      mcp0.digitalWrite(i+5, HIGH);
      switchesRed[i] = true;
    }
    else {
      mcp0.digitalWrite(i+5, LOW);
      switchesRed[i] = false;
    }
  }
  
  
  int j = 0;
  for (byte i = 2; i < 12; i = i + 2) {
    if (digitalRead(i) == LOW) {
      switchesBlue[j] = 2;
      mcp0.digitalWrite(j, LOW);
    }
    else if (digitalRead(i + 1) == LOW) {
      switchesBlue[j] = 1;
      mcp0.digitalWrite(j, HIGH);
    }
    else {
      switchesBlue[j] = 0;
    }
    j++;
  }


}

String sendSwitches(){
  String temp="";

  for(byte i = 0; i < 5; i++){
    temp = temp + String(switchesBlue[i]);
  }

  /*for(byte i = 0; i < 5; i++){
    temp = temp + String(switchesRed[i]);
  }9*/

  return temp;
}


#include "PCF8574.h" // Required for PCF8574

PCF8574 pcf3;
bool pyroButton[7]={false, false, false, false, false, false, false};
void initPyroPanel(){

  pcf3.begin(0x23);

  for(byte i = 0; i < 7; i++){
    pcf3.pinMode(i, INPUT);
    pcf3.digitalWrite(i, HIGH);
  }
}

void readPyroButtons(){

  for(byte i = 0; i < 7; i++){
    if(pcf3.digitalRead(i) == HIGH){
      pyroButton[i] = true;
    }
    else{
      pyroButton[i] = false;
    }
  }
}


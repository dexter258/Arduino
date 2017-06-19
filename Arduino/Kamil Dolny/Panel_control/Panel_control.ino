#include "switches.h"
long startSend, stopSend;
bool sendString= false;
void setup() {
  delay(10000);
  mcp0.begin(0);

  for(byte i = 0; i < 16; i++){
    if(i < 10){
      mcp0.pinMode(i, OUTPUT);
      mcp0.digitalWrite(i, LOW);
    }
    else{
      mcp0.pinMode(i, INPUT_PULLUP);
      mcp0.digitalWrite(i, HIGH);
    }
  }

  for(byte i = 2; i < 12; i++){
    pinMode(i, INPUT_PULLUP); 
  }
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  readSwitches();
  if(sendString == false){
    startSend = millis();
    sendString = true;
  }

  stopSend = millis();

  if(stopSend- startSend > 250){
    Serial.println(sendSwitches());
    sendString = false;
  }
  
}



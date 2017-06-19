#include "ledsBar.h"

void setup() {
  // put your setup code here, to run once:
  mcp0.begin(0);
  mcp1.begin(1);
  mcp2.begin(2);
  
  for(byte i = 0; i < 16; i ++){
    mcp0.pinMode(i, OUTPUT);
    mcp1.pinMode(i, OUTPUT);
    mcp2.pinMode(i, OUTPUT);

    mcp0.digitalWrite(i, HIGH);
    mcp1.digitalWrite(i, HIGH);
    mcp2.digitalWrite(i, HIGH);
  }

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  //Serial.println("Voltage = " + String(analogRead(A0)) + " Q = " + String(analogRead(A1)) + " Current = "+ String(analogRead(A2)) + " QFLOW = " + String(analogRead(A3)));
  setBars(map(analogRead(A0),0,1023,1,10), map(analogRead(A1),0,1023,1,10), map(analogRead(A2),0,1023,1,10), map(analogRead(A3),0,1023,1,10));
  //delay(100);
  
}

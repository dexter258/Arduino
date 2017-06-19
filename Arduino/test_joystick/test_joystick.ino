#include <Wire.h>
#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp;
#define lewo A
#define prawo 
void setup() {  
  mcp.begin();      // use default address 0
for (int i=0;i<16;i++){
  mcp.pinMode(i, OUTPUT);
    mcp.digitalWrite(i,LOW);
}
pinMode(lewo,INPUT);
pinMode(prawo,INPUT);
pinMode(gota,INPUT);
pinMode(dol,INPUT);
pinMode(strzal,INPUT);



}



void loop() {
//duupa 
//tak adwadwad

}

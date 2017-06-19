#include <Wire.h>
#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp;
#define lewo A0
#define prawo 5
#define gora 6
#define dol 7
#define strzal 8
$define stycznik 4
byte x;
boolean Joystick[5];
boolean start=false;
boolean left=false;
boolean right=false;
boolean up=false;
boolean down=false;
void setup() {  
  mcp.begin();      // use default address 0
for (int i=0;i<16;i++){
  mcp.pinMode(i, OUTPUT);
    mcp.digitalWrite(i,LOW);
}
pinMode(stycznik,INPUT);
pinMode(lewo,INPUT);
pinMode(prawo,INPUT);
pinMode(gora,INPUT);
pinMode(dol,INPUT);
pinMode(strzal,INPUT);



}



void loop() {
 if (digitalRead(stycznik)==HIGH){
   start=true;
 }
 
 if (start==true){
   Joystick[0]=false;
   Joystick[1]=false;
   Joystick[2]=false;
   Joystick[3]=false;
   Joystick[4]=false;
   
  if ((digitalRead(lewo)==LOW)&& (Left==true)){
   left=false;
  } 
   if ((digitalRead(lewo)==HIGH)&& (Left==false)){ 
     Joystick[0]=true;
     Left=true;
   }
  x=random(0,3);
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 }
 }












}

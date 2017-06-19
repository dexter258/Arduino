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
boolean wylosowano=false;
boolean strzelaj=false;
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
   
  if ((digitalRead(lewo)==LOW)&& (left==true)){
   left=false;
  } 
   if ((digitalRead(lewo)==HIGH)&& (left==false)){ 
     Joystick[0]=true;
     left=true;
   }
   
    if ((digitalRead(prawo)==LOW)&& (right==true)){
   right=false;
  } 
   if ((digitalRead(prawo)==HIGH)&& (right==false)){ 
     Joystick[1]=true;
     right=true;
   }
   
      if ((digitalRead(gora)==LOW)&& (up==true)){
   up=false;
  } 
   if ((digitalRead(gora)==HIGH)&& (up==false)){ 
     Joystick[2]=true;
     up=true;
   }
   
      if ((digitalRead(dol)==LOW)&& (down==true)){
   down=false;
  } 
   if ((digitalRead(dol)==HIGH)&& (down==false)){ 
     Joystick[3]=true;
     down=true;
   }
   
      if ((digitalRead(strzal)==LOW)&& (fire==true)){
   fire=false;
  } 
   if ((digitalRead(strzal)==HIGH)&& (fire==false)){ 
     Joystick[4]=true;
     fire=true;
   }
   
   if (wylosowano==false){
       x=random(0,4);
       wylosowano=true;
   }
  digitalWrite(x*0
  for (int i=0; 
  
  
  if ((strzelaj==false)&& (pauza_stzelania==false)){
    strzelaj=true;
    odliczanie_strzal=millis();
  }
  if ((strzelaj==true) && (Joystick==true)){
  strzelaj=false;
  }
  if (millis()-odliczanie_strzal>3000){
  mcp.digitalWrite(12,HIGH);
   mcp.digitalWrite(13,LOW);
mcp.digitalWrite(14,LOW);
  
  
 }
 }












}

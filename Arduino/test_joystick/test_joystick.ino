#include <Wire.h>
#include "Adafruit_MCP23017.h"

boolean start=true;


Adafruit_MCP23017 mcp;
#define lewo A0
#define prawo 6
#define gora 5
#define dol 7
#define strzal 8
#define stycznik 4
byte x;
boolean Joystick[5];

boolean left=false;
boolean right=false;
boolean up=false;
boolean down=false;
boolean fire=false;
boolean wylosowano=false;
boolean strzelaj=false;
boolean pauza_strzelania=false;
boolean wygaszenie_strzal=false;
boolean    wygaszenie=false;

long czas_na_strzal=2400;    
long czas_po_strzale=500;
long po_strzale;
long czas_pauzy_pomiedzy_strzalami=6000;          //pozniej jest losowane    fire
long odliczanie_strzal;
long  czas_pauza_strzelanie;


boolean strzelaj_boki=false;
boolean pauza_strzelania_boki=false;
boolean wygaszenie_strzal_boki=false;
boolean    wygaszenie_boki=false;
long czas_na_strzal_boki=2400;    
long czas_po_strzale_boki=500;

long po_strzale_boki;
long czas_pauzy_pomiedzy_strzalami_boki=6000;        // pozniej jest losowanie boki
long odliczanie_strzal_boki;
long  czas_pauza_strzelanie_boki;






void setup() {  
  Serial.begin(9600);
  mcp.begin();      // use default address 0
for (int i=0;i<16;i++){
  mcp.pinMode(i, OUTPUT);
    mcp.digitalWrite(i,HIGH);
}
pinMode(stycznik,INPUT);
pinMode(lewo,INPUT);
pinMode(prawo,INPUT);
pinMode(gora,INPUT);
pinMode(dol,INPUT);
pinMode(strzal,INPUT);

}


void loop() {
  
  
  Serial.println(digitalRead(lewo));
Serial.println(digitalRead(prawo));
Serial.println(digitalRead(gora));
Serial.println(digitalRead(dol));
Serial.println(digitalRead(strzal));
Serial.println("                                           ");
Serial.println("                                           ");
Serial.println("                                           ");
      delay(1000);
  
  
// if (digitalRead(stycznik)==HIGH){
//   start=true;
// }

/*
 for (int i=0;i<15;i=i+3){
mcp.digitalWrite(i,LOW);
  mcp.digitalWrite(i+1,HIGH);
  mcp.digitalWrite(i+2,HIGH);
}
delay(3000);
for (int i=0;i<15;i=i+3){
mcp.digitalWrite(i,HIGH);
  mcp.digitalWrite(i+1,LOW);
  mcp.digitalWrite(i+2,HIGH);
}
delay(3000);
for (int i=0;i<15;i=i+3){
mcp.digitalWrite(i,HIGH);
  mcp.digitalWrite(i+1,HIGH);
  mcp.digitalWrite(i+2,LOW);
}
delay(3000);

*/
 if (start==true){
   Joystick[0]=false;                             //kasowanie wychylen
   Joystick[1]=false;
   Joystick[2]=false;
   Joystick[3]=false;
   Joystick[4]=false;
                                        

                                                            //sprawdzenie wychylan joysticka
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
   
  if ((strzelaj_boki==false)&& (pauza_strzelania_boki==false)){
    strzelaj_boki=true;
     x=random(0,4);
    odliczanie_strzal_boki=millis();
  mcp.digitalWrite(0*x,HIGH);
   mcp.digitalWrite(1*x,HIGH);
mcp.digitalWrite(2*x,LOW);  
}
  if (((millis()-odliczanie_strzal_boki>czas_na_strzal_boki)&&(strzelaj_boki==true)) || ((strzelaj_boki==false)&&(Joystick[x]==true))){
  mcp.digitalWrite(0*x,LOW);
   mcp.digitalWrite(1*x,HIGH);
mcp.digitalWrite(2*x,HIGH);
   po_strzale_boki=millis();
   strzelaj_boki=false;
   pauza_strzelania_boki=true;
   wygaszenie_strzal_boki=true;
   wygaszenie_boki=true;
 }
   if ((strzelaj_boki==true) && (Joystick[x]==true)){
  strzelaj_boki=false;
   mcp.digitalWrite(0*x,HIGH);
   mcp.digitalWrite(1*x,LOW);
mcp.digitalWrite(2*x,HIGH); 
pauza_strzelania_boki=true;
po_strzale_boki=millis();
  wygaszenie_strzal_boki=true;
     wygaszenie_boki=true;
  }
   if (((millis()-po_strzale_boki>czas_po_strzale_boki)&&(strzelaj_boki==false))&& (wygaszenie_strzal_boki==true)){
   mcp.digitalWrite(0*x,HIGH);
   mcp.digitalWrite(1*x,HIGH);
mcp.digitalWrite(2*x,HIGH);
  wygaszenie_strzal_boki=false;
 }
if (wygaszenie_boki==true){
wygaszenie_boki=false;
czas_pauzy_pomiedzy_strzalami_boki=random(900,2400);
 czas_pauza_strzelanie_boki=millis();
}
 if ((millis()-czas_pauza_strzelanie_boki>czas_pauzy_pomiedzy_strzalami_boki)&&(pauza_strzelania_boki==true)){
   pauza_strzelania_boki=false;
 }




                                                  // przeprowadzanie analizy strzalu 

  
  if ((strzelaj==false)&& (pauza_strzelania==false)){
    strzelaj=true;
    odliczanie_strzal=millis();
  mcp.digitalWrite(12,HIGH);
   mcp.digitalWrite(13,HIGH);
mcp.digitalWrite(14,LOW);  
}
                                                           // jezeli blad strzalu
  if (((millis()-odliczanie_strzal>czas_na_strzal)&&(strzelaj==true)) || ((strzelaj==false)&&(Joystick[4]==true))){
  mcp.digitalWrite(12,LOW);
   mcp.digitalWrite(13,HIGH);
mcp.digitalWrite(14,HIGH);
   po_strzale=millis();
   strzelaj=false;
   pauza_strzelania=true;
   wygaszenie_strzal=true;
   wygaszenie=true;
 }
                                                                // jezeli strzal dobrze
   if ((strzelaj==true) && (Joystick[4]==true)){
  strzelaj=false;
   mcp.digitalWrite(12,HIGH);
   mcp.digitalWrite(13,LOW);
mcp.digitalWrite(14,HIGH); 
pauza_strzelania=true;
po_strzale=millis();
  wygaszenie_strzal=true;
     wygaszenie=true;
  }
                                                                    // wygaszenie po bledzie lub dobrze
   if (((millis()-po_strzale>czas_po_strzale)&&(strzelaj==false))&& (wygaszenie_strzal==true)){
   mcp.digitalWrite(12,HIGH);
   mcp.digitalWrite(13,HIGH);
mcp.digitalWrite(14,HIGH);
  wygaszenie_strzal=false;
 }
if (wygaszenie==true){
wygaszenie=false;
czas_pauzy_pomiedzy_strzalami=random(2200,3800);
 czas_pauza_strzelanie=millis();
}
                                                                      //przerwa 
 if ((millis()-czas_pauza_strzelanie>czas_pauzy_pomiedzy_strzalami)&&(pauza_strzelania==true)){
   pauza_strzelania=false;
 }
 }

}

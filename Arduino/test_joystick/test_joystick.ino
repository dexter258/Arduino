#include <Wire.h>
#include "Adafruit_MCP23017.h"

boolean start=true;
int poziom=128;
int maxx=175;
int minn=65;
int ilosc_pkt_odejmowanych_za_blad=5;
int ilosc_pkt_dodawanyc_za_dobrze=5;

Adafruit_MCP23017 mcp;
#define lewo A0
#define prawo 6
#define gora 5
#define dol 7
#define strzal 8
#define stycznik 4
#define przelacznik_gora 2
#define przelacznik_dol 1 
#define sterownik 3
#define koniec 10 
int x;
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
long czas_po_strzale_boki=380;

long po_strzale_boki;
long czas_pauzy_pomiedzy_strzalami_boki=6000;        // pozniej jest losowanie boki
long odliczanie_strzal_boki;
long  czas_pauza_strzelanie_boki;






void setup() {  
  
//  Serial.begin(9600);
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
pinMode(przelacznik_gora,INPUT);
pinMode(przelacznik_dol,INPUT);
pinMode(koniec,INPUT_PULLUP);
pinMode(sterownik,OUTPUT);
analogWrite(sterownik,poziom);
}


void loop() {
  
  /*
  Serial.println(digitalRead(gora));
  Serial.println(digitalRead(dol));
  Serial.println(digitalRead(lewo));
Serial.println(digitalRead(prawo));
Serial.println(digitalRead(strzal));
Serial.println("                                           ");
Serial.println("                                           ");
Serial.println("                                           ");
     // delay(1000);
  
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
  
  
  
  
  
                                                                /////////          POCZATEK PROGRAMU, SPRAWDZANIE CZY KLODKA JEST OTWARTA PRZEZ STYCZNIUK 
  
  
 
 if (digitalRead(stycznik)==LOW){
  start=true;
}
else {
  start=false;
    for (int i=0;i<15;i++){
     mcp.digitalWrite(i,HIGH);
  }
}
if (digitalRead(koniec)==LOW){
  start=false;
}


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
     Joystick[2]=true;
     left=true;
   }
   
    if ((digitalRead(prawo)==LOW)&& (right==true)){
   right=false;
  } 
   if ((digitalRead(prawo)==HIGH)&& (right==false)){ 
     Joystick[3]=true;
     right=true;
   }
   
      if ((digitalRead(gora)==LOW)&& (up==true)){
   up=false;
  } 
   if ((digitalRead(gora)==HIGH)&& (up==false)){ 
     Joystick[0]=true;
     up=true;
   }
   
      if ((digitalRead(dol)==LOW)&& (down==true)){
   down=false;
  } 
   if ((digitalRead(dol)==HIGH)&& (down==false)){ 
     Joystick[1]=true;
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
  mcp.digitalWrite(0+x*3,HIGH);
   mcp.digitalWrite(1+x*3,HIGH);
mcp.digitalWrite(2+x*3,LOW);  
}
  if (((millis()-odliczanie_strzal_boki>czas_na_strzal_boki)&&(strzelaj_boki==true)) || ((strzelaj_boki==false)&&(Joystick[x]==true))){
  mcp.digitalWrite(0+x*3,LOW);
   mcp.digitalWrite(1+x*3,HIGH);
mcp.digitalWrite(2+x*3,HIGH);
   po_strzale_boki=millis();
   strzelaj_boki=false;
   pauza_strzelania_boki=true;
   wygaszenie_strzal_boki=true;
   wygaszenie_boki=true;
   poziom-=ilosc_pkt_odejmowanych_za_blad;
 }
 if ((x!=0)&&(Joystick[0]==true)){
    mcp.digitalWrite(0,LOW);
   mcp.digitalWrite(1,HIGH);
mcp.digitalWrite(2,HIGH);
mcp.digitalWrite(0+x*3,HIGH);
   mcp.digitalWrite(1+x*3,HIGH);
mcp.digitalWrite(2+x*3,HIGH);  
     po_strzale_boki=millis();
   strzelaj_boki=false;
   pauza_strzelania_boki=true;
   wygaszenie_strzal_boki=true;
   wygaszenie_boki=true;
   poziom-=ilosc_pkt_odejmowanych_za_blad;
 }
  if ((x!=1)&&(Joystick[1]==true)){
    mcp.digitalWrite(3,LOW);
   mcp.digitalWrite(4,HIGH);
mcp.digitalWrite(5,HIGH);
mcp.digitalWrite(0+x*3,HIGH);
   mcp.digitalWrite(1+x*3,HIGH);
mcp.digitalWrite(2+x*3,HIGH);  
     po_strzale_boki=millis();
   strzelaj_boki=false;
   pauza_strzelania_boki=true;
   wygaszenie_strzal_boki=true;
   wygaszenie_boki=true;
   poziom-=ilosc_pkt_odejmowanych_za_blad;
 }
  if ((x!=2)&&(Joystick[2]==true)){
    mcp.digitalWrite(6,LOW);
   mcp.digitalWrite(7,HIGH);
mcp.digitalWrite(8,HIGH);
mcp.digitalWrite(0+x*3,HIGH);
   mcp.digitalWrite(1+x*3,HIGH);
mcp.digitalWrite(2+x*3,HIGH);  
     po_strzale_boki=millis();
   strzelaj_boki=false;
   pauza_strzelania_boki=true;
   wygaszenie_strzal_boki=true;
   wygaszenie_boki=true;
   poziom-=ilosc_pkt_odejmowanych_za_blad;
 }
  if ((x!=3)&&(Joystick[3]==true)){
    mcp.digitalWrite(9,LOW);
   mcp.digitalWrite(10,HIGH);
mcp.digitalWrite(11,HIGH);
mcp.digitalWrite(0+x*3,HIGH);
   mcp.digitalWrite(1+x*3,HIGH);
mcp.digitalWrite(2+x*3,HIGH);  
     po_strzale_boki=millis();
   strzelaj_boki=false;
   pauza_strzelania_boki=true;
   wygaszenie_strzal_boki=true;
   wygaszenie_boki=true;
   poziom-=ilosc_pkt_odejmowanych_za_blad;
 }
 
   if ((strzelaj_boki==true) && (Joystick[x]==true)){
  strzelaj_boki=false;
   mcp.digitalWrite(0+x*3,HIGH);
   mcp.digitalWrite(1+x*3,LOW);
mcp.digitalWrite(2+x*3,HIGH); 
pauza_strzelania_boki=true;
po_strzale_boki=millis();
  wygaszenie_strzal_boki=true;
     wygaszenie_boki=true;
     
     poziom+=ilosc_pkt_dodawanyc_za_dobrze;
  }
   if (((millis()-po_strzale_boki>czas_po_strzale_boki)&&(strzelaj_boki==false))&& (wygaszenie_strzal_boki==true)){
  for (int i=0;i<12;i++){
     mcp.digitalWrite(i,HIGH);
  }
  wygaszenie_strzal_boki=false;
 }
if (wygaszenie_boki==true){
wygaszenie_boki=false;
czas_pauzy_pomiedzy_strzalami_boki=random(400,900);
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
   poziom-=ilosc_pkt_odejmowanych_za_blad;
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
    poziom+=ilosc_pkt_dodawanyc_za_dobrze;
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
 if (start==false)poziom=128;
 
  if (poziom<=128) poziom=128;
 if (poziom>=maxx)poziom=maxx;
 
 if ((digitalRead(przelacznik_gora)==HIGH)&& (start==false)){
   poziom=minn;
 }
 if ((digitalRead(przelacznik_dol)==HIGH)&&(start==false)){
   poziom=maxx;
 }
 analogWrite(sterownik,poziom);

// Serial.println(poziom);

}

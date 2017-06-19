#include <Wire.h>
#include "Adafruit_MCP23017.h"
#include <SimpleSDAudio.h>
#include <muzyka.h>
Adafruit_MCP23017 spindle;
Adafruit_MCP23017 bombardment;
Adafruit_MCP23017 gravity;
  Adafruit_MCP23017 system;
int x=0;
int led=0;
int lvl=0;
int suma=0;
boolean wcisniete=false;
int pasek_led=1;
boolean pasek=false;
const long interval = 10000;  
boolean liczenie=false;
boolean przycisk_poczatkowy_wcisniety=false;
unsigned long previousMillis =0;
unsigned long previous =0;
int anti[3]={2,3,4};
int bombaaa[3]={7,5,6};
int mainn[3]={8,A1,10};

int vital[3]={15,12,9};
int panele[3][4]={{2,7,8,15},{3,5,A1,12},{4,6,10,9}};
int x1=1;
int x2=1;
int x3=1;
int x4=1;
boolean sound[30];
boolean zapamietane_stany[30];
boolean wcisniety[30];
boolean sprawdzaj_dzwieki=false;
boolean koniecc=false;
boolean muzyka_koniec=false;
void setup() {                                                  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Serial.begin(9600);
SdPlay.setSDCSPin(A0); // sd kart cs pini
// Serial.println("poczatek");
if (!SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER))
{
      Serial.println(F("initialization failed. Things to check:"));
    Serial.println(F("* is a card is inserted?"));
    Serial.println(F("* Is your wiring correct?"));
    Serial.println(F("* maybe you need to change the chipSelect pin to match your shield or module?"));
    Serial.print(F("Error code: "));
    Serial.println(SdPlay.getLastError());
      SdPlay.setFile("14.wav"); 
  SdPlay.play();
while(1);
}
// Serial.println("start");
 for (int r=0;r<30;r++){
   sound[r]=false;
 }

spindle.begin(0); 
bombardment.begin(1);   
gravity.begin(2); 
system.begin(3);
for (int aa=2;aa<9;aa++){
  pinMode(aa,OUTPUT);
}
pinMode(A1,OUTPUT);

pinMode(10,OUTPUT);
for (int a=0;a<6;a++){
  spindle.pinMode(a,INPUT);                                // !!!!!!!!!!!!!!!!!!!!!!
}
    spindle.pinMode(8,OUTPUT);
    spindle.pinMode(9,OUTPUT);
spindle.pinMode(10,INPUT);                              // !!!!!!!!!!!!!!!!!!!!!!
    spindle.pinMode(11,OUTPUT);
spindle.pinMode(12,INPUT);                                // !!!!!!!!!!!!!!!!!!!!!!
    spindle.pinMode(13,OUTPUT);
spindle.pinMode(14,INPUT);                                  // !!!!!!!!!!!!!!!!!!!!!!
spindle.pinMode(15,INPUT);  

for (int i=0;i<8;i=i+2){
  
  bombardment.pinMode(i, INPUT);
}
for (int j=8;j<16;j++){
  
  bombardment.pinMode(j, INPUT);
}
for (int k=1;k<8;k=k+2){
  
  bombardment.pinMode(k, OUTPUT);
}

gravity.pinMode(0, INPUT);  
gravity.pinMode(1, INPUT);  
   gravity.pinMode(2, OUTPUT); 
gravity.pinMode(3, INPUT);   
   gravity.pinMode(4, OUTPUT);
gravity.pinMode(5, INPUT);     
   gravity.pinMode(6, OUTPUT);
gravity.pinMode(7, INPUT);
for (int y=9;y<16;y=y+3){
  gravity.pinMode(y,OUTPUT);
}
for (int l=0;l<10;l++){
  system.pinMode(l,OUTPUT);
   system.digitalWrite(l,LOW);
}
 system.pinMode(10,INPUT);
 system.pinMode(11,OUTPUT);
  system.digitalWrite(11,LOW);
 system.pinMode(12,INPUT);
 for (int m=13;m<16;m++){
   system.pinMode(m,OUTPUT);
 }
 
 
                                  //GRAVITY
 digitalWrite(2,LOW);                       //niebieski
digitalWrite(3,LOW);                         //czerwony
  digitalWrite(4,LOW);                        //zielony
                                   
                                    // BOMBARDMENT
digitalWrite(5,LOW);                           //czerwony
digitalWrite(6,LOW);                           //zielony
digitalWrite(7,LOW);                            //niebieski


                             // SPINDLE
digitalWrite(10,LOW);         //zielony
digitalWrite(A1,LOW);         //czerwony
digitalWrite(8,LOW);           //niebieski

                                  //SYSTEM
gravity.digitalWrite(12,LOW) ;        //czerwnoy
gravity.digitalWrite(15,LOW);         //niebieski
gravity.digitalWrite(9,LOW);  
 
 
     spindle.digitalWrite(9,LOW);          //czerwony
    spindle.digitalWrite(8,HIGH);            //zielony
}

void loop() {                                      ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //Serial.println(spindle.digitalRead(12));
  // Serial.println("loop");
  if (przycisk_poczatkowy_wcisniety==false){
       if (spindle.digitalRead(12)==HIGH) {      //przycisk poczatku                                          //przycisk "IGNITION"
             SdPlay.stop();   
     if(!SdPlay.setFile("POWTORZ.wav")) {while(1); }
        //    if(!SdPlay.setFile("14.wav")) {while(1); }
             SdPlay.play();

    sprawdzaj_dzwieki=true;
    delay(5000);
    przycisk_poczatkowy_wcisniety=true;
  }
  
     
  }
   
if (sprawdzaj_dzwieki==true) {
  
  dzwieki_przyciskow();
digitalWrite(2,HIGH); 
digitalWrite(5,HIGH); 
digitalWrite(A1,HIGH);
gravity.digitalWrite(15,HIGH); 

  if (liczenie==false)
 { previousMillis = millis();
 }
      unsigned long currentMillis = millis();



    for (int s=0;s<8;s=s+2){
        bombardment.digitalWrite(s+1,bombardment.digitalRead(s));
  }
      spindle.digitalWrite(11,spindle.digitalRead(10));
  
    spindle.digitalWrite(13,spindle.digitalRead(14));
  for (int i=1;i<7;i=i+2){
    gravity.digitalWrite(i+1,gravity.digitalRead(i));
  }
}

if (koniecc==true){
  sprawdzaj_dzwieki=false;  

  if (muzyka_koniec==false){
               SdPlay.stop();   
     if(!SdPlay.setFile("KONIEC.wav")) {while(1); }
        //    if(!SdPlay.setFile("14.wav")) {while(1); }
             SdPlay.play();
             muzyka_koniec=true;
               zwyciestwo();
  }
  
         if ((spindle.digitalRead(12)==HIGH) && (sound[29]==false)){                                                //przycisk "IGNITION"
             SdPlay.stop();   
     if(!SdPlay.setFile("KONIEC.wav")) {while(1); }
        //    if(!SdPlay.setFile("14.wav")) {while(1); }
             SdPlay.play();
    sound[29]=true;
  }
     if (spindle.digitalRead(12)==LOW) sound[29]=false;
}
 
  // zwyciestwo();
  
*/


}



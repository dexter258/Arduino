#include <Wire.h>
#include "Adafruit_MCP23017.h"
#include <SoftwareSerial.h>
Adafruit_MCP23017 mcp;
SoftwareSerial portOne(12, 13);
SoftwareSerial portTwo(8, 9);
int POWER_1=0;
#define POWER_2 5
int DETEK_1c=2;
int DETEK_1z=1;
#define DETEK_2c 7
#define DETEK_2z 6

#define wyjscie_1_cisza 8
#define wyjscie_2_alarm 11

#define wejscie_1 9
#define wejscie_2 10
int koniec=6;
int zasilanie=5;
int buzzer=4;
int czujnik[5];
int zolty=13;
int zielony=14;
int czerwony=7;
int alarm=15;
int blad=0;
boolean rfid1=false;
boolean rfid2=false;
boolean rfid3=false;
boolean rfid4=false;
boolean sprawdzaj=true;
boolean rozwiazane=false;
boolean alarm_sygnal=true;
const long interval = 2000;  
const long interval_buzzer = 1000;  
   unsigned long currentMillis=0;
  unsigned long currentM=0;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; 
  }
     portOne.begin(9600);
  portTwo.begin(9600);
  mcp.begin();    
 
//  mcp.pinMode(0, OUTPUT);
       czujnik[0]=0;
        czujnik[1]=11;
            czujnik[2]=2;
                czujnik[3]=10;
                    czujnik[4]=4;
  for (int i=0;i<5;i++){

    pinMode(czujnik[i],INPUT);
  }
  pinMode(DETEK_2c,OUTPUT);
    pinMode(DETEK_2z,OUTPUT);
  mcp.pinMode(DETEK_1c,OUTPUT);
    mcp.pinMode(DETEK_1z,OUTPUT);
    
    mcp.pinMode(zielony,OUTPUT);
    mcp.pinMode(zolty,OUTPUT);
    mcp.pinMode(czerwony,OUTPUT);
    mcp.pinMode(alarm,OUTPUT);
   
        mcp.pinMode(wejscie_1,INPUT);
         mcp.pinMode(wejscie_2,INPUT);
      mcp.pinMode(wyjscie_1_cisza,OUTPUT);
         mcp.pinMode(wyjscie_2_alarm,OUTPUT);
          mcp.digitalWrite(wyjscie_1_cisza,HIGH);
          mcp.digitalWrite(wyjscie_2_alarm,LOW);
          
 mcp.pinMode(koniec,OUTPUT);   
 mcp.pinMode(zasilanie,INPUT);
 mcp.pinMode(buzzer,OUTPUT);
 
      mcp.digitalWrite(koniec,LOW);
      mcp.digitalWrite(buzzer,LOW);
pinMode(POWER_2,OUTPUT);
mcp.pinMode(POWER_1,OUTPUT);

mcp.digitalWrite(POWER_1,LOW);
digitalWrite(POWER_2,LOW);
mcp.digitalWrite(DETEK_1z,LOW);
digitalWrite(DETEK_2z,LOW);
mcp.digitalWrite(DETEK_1c,LOW);
digitalWrite(DETEK_2c,LOW);

mcp.digitalWrite(zielony,LOW);
mcp.digitalWrite(zolty,LOW);
mcp.digitalWrite(czerwony,HIGH);
mcp.digitalWrite(alarm,LOW);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char c;
String msg;
char c2;
String msg2;
//char c3;
//String msg3;
void loop() {
  
  if ((mcp.digitalRead(zasilanie)==HIGH) || (rozwiazane==true)){
  
 if (alarm_sygnal==true){
   mcp.digitalWrite(POWER_1,HIGH);
digitalWrite(POWER_2,HIGH);
mcp.digitalWrite(DETEK_1z,LOW);
digitalWrite(DETEK_2z,LOW);
mcp.digitalWrite(DETEK_1c,HIGH);
digitalWrite(DETEK_2c,HIGH);

mcp.digitalWrite(zielony,HIGH);
mcp.digitalWrite(zolty,LOW);
mcp.digitalWrite(czerwony,LOW);
mcp.digitalWrite(alarm,LOW);
 mcp.digitalWrite(buzzer,LOW);

 alarm_sygnal=false;
 }
    mcp.digitalWrite(wyjscie_1_cisza,LOW);
  if ((sprawdzaj==true)&&(rozwiazane==false)){
   
  if ((digitalRead(czujnik[0])==HIGH) || (digitalRead(czujnik[1])==HIGH) ||  (digitalRead(czujnik[2])==HIGH) || (digitalRead(czujnik[3])==HIGH) ||  (digitalRead(czujnik[4])==HIGH)){
     sprawdzaj=false;
  blad++;
 currentMillis = millis();
}
  }
    if (sprawdzaj==false){
    if ((digitalRead(czujnik[0])==LOW) && (digitalRead(czujnik[1])==LOW) &&  (digitalRead(czujnik[2])==LOW) && (digitalRead(czujnik[3])==LOW) &&  (digitalRead(czujnik[4])==LOW)){
   sprawdzaj=true;
    }
    }   
      
      
  
  if (blad!=4){
  if (millis() - currentMillis < interval){
  mcp.digitalWrite(alarm,HIGH);
  }
  else {
    mcp.digitalWrite(alarm,LOW);
}
  if (millis() - currentMillis < interval_buzzer){
  mcp.digitalWrite(buzzer,HIGH);
  }
  else {
      mcp.digitalWrite(buzzer,LOW);
  }
}
if (blad==0)
{

  mcp.digitalWrite(zielony,HIGH);
mcp.digitalWrite(zolty,LOW);
mcp.digitalWrite(czerwony,LOW);
          mcp.digitalWrite(wyjscie_1_cisza,LOW);
          mcp.digitalWrite(wyjscie_2_alarm,LOW);
}
if (blad==1)
{
  mcp.digitalWrite(zielony,HIGH);
mcp.digitalWrite(zolty,HIGH);
mcp.digitalWrite(czerwony,LOW);
}
if (blad==2)
{
  mcp.digitalWrite(zielony,LOW);
mcp.digitalWrite(zolty,HIGH);
mcp.digitalWrite(czerwony,LOW);
}
if (blad==3)
{
  mcp.digitalWrite(zielony,LOW);
mcp.digitalWrite(zolty,HIGH);
mcp.digitalWrite(czerwony,HIGH);
}
if (blad==4)
{
  rozwiazane=true;
  alarm_sygnal=true;
  mcp.digitalWrite(zasilanie,HIGH);
  mcp.digitalWrite(zielony,LOW);
mcp.digitalWrite(zolty,LOW);
mcp.digitalWrite(czerwony,HIGH);
mcp.digitalWrite(POWER_1,LOW);
digitalWrite(POWER_2,LOW);
mcp.digitalWrite(DETEK_1c,HIGH);
mcp.digitalWrite(DETEK_1z,LOW);
digitalWrite(DETEK_2c,HIGH);
digitalWrite(DETEK_2z,LOW);
          mcp.digitalWrite(wyjscie_1_cisza,LOW);
          mcp.digitalWrite(wyjscie_2_alarm,HIGH);
          rfid1=false;
          rfid2=false;
          rfid3=false;
          rfid4=false;
          mcp.digitalWrite(koniec,LOW);
  for (int i=0;i<7;i++){
       mcp.digitalWrite(alarm,HIGH);
           mcp.digitalWrite(buzzer,HIGH);
  delay(750);
  mcp.digitalWrite(alarm,LOW);
      mcp.digitalWrite(buzzer,LOW);
  delay(250);
  if (i==6){
    rozwiazane=false;
  }
  }
  blad=0;
    mcp.digitalWrite(POWER_1,HIGH);
digitalWrite(POWER_2,HIGH);
    //mcp.digitalWrite(zasilanie,LOW);
}


  portOne.listen();
  Serial.println("Data from port one:");
  while (portOne.available() > 0) {
        c=portOne.read(); 
    msg += c;
  }
    if (msg.length() > 10) {
    msg = msg.substring(1,13);
    Serial.println(msg);
  if ((msg=="020030BF931E")||(msg=="400042FFDD20")||(msg=="400042D8F12B")||(msg=="400042D1C714"))
 {

mcp.digitalWrite(DETEK_1c,LOW);
mcp.digitalWrite(DETEK_1z,HIGH);
          rfid1=true;
 }
    msg = "";
  }
  

  portTwo.listen();
    Serial.println("Data from port two:");
  while (portTwo.available() > 0) {

    c2=portTwo.read(); 
    msg2 += c2;
  }
    if (msg2.length() > 10) {
    msg2 = msg2.substring(1,13);
    Serial.println(msg2);
  if ((msg2=="020030BF931E")||(msg2=="400042FFDD20")||(msg2=="400042D8F12B")||(msg2=="400042D1C714"))
 {
digitalWrite(DETEK_2c,LOW);
digitalWrite(DETEK_2z,HIGH);
          rfid2=true;
 }
    msg2 = "";
  }

if (mcp.digitalRead(wejscie_1)==HIGH){
rfid3=true;
}
if (mcp.digitalRead(wejscie_2)==HIGH){
rfid4=true;
}

if ((rfid1==true)&&(rfid2==true)&&(rfid3==true)&&(rfid4==true)){
  rozwiazane=true;
  blad=0;
   mcp.digitalWrite(wyjscie_1_cisza,LOW);
          mcp.digitalWrite(wyjscie_2_alarm,LOW);
  mcp.digitalWrite(zielony,HIGH);
mcp.digitalWrite(zolty,LOW);
mcp.digitalWrite(czerwony,LOW);
mcp.digitalWrite(alarm,LOW);

mcp.digitalWrite(koniec,HIGH);
}


}
if ((mcp.digitalRead(zasilanie)==LOW)&&(rozwiazane==false)) {
  alarm_sygnal=true;
   rfid1=false;
          rfid2=false;
          rfid3=false;
          rfid4=false;
                    mcp.digitalWrite(wyjscie_1_cisza,HIGH);
          mcp.digitalWrite(wyjscie_2_alarm,LOW);
          
          mcp.digitalWrite(POWER_1,LOW);
digitalWrite(POWER_2,LOW);
mcp.digitalWrite(DETEK_1z,LOW);
digitalWrite(DETEK_2z,LOW);
mcp.digitalWrite(DETEK_1c,LOW);
digitalWrite(DETEK_2c,LOW);
 mcp.digitalWrite(zielony,LOW);
mcp.digitalWrite(zolty,LOW);
mcp.digitalWrite(czerwony,HIGH);
  
    if ((digitalRead(czujnik[0])==HIGH) || (digitalRead(czujnik[1])==HIGH) ||  (digitalRead(czujnik[2])==HIGH) || (digitalRead(czujnik[3])==HIGH) ||  (digitalRead(czujnik[4])==HIGH)){
      
       currentM = millis();
    }
    
      if (millis() - currentM < interval_buzzer){
  mcp.digitalWrite(buzzer,HIGH);
  }
  else {
      mcp.digitalWrite(buzzer,LOW);
  }
   if (millis() - currentM < interval){
  mcp.digitalWrite(alarm,HIGH);
  }
  else{
      mcp.digitalWrite(alarm,LOW);
  }
}


}

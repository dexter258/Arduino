#include <SoftwareSerial.h>

SoftwareSerial portOne(12, 13);
SoftwareSerial portTwo(8, 9);
#define POWER_1 2
#define POWER_2 5
#define DETEK_1c 4
#define DETEK_1z 3
#define DETEK_2c 7
#define DETEK_2z 6

#define wyjscie_1 0
#define wyjscie_2 1

#define wejscie_1_cisza 10
#define wejscie_2_alarm 11
boolean rfid1=false;
boolean rfid2=false;
boolean alarm=true;
void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; 
  }

  portOne.begin(9600);
  portTwo.begin(9600);
  pinMode(DETEK_2c,OUTPUT);
    pinMode(DETEK_2z,OUTPUT);
  pinMode(DETEK_1c,OUTPUT);
    pinMode(DETEK_1z,OUTPUT);
    
    pinMode(wejscie_1_cisza,INPUT);
        pinMode(wejscie_2_alarm,INPUT);
     pinMode(wyjscie_1,OUTPUT);
        pinMode(wyjscie_2,OUTPUT);
        
pinMode(POWER_2,OUTPUT);
pinMode(POWER_1,OUTPUT);
   digitalWrite(POWER_1,LOW);
digitalWrite(POWER_2,LOW);
digitalWrite(DETEK_1z,LOW);
digitalWrite(DETEK_2z,LOW);
digitalWrite(DETEK_1c,LOW);
digitalWrite(DETEK_2c,LOW);
digitalWrite(wyjscie_1,LOW);
digitalWrite(wyjscie_2,LOW);
}
char c;
String msg;
char c2;
String msg2;
//char c3;
//String msg3;
void loop() {
  
  
  if (digitalRead(wejscie_1_cisza)==HIGH){
    digitalWrite(POWER_1,LOW);
digitalWrite(POWER_2,LOW);
  digitalWrite(DETEK_1z,LOW);
digitalWrite(DETEK_2z,LOW);
digitalWrite(DETEK_1c,LOW);
digitalWrite(DETEK_2c,LOW); 
      rfid1=false;
  rfid2=false;
  alarm=true;
  }
 else
 {
   if (alarm==true){
   digitalWrite(POWER_1,HIGH);
digitalWrite(POWER_2,HIGH);
digitalWrite(DETEK_1z,LOW);
digitalWrite(DETEK_2z,LOW);
digitalWrite(DETEK_1c,HIGH);
digitalWrite(DETEK_2c,HIGH);
digitalWrite(wyjscie_1,LOW);
digitalWrite(wyjscie_2,LOW);
   alarm=false;
   }
 
  
if ( (digitalRead(wejscie_2_alarm)==HIGH)){
  rfid1=false;
  rfid2=false;
  alarm=true;
digitalWrite(wyjscie_1,LOW);
digitalWrite(wyjscie_2,LOW);
digitalWrite(DETEK_1z,LOW);
digitalWrite(DETEK_2z,LOW);
digitalWrite(POWER_1,LOW);
digitalWrite(POWER_2,LOW);
digitalWrite(DETEK_1c,HIGH);
digitalWrite(DETEK_2c,HIGH);
delay(7100);
digitalWrite(POWER_1,HIGH);
digitalWrite(POWER_2,HIGH);
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
digitalWrite(DETEK_1c,LOW);
digitalWrite(DETEK_1z,HIGH);
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
if ((rfid1==true)&&(rfid2==true)){
  digitalWrite(wyjscie_1,HIGH);
digitalWrite(wyjscie_2,HIGH);
}
}

}


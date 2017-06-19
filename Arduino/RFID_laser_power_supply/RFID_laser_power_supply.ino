#include <SoftwareSerial.h>

SoftwareSerial RFID = SoftwareSerial(11,12);

char readString;

char c;
String msg;
#define start 2
#define czerwony 5 
#define zielony ,
6 
#define niebieski 7
boolean sygnal=false;
boolean dioda_swieci=false;
unsigned long currentMillis = 0;        // will store last time LED was updated
unsigned long swiecenie = 0; 
unsigned long zgaszona = 0; 
// constants won't change :
const long interval = 3000;    
const long interval_diody = 3000;    
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  RFID.begin(9600);
   pinMode(czerwony,OUTPUT);
   pinMode(zielony,OUTPUT);
  pinMode(niebieski,OUTPUT);
 pinMode(start,OUTPUT);
  digitalWrite(start,HIGH);
  digitalWrite(zielony,LOW);
  digitalWrite(czerwony,LOW);
  digitalWrite(niebieski,LOW);
}


 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  
  
  while(RFID.available()>0){
    c=RFID.read(); 
    msg += c;
  }

  if (msg.length() > 10) {
    msg = msg.substring(1,13);

   if ((msg=="020030BF931E")||(msg=="400042FFDD20")||(msg=="400042D8F12B")||(msg=="400042D1C714"))
 {
   currentMillis = millis();
       }

    msg = "";
  }
  
   if (millis() -currentMillis <= interval) {
     sygnal=true;
   }
   else {
     sygnal=false;
   }
  
if (sygnal==true){
 digitalWrite(start, LOW);
  analogWrite(zielony, 255);
}  
if (sygnal==false){
   digitalWrite(start, HIGH);
   

 analogWrite(zielony, 2 );
   

     
   
 }
}

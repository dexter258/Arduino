#include <Wire.h>
#include <DS1307.h>

 #include <EEPROM.h>
DS1307 clock;
RTCDateTime dt;

 #define roleta_1 9
 #define roleta_2 10


String readString;
int BT,kroki1,kroki2;
int  przesuniecie_1;
int  przesuniecie_2;
int poziom_rolety_1;
int poziom_rolety_2;
 
const int stepPin_1 = 3; 
const int dirPin_1 = 4; 
const int mnoznik_1=5;   //mnożnik ilosci obrotów razy staą wartośc 

const int stepPin_2 = 5; 
const int dirPin_2 = 6; 
const int mnoznik_2 = 5;

unsigned long previousMillis = 0;        // will store last time LED was updated
  
const long interval = 1000;  

 

void setup() {
  Serial.begin(9600);
  
  Serial.println("Inicjalizacja DS1307");
  clock.begin();
  if (!clock.isReady())
  {
    // Data i czas z momentu kompilacji
    clock.setDateTime(__DATE__, __TIME__);
  }
  pinMode(roleta_1,OUTPUT);
  pinMode(roleta_2,OUTPUT);
  
    pinMode(stepPin_1,OUTPUT); 
    pinMode(dirPin_1,OUTPUT);
    pinMode(stepPin_2,OUTPUT); 
    pinMode(dirPin_2,OUTPUT);
    
     poziom_rolety_1=EEPROM.read(0);
     analogWrite(roleta_1,poziom_rolety_1);
   
      poziom_rolety_2=EEPROM.read(1);
      analogWrite(roleta_2,poziom_rolety_2);
}
void loop(){


  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
  dt = clock.getDateTime();
   Serial.print(dt.hour);   Serial.print(":");
  
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");
  }



  while (Serial.available()){
    delay(3);
    char c = Serial.read();
    readString+=c;
  }

  if (readString.length()>0){
      BT=readString.toInt();
      Serial.println(BT);
      
  if (BT>0 && BT<101){
    kroki1=map(BT,0,100,0,255);
    kroki1=255-kroki1;
    EEPROM.write(0,kroki1);

       analogWrite(roleta_1,kroki1);
     przesuniecie_1=kroki1-poziom_rolety_1;
     if (przesuniecie_1<0){
       digitalWrite(dirPin_111112WSZX2,LOW); 
      
     }
    if (przesuniecie_1>=0){
     
       digitalWrite(dirPin_1,HIGH); 
     }
     przesuniecie_1=abs(przesuniecie_1*mnoznik_1);
    for(int x = 0; x < przesuniecie_1; x++) {
    digitalWrite(stepPin_1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin_1,LOW); 
    delayMicroseconds(500); 
  }
         poziom_rolety_1=EEPROM.read(0);
         
  }
  
   if (BT>100 && BT<201){
    kroki2=map(BT,101,200,0,255);
    kroki2=255-kroki2;
     EEPROM.write(1,kroki2);
    analogWrite(roleta_2,kroki2);
    
     przesuniecie_2=kroki2-poziom_rolety_2;
     if (przesuniecie_2<0){
       digitalWrite(dirPin_2,LOW); 
      
     }
    if (przesuniecie_2>=0){
     
       digitalWrite(dirPin_2,HIGH); 
     }
     przesuniecie_2=abs(przesuniecie_2*mnoznik_2);
    for(int x = 0; x < przesuniecie_2; x++) {
    digitalWrite(stepPin_2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin_2,LOW); 
    delayMicroseconds(500); 
  }
         poziom_rolety_2=EEPROM.read(1);
         
    
    
   }
  
     readString="";
  }
    
  }



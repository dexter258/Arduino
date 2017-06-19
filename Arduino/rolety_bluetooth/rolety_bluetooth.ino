#include <Wire.h>
#include <DS1307.h>

 #include <EEPROM.h>
DS1307 clock;
RTCDateTime dt;

String readString;
String wskaznik,wartosc;


int przesuniecie;


boolean aktywowanie_tryb_godz_2=false; 
int wysokosc, kroki, przesuniecie_2, poziom_rolety_2, godz_noc_2,minut_noc_2,godz_dzien_2,minut_dzien_2;
int predkosc_2 = 800;
int natezenie_2 = 400;

const int dirPin_2 = 2;
const int stepPin_2 = 3; 
const int enable_2 = 4;


boolean aktywowanie_tryb_godz_1=false; 
int   przesuniecie_1, poziom_rolety_1, godz_noc_1,minut_noc_1,godz_dzien_1,minut_dzien_1;
int predkosc_1 = 800;
int natezenie_1= 400;

const int dirPin_1 = 5;
const int stepPin_1 = 6; 
const int enable_1 = 7;



boolean mniejszy_lewy=false;
boolean mniejszy_prawy=false;


unsigned long previousMillis = 0;        // will store last time LED was updated
  
const long interval = 1000;  

boolean silnik_lewy=false;
boolean silnik_prawy=false;

void setup() {
  Serial.begin(9600);
   Serial.println("Inicjalizacja DS1307");
  
  clock.begin();
  if (!clock.isReady())
  {
   // clock.setDateTime(__DATE__, __TIME__);
   //clock.setDateTime(2016, 10, 18, 20, 12, 00);
  }
    pinMode(dirPin_2,OUTPUT);
    pinMode(stepPin_2,OUTPUT); 
    pinMode(enable_2,OUTPUT);
    digitalWrite(enable_2,HIGH);
    
     pinMode(dirPin_1,OUTPUT);
    pinMode(stepPin_1,OUTPUT); 
    pinMode(enable_1,OUTPUT);
    digitalWrite(enable_1,HIGH);
    
    
     poziom_rolety_1=EEPROM.read(0);
     //analogWrite(roleta_1,poziom_rolety_1);
   
      poziom_rolety_2=EEPROM.read(1);
   //   analogWrite(roleta_2,poziom_rolety_2);
}
void loop(){

  dt = clock.getDateTime();
  while (Serial.available()){
    delay(3);
    char c = Serial.read();
    readString+=c;
  }
  
  
  

  if (readString.length()>0){
    
   wskaznik=readString.substring(0,5);
   wartosc=readString.substring(5);
   
   
   if (wskaznik=="_OBA_")
   {
     silnik_lewy=true;
     silnik_prawy=true;
   }
    if (wskaznik=="LEWE_")
   {
     silnik_lewy=true;
     silnik_prawy=false;
   }
     if (wskaznik=="PRAWE")
   {
     silnik_lewy=false;
     silnik_prawy=true;
   }
   
 
  
  if (wskaznik=="r2wys")
   
  {
    wysokosc=wartosc.toInt();
  
      kroki=map(wysokosc,0,100,0,255);
  //  kroki_2=255-kroki_2;
  if (silnik_lewy==true){
     EEPROM.write(0,kroki);
      przesuniecie_1=kroki-poziom_rolety_1;
      
         if (przesuniecie_1!=0)
      {
     if (przesuniecie_1<0){
       digitalWrite(dirPin_2,LOW); 
     }
       if (przesuniecie_1>0){
     
       digitalWrite(dirPin_2,HIGH); 
     }
      }
       digitalWrite(enable_1,LOW);
       przesuniecie_1=abs(przesuniecie_1);
       przesuniecie_1=map(przesuniecie_1,0,255,0,4400);
       przesuniecie=przesuniecie_1;
  }
  if (silnik_prawy==true){
     EEPROM.write(1,kroki);
     przesuniecie_2=kroki-poziom_rolety_2;
      if (przesuniecie_2!=0)
      {
     if (przesuniecie_2<0){
       digitalWrite(dirPin_2,LOW); 
     }
       if (przesuniecie_2>0){
     
       digitalWrite(dirPin_2,HIGH); 
     }
      }
       digitalWrite(enable_2,LOW);
       przesuniecie_2=abs(przesuniecie_2);
       przesuniecie_2=map(przesuniecie_2,0,255,0,4400);
       przesuniecie=przesuniecie_2;
  }
     delay(1800);
   
      if ((silnik_prawy==true) && (silnik_lewy==true)) {
       if ( przesuniecie_2>przesuniecie_1){
       przesuniecie=przesuniecie_1;
       mniejszy_lewy=true;
      }
      else{
         przesuniecie=przesuniecie_2;
       mniejszy_prawy=true;
      }
    }
      
    for(int x = 0; x < przesuniecie; x++) {
      if (silnik_lewy==true){  digitalWrite(stepPin_1,HIGH); }
     if (silnik_prawy==true){  digitalWrite(stepPin_2,HIGH); }
    delayMicroseconds(predkosc_2); 
    digitalWrite(stepPin_2,LOW); 
    delayMicroseconds(predkosc_2); 
  }
  
  for(int x = 0; x < przesuniecie; x++) {
    digitalWrite(stepPin_2,HIGH); 
    delayMicroseconds(predkosc_2); 
    digitalWrite(stepPin_2,LOW); 
    delayMicroseconds(predkosc_2); 
  }
  
  
  
  delay(1000);
  if (silnik_lewy==true){
  digitalWrite(enable_1,HIGH);
  poziom_rolety_1=EEPROM.read(0);
   }
  
   if (silnik_prawy==true){
  digitalWrite(enable_2,HIGH);
  poziom_rolety_2=EEPROM.read(1);
   }
  
  }
  
  
  
     
   if (wskaznik=="r2pre")
   
  {
    predkosc_2=wartosc.toInt();
    
  }
  
    if (wskaznik=="r2nat")
   
  {
    natezenie_2=wartosc.toInt();
  }
  
  if (wskaznik=="r2gno")
  {
    if (wartosc.substring(1,2)==":")
    {
     godz_noc_2= wartosc.substring(0,1).toInt();
     minut_noc_2=wartosc.substring(2).toInt();
    }
   
    if (wartosc.substring(2,3)==":")
    {
     godz_noc_2= wartosc.substring(0,2).toInt();
     minut_noc_2=wartosc.substring(3).toInt();
    }  
  }
  if ((wskaznik=="r2gdz")||(wskaznik=="r2gdznat"))
  {
    if (wartosc.substring(1,2)==":")
    {
     godz_dzien_2= wartosc.substring(0,1).toInt();
     minut_dzien_2=wartosc.substring(2).toInt();
    }
   
    if (wartosc.substring(2,3)==":")
    {
     godz_dzien_2= wartosc.substring(0,2).toInt();
     minut_dzien_2=wartosc.substring(3).toInt();
    }  
  }
  
  
  
  if (wskaznik=="r2ust")
  {
    if (wartosc=="godz")
    {
      aktywowanie_tryb_godz_2=true;
    }
    if (wartosc=="off")
    {
        aktywowanie_tryb_godz_2=false;
    }
     if (wartosc=="zero")
     {
       poziom_rolety_2=0;
       EEPROM.write(1,0);
     }
     if (wartosc=="end")
     {
       poziom_rolety_2=255;
       EEPROM.write(1,255);
     }
  }
  

  
    Serial.println(wskaznik);
    Serial.println(wartosc);
    Serial.println();
   readString="";
  }
  
  
  
  
    if ( aktywowanie_tryb_godz_2==true)
  {
   if ((godz_noc_2==godz_dzien_2) && (minut_noc_2==minut_dzien_2))
   {
     minut_dzien_2=minut_dzien_2+1;
     if (minut_dzien_2==60)
     {
       minut_dzien_2=0;
       godz_dzien_2=(godz_dzien_2+1)%24;
     }
   }
   
     Serial.println("timer");
      Serial.println(dt.hour);
       Serial.println(dt.minute);
    
      Serial.println("bluetooth noc");
      Serial.println(godz_noc_2);
    Serial.println(minut_noc_2);
     Serial.println("bluetooth dzien");
      Serial.println(godz_dzien_2);
    Serial.println(minut_dzien_2);
    
    if ((dt.hour==godz_noc_2) && (dt.minute==minut_noc_2))
    {
         wysokosc=100;
   
      kroki=map(wysokosc,0,100,0,255);
  //  kroki_2=255-kroki_2;
     EEPROM.write(1,kroki);
      przesuniecie_2=kroki-poziom_rolety_2;
      if (przesuniecie_2!=0)
      {
     if (przesuniecie_2<0){
       digitalWrite(dirPin_2,LOW); 
     }
       if (przesuniecie_2>0){
     
       digitalWrite(dirPin_2,HIGH); 
     }
     digitalWrite(enable_2,LOW);
     delay(1800);
     
       przesuniecie_2=abs(przesuniecie_2);
       przesuniecie_2=map(przesuniecie_2,0,255,0,4400);
    for(int x = 0; x < przesuniecie_2; x++) {
    digitalWrite(stepPin_2,HIGH); 
    delayMicroseconds(predkosc_2); 
    digitalWrite(stepPin_2,LOW); 
    delayMicroseconds(predkosc_2); 
  }
  delay(1000);
  digitalWrite(enable_2,HIGH);
      }
         poziom_rolety_2=EEPROM.read(1);
  }
  
  
  if ((dt.hour==godz_dzien_2) && (dt.minute==minut_dzien_2))
    {
         wysokosc=0;
   
      kroki=map(wysokosc,0,100,0,255);
  //  kroki_2=255-kroki_2;
     EEPROM.write(1,kroki);
      przesuniecie_2=kroki-poziom_rolety_2;
      if (przesuniecie_2!=0)
      {
     if (przesuniecie_2<0){
       digitalWrite(dirPin_2,LOW); 
     }
       if (przesuniecie_2>0){
     
       digitalWrite(dirPin_2,HIGH); 
     }
     digitalWrite(enable_2,LOW);
     delay(1800);
     
       przesuniecie_2=abs(przesuniecie_2);
       przesuniecie_2=map(przesuniecie_2,0,255,0,4400);
    for(int x = 0; x < przesuniecie_2; x++) {
    digitalWrite(stepPin_2,HIGH); 
    delayMicroseconds(predkosc_2); 
    digitalWrite(stepPin_2,LOW); 
    delayMicroseconds(predkosc_2); 
  }
  delay(1000);
  digitalWrite(enable_2,HIGH);
      }
         poziom_rolety_2=EEPROM.read(1);
  }
  
  
  }
  
  
  
  
  
  
}


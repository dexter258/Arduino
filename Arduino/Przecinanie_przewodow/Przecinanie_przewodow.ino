#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "Timer.h"
Timer t;
 int tickEvent;
 int tick;  
boolean odliczanie=false;
int przerwa=1000;
#define niebieski 10
#define czerwony 11
#define zielony 12
#define zolty 13
unsigned long current;
boolean start_buzzer1=false;
boolean start_buzzer2=false;
boolean start_buzzer3=false;
boolean start_buzzer4=false;
boolean start_buzzer5=false;
boolean start_buzzer6=false;

int speakerOut = 9;
unsigned long czas[7];
#define krancowka1 A1

#define bezpieczniki A3
int przewody[6];
boolean przerwany[6];
boolean start=false;
boolean wygrana=false;
boolean porazka=false;
int sekundy=120;
boolean sprawdzanie_poczatkowe=true;
int setne=1;
int x=11;
int setne_czas=999;
int setne_licznik=1;
boolean koniec=false;
#define BACKLIGHT_PIN 3
LiquidCrystal_I2C lcd(0x20,2,1,0,4,5,6,7);

void setup ()
{
  pinMode(niebieski,OUTPUT);
  pinMode(czerwony,OUTPUT);
  pinMode(zielony,OUTPUT);
  pinMode(zolty,OUTPUT);
  pinMode(krancowka1,INPUT);
  pinMode(bezpieczniki,INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(LOW);
   pinMode(speakerOut, OUTPUT);

   for (int i=0;i<6;i++){
     przewody[i]=i+3;
        pinMode(przewody[i],INPUT);
        przerwany[i]=false;
   }
   lcd.setBacklight(LOW);
  
    delay(10000);
        digitalWrite(niebieski,LOW);
    digitalWrite(zielony,LOW);
    digitalWrite(czerwony,LOW);
    digitalWrite(zolty,LOW);
   
}


void loop ()
{
  if (sprawdzanie_poczatkowe==true){
     if ((digitalRead(przewody[0])==HIGH)&&(digitalRead(przewody[1])==HIGH)&&(digitalRead(przewody[2])==HIGH)&&(digitalRead(przewody[3])==HIGH)&&(digitalRead(przewody[4])==HIGH)&&(digitalRead(przewody[5])==HIGH)){
  sprawdzanie_poczatkowe=false;
    digitalWrite(niebieski,HIGH);
    digitalWrite(zielony,HIGH);
    digitalWrite(czerwony,HIGH);
    digitalWrite(zolty,HIGH);
    delay(10000);
        digitalWrite(niebieski,LOW);
    digitalWrite(zielony,LOW);
    digitalWrite(czerwony,LOW);
    digitalWrite(zolty,LOW);
    
  }
  }
if (digitalRead(krancowka1)==HIGH){start=true; }              //sprawdzanie krancowki


if ((start==true) && (wygrana==false) && (porazka==false)){  //STARTUJEMY
digitalWrite(niebieski,HIGH);
if (digitalRead(bezpieczniki)==HIGH)lcd.setBacklight(HIGH);
else lcd.setBacklight(LOW);
t.update();

if (odliczanie==false)
{
  odliczanie=true;
  tickEvent= t.every(przerwa, doSomething);
  tick=t.every(setne_licznik,Something);
}
  for (int i=0;i<6;i++){
    if (digitalRead(przewody[i])==HIGH){
    czas[i] = millis();   
    }     
    if ((millis()-czas[i])>800){
      przerwany[i]=true; 
    }  
  }
 
  
 
 
   if (przerwany[2]==true){
       //lcd.clear();
         lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("       ");
       porazka=true;
      t.stop(tickEvent);
      digitalWrite(speakerOut,HIGH);
      }
  
   if ((((przerwany[3]==true)&&(przerwany[5]==false)&&porazka==false))||(((przerwany[5]==true)&&(przerwany[3]==false)&&porazka==false))) {

      if (start_buzzer1==false){
         start_buzzer1=true;
             digitalWrite(niebieski,HIGH);
    digitalWrite(zielony,HIGH);
    digitalWrite(czerwony,LOW);
    digitalWrite(zolty,LOW);
    }
 }

   if ((przerwany[1]==true)&&(porazka==false)){
         if (start_buzzer2==false){
         start_buzzer2=true;
     t.stop(tickEvent);
      przerwa=650;
        tickEvent= t.every(przerwa, doSomething);
               digitalWrite(niebieski,HIGH);
    digitalWrite(zielony,LOW);
    digitalWrite(czerwony,LOW);
    digitalWrite(zolty,HIGH);
     tone(speakerOut,500,700);
      }
    }
       
   if ((przerwany[0]==true)&&(porazka==false)){
         if (start_buzzer3==false){
         start_buzzer3=true;
          t.stop(tickEvent);
     
        tickEvent= t.every(przerwa, doSomething);
   sekundy=sekundy-15;
   if (sekundy<10)sekundy=9;
          digitalWrite(niebieski,HIGH);
    digitalWrite(zielony,LOW);
    digitalWrite(czerwony,LOW);
    digitalWrite(zolty,HIGH);
     tone(speakerOut,500,700);
      }
    }
       if ((przerwany[4]==true)&&(porazka==false)){
         if (start_buzzer4==false){
         start_buzzer4=true;
          t.stop(tickEvent);
    przerwa=3000;
    x=2;
    setne=999;
        tickEvent= t.every(przerwa, doSomething);
          int afterEvent = t.after(6000, doAfter);
                 digitalWrite(niebieski,HIGH);
    digitalWrite(zielony,LOW);
    digitalWrite(czerwony,LOW);
    digitalWrite(zolty,HIGH);
     tone(speakerOut,500,700);
      }
    }
    
 if ((przerwany[3]==true)&& (przerwany[5]==true)&& (porazka==false)){
     //  lcd.clear();
          lcd.home();
  lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("       ");
       wygrana=true;
      t.stop(tickEvent);
      }
  
  }
  if (wygrana==true)
  {
    lcd.setBacklight(HIGH);
    digitalWrite(niebieski,LOW);
    digitalWrite(zielony,HIGH);
    digitalWrite(czerwony,LOW);
    digitalWrite(zolty,LOW);
      lcd.home();
        lcd.print("wygrana");
                 if (start_buzzer6==false){
         start_buzzer6=true;
        graj();
                 }
  }
  
        if ((porazka==true)&&(koniec==false))
  {
    lcd.setBacklight(HIGH);
        digitalWrite(niebieski,LOW);
    digitalWrite(zielony,LOW);
    digitalWrite(czerwony,HIGH);
    digitalWrite(zolty,LOW);
      lcd.home();
        lcd.print("przegrales");
         if (start_buzzer5==false){
           current=millis();
         
         start_buzzer5=true;
         }
         digitalWrite(speakerOut,HIGH);
         if ((millis()-current)>10000){
       
          digitalWrite(speakerOut,LOW);
         koniec=true;
       }
  
  }
}

 void doSomething()
{
  tone(speakerOut,przerwa*2,50);
//  Serial.println(millis());
  if (sekundy>=0){
  lcd.setCursor(8,1);
    lcd.print("   ");
     lcd.home();
  lcd.print("UTNIJ ODPOWIEDNI");
    lcd.setCursor(0,1);
  lcd.print("PRZEWOD"); 
  
  
  
  if (sekundy>=100)  lcd.setCursor(8,1); 
  if ((sekundy<100)&&(sekundy>=10))  lcd.setCursor(9,1); 
  if (sekundy<10) lcd.setCursor(10,1); 
  lcd.print(sekundy); 
  lcd.setCursor(11,1);
  lcd.print("s"); 
  
  sekundy--;
  }
  else{
    porazka=true;
   lcd.clear();
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("       ");
        t.stop(tickEvent);
      digitalWrite(speakerOut,HIGH);
  }
}
void Something()
{
  setne=setne-x;
  if (setne<=0)setne=999;
  if (sekundy>=0){
  lcd.setCursor(15,1); 
  lcd.print(" "); 
  lcd.setCursor(12,1);  
  lcd.print(setne);  
 
  


    
  }
  
}
void doAfter()
{
          t.stop(tickEvent);
          przerwa=500;
          x=21;
          tickEvent= t.every(przerwa, doSomething);
}



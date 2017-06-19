#include <Stepper.h>
#include <Servo.h> 
Servo servo_klucz;
Servo servo_blokada;
#define STEPS 200
#define czerwone 2
#define zielone 1
#define niebieskie 0

#define silnik_L 3
#define silnik_P 4
#define przycisk A5
#define radiowe A4
#define przycisk_pokrywa A3
#define krancowka 11
#define sygnal_koniec 12
#define sygnal_poczatek 13
int servo_klucz_open=90;
int servo_klucz_close=165;
int servo_blokada_open=25;
int servo_blokada_close=125;
Stepper stepper(STEPS, 5, 6, 7, 8);
boolean start=false;
boolean koniec=false;
boolean otwarcie=false;
boolean reset_pokrywa=false;
boolean reset_klucz=false;
int previous = 0;
int klucz=9;
int blokada=10;
boolean czas=true;   
const long interval = 1000;
  unsigned long currentMillis=0;
void setup()
{

  stepper.setSpeed(140);
  pinMode(silnik_L,OUTPUT);
  pinMode(silnik_P,OUTPUT);
  pinMode(silnik_L,LOW);
  pinMode(silnik_P,LOW);
  pinMode(przycisk,INPUT);
  pinMode(radiowe,INPUT);
  
  pinMode(krancowka,INPUT);
  pinMode(sygnal_poczatek,INPUT);
  pinMode(sygnal_koniec,OUTPUT);
      digitalWrite(sygnal_koniec,LOW);
      pinMode(przycisk_pokrywa,INPUT);
  pinMode(czerwone,OUTPUT);
  pinMode(zielone,OUTPUT);
  pinMode(niebieskie,OUTPUT);
  digitalWrite(czerwone,HIGH);
  digitalWrite(zielone,LOW);
  digitalWrite(niebieskie,LOW);
  
//  pinMode(zasilanie_silnika
  servo_klucz.attach(klucz);
 servo_blokada.attach(blokada);
  delay(100);
    servo_klucz.write(servo_klucz_close);
    servo_blokada.write(servo_blokada_close);
  delay(1000);
  servo_blokada.detach();
  servo_klucz.detach();
}

void loop()
{
if (czas==true){
  currentMillis=millis();
}
  if (digitalRead(sygnal_poczatek)==HIGH){
  czas=false;
  }
  else {
    czas=true;
  }
  if (millis() - currentMillis >= interval) {
    start=true;
  digitalWrite(czerwone,LOW);
  digitalWrite(zielone,HIGH);
  digitalWrite(niebieskie,LOW);
    if (otwarcie==false){
         servo_blokada.attach(blokada);
         delay(100);
         servo_blokada.write(servo_blokada_open);
         otwarcie=true;
         delay(500);
        }
 }
  if (start==true){
    digitalWrite(silnik_L,HIGH);
    digitalWrite(silnik_P,HIGH);
      stepper.step(200);
  }
  if (digitalRead(krancowka)==HIGH){
      start=false;
      digitalWrite(silnik_L,LOW);
      digitalWrite(silnik_P,LOW);
      servo_blokada.detach();
  }
    
    if (digitalRead(radiowe)==HIGH){
            digitalWrite(sygnal_koniec,HIGH);
        servo_klucz.attach(klucz);
        digitalWrite(czerwone,LOW);
  digitalWrite(zielone,LOW);
  digitalWrite(niebieskie,HIGH);
    delay(100);
    servo_klucz.write(servo_klucz_open);
    delay(8000);
      servo_klucz.detach();
    }
    
    if (digitalRead(przycisk_pokrywa)==HIGH){
            otwarcie=false;
        digitalWrite(sygnal_koniec,LOW);
        digitalWrite(czerwone,HIGH);
        digitalWrite(zielone,LOW);
        digitalWrite(niebieskie,LOW);
  servo_blokada.attach(blokada);
  delay(100);
  servo_blokada.write(servo_blokada_open);
  delay(6000);
  servo_blokada.write(servo_blokada_close);
  delay(1000);
  servo_blokada.detach();
    }
    
   if (digitalRead(przycisk)==HIGH){ 
        digitalWrite(sygnal_koniec,LOW);
        digitalWrite(czerwone,HIGH);
        digitalWrite(zielone,LOW);
        digitalWrite(niebieskie,LOW);
  servo_klucz.attach(klucz);
  delay(100);
  servo_klucz.write(servo_klucz_open);
  delay(6000);
  servo_klucz.write(servo_klucz_close);
  delay(1000);
  servo_klucz.detach();
    }
    
}

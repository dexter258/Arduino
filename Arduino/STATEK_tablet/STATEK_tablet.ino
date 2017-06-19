// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo servo_naped;  // create servo object to control a servo 
 #define przycisk 7
 #define odnowa 5
 #define led 4
 Servo servo_blokada;          // a maximum of eight servo objects can be created 
 int poczatek_blokada=50;
 int koniec_blokada=132;
  int poczatek_naped=0;
 int koniec_naped=164;
int pos = 0;    // variable to store the servo position 
 boolean start=false;
void setup() 
{ 
  servo_blokada.attach(9);  
  servo_naped.attach(8);  
  pinMode(przycisk,INPUT);
   pinMode(odnowa,INPUT);
   pinMode(led,OUTPUT);
   analogWrite(led,0);
   servo_naped.write(poczatek_naped); 
     delay(2500);
    servo_blokada.write(poczatek_blokada); 
   
   delay(1800);
 //   servo_blokada.detach();  
  servo_naped.detach();  
} 
 
 
void loop() 
{ 
   analogWrite(led,0);
   delay(5000);
  for (int i=0;i<255;i++){
   analogWrite(led,i);
   delay(15);
}
delay(5000);
  if (digitalRead(przycisk)==HIGH){
    start=true;
      servo_blokada.attach(9);  
  servo_naped.attach(8);  
  }
  if (start==true){
      servo_blokada.write(koniec_blokada);
     delay(1000); 
   servo_naped.write(koniec_naped); 
    servo_blokada.detach();  
  }
  if (digitalRead(odnowa)==HIGH){
  start=false;
  servo_blokada.attach(9); 
     servo_naped.write(poczatek_naped); 
     delay(5500);
    servo_blokada.write(poczatek_blokada); 
   
   delay(1800);
 //   servo_blokada.detach();  
  servo_naped.detach(); 
  }
 
} 

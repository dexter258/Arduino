
#include <VirtualWire.h>
#include <ServoTimer2.h>  // the servo library
#define transmit_pin 10
#define yawPin   4
int switchPin = 12;
int p=0;
int diody=0;
int led3=6;
int led2=5;
int led1=9;
int led4=1;
int led5=2;
int led6=3;
const char *wiadomosc;
ServoTimer2 servoRoll;    // declare variables for up to eight servos
ServoTimer2 servoPitch;
ServoTimer2 servoYaw;
void setup()
{
   pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
   pinMode(led3,OUTPUT);
    pinMode(led4,OUTPUT);
    pinMode(led5,OUTPUT);
    pinMode(led6,OUTPUT);
      digitalWrite(led1, LOW); 
      digitalWrite(led2,LOW);
     digitalWrite(led3, LOW); 
    digitalWrite(led4, LOW);  
     digitalWrite(led5, LOW); 
    digitalWrite(led6, LOW);
    servoYaw.attach(yawPin);
         servoYaw.write(1094);
  // przygotowujemy potrzebne informacje dla biblioteki
    vw_set_tx_pin(transmit_pin);
    vw_setup(2000);
      servoYaw.detach();
}
void loop()
{

wiadomosc="9";

//else { wiadomosc="0";}
  String toSend = (wiadomosc); // tekst wiadomości

char msg[23]; // tworzymy tablicę typu char
  toSend.toCharArray(msg, toSend.length() + 1); // konwertujemy nasz tekst do tablicy charów
  
  if (digitalRead(switchPin) == HIGH)
  {
    p=1;
    diody=1;
  }
  if (p==1)
  {
  vw_send((uint8_t *)msg, strlen(msg));// wysyłamy 
  vw_wait_tx(); 
  delay(1000);
  wiadomosc="0";
   String toSend = (wiadomosc); // tekst wiadomości

char msg[23]; // tworzymy tablicę typu char
  toSend.toCharArray(msg, toSend.length() + 1); // konwertujemy nasz tekst do tablicy charów
   vw_send((uint8_t *)msg, strlen(msg));// wysyłamy 
  vw_wait_tx(); 
p=0;  
}
if (diody==1)
{
  servoYaw.attach(yawPin);
  for(int a=0; a<=6; a+=1)
  {
   
     delay(40);
     digitalWrite(led1,HIGH);
     digitalWrite(led2,HIGH);
     digitalWrite(led3,HIGH);
      digitalWrite(led4,HIGH);
     digitalWrite(led5,HIGH);
     digitalWrite(led6,HIGH);
   
     servoYaw.write(1554);
     delay(1500);
     servoYaw.write(1094);
           digitalWrite(led1,LOW);
     digitalWrite(led2,LOW);
     digitalWrite(led3,LOW);
         digitalWrite(led4,LOW);
     digitalWrite(led5,LOW);
     digitalWrite(led6,LOW);
     delay(1000);
  }
     servoYaw.detach();
    // diody=0;
}

  
}

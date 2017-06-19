#include <PCF8574.h>
#include <Wire.h>
#include <VirtualWire.h>
#include "Timer.h"
Timer t;
PCF8574 expander;
#define transmit_pin 10
boolean ON=HIGH;
boolean OFF=LOW;
int i=10;
int p=0;
int switchPin = 7;
int zerowanie_czasu=9;
const char *wiadomosc;
void setup()
{
    vw_set_tx_pin(transmit_pin);
    vw_setup(2000);
  Serial.begin(9600);
  int tickEvent = t.every(1000, odliczanie);   
  pinMode(8, INPUT);
  pinMode(zerowanie_czasu, INPUT);
  expander.begin(0x38);
     expander.pinMode(0, OUTPUT);
     expander.pinMode(1, OUTPUT);
     expander.pinMode(2, OUTPUT);
     expander.pinMode(3, OUTPUT);
     expander.pinMode(4, OUTPUT);
     expander.pinMode(5, OUTPUT);
     expander.pinMode(6, OUTPUT);
     expander.pinMode(7, OUTPUT);
}

void loop()
{
 if (digitalRead(zerowanie_czasu)==HIGH)
 { 
   i=10;
 }
 
 
 wiadomosc="1";

//else { wiadomosc="0";}
  String toSend = (wiadomosc); // tekst wiadomości

char msg[23]; // tworzymy tablicę typu char
  toSend.toCharArray(msg, toSend.length() + 1); // konwertujemy nasz tekst do tablicy charów
  
  if (digitalRead(switchPin) == HIGH)
  {
    p=1;
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





  if (digitalRead(8)==HIGH)
  {
t.update();
  }
     Serial.println(i); 
switch(i) 
{
  case 0:
  {
  expander.digitalWrite(0, ON);
  expander.digitalWrite(1, ON);
  expander.digitalWrite(2, ON);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, OFF);
  expander.digitalWrite(5, ON);
  expander.digitalWrite(6, ON);
  expander.digitalWrite(7, ON);
  }
  break;
//JEDEN
  case 1:
  {
  expander.digitalWrite(0, OFF);
  expander.digitalWrite(1, OFF);
  expander.digitalWrite(2, ON);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, OFF);
  expander.digitalWrite(5, OFF);
  expander.digitalWrite(6, OFF);
  expander.digitalWrite(7, ON);
  }
  break;
 //DWA
  case 2:
  {
  expander.digitalWrite(0, ON);
  expander.digitalWrite(1, ON);
  expander.digitalWrite(2, OFF);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, ON);
  expander.digitalWrite(5, OFF);
  expander.digitalWrite(6, ON);
  expander.digitalWrite(7, ON);
  }
  break;
//TRZY
  case 3:
  {
  expander.digitalWrite(0, OFF);
  expander.digitalWrite(1, ON);
  expander.digitalWrite(2, ON);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, ON);
  expander.digitalWrite(5, OFF);
  expander.digitalWrite(6, ON);
  expander.digitalWrite(7, ON);  
  }
  break;
  //CZTERY
  case 4:
  {
  expander.digitalWrite(0, OFF);
  expander.digitalWrite(1, OFF);
  expander.digitalWrite(2, ON);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, ON);
  expander.digitalWrite(5, ON);
  expander.digitalWrite(6, OFF);
  expander.digitalWrite(7, ON);
  }
  break;
//PIEC
  case 5:
  {
  expander.digitalWrite(0, OFF);
  expander.digitalWrite(1, ON);
  expander.digitalWrite(2, ON);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, ON);
  expander.digitalWrite(5, ON);
  expander.digitalWrite(6, ON);
  expander.digitalWrite(7, OFF);
  }
  break;
//SZESC
  case 6:
  {
  expander.digitalWrite(0, ON);
  expander.digitalWrite(1, ON);
  expander.digitalWrite(2, ON);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, ON);
  expander.digitalWrite(5, ON);
  expander.digitalWrite(6, ON);
  expander.digitalWrite(7, OFF); 
  }
  break;
//SIEDEM
  case 7:
  {
  expander.digitalWrite(0, OFF);
  expander.digitalWrite(1, OFF);
  expander.digitalWrite(2, ON);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, OFF);
  expander.digitalWrite(5, OFF);
  expander.digitalWrite(6, ON);
  expander.digitalWrite(7, ON); 
  }
  break;
//OSIEM
  case 8:
  {
  expander.digitalWrite(0, ON);
  expander.digitalWrite(1, ON);
  expander.digitalWrite(2, ON);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, ON);
  expander.digitalWrite(5, ON);
  expander.digitalWrite(6, ON);
  expander.digitalWrite(7, ON); 
  }
  break;
//DZIEWIEC
  case 9:
  {
  expander.digitalWrite(0, OFF);
  expander.digitalWrite(1, ON);
  expander.digitalWrite(2, ON);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, ON);
  expander.digitalWrite(5, ON);
  expander.digitalWrite(6, ON);
  expander.digitalWrite(7, ON);  
  }
  break;
  
  case 10:
  {
  expander.digitalWrite(0, OFF);
  expander.digitalWrite(1, OFF);
  expander.digitalWrite(2, OFF);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, OFF);
  expander.digitalWrite(5, OFF);
  expander.digitalWrite(6, OFF);
  expander.digitalWrite(7, OFF);
  }
  break;
}


}

void odliczanie ()
{
   i=i-1;
  if (i<=0)
  {
    i=0;
  }
}

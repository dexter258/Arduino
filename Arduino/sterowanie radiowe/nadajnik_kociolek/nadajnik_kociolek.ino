#include <VirtualWire.h>
#define transmit_pin 10
#define pot_pin A0
int switchPin = 7;
int p=0;
int led0=0;
int led1=1;
int led2=2;
int led3=3;
int led4=4;
int start=0;
const char *wiadomosc;
void setup()
{
  // przygotowujemy potrzebne informacje dla biblioteki
    vw_set_tx_pin(transmit_pin);
    vw_setup(2000);
    pinMode(led0,OUTPUT);
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(led3,OUTPUT);
    pinMode(led4,OUTPUT);
}

void loop()
{

wiadomosc="1";

//else { wiadomosc="0";}
  String toSend = (wiadomosc); // tekst wiadomości

char msg[23]; // tworzymy tablicę typu char
  toSend.toCharArray(msg, toSend.length() + 1); // konwertujemy nasz tekst do tablicy charów
  
  if (digitalRead(switchPin) == HIGH)
  {
    if (start==0)
    {
    p=1;
    start=1;
    }
    
    
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
if (start==1)
{
digitalWrite(led0,HIGH);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
     digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    delay(10000);
}

else 
{
  digitalWrite(led0,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
     digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
}
  
}

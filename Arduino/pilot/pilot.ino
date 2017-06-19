#include <VirtualWire.h>
#define transmit_pin 10
#define sygnal0 0
#define sygnal1 1
#define sygnal2 2
#define sygnal3 3
#define sygnal4 4
#define sygnal5 5
#define sygnal6 6
#define sygnal7 7
#define sygnal8 9
#define sygnal9 8

int p=0;
const char *wiadomosc;
void setup()
{
  pinMode(sygnal0,INPUT);
   pinMode(sygnal1,INPUT);
    pinMode(sygnal2,INPUT);
     pinMode(sygnal3,INPUT);
     pinMode(sygnal4,INPUT);
       pinMode(sygnal5,INPUT);
        pinMode(sygnal6,INPUT);
         pinMode(sygnal7,INPUT);
         pinMode(sygnal8,INPUT);
          pinMode(sygnal9,INPUT);
  // przygotowujemy potrzebne informacje dla biblioteki
    vw_set_tx_pin(transmit_pin);
    vw_setup(2000);
}

void loop()
{
if (digitalRead(sygnal0)==HIGH)
{
    delay(20);
wiadomosc="dotyk";
p=1;
  delay(20);
}
if (digitalRead(sygnal1)==HIGH)
{
    delay(20);
wiadomosc="1";
p=1;
  delay(20);
}
if (digitalRead(sygnal2)==HIGH)
{
    delay(20);
wiadomosc="2";
p=1;
  delay(20);
}
if (digitalRead(sygnal3)==HIGH)
{
  delay(20);
wiadomosc="3";
p=1;
  delay(20);
}
if (digitalRead(sygnal4)==HIGH)
{
    delay(20);
wiadomosc="4";
p=1;
  delay(20);
}
if (digitalRead(sygnal5)==HIGH)
{
    delay(20);
wiadomosc="5";
p=1;
  delay(20);
}
if (digitalRead(sygnal6)==HIGH)
{
    delay(20);
wiadomosc="6";
p=1;
  delay(20);
}
if (digitalRead(sygnal7)==HIGH)
{
    delay(20);
wiadomosc="7";
p=1;
  delay(20);
}
if (digitalRead(sygnal8)==HIGH)
{
    delay(20);
wiadomosc="8";
p=1;
  delay(20);
}
if (digitalRead(sygnal9)==HIGH)
{
    delay(20);
wiadomosc="9";
p=1;
  delay(20);
}

  String toSend = (wiadomosc); // tekst wiadomości
char msg[23]; // tworzymy tablicę typu char
  toSend.toCharArray(msg, toSend.length() + 1); // konwertujemy nasz tekst do tablicy charów
  
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
 
}

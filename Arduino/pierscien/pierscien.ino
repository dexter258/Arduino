#include <VirtualWire.h>
#define transmit_pin 10
#define pot_pin A0
int switchPin = 7;
int p=0;
int start=0;
const char *wiadomosc;
void setup()
{
    vw_set_tx_pin(transmit_pin);
    vw_setup(2000);
}

void loop()
{
wiadomosc="1";
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

  
}

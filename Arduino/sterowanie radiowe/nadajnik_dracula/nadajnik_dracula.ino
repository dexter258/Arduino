#include <VirtualWire.h>
#define transmit_pin 10
#define pot_pin A0
#define gargulce_halas 6
#define klucz 8
#define koniec_czasu 7
int poczatek=0;
int zwyciestwo=0;
const char *wiadomosc;
void setup()
{
    vw_set_tx_pin(transmit_pin);
    vw_setup(2000);
}

void loop()
{

  if ((digitalRead(gargulce_halas) == HIGH) || (digitalRead(klucz) == HIGH) || (digitalRead(koniec_czasu) == HIGH))
{
if (digitalRead(gargulce_halas) == HIGH)
  {
  wiadomosc="1";
  String toSend = (wiadomosc); // tekst wiadomości

char msg[23]; // tworzymy tablicę typu char
  toSend.toCharArray(msg, toSend.length() + 1); // konwertujemy nasz tekst do tablicy charów
    vw_send((uint8_t *)msg, strlen(msg));// wysyłamy 
     vw_wait_tx();
  }
if (digitalRead(klucz) == HIGH)
  {
  wiadomosc="5";
  String toSend = (wiadomosc); // tekst wiadomości

char msg[23]; // tworzymy tablicę typu char
  toSend.toCharArray(msg, toSend.length() + 1); // konwertujemy nasz tekst do tablicy charów
    vw_send((uint8_t *)msg, strlen(msg));// wysyłamy 
     vw_wait_tx();
  }
  if (digitalRead(koniec_czasu) == HIGH)
  {
  wiadomosc="1";
  String toSend = (wiadomosc); // tekst wiadomości

char msg[23]; // tworzymy tablicę typu char
  toSend.toCharArray(msg, toSend.length() + 1); // konwertujemy nasz tekst do tablicy charów
    vw_send((uint8_t *)msg, strlen(msg));// wysyłamy 
     vw_wait_tx();
  }

 
    
    delay(1000);
      wiadomosc="0";
      String toSend = (wiadomosc); // tekst wiadomości
      char msg[23]; // tworzymy tablicę typu char
      toSend.toCharArray(msg, toSend.length() + 1); // konwertujemy nasz tekst do tablicy charów
         vw_send((uint8_t *)msg, strlen(msg));// wysyłamy 
         vw_wait_tx(); 
   }


}

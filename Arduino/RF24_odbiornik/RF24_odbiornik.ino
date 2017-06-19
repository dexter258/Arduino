#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <IRremote.h>
IRsend irsend;
int msg[1];
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int LED1 = 4;
int stycznik = 8;
void setup()
{
 Serial.begin(9600);
 radio.begin();
 radio.openReadingPipe(1,pipe);
 radio.startListening();
 pinMode(LED1, OUTPUT);
 pinMode(stycznik, OUTPUT);
   
}

void loop()
{
 if (radio.available())
{
   bool done = false;    
   while (!done){
     done = radio.read(msg, 2);      
     Serial.println(msg[0]);
     if (msg[0] == 100)     //projektor
{
  int khz = 38;
delay(10);
unsigned int irSignal[] = { 6300, 2100, 500, 1700, 1450, 750, 1500, 650, 600, 1600, 1550, 650, 550, 1600, 500, 1700, 500, 1700, 1550, 650, 550, 1650, 1500, 700, 500, 1650, 1500, 700, 550, 1650, 550, 1600, 1550, 650, 1500, 700, 550, 1650, 1500, 700, 500, 1650, 1550, 650, 550, 1600, 600, 1600, 1500, 700, 2050}; //AnalysIR Batch Export (IRremote) - RAW
digitalWrite(LED1, HIGH);
irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
delay(500);
digitalWrite(LED1, LOW);
}
     if (msg[0] == 50)      //uruchamianie
{
delay(10);
digitalWrite(stycznik, HIGH);
delay(600);
digitalWrite(stycznik, LOW);
}
     if (msg[0] == 150) //przod
{int khz = 38;
  unsigned int irSignal[] = { 6250, 2150, 550, 1600, 1550, 650, 1550, 650, 550, 1650, 1500, 700, 500, 1650, 550, 1650, 550, 1650, 1500, 700, 450, 1700, 1550, 650, 550, 1650, 1500, 700, 1500, 650, 1450, 750, 550, 1650, 1500, 700, 500, 1650, 1550, 650, 550, 1600, 1550, 700, 1500, 650, 1550, 650, 550, 1650, 2100};
 digitalWrite(LED1, HIGH);
irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
delay(500);
digitalWrite(LED1, LOW);
}  
 if (msg[0] == 200)      //tyl
{
  int khz = 38;
delay(10);
unsigned int irSignal[] = { 6250, 2150, 550, 1600, 1550, 650, 1550, 650, 550, 1650, 1500, 700, 500, 1650, 550, 1650, 550, 1650, 1500, 700, 450, 1700, 1550, 650, 550, 1650, 1500, 700, 1500, 650, 1450, 750, 550, 1650, 1500, 700, 500, 1650, 1550, 650, 550, 1600, 1550, 700, 1500, 650, 1550, 650, 550, 1650, 2100};
digitalWrite(LED1, HIGH);
irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
delay(500);
digitalWrite(LED1, LOW);
}  
if (msg[0] == 250)      //prawo
{
  int khz = 38;
delay(10);
unsigned int irSignal[] = {  6300, 2100, 550, 1650, 1450, 750, 1500, 700, 550, 1600, 1550, 650, 550, 1650, 550, 1650, 450, 1700, 1550, 650, 550, 1650, 1500, 650, 550, 1650, 1450, 750, 550, 1650, 1500, 650, 1550, 650, 1550, 650, 500, 1700, 1500, 700, 550, 1600, 1550, 650, 550, 1650, 1500, 700, 1500, 650, 2150};
digitalWrite(LED1, HIGH);
irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
delay(500);
digitalWrite(LED1, LOW);
}  
if (msg[0] == 300)      //lewo
{
  int khz = 38;
delay(10);
unsigned int irSignal[] = {6350, 2050, 600, 1600, 1550, 650, 1550, 650, 600, 1600, 1500, 650, 550, 1650, 600, 1600, 550, 1600, 1550, 650, 500, 1700, 1550, 650, 550, 1600, 1600, 600, 1550, 650, 600, 1600, 550, 1600, 1550, 650, 550, 1650, 1550, 650, 550, 1600, 1600, 600, 1550, 650, 600, 1550, 550, 1700, 2100};
digitalWrite(LED1, HIGH);
irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
delay(500);
digitalWrite(LED1, LOW);
}
if (msg[0] == 350)      //kolko
{
  int khz = 38;
delay(10);
unsigned int irSignal[] = {6250, 2100, 600, 1600, 1500, 700, 1550, 650, 550, 1650, 1450, 700, 600, 1600, 550, 1650, 550, 1600, 1550, 650, 500, 1700, 1550, 650, 550, 1600, 600, 1600, 1550, 650, 1450, 750, 1500, 700, 1500, 650, 600, 1600, 1550, 650, 550, 1600, 500, 1700, 1550, 650, 1550, 650, 1450, 750, 2050};
digitalWrite(LED1, HIGH);
irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
delay(500);
digitalWrite(LED1, LOW);
}  
if (msg[0] == 400)      //mikrofon
{
  int khz = 38;
delay(10);
unsigned int irSignal[] = {6300, 2100, 550, 1650, 1450, 750, 1500, 700, 500, 1700, 1400, 750, 550, 1650, 550, 1650, 450, 1700, 1550, 650, 550, 1650, 1500, 700, 500, 1650, 500, 1700, 1500, 700, 550, 1650, 1500, 700, 1500, 650, 550, 1650, 1500, 700, 500, 1650, 500, 1700, 1500, 700, 550, 1650, 1500, 650, 2150};
digitalWrite(LED1, HIGH);
irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
delay(500);
digitalWrite(LED1, LOW);
}  
if (msg[0] == 450)      //gwiazdka
{
  int khz = 38;
delay(10);
unsigned int irSignal[] = {6300, 2100, 550, 1650, 1500, 700, 1500, 650, 600, 1600, 1550, 650, 550, 1650, 550, 1650, 550, 1600, 1550, 650, 550, 1650, 1500, 650, 600, 1600, 500, 1700, 1550, 650, 550, 1650, 500, 1650, 1550, 650, 550, 1650, 1500, 650, 600, 1600, 500, 1700, 1550, 650, 550, 1650, 550, 1600, 2150};
digitalWrite(LED1, HIGH);
irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
delay(500);
digitalWrite(LED1, LOW);
}  
if (msg[0] == 999)      //START
{
  int khz = 38;
delay(10);
digitalWrite(stycznik, HIGH);
delay(600);
digitalWrite(stycznik, LOW);
delay(10000);
unsigned int irSignal[] = { 6250, 2150, 500, 1700, 1500, 650, 1550, 650, 550, 1650, 1500, 650, 550, 1650, 500, 1700, 550, 1650, 1500, 700, 1500, 650, 550, 1650, 1500, 700, 1450, 750, 1500, 700, 1500, 650, 1550, 650, 1500, 700, 1450, 750, 450, 1700, 1550, 650, 1550, 650, 1500, 700, 1500, 650, 1550, 650, 2150, 4850, 0, 300, 50, 3950, 400, 4050, 250, 5150, 500, 700, 50, 3350, 300, 450, 6250, 2150, 550, 1600, 1500, 750, 1400, 750, 550, 1650, 1500, 700, 550, 1600, 550, 1650, 500, 1700, 1500, 700, 1500, 700, 550, 1600, 1550, 650, 1500, 700, 1450, 750, 1500, 650, 1550, 650};
  digitalWrite(LED1, HIGH);
irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); 
delay(500);
digitalWrite(LED1, LOW);
delay(25000);
}
     delay(10);

 }
 }

}


#include <IRremote.h>

IRsend irsend;

void setup()
{

}

void loop() {
  int khz = 38;
  // URUCHAMIANIE PROJEKTORA
 // unsigned int irSignal[] = { 6300, 2100, 500, 1700, 1450, 750, 1500, 650, 600, 1600, 1550, 650, 550, 1600, 500, 1700, 500, 1700, 1550, 650, 550, 1650, 1500, 700, 500, 1650, 1500, 700, 550, 1650, 550, 1600, 1550, 650, 1500, 700, 550, 1650, 1500, 700, 500, 1650, 1550, 650, 550, 1600, 600, 1600, 1500, 700, 2050}; //AnalysIR Batch Export (IRremote) - RAW
  
  //STRZALKA PRZOD
 // unsigned int irSignal[] = { 6250, 2150, 550, 1600, 1550, 650, 1550, 650, 550, 1650, 1500, 700, 500, 1650, 550, 1650, 550, 1650, 1500, 700, 450, 1700, 1550, 650, 550, 1650, 1500, 700, 1500, 650, 1450, 750, 550, 1650, 1500, 700, 500, 1650, 1550, 650, 550, 1600, 1550, 700, 1500, 650, 1550, 650, 550, 1650, 2100};
 
 //STRZALKA TYL
   //unsigned int irSignal[] = {6300, 2100, 550, 1650, 1450, 750, 1500, 700, 550, 1600, 1550, 650, 550, 1650, 550, 1600, 600, 1600, 1550, 650, 550, 1650, 1500, 700, 550, 1600, 1550, 650, 1550, 650, 550, 1600, 1500, 700, 1550, 650, 550, 1650, 1500, 700, 550, 1600, 1450, 750, 1550, 650, 550, 1650, 1500, 650, 2150};

 //STRZALKA PRAWO
 //unsigned int irSignal[] = {  6300, 2100, 550, 1650, 1450, 750, 1500, 700, 550, 1600, 1550, 650, 550, 1650, 550, 1650, 450, 1700, 1550, 650, 550, 1650, 1500, 650, 550, 1650, 1450, 750, 550, 1650, 1500, 650, 1550, 650, 1550, 650, 500, 1700, 1500, 700, 550, 1600, 1550, 650, 550, 1650, 1500, 700, 1500, 650, 2150};

//STRZALKA LEWO
//unsigned int irSignal[] = {6350, 2050, 600, 1600, 1550, 650, 1550, 650, 600, 1600, 1500, 650, 550, 1650, 600, 1600, 550, 1600, 1550, 650, 500, 1700, 1550, 650, 550, 1600, 1600, 600, 1550, 650, 600, 1600, 550, 1600, 1550, 650, 550, 1650, 1550, 650, 550, 1600, 1600, 600, 1550, 650, 600, 1550, 550, 1700, 2100};
// KRECENIE W KOLKO
//unsigned int irSignal[] = {6250, 2100, 600, 1600, 1500, 700, 1550, 650, 550, 1650, 1450, 700, 600, 1600, 550, 1650, 550, 1600, 1550, 650, 500, 1700, 1550, 650, 550, 1600, 600, 1600, 1550, 650, 1450, 750, 1500, 700, 1500, 650, 600, 1600, 1550, 650, 550, 1600, 500, 1700, 1550, 650, 1550, 650, 1450, 750, 2050};
//SLACZEK
 //unsigned int irSignal[] = { 6300, 2100, 550, 1650, 1550, 650, 1550, 650, 550, 1600, 1550, 650, 550, 1650, 550, 1600, 600, 1600, 1550, 650, 500, 1700, 1550, 600, 600, 1600, 550, 1650, 1550, 600, 1550, 700, 500, 1650, 1550, 650, 550, 1650, 1500, 650, 600, 1600, 500, 1700, 1550, 650, 1500, 700, 500, 1650, 2100};
 //DYMEK
 //unsigned int irSignal[] = {6300, 2100, 500, 1700, 1500, 650, 1550, 650, 550, 1650, 1550, 650, 550, 1600, 500, 1700, 550, 1650, 1550, 650, 550, 1600, 1600, 600, 550, 1650, 1550, 650, 550, 1600, 1550, 650, 600, 1600, 1550, 650, 500, 1700, 1500, 650, 600, 1600, 1550, 650, 550, 1650, 1500, 650, 600, 1600, 2150};
 //STOP
 //unsigned int irSignal[] = { 6250, 2150, 500, 1700, 1500, 650, 1550, 650, 550, 1650, 1500, 650, 550, 1650, 500, 1700, 550, 1650, 1500, 700, 1500, 650, 550, 1650, 1500, 700, 1450, 750, 1500, 700, 1500, 650, 1550, 650, 1500, 700, 1450, 750, 450, 1700, 1550, 650, 1550, 650, 1500, 700, 1500, 650, 1550, 650, 2150, 4850, 0, 300, 50, 3950, 400, 4050, 250, 5150, 500, 700, 50, 3350, 300, 450, 6250, 2150, 550, 1600, 1500, 750, 1400, 750, 550, 1650, 1500, 700, 550, 1600, 550, 1650, 500, 1700, 1500, 700, 1500, 700, 550, 1600, 1550, 650, 1500, 700, 1450, 750, 1500, 650, 1550, 650};
 //PROG
 //unsigned int irSignal[] = {6300, 2100, 550, 1650, 1450, 750, 1500, 700, 550, 1600, 1550, 650, 550, 1650, 550, 1600, 600, 1600, 1550, 650, 1450, 750, 450, 1750, 550, 1600, 1550, 650, 550, 1650, 550, 1600, 500, 1700, 1550, 650, 1550, 650, 550, 1650, 550, 1600, 1500, 700, 500, 1700, 550, 1650, 550, 1600, 2150};
  //MIKROFON
  //unsigned int irSignal[] = {6300, 2100, 550, 1650, 1450, 750, 1500, 700, 500, 1700, 1400, 750, 550, 1650, 550, 1650, 450, 1700, 1550, 650, 550, 1650, 1500, 700, 500, 1650, 500, 1700, 1500, 700, 550, 1650, 1500, 700, 1500, 650, 550, 1650, 1500, 700, 500, 1650, 500, 1700, 1500, 700, 550, 1650, 1500, 650, 2150};
  //GWIAZDKA
 // unsigned int irSignal[] = 6300, 2100, 550, 1650, 1500, 700, 1500, 650, 600, 1600, 1550, 650, 550, 1650, 550, 1650, 550, 1600, 1550, 650, 550, 1650, 1500, 650, 600, 1600, 500, 1700, 1550, 650, 550, 1650, 500, 1650, 1550, 650, 550, 1650, 1500, 650, 600, 1600, 500, 1700, 1550, 650, 550, 1650, 550, 1600, 2150};
 // PRZOD LEWO 
 //for (int s;s<100;s++){
//unsigned int irSignal[] = {6300, 2100, 500, 1700, 1450, 750, 1500, 650, 550, 1650, 1550, 650, 550, 1600, 500, 1700, 550, 1650, 1550, 650, 1500, 700, 1500, 650, 1500, 700, 1500, 700, 1550, 650, 550, 1600, 600, 1600, 1550, 650, 1550, 650, 1500, 700, 1450, 750, 1450, 700, 1550, 650, 550, 1650, 550, 1600, 2150};
 
//TYL LEWO 
unsigned int irSignal[] = { 6300, 2100, 500, 1700, 1450, 750, 1550, 650, 550, 1600, 1550, 650, 550, 1650, 500, 1700, 500, 1700, 1500, 650, 1550, 650, 1550, 650, 1450, 750, 1500, 700, 550, 1600, 1550, 650, 1500, 700, 1500, 700, 1500, 650, 1550, 650, 1450, 750, 1450, 750, 500, 1650, 1550, 650, 1550, 650, 2150};

 
  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.

// }
  delay(5); //In this example, the signal will be repeated every 5 seconds, approximately.
}
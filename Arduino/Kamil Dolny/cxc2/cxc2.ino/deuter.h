#include "PCF8574.h" // Required for PCF8574

PCF8574 pcf0;

long startTime;



const bool colorVariant[6][8] = {{LOW, HIGH, LOW,     HIGH, LOW, LOW,     LOW, HIGH}, // zielony, czerwony, niebieski
                                 {HIGH, LOW, LOW,     HIGH, LOW, LOW,     HIGH, LOW}, // czerowny, czerwony, czerwony
                                 {LOW, LOW, HIGH,     LOW, HIGH, LOW,     LOW, HIGH}, // niebieski, zielony, niebieski
                                 {LOW, LOW, HIGH,     HIGH, LOW, LOW,     HIGH, LOW}, // niebieski, czerowny, czerowny
                                 {LOW, HIGH, LOW,     LOW, HIGH, LOW,     HIGH, LOW},// zielony, zielony, czerowny
                                 {LOW, LOW, LOW,      LOW, LOW, LOW,      LOW, LOW}
                                 };



void initDeuterPanel(){

  pcf0.begin(0x20);

  for(byte i = 0; i < 8; i++){
     pcf0.pinMode(i, OUTPUT);
     pcf0.digitalWrite(i, HIGH);
  }
}


//Można wybierać jeden z 5 dostępnych kolorów
void setDeuterColorVariant(byte number){
  
  for(byte i = 0; i < 8; i++){

      pcf0.digitalWrite(i, !colorVariant[number][i]);
  }
}



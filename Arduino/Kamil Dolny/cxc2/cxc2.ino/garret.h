#include "PCF8574.h" // Required for PCF8574

PCF8574 pcf1;
bool garretButton[3] = {false, false, false};
bool numbersGarret[11][7] = {  {HIGH, LOW, LOW, LOW, LOW, LOW, LOW}, // zero
                               {HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH}, // jeden
                               {LOW, HIGH, LOW, LOW, HIGH, LOW, LOW }, // dwa
                               {LOW, HIGH, LOW, LOW, LOW, LOW, HIGH}, //trzy
                               {LOW, LOW, HIGH, LOW, LOW, HIGH, HIGH}, // cztery
                               {LOW, LOW, LOW, HIGH, LOW, LOW, HIGH}, // pięć
                               {LOW, LOW, LOW, HIGH, LOW, LOW, LOW}, // sześć
                               {HIGH, HIGH, LOW, LOW, LOW, HIGH, HIGH}, // siedem
                               {LOW,LOW,LOW,LOW,LOW,LOW,LOW}, // osiem
                               {LOW,LOW,LOW,LOW,LOW,LOW,HIGH}, // dziewięć
                               {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH}}; // nic

void initGarretPanel(){
  pcf1.begin(0x21);

  for(byte i = 0; i < 5; i ++){
    pcf1.pinMode(i, OUTPUT);
    pcf1.digitalWrite(i, HIGH);
  }

  for(byte i = 5; i < 8; i ++){
    pcf1.pinMode(i, INPUT_PULLUP); 
  }
}

void setGarretNumber(byte number){
  for(byte i = 0; i< 5; i ++){
    pcf1.digitalWrite(i, numbersGarret[number][i+2]);
  }
}

void readGarretButton(){
  if(pcf1.digitalRead(5) == LOW){
    delay(40);
    if(pcf1.digitalRead(5) == LOW){
      garretButton[0] = true;
     
    }
  }
  else garretButton[0] = false;

  if(pcf1.digitalRead(6) == LOW){
    delay(40);
    if(pcf1.digitalRead(6) == LOW){
      garretButton[1] = true;
     
     }
  }
  else garretButton[1] = false;

  if(pcf1.digitalRead(7) == LOW){
    delay(40);
    if(pcf1.digitalRead(7) == LOW){
      garretButton[2] = true;
      
    }
  }
  else garretButton[2] = false;
}




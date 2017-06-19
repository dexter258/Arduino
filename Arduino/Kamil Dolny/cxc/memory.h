#include "memoryLogic.h"
extern byte error;
extern bool debug;
Adafruit_MCP23017 mcp4, mcp5, mcp6;
bool memoryPass = false;

bool numbersMemorySmall[11][7] = {{HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW}, // zero
                               {LOW,LOW,HIGH,HIGH,LOW,LOW,LOW}, // jeden
                               {HIGH,HIGH,LOW,HIGH,HIGH,LOW,HIGH}, // dwa
                               {LOW,HIGH,HIGH,HIGH,HIGH,LOW,HIGH}, //trzy
                               {LOW,LOW,HIGH,HIGH,LOW,HIGH,HIGH}, // cztery
                               {LOW,HIGH,HIGH,LOW,HIGH,HIGH,HIGH}, // pięć
                               {HIGH,HIGH,HIGH,LOW,HIGH,HIGH,HIGH}, // sześć
                               {LOW,LOW,HIGH,HIGH,HIGH,LOW,LOW}, // siedem
                               {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH}, // osiem
                               {LOW,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH}, // dziewięć
                               {LOW,LOW,LOW,LOW,LOW,LOW,LOW}}; // nic

bool numbersMemoryBig[11][7] =  {{LOW,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH}, // zero
                                {LOW,LOW,LOW,HIGH,LOW,LOW,HIGH}, // jeden
                                {HIGH,LOW,HIGH,HIGH,HIGH,HIGH,LOW}, // dwa
                                {HIGH,LOW,HIGH,HIGH,LOW,HIGH,HIGH}, // trzy
                                {HIGH,HIGH,LOW,HIGH,LOW,LOW,HIGH}, // cztery
                                {HIGH,HIGH,HIGH,LOW,LOW,HIGH,HIGH}, // pięć
                                {HIGH,HIGH,HIGH,LOW,HIGH,HIGH,HIGH}, // sześć
                                {LOW,LOW,HIGH,HIGH,LOW,LOW,HIGH}, // siedem
                                {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH}, // osiem
                                {HIGH,HIGH,HIGH,HIGH,LOW,HIGH,HIGH}, //dziewięć
                                {LOW,LOW,LOW,LOW,LOW,LOW,LOW}};


void setNumbersMemory(byte big, byte first, byte second, byte third, byte fourth){
  //DUŻY WYŚWIETLACZ, pierwszy i trzeci mały

  for(byte i = 0; i< 7; i ++){
    mcp4.digitalWrite(i,numbersMemoryBig[big][i]);
    mcp4.digitalWrite(i+7,numbersMemorySmall[first][i]);
    mcp5.digitalWrite(i+5, numbersMemorySmall[third][i]);
  }

  
  // Drugi mały 
  
  mcp4.digitalWrite(14,numbersMemorySmall[second][0]); 
  mcp4.digitalWrite(15,numbersMemorySmall[second][1]);
  for(byte i = 0; i < 5; i++){
    mcp5.digitalWrite(i, numbersMemorySmall[second][i+2]);
  }

  //Czwarty mały
  mcp5.digitalWrite(15, numbersMemorySmall[fourth][3]);
  for(byte i = 0; i < 3; i++){
    mcp5.digitalWrite(i+12, numbersMemorySmall[fourth][i]);
    mcp6. digitalWrite(i,  numbersMemorySmall[fourth][i+4]);
  }
    
}

void setMemoryLevel(byte numer){
  for(byte i =0; i<5; i++){
    mcp6.digitalWrite(11-i, LOW); 
  }
  for(byte i = 0; i < numer; i++){
    mcp6.digitalWrite(11-i, HIGH);
  }
}

byte readMemoryButton(){
  if(mcp6.digitalRead(3) == LOW){
    while(mcp6.digitalRead(3) == LOW);
    return 1;
  }
    
  else if(mcp6.digitalRead(4) == LOW){
    while(mcp6.digitalRead(4) == LOW);
    return 2;
  }
   
  else if(mcp6.digitalRead(5) == LOW){
    while(mcp6.digitalRead(5) == LOW);
     return 3; 
  }
   
  else if(mcp6.digitalRead(6) == LOW){
    while(mcp6.digitalRead(6) == LOW);
    return 4;
  }
    

  return 0;
  
}
void initMemoryPanel(){

  randomSeed(analogRead(A8));
  mcp4.begin(4);
  mcp5.begin(5);
  mcp6.begin(6);
  for(byte i = 0; i < 16; i++){
    mcp4.pinMode(i, OUTPUT);
    mcp5.pinMode(i, OUTPUT);
    mcp4.digitalWrite(i, LOW);
    mcp5.digitalWrite(i, LOW);
  }

   for(byte i = 0; i< 4; i++){
    mcp6.pinMode(i+8, OUTPUT);
    mcp6.digitalWrite(i+8, LOW);
    
    mcp6.pinMode(i+3, INPUT);
    
    mcp6.pullUp(i+3, HIGH);
   }

   for(byte i = 0; i< 3; i++){
    mcp6.pinMode(i, OUTPUT);
    mcp6.digitalWrite(i, LOW);
   }

   mcp6.pinMode(7, OUTPUT);
   mcp6.digitalWrite(7, LOW);
  
}



void memoryGame(){
  
  if(memoryFlag == true){
    randomNumber();
    setNumbersMemory(randomBig, randomSmall[0], randomSmall[1], randomSmall[2], randomSmall[3]);
    setMemoryLevel(memoryLevel);
    memoryFlag = false;
    if(debug == true){
      Serial.println("Poziom = " + String(memoryLevel));
      Serial.println("Errors = " + String(error));
    }
    
  }
  byte button = readMemoryButton();
  
  if(button!= 0 && debug == true)
  Serial.println(button);
   
  if(memoryLevel == 1 && button!= 0)
    memoryLevel1(button);
 
  else  if(memoryLevel == 2 && button != 0)
    memoryLevel2(button);
  
  else  if(memoryLevel == 3 && button != 0)
    memoryLevel3(button);
  
  else  if(memoryLevel == 4 && button != 0)
    memoryLevel4(button);

  else  if(memoryLevel == 5 && button != 0)
    memoryLevel5(button);

  if(memoryLevel == 6){
     setNumbersMemory(10,10,10,10,10);
     setMemoryLevel(0);
     memoryPass = true;
  }
   
  
  
 
 
  
  
}



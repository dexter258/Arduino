bool acceptGarret = false;
extern bool sendingInfo;
#include "garretLogic.h"
extern bool startGames[9];
extern byte debugGames;
bool garretFlag = false;
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
bool readAcceptGarret(){
  if(digitalRead(22) == LOW && acceptGarret == false){
    delay(80);
    if(digitalRead(22) == LOW && acceptGarret == false){
    
    acceptGarret = true;
    return true;

    
    
  }
  }
  

  else if(digitalRead(22) == HIGH && acceptGarret == true){
    delay(80);
    if(digitalRead(22) == HIGH && acceptGarret == true){
       
       acceptGarret = false;
       return false;
       
    }
   
    
   
    
  }
  else {
    
    return false;
  }

  

 
}
void setGarretNumbers(byte first, byte second, byte third){
  for(byte i = 0; i< 7; i ++){
    mcp3.digitalWrite(i, numbersGarret[first][i]);
    mcp3.digitalWrite(i+7, numbersGarret[second][i]);
  }

  mcp3.digitalWrite(14, numbersGarret[third][0]);
  mcp3.digitalWrite(15, numbersGarret[third][1]);

 sendingInfo = true;
 delay(50);
 if(third == 10){
  Serial2.println("gn");
 }
 else {
 Serial2.println("g" + String(third));
 }
 delay(50);
 sendingInfo = false;
}
void initGarretPanel(){

  mcp3.begin(3);
  for(byte i = 0; i < 16; i++){
    mcp3.pinMode(i, OUTPUT);

    
    mcp3.digitalWrite(i, HIGH);

    
  }
  //setGarretNumbers(0,0,0);

  pinMode(22, INPUT_PULLUP);
}

void checkGarret(){
  if(sendingInfo == false){
    Serial2.println("G");
  }
  
}

void readGarretButtons(String info){
   String temp1 = "", temp2 = "", temp3 = "";

  temp1 += info[0];
  temp2 += info[1];
  temp3 += info[2];

  garretButtonPrev[0] = garretButton[0];
  garretButtonPrev[1] = garretButton[1];
  garretButtonPrev[2] = garretButton[2];


  garretButton[0] = bool(temp1.toInt());
  garretButton[1] = bool(temp2.toInt());
  garretButton[2] = bool(temp3.toInt());

  if (garretButton[0] == true && garretButtonPrev[0] == false) {
    garretNumberButton[0] ++;
    if (garretNumberButton[0] > 9)
      garretNumberButton[0] = 0;

  }
  if (garretButton[1] == true && garretButtonPrev[1] == false) {
    garretNumberButton[1] ++;
    if (garretNumberButton[1] > 9)
      garretNumberButton[1] = 0;

  }

  if (garretButton[2] == true && garretButtonPrev[2] == false) {

    garretNumberButton[2] ++;
    if (garretNumberButton[2] > 9)
      garretNumberButton[2] = 0;

  }


  if (startGames[0] == true && garretPass == false || debugGames == 0) {

    setGarretNumbers(garretNumberButton[0], garretNumberButton[1], garretNumberButton[2]);
  }

}



#include "PCF8574.h" // Required for PCF8574

PCF8574 pcf4;
String buttonColor[5] = {"red", "green", "blue", "pink", "none"};

bool eventButton[5] = {false, false, false, false, false};
void initButtonPanel(){
  pcf4.begin(0x24);
  for(byte i = 0; i < 4; i++){
    pcf4.pinMode(i, INPUT_PULLUP);
    
  }

  pcf4.pinMode(4, INPUT);
  pcf4.digitalWrite(4, HIGH);

  for(byte i = 0; i < 4; i ++){
    pcf4.pinMode(i+5, OUTPUT);
    pcf4.digitalWrite(i+5, HIGH);
  }
}


void setColorButton(String color){
  if( color == "red"){
    pcf4.digitalWrite(5, LOW);
    pcf4.digitalWrite(6, HIGH);
    pcf4.digitalWrite(7, HIGH);
  }
  else if(color == "blue"){
    pcf4.digitalWrite(5, HIGH);
    pcf4.digitalWrite(6, HIGH);
    pcf4.digitalWrite(7, LOW);
  }
  else if(color == "green"){
    pcf4.digitalWrite(5, HIGH);
    pcf4.digitalWrite(6, LOW);
    pcf4.digitalWrite(7, HIGH);
  }
  else if(color == "pink"){
    pcf4.digitalWrite(5, LOW);
    pcf4.digitalWrite(6, HIGH);
    pcf4.digitalWrite(7, LOW);
  }
  else if(color == "none"){
    pcf4.digitalWrite(5, HIGH);
    pcf4.digitalWrite(6, HIGH);
    pcf4.digitalWrite(7, HIGH);
  }
  
}

void readEventButtons(){

  for(byte i = 0; i < 5; i++){
    if(pcf4.digitalRead(i) == LOW){
      eventButton[i] = true;
    }
    else eventButton[i] = false;
  }

}


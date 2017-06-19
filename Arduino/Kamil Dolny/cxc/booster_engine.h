Adafruit_MCP23017 mcp2;

extern byte error;
extern String mainInfoText[10][7];
extern byte randomMainInfo;
extern String additionalInfoText[4];
extern byte randomAddInfo;
extern byte status1[15];
extern byte deuterRandom;
extern bool debug;

bool enginePass = false;
bool engineButton[3] = {false, false, false};
bool engineButtonPrev[3] =  {false, false, false};
bool engineButtonFirst[3] = {false, false, false};
bool boosterButton[9]= {false, false, false, false, false, false, false, false, false};
byte engineError;
bool passLevelEngine[3] = {false, false, false};
bool activeSwitch[3] = {false, false, false};

bool przelaczony[3] = {false,false,false};
void initBoosterEnginePanel() {
  mcp2.begin(2);
  for (byte i = 0; i < 12; i++) {
    mcp2.pinMode(i, INPUT_PULLUP);
    mcp2.digitalWrite(i, HIGH);
  }

  for (byte i = 12; i < 15; i++) {
    mcp2.pinMode(i, OUTPUT);
    //delay(500);
    mcp2.digitalWrite(i, LOW);
  }

  for (byte i = 9; i < 12; i++) {
    engineButtonPrev[i - 9] = !mcp.digitalRead(i);
  }
}

void readBoosterEngineKey() {
  for (byte i = 0; i < 12; i++) {
    if (mcp2.digitalRead(i) == LOW) {
      // Serial.println("Przycisk " + String(i));
    }
  }
}

void setEngineLeds() {
  mcp2.digitalWrite(12, !mcp2.digitalRead(9));
  mcp2.digitalWrite(13, !mcp2.digitalRead(10));
  mcp2.digitalWrite(14, !mcp2.digitalRead(11));

}

void readEngineButtons() {
  setEngineLeds();
  for (byte i = 0; i < 3; i ++) {

    engineButtonPrev[i] = engineButtonFirst[i];
    engineButtonFirst[i] = !mcp2.digitalRead(i + 9);
    if (engineButtonFirst[i] == true &&  engineButtonPrev[i] == false) {
      engineButton[i] = engineButtonFirst[i];

 //     if (debug == true) Serial.println("Button Engine " + String(i) + " = " + String(engineButton[i]));
    }
    else {
      engineButton[i] = false;
    }
  }

  for(byte i = 0; i < 9; i++){
      
      boosterButton[i] = bool(!mcp2.digitalRead(i));
  }
}




void engineGame() {
 
  //setEngineLeds();
  for (byte i = 0; i < 3; i++) {
if (engineButtonFirst[i]==true && engineButton[i]==true){
  przelaczony[i]=true;
}
else{
    przelaczony[i]=false;
}
  }

   readEngineButtons();

  //LOGIKA DLA ENGINE I

  if ( mainInfoText[randomMainInfo][5] == "Y" && engineButtonFirst[1] && ((additionalInfoText[randomAddInfo] != "FKW")|| (status1[5] == 1 && status1[9] == 1 && status1[3] != 2))) {

    activeSwitch[0] = true; // spelniony warunek
    if(debug == true)  Serial.print("1T"); 
  }
  //Jeśli nie ma liczby podzielnej przez 3 lub ENGINE II jest OFF
  else {
    activeSwitch[0] = false;
    if(debug == true)  Serial.print("1F");
  
  }

  //LOGIKA DLA ENGINE II

  if (additionalInfoText[randomAddInfo] != "FKW") {
    activeSwitch[1] = true;
 // if(debug == true)  Serial.print("2T");
  }
  else if (status1[5] == 1 && status1[9] == 1 && status1[3] != 2) {
    activeSwitch[1] = true;
  //   if(debug == true)  Serial.print("2T");
  }
  else {
    activeSwitch[1] = false;
 //   if(debug == true)  Serial.print("2F");
     
  }

  // LOGIKA dla ENGINE III

  if ( activeSwitch[0] == false && activeSwitch[1] == false) {
    activeSwitch[2] = true;
 //   if(debug == true)  Serial.print("3T");
   
  }
  else if ((deuterRandom == 1 || deuterRandom == 3) && mainInfoText[randomMainInfo][4] == "Y") {
    activeSwitch[2] = true;
//    if(debug == true)  Serial.print("3T");
     }
  else {
    activeSwitch[2] = false;
 //     if(debug == true)  Serial.print("3F");
  }


if(debug == true)  Serial.println();

  //LOGIKA SPRAWDZAJĄCA DLA ENGINE 
 
      for (byte i = 0; i < 3; i++) {
        
      
  if (przelaczony[i] == true && activeSwitch[i] == true ) {
    passLevelEngine[i] = true;
 //    if(debug == true)  Serial.println("przycisk" + String(i)+ "X1");
  }
  else if (engineButtonFirst[i] == false && activeSwitch[i] == true ){
    passLevelEngine[i] = false;
//    if(debug == true)  Serial.println("przycisk" + String(i)+ "X2");
  }
  else if (engineButtonFirst[i] == false && activeSwitch[i] == false ) {
    passLevelEngine[i] = true;
 //    if(debug == true)  Serial.println("przycisk" + String(i)+ "X3");
  }
  else if(przelaczony[i] == true) {
  passLevelEngine[i] = false;
    error++;
     if(debug == true)  Serial.println("przycisk" + String(i) + "X4  ERROR ");
    }
  
}

      
  if(passLevelEngine[0] == true && passLevelEngine[1] == true && passLevelEngine[2] == true){
    enginePass = true;
    for (byte i = 0; i < 3; i++) {
    przelaczony[i]=false;
}
//    if(debug == true) Serial.println("ENGINE END");
  }

//  }

  



}


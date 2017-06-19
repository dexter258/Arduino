extern byte amountErrorStatus2;
extern byte status1[15];
extern byte error;
extern String mainInfoText[10][7];
extern byte randomMainInfo;
extern byte deuterRandom;

bool abortButton[3] = {false, false, false}; // ABORT, SAFE, AUTO
bool abortAcceptPrev = false;
bool abortAccept = false;
bool armAbortPass = false;
bool abortModePass = false;
bool abortPass = false;
bool safe = false;
bool autoo = false;
void initAbortPanel() {
  
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);

  pinMode(A0, INPUT);


}


void readAbortButtons(String info) {
  String temp = "";
  abortAcceptPrev = abortButton[0];

  for (byte i = 0; i < 3; i++) {
    temp += info[i + 10];
    abortButton[i] = bool(temp.toInt());
            if (abortButton[0]==1||abortButton[0]==true){
              i=3;
            }
          
  
  }

  if (abortButton[0] == true && abortAcceptPrev != abortButton[0]) {
    abortAccept = true;
    Serial.println("AcceptAbort");
  }
  else {
    abortAccept = false;
  }
  

  if ( abortButton[1]==1 && abortButton[2]==1){
  safe = true;
}
else safe=false;
if ( abortButton[1]==0 && abortButton[2]==1){
  autoo = true;
}
else autoo=false;

}

 void readAbortButton(){
 
 }
    
String readPotValue() {
  int temp = analogRead(A0);

  if (temp <= 100) {
    return "V";
    if(debug == true) Serial.println("V");
  }
  else if (temp > 100 && temp <= 200) {
    return "S-IVB";
        if(debug == true) Serial.println("S-IVB");
  }

  else if (temp > 200 && temp <= 290) {
    return "IV";
        if(debug == true) Serial.println("IV");
  }
  else if (temp > 290 && temp <= 510) {
    return "III";
        if(debug == true) Serial.println("III");
  }
  else if (temp > 510 && temp <= 610) {
    return "II";
        if(debug == true) Serial.println("II");
  }
  else if ( temp > 610 && temp <= 705) {
    return "I";
        if(debug == true) Serial.println("I");
  }
  else if (temp > 705) {
    return "PAD";
        if(debug == true) Serial.println("PAD");
  }


}

void abortGame() {

 
  if (abortAccept == true) {
    

    

     digitalWrite(6, HIGH);
      
    if (amountErrorStatus2 > 4 && safe == 1) {
      armAbortPass = true;
      if (debug == true) Serial.println("SAFE");
  
    }
    else if ( amountErrorStatus2 <= 4 && autoo == 1 && status1[11] == 1) {
      armAbortPass = true;
       
     if (debug == true) Serial.println("AUTO");
    }
    else if (amountErrorStatus2 <= 4 &&  status1[11] != 1 && safe == 0 && autoo == 0) {
       if(debug == true)
        if (debug == true) Serial.println("NEUTRAL");
      armAbortPass = true;
    }

    else {
      armAbortPass = false;
    }

    String pot = "";
    //Pętla na wypadek gdyby pierwszy pomiar nie był miarodajny;
    for (byte i = 0; i < 5; i++) {
      pot = readPotValue();
     if(debug == true) Serial.println(pot);
    }

    if (error == 1 && pot == "III") {

      abortModePass = true;
    }
    else if (error!=1 &&             mainInfoText[randomMainInfo][6] == "Y" && pot == "II") {

      abortModePass = true;
    }
    else if (error!=1 && mainInfoText[randomMainInfo][6] == "N" &&                   deuterRandom == 1 && pot == "PAD") {

      abortModePass = true;
    }
    else if (error!=1 && mainInfoText[randomMainInfo][6] == "N" &&  deuterRandom != 1 &&         status1[2] == 2 && pot == "S-IVB") {

      abortModePass = true;
    }
    else if (error!=1 && mainInfoText[randomMainInfo][6] == "N" &&  deuterRandom != 1 && status1[2] != 2 &&   amountErrorStatus2 <= 4 &&  status1[11] != 1   &&     pot == "V") {

      abortModePass = true;
    }
    else if (error != 1 && mainInfoText[randomMainInfo][6] == "N" && deuterRandom != 1 && status1[2] != 2 &&  (amountErrorStatus2 > 4 || status1[11] == 1) && pot == "IV") {
     
      abortModePass = true;
    }
    else {
      abortModePass = false;

    }

    if (abortModePass == true && armAbortPass == true) {
      abortPass = true;
      digitalWrite(6, LOW);
      abortModePass = false;
      armAbortPass = false;
    }
    else {
      error++;
      for(byte i = 0; i < 5; i++){
        digitalWrite(6, HIGH);
        delay(50);
        digitalWrite(6, LOW);
        delay(50);

         abortModePass = false;
          armAbortPass = false;
      }
    }

  }
  
}


extern byte error;
Adafruit_MCP23017 mcp3;
bool garretButton[3] = {false, false, false};
bool garretButtonPrev[3] = {false, false, false};
byte garretNumberButton[3] = {0, 0, 0};
bool garretPass = false;
extern byte status1[15];
extern String mainInfoText[10][7];
extern byte randomMainInfo;
extern byte amountActiveStatus2;
extern byte deuterRandom;
extern bool debug;
extern byte passedGames;
void garretGame() {

  if (debug == true) {
    Serial.println(garretNumberButton[0]);
    Serial.println(garretNumberButton[1]);
    Serial.println(garretNumberButton[2]);
    Serial.println(status1[4]);
    Serial.println(mainInfoText[randomMainInfo][1].toInt());
    Serial.println(deuterRandom);
  }
  byte pass = 0;
  //Czerwony przycisk
  if (garretNumberButton[0] == (garretNumberButton[2] - 2) && status1[4] != 1) {

    pass++;
    if (debug == true) Serial.println("Test1");
  }
  else if (status1[4] == 1 && (garretNumberButton[0] ) == garretNumberButton[1] + 1) {
    pass++;
    if (debug == true) Serial.println("Test2");
  }


  //Żółty przycisk
  if (garretNumberButton[1] == mainInfoText[randomMainInfo][1].toInt() && status1[14] != 2) {
    pass++;
    if (debug == true) Serial.println("Test3");
  }
  else if (status1[14] == 2 && garretNumberButton[1] == mainInfoText[randomMainInfo][2].toInt()) {
    pass++;
    if (debug == true) Serial.println("Test4");
  }



  //Zielony przycisk
  if ( amountActiveStatus2 == garretNumberButton[2] && deuterRandom != 0 ) {
    pass++;
    if (debug == true) Serial.println("Test5");
  }
  else if (deuterRandom == 0 && garretNumberButton[2] == 5) {
    pass++;
    if (debug == true) Serial.println("Test6");
  }

  if (pass < 3) {
    error++;
  }

  if (pass == 3) {
    garretPass = true;
    passedGames ++;
  }
  if (debug == true) Serial.println("Test7 = " + String(pass));
}


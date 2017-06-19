#include "ledsBar.h"
#include "switches.h"
#include "Timers.h"
long firstStart, firstStop, secondStart, secondStop, thirdStart, thirdStop, fourthStart, fourthStop, fifthStart, fifthStop;
bool stFlag = false, sdFlag = false, thFlag = false, fhFlag = false, ftFlag = false;
bool allow1 = false, allow2 = false, allow3 = false, allow4 = false, allow5 = false;
bool on1 = false, on2 = false, on3=false, on4 = false, on5 = false;
byte random1, random2, random3, random4, random5;
byte randomPrev1, randomPrev2, randomPrev3, randomPrev4, randomPrev5;
byte first, second, third, fourth, fifth;
byte seconds = 10;
Timers<2> timer_t;


void setAuto() {
  if (allow1 == true) {
    if (random1 > first) {
      first++;

    }
    else if (random1 < first) {
      first--;

    }
    else {
      allow1 = false;
    }
  }

  if (allow2 == true) {
    if (random2 > second) {
      second++;

    }
    else if (random2 < second) {
      second--;

    }
    else {
      allow2 = false;
    }
  }

  if (allow3 == true) {
    if (random3 > third) {
      third++;

    }
    else if (random3 < third) {
      third--;

    }
    else {
      allow3 = false;
    }
  }

  if (allow4 == true) {
    if (random4 > fourth) {
      fourth++;

    }
    else if (random4 < fourth) {
      fourth--;

    }
    else {
      allow4 = false;
    }
  }

  if (allow5 == true) {
    if (random5 > fifth) {
      fifth++;
      
    }
    else if (random5 < fifth) {
      fifth--;
      
    }
    else {
      allow5 = false;
    }
  }
}

void setON() {
  if(on1 == true){
    if(first<10){
      first++;
    }
  }
  if(on2 == true){
    if(second<10){
      second++;
    }
  }
  if(on3 == true){
    if(third<10){
      third++;
    }
  }
  if(on4 == true){
    if(fourth<10){
      fourth++;
    }
  }
  if(on5 == true){
    if(fifth<10){
      fifth++;
    }
  }
}
void setup() {
  // put your setup code here, to run once:
  mcp0.begin(0);
  mcp1.begin(1);
  mcp2.begin(2);
  pcf.begin(0x3F);

  timer_t.attach(0, 1000, setAuto);
  timer_t.attach(1, 2000, setON);

  for (byte i = 0; i < 16; i++) {
    mcp0.pinMode(i, OUTPUT);
    mcp0.digitalWrite(i, LOW);
    mcp1.pinMode(i, OUTPUT);
    mcp1.digitalWrite(i, LOW);
    mcp2.pinMode(i, OUTPUT);
    mcp2.digitalWrite(i, LOW);
  }

  for (byte i = 0; i < 6; i++) {
    pcf.pinMode(i, OUTPUT);
    pcf.digitalWrite(i, LOW);

  }
  for (byte i = 6; i < 8; i++) {
    pcf.pinMode(i, OUTPUT);
    pcf.digitalWrite(i, HIGH);

  }

  for (byte i = 2; i < 12; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  Serial.begin(9600);

  randomSeed(analogRead(A0));
  randomPrev1 = first = random1 = random(1, 10);
  randomPrev2 = second = random2 = random(1, 10);
  randomPrev3 = third = random3 = random(1, 10);
  randomPrev4 = fourth = random4 = random(1, 10);
  randomPrev5 = fifth = random5 = random(1, 10);


}

void loop() {
  timer_t.process();

  setBars(first, second, third, fourth, fifth);
  readSwitches();


  if (stFlag == false || switches[0] != 1) {
    firstStart = millis();
    stFlag = true;
  }
  if (sdFlag == false || switches[1] != 1) {
    secondStart = millis();
    sdFlag = true;
  }
  if (thFlag == false || switches[2] != 1) {
    thirdStart = millis();
    thFlag = true;
  }
  if (fhFlag == false || switches[3] != 1) {
    fourthStart = millis();
    fhFlag = true;
  }
  if (ftFlag == false || switches[4] != 1) {
    fifthStart = millis();
    ftFlag = true;
  }

  firstStop = millis();
  secondStop = millis();
  thirdStop = millis();
  fourthStop = millis();
  fifthStop = millis();

  if (firstStop - firstStart > seconds * 1000) {

    random1 = random(1,10);
    
    allow1 = true;
    stFlag = false;

  }
  if (secondStop - secondStart > seconds * 1000) {

    random2 = random(1,10);
    allow2 = true;
    sdFlag = false;

  }
  if (thirdStop - thirdStart > seconds * 1000) {

    random3 = random(1,10);

    allow3 = true;
    thFlag = false;

  }
  if (fourthStop - fourthStart > seconds * 1000) {

    random4 = random(1,10);

    allow4 = true;
    fhFlag = false;

  }
  if (fifthStop - fifthStart > seconds * 1000) {

    random5 = random(1,10);

    allow5 = true;
    ftFlag = false;

  }



}


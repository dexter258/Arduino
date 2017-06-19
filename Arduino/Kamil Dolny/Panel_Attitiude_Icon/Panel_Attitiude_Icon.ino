#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp0, mcp1, mcp2, mcp3, mcp4;
byte s = 2;
byte barLeds = 0;
byte pitch = 0;
byte yaw = 0;
int randomPitch, randomYaw, randomRoll, randomRollTime;

long startYaw =0, stopYaw = 0, startPitch =0, stopPitch = 0, startRoll = 0, stopRoll = 0;
bool yawFlag = false, pitchFlag = false, rollFlag = false;

bool sevenSegmentDisplay[11][12] = {{0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0}, // ZERO
  {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // JEDEN
  {0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0}, // DWA
  {0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0}, // TRZY
  {0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0}, // CZTERY
  {0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0}, // PIĘĆ
  {0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0}, // SZEŚĆ
  {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0}, // SIEDEM
  {0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0}, // OSIEM
  {0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0}, // DZIEWIĘĆ
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
}; // NIC

void setup() {
  // put your setup code here, to run once:
  mcp0.begin(0);
  mcp1.begin(1);
  mcp2.begin(2);
  mcp3.begin(3);
  mcp4.begin(4);


  for (byte i = 0; i < 16; i++) {
    mcp0.pinMode(i, OUTPUT);
    mcp0.digitalWrite(i, HIGH);
    mcp1.pinMode(i, OUTPUT);
    mcp1.digitalWrite(i, HIGH);
    mcp2.pinMode(i, OUTPUT);
    mcp2.digitalWrite(i, HIGH);
    mcp3.pinMode(i, OUTPUT);
    mcp4.pinMode(i, OUTPUT);
    mcp3.digitalWrite(i, LOW);
    mcp4.digitalWrite(i, LOW);
  }
  for (byte i = 2; i < 6; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  pinMode(A3, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  randomSeed(A0);
  Serial.begin(9600);
  mcp0.digitalWrite(11, LOW);
  //delay(2000);
  //displayNumber(mcp0, 9);
  //displayNumber(mcp1, 2);
  //displayNumber(mcp2, 7);
  randomRollTime = random(5, 20);
  randomPitch = random(0, 10000);
  randomYaw = random(0, 10000);
  randomRoll = random(0, 10000);
  

}

void loop() {

  displayNumber(mcp0, randomPitch, mcp1, randomYaw, mcp2, randomRoll);
  
  barLeds = map(analogRead(A3), 0, 1023, 36, 1);
  yaw = map(analogRead(A2), 0, 1023, 5, 25);
  pitch = map(analogRead(A1), 0, 1023, 5, 25);
  
  
  //displayNumber(mcp1, 2000);
  //displayNumber(mcp2, 8789);
 
 // barLedsPrev = barLeds;
  if(yawFlag == false){
    startYaw = millis();
    yawFlag = true;
  }
  if(pitchFlag == false){
    startPitch = millis();
    pitchFlag = true;
  }
  if(rollFlag == false){
    startRoll = millis();
    rollFlag = true;
  }
  stopRoll = stopPitch = stopYaw = millis();
  
  if(stopYaw - startYaw > yaw * 1000){
    randomYaw = random(0, 10000);
    yawFlag = false;
  }
  if(stopPitch - startPitch > pitch * 1000){
    randomPitch = random(0,10000);
    pitchFlag = false;
  }
  if(stopRoll - startRoll > randomRollTime * 1000){
    randomRoll = random(0,10000);
    randomRollTime = random(5,20);
    rollFlag = false;
  }
 

  
  
  
    setBarLeds(barLeds);
 
  // put your main code here, to run repeatedly:
  //Serial.println("A0 = " + String(analogRead(A3)) + " A1 = " + String(analogRead(A1)) + " A2 = " + String(analogRead(A2)));



}
void displayNumber(Adafruit_MCP23017 mcp1, int number1, Adafruit_MCP23017 mcp2, int number2, Adafruit_MCP23017 mcp3, int number3) {

  word temp1 = B0, temp2 = B0, temp3 = B0;
  int number[3] = {number1, number2, number3};
  String tempTextNumber[3][4] = {{"", "", "", ""},
    {"", "", "", ""},
    {"", "", "", ""}
  };
  int tempNumber[3][4];

  for (byte j = 0; j < 3; j++) {
    for (byte i = 0; i < 4; i++) {
      tempTextNumber[j][i] = tempTextNumber[j][i] +  returnNumberInString(number[j])[i];
      tempNumber[j][i] = tempTextNumber[j][i].toInt();
    }
  }


  for (byte i = 0; i < 12; i++) {
    bitWrite(temp1, i, sevenSegmentDisplay[tempNumber[0][0]][11 - i]);
    bitWrite(temp2, i, sevenSegmentDisplay[tempNumber[1][0]][11 - i]);
    bitWrite(temp3, i, sevenSegmentDisplay[tempNumber[2][0]][11 - i]);
  }
  bitWrite(temp1, 0, 1);
  bitWrite(temp2, 0, 1);
  bitWrite(temp3, 0, 1);
  mcp1.writeGPIOAB(temp1);
  mcp2.writeGPIOAB(temp2);
  mcp3.writeGPIOAB(temp3);

  delay(s);

  for (byte i = 0; i < 12; i++) {
    bitWrite(temp1, i, sevenSegmentDisplay[tempNumber[0][1]][11 - i]);
    bitWrite(temp2, i, sevenSegmentDisplay[tempNumber[1][1]][11 - i]);
    bitWrite(temp3, i, sevenSegmentDisplay[tempNumber[2][1]][11 - i]);
  }
  bitWrite(temp1, 3, 1);
  bitWrite(temp2, 3, 1);
  bitWrite(temp3, 3, 1);
  mcp1.writeGPIOAB(temp1);
  mcp2.writeGPIOAB(temp2);
  mcp3.writeGPIOAB(temp3);

  delay(s);
  for (byte i = 0; i < 12; i++) {
    bitWrite(temp1, i, sevenSegmentDisplay[tempNumber[0][2]][11 - i]);
    bitWrite(temp2, i, sevenSegmentDisplay[tempNumber[1][2]][11 - i]);
    bitWrite(temp3, i, sevenSegmentDisplay[tempNumber[2][2]][11 - i]);
  }
  bitWrite(temp1, 4, 1);
  bitWrite(temp2, 4, 1);
  bitWrite(temp3, 4, 1);
  mcp1.writeGPIOAB(temp1);
  mcp2.writeGPIOAB(temp2);
  mcp3.writeGPIOAB(temp3);
  delay(s);
  
  for (byte i = 0; i < 12; i++) {
    bitWrite(temp1, i, sevenSegmentDisplay[tempNumber[0][3]][11 - i]);
    bitWrite(temp2, i, sevenSegmentDisplay[tempNumber[1][3]][11 - i]);
    bitWrite(temp3, i, sevenSegmentDisplay[tempNumber[2][3]][11 - i]);
  }
  bitWrite(temp1, 11, 1);
  bitWrite(temp2, 11, 1);
  bitWrite(temp3, 11, 1);
  mcp1.writeGPIOAB(temp2);
  mcp2.writeGPIOAB(temp3);
  mcp3.writeGPIOAB(temp3);
  delay(s);

}

String returnNumberInString(int number) {
  if (number < 10) {
    return "000" + String(number);
  }
  else if (number >= 10 && number < 100) {
    return "00" + String(number);
  }
  else if (number >= 100 && number < 1000) {
    return "0" + String(number);
  }

  return String(number);
}
void setBarLeds(byte leds) {
  word temp = B0;
  mcp3.writeGPIOAB(0x0);
  mcp4.writeGPIOAB(0x0);
  for (byte i = 2; i < 6; i++) {
    digitalWrite(i, LOW);
  }

  if (leds <= 16) {
    for (byte i = 0; i < leds; i++) {
      bitWrite(temp, i, 1);
    }
    mcp3.writeGPIOAB(temp);
  }
  else if (leds > 16 && leds <= 32) {
    mcp3.writeGPIOAB(0xffff);
    for (byte i = 0; i < leds - 16; i++) {
      bitWrite(temp, i, 1);
    }

    mcp4.writeGPIOAB(temp);
  }
  else {
    mcp3.writeGPIOAB(0xffff);
    mcp4.writeGPIOAB(0xffff);
    for (byte i = 0; i < leds - 32; i++) {
      digitalWrite(i + 2, HIGH);
    }
  }
}





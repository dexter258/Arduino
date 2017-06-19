#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp0, mcp1, mcp2, mcp3, mcp4;
byte s = 2;
byte barLeds = 0;
byte pitch = 0;
byte yaw = 0;
int randomIHR, randomAHR, randomABR, randomIHRTime, randomAHRTime, randomABRTime;

long startIHR = 0, stopIHR = 0, startAHR = 0, stopAHR = 0, startoABR = 0, stopABR = 0;
bool IHRFlag = false, AHRFlag = false, ABRFlag = false;

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



  for (byte i = 0; i < 16; i++) {
    mcp0.pinMode(i, OUTPUT);
    mcp0.digitalWrite(i, HIGH);
    mcp1.pinMode(i, OUTPUT);
    mcp1.digitalWrite(i, HIGH);
    mcp2.pinMode(i, OUTPUT);
    mcp2.digitalWrite(i, HIGH);
  }

  randomSeed(analogRead(A0));
  Serial.begin(9600);
  mcp0.digitalWrite(11, LOW);

  randomIHRTime = random(5, 20);
  randomAHRTime = random(5, 20);
  randomABRTime = random(5, 20);
  randomIHR = random(0, 10000);
  randomAHR = random(0, 10000);
  randomABR = random(0, 10000);


}

void loop() {

  displayNumber(mcp0, randomIHR, mcp1, randomAHR, mcp2, randomABR);



  // barLedsPrev = barLeds;
  if (IHRFlag == false) {
    startIHR = millis();
    IHRFlag = true;
  }
  if (AHRFlag == false) {
    startAHR = millis();
    AHRFlag = true;
  }
  if (ABRFlag == false) {
    startABR = millis();
    ABRFlag = true;
  }
  stopABR = stopIHR = stopAHR = millis();

  if (stopIHR - startIHR > randomIHRTime * 1000) {
    randomIHR = random(0, 10000);
    randomIHRTime = random(5, 20);
    IHRFlag = false;
  }
  if (stopAHR - startAHR > randomAHRTime * 1000) {
    randomAHR = random(0, 10000);
    randomAHRTime = random(5, 20);
    AHRFlag = false;
  }
  if (stopABR - startABR > randomABRTime * 1000) {
    randomABR = random(0, 10000);
    randomABRTime = random(5, 20);
    ABRFlag = false;
  }







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


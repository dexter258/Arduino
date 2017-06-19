#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp0, mcp1, mcp2;
#include "PCF8574.h" // Required for PCF8574
extern byte switches[5];
PCF8574 pcf;
word temp0 = B0;
word temp1 = B0;
word temp2 = B0;
word temp3 = B0;
word temp4 = B0;
word temp5 = B0;
word temp6 = B0;
word temp7 = B0;
void setFirstBar(byte number) {
  temp0 = B0;
  if (number <= 2) {
    for (byte i = 0; i < number; i++) {
      bitWrite(temp0, 9 - i, 1);
    }
    mcp0.writeGPIOAB(temp0);
  }
  else {
    bitWrite(temp0, 9, 1);
    bitWrite(temp0, 8, 1);

    for (byte i = 0; i < number - 2; i++) {
      bitWrite(temp0, i, 1);
    }
    mcp0.writeGPIOAB(temp0);
  }
}

void setSecondBar(byte number) {
  temp1 = B0;
  temp2 = B0;
  if (number <= 6) {
    for (byte i = 0; i < number; i++) {
      bitWrite(temp1, 10 + i, 1);
    }
    temp1 = temp0 | temp1;
    mcp0.writeGPIOAB(temp1);
    mcp1.writeGPIOAB(temp2);
  }
  else {
    for (byte i = 10; i < 16; i++) {
      bitWrite(temp1, i, 1);
    }
    temp1 = temp0 | temp1;
    mcp0.writeGPIOAB(temp1);

    for (byte i = 0; i < number - 6; i++) {
      bitWrite(temp2, 7 - i, 1);
    }
    mcp1.writeGPIOAB(temp2);
  }
}

void setThirdBar(byte number) {
  temp3 = B0;
  if ( number <= 4) {
    for (byte i = 0; i < number; i++) {
      bitWrite(temp3, 3 - i, 1);
    }
    temp3 = temp2 | temp3;
    mcp1.writeGPIOAB(temp3);
  }

  else {
    for (byte i = 0; i < 4; i++) {
      bitWrite(temp3, i, 1);
    }

    for (byte i = 0; i < number - 4; i++) {
      bitWrite(temp3, 8 + i, 1);
    }
    temp3 = temp2 | temp3;
    mcp1.writeGPIOAB(temp3);
  }
}

void setFourthBar(byte number) {
  temp4 = B0;
  temp5 = B0;
  if (number <= 2) {
    for (byte i = 0; i < number; i++) {
      bitWrite(temp4, i + 14, 1);
    }

    temp4 = temp2 | temp3 | temp4;

    mcp1.writeGPIOAB(temp4);
    mcp2.writeGPIOAB(temp5);
  }
  else {

    for (byte i = 14; i < 16; i++) {
      bitWrite(temp4, i, 1);
    }
    temp4 = temp2 | temp3 | temp4;
    mcp1.writeGPIOAB(temp4);

    for (byte i = 0; i < number - 2; i++) {
      bitWrite(temp5, 7 - i, 1);
    }
    mcp2.writeGPIOAB(temp5);
  }
}

void setFifthBar(byte number) {

  temp6 = B0;

  if (number <= 8) {
    for (byte i = 0; i < number; i++) {
      bitWrite(temp6, 8 + i, 1);
    }

    temp6 = temp5 | temp6;

    mcp2.writeGPIOAB(temp6);
    pcf.digitalWrite(6, HIGH);
    pcf.digitalWrite(7, HIGH);
  }
  else {
    for (byte i = 8; i < 16; i++) {
      bitWrite(temp6, i, 1);
    }

    temp6 = temp5 | temp6;
    mcp2.writeGPIOAB(temp6);

    pcf.digitalWrite(6, HIGH);
    pcf.digitalWrite(7, HIGH);
    for (byte i = 0; i < number - 8; i++) {
      pcf.digitalWrite(i + 6, LOW);
    }


  }
}

void setBars(byte first, byte second, byte third, byte fourth, byte fifth) {
  setFirstBar(first);
  setSecondBar(second);
  setThirdBar(third);
  setFourthBar(fourth);
  setFifthBar(fifth);
}



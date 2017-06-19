#include "Adafruit_MCP23017.h"
#include <SPI.h>
#include "PCF8574.h" // Required for PCF8574

PCF8574 pcf;

Adafruit_MCP23017 mcp0, mcp1, mcp2, mcp3, mcp4;




void setPyro(byte i) {
  if (i == 0) { // czerwony  nieaktywny
    mcp4.digitalWrite(15, LOW);
    mcp4.digitalWrite(14, HIGH);
    mcp4.digitalWrite(13, HIGH);
  }
  else if (i == 1) { // Niebieski aktywny
    mcp4.digitalWrite(15, HIGH);
    mcp4.digitalWrite(14, HIGH);
    mcp4.digitalWrite(13, LOW);
  }
  else if (i == 2) { // Zielony rozwiązany
    mcp4.digitalWrite(15, HIGH);
    mcp4.digitalWrite(14, LOW);
    mcp4.digitalWrite(13, HIGH);
  }
}


void setLab(byte i) {
  if (i == 0) { // czerwony  nieaktywny
    mcp4.digitalWrite(12, LOW);
    mcp4.digitalWrite(11, HIGH);
    mcp4.digitalWrite(10, HIGH);
  }
  else if (i == 1) { // Niebieski aktywny 13   // czerwony
    mcp4.digitalWrite(12, HIGH);
    mcp4.digitalWrite(11, HIGH);
    mcp4.digitalWrite(10, LOW);
  }
  else if (i == 2) { // Zielony rozwiązany 14  // niebieski
    mcp4.digitalWrite(12, HIGH);
    mcp4.digitalWrite(11, LOW);
    mcp4.digitalWrite(10, HIGH);
  }
}

void setEngine(byte i) {
  if (i == 0) { // czerwony  nieaktywny
    mcp4.digitalWrite(9, LOW);
    mcp4.digitalWrite(8, HIGH);
    mcp4.digitalWrite(7, HIGH);
  }
  else if (i == 1) { // Niebieski aktywny 13   // czerwony
    mcp4.digitalWrite(9, HIGH);
    mcp4.digitalWrite(8, HIGH);
    mcp4.digitalWrite(7, LOW);
  }
  else if (i == 2) { // Zielony rozwiązany 14  // niebieski
    mcp4.digitalWrite(9, HIGH);
    mcp4.digitalWrite(8, LOW);
    mcp4.digitalWrite(7, HIGH);
  }
}

void setSymbols(byte i) {
  if (i == 0) { // czerwony  nieaktywny
    mcp4.digitalWrite(6, LOW);
    mcp4.digitalWrite(5, HIGH);
    mcp4.digitalWrite(4, HIGH);
  }
  else if (i == 1) { // Niebieski aktywny 13   // czerwony
    mcp4.digitalWrite(6, HIGH);
    mcp4.digitalWrite(5, HIGH);
    mcp4.digitalWrite(4, LOW);
  }
  else if (i == 2) { // Zielony rozwiązany 14  // niebieski
    mcp4.digitalWrite(6, HIGH);
    mcp4.digitalWrite(5, LOW);
    mcp4.digitalWrite(4, HIGH);
  }
}

void setGarret(byte i) {
  if (i == 0) { // czerwony  nieaktywny
    mcp4.digitalWrite(3, LOW);
    mcp4.digitalWrite(2, HIGH);
    mcp4.digitalWrite(1, HIGH);
  }
  else if (i == 1) { // Niebieski aktywny 13   // czerwony
    mcp4.digitalWrite(3, HIGH);
    mcp4.digitalWrite(2, HIGH);
    mcp4.digitalWrite(1, LOW);
  }
  else if (i == 2) { // Zielony rozwiązany 14  // niebieski
    mcp4.digitalWrite(3, HIGH);
    mcp4.digitalWrite(2, LOW);
    mcp4.digitalWrite(1, HIGH);
  }
}

void setMemory(byte i) {
  if (i == 0) { // czerwony  nieaktywny
    mcp4.digitalWrite(0, LOW);
    pcf.digitalWrite(0, HIGH);
    pcf.digitalWrite(1, HIGH);
  }
  else if (i == 1) { // Niebieski aktywny 13   // czerwony
    mcp4.digitalWrite(0, HIGH);
    pcf.digitalWrite(0, HIGH);
    pcf.digitalWrite(1, LOW);
  }
  else if (i == 2) { // Zielony rozwiązany 14  // niebieski
    mcp4.digitalWrite(0, HIGH);
    pcf.digitalWrite(0, LOW);
    pcf.digitalWrite(1, HIGH);
  }
}

void setButton(byte i) {
  if (i == 0) { // czerwony  nieaktywny
    pcf.digitalWrite(2, LOW);
    pcf.digitalWrite(3, HIGH);
    pcf.digitalWrite(4, HIGH);
  }
  else if (i == 1) { // Niebieski aktywny 13   // czerwony
    pcf.digitalWrite(2, HIGH);
    pcf.digitalWrite(3, HIGH);
    pcf.digitalWrite(4, LOW);
  }
  else if (i == 2) { // Zielony rozwiązany 14  // niebieski
    pcf.digitalWrite(2, HIGH);
    pcf.digitalWrite(3, LOW);
    pcf.digitalWrite(4, HIGH);
  }
}

void setAbort(byte i) {
  if (i == 0) { // czerwony  nieaktywny
    pcf.digitalWrite(5, LOW);
    pcf.digitalWrite(6, HIGH);
    pcf.digitalWrite(7, HIGH);
  }
  else if (i == 1) { // Niebieski aktywny 13   // czerwony
    pcf.digitalWrite(5, HIGH);
    pcf.digitalWrite(6, HIGH);
    pcf.digitalWrite(7, LOW);
  }
  else if (i == 2) { // Zielony rozwiązany 14  // niebieski
    pcf.digitalWrite(5, HIGH);
    pcf.digitalWrite(6, LOW);
    pcf.digitalWrite(7, HIGH);
  }
}

void setSimon(byte i) {
  if (i == 0) { // czerwony  nieaktywny
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  }
  else if (i == 1) { // Niebieski aktywny 13   // czerwony
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }
  else if (i == 2) { // Zielony rozwiązany 14  // niebieski
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  }
}

void setLedsGame(String info) {
  String temp = "";

  temp += info[1];
  setGarret(temp.toInt());

  temp = "";
  temp += info[2];
  setSymbols(temp.toInt());

  temp = "";
  temp += info[3];
  setEngine(temp.toInt());

  temp = "";
  temp += info[4];
  setLab(temp.toInt());

  temp = "";
  temp += info[5];
  setPyro(temp.toInt());

  temp = "";
  temp += info[6];
  setMemory(temp.toInt());
  
  temp = "";
  temp += info[7];
  setButton(temp.toInt());

  temp="";
  temp+= info[8];
  setAbort(temp.toInt());

  temp="";
  temp+= info[9];
  setSimon(temp.toInt());
}

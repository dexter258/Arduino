Adafruit_MCP23017 mcp7;
bool eventButton[10] = {false, false, false, false, false, false, false, false, false, false};
void initEventPanel() {
  mcp7.begin(7);

  for (byte i = 0; i < 16; i++) {
    if (i < 10) {
      mcp7.pinMode(i, OUTPUT);
      mcp7.digitalWrite(i, LOW);
      

    }
    else
      mcp7.pinMode(i, INPUT_PULLUP);
      mcp7.digitalWrite(i, HIGH);
  }
}

void readEventButtons(String info) {
  String temp;
  for (byte i = 0; i < 10; i++) {
    temp ="";
    if (i < 5) {
      eventButton[i] = bool(!mcp7.digitalRead(i + 10));
      mcp7.digitalWrite(4-i, eventButton[i]);
    }
   
    else{
      temp += info[i+7];
      eventButton[i] = bool(temp.toInt());
      mcp7.digitalWrite(14-i, eventButton[i]);
    }
  }
}


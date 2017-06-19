#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 5; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'F','G','#','*'},
  {'1','2','3','U'},
  {'4','5','6','D'},
  {'7','8','9','Q'},
  {'R','0','L','E'}
};
byte rowPins[ROWS] = {39, 37, 35, 33, 31}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {23, 25, 27, 29}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


LiquidCrystal lcd_red(12, 7, 5, 4, 3, 2);


void initRedundant() {
  pinMode(A3, INPUT_PULLUP);
  //digitalWrite(A3, HIGH);
  lcd_red.begin(16,2);
 // lcd_red.setCursor(0,0);
 // lcd_red.print("Witaj");
}

bool readRKey() {
  return digitalRead(A3);
}



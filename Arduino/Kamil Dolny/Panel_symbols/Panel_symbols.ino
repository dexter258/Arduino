

#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin



#include <Adafruit_TFTLCD.h>
// Assign human-readable names to some common 16-bit color values:

#include "logic.h"
#include <TouchScreen.h>
uint8_t YP = A1;  // must be an analog pin, use "An" notation!
uint8_t XM = A2;  // must be an analog pin, use "An" notation!
uint8_t YM = 7;   // can be a digital pin
uint8_t XP = 6;   // can be a digital pin
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
TSPoint tp;
#define MINPRESSURE 20
#define MAXPRESSURE 1000
bool resetGame = false;

void setup(void) {
  init_TFTLCD();
  initRandomImage();
  tft.fillScreen(WHITE);
  tft.setRotation(1);
  ts = TouchScreen(XP, YP, XM, YM, 300);
}



bool startGame = false;

void loop(void) {
  String msg;
  while (1) {

    msg = "";
    resetGame = false;
    if (Serial.available() > 0) { // Pobieranie danych z portu szeregowego
      while (Serial.available() > 0) { // pobieraj tak długo aż bufor będzie pusty
        msg += char(Serial.read());
        delay(5);
      }
      searchFrame(msg); // Przeszukaj ramke
    }

    if (startGame == true)
    { tft.fillScreen(WHITE);
      randomImage();
      bmpDraw(filesName(column, image[0]), 0, 0); // pierwszy
      bmpDraw(filesName(column, image[1]), 240, 0); // drugi
      bmpDraw(filesName(column, image[2]), 0, 160); // trzeci
      bmpDraw(filesName(column, image[3]), 240, 160); // czwarty

      do {
        msg = "";

        if (Serial.available() > 0) { // Pobieranie danych z portu szeregowego
          while (Serial.available() > 0) { // pobieraj tak długo aż bufor będzie pusty
            msg += char(Serial.read());
            delay(5);
          }
          searchFrame(msg); // Przeszukaj ramke
        }

        readPanelPosition();
         if(fail == true){
    Serial.println("E");
         }
         fail = false;
        if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {
          delay(80);
          readPanelPosition();
          if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {
            //Serial.println("X = " + String(tp.y) + " Y = " + String(tp.x));
            selectedSequence(map(tp.y, 940, 150, 0, 480), map(tp.x, 210, 860, 0 , 320));
          }
        }
        while (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) readPanelPosition();
      } while (pass != 4 && resetGame == false);
      startGame = false;
      pass = 0;
      stepInGame = 0;
      tft.fillScreen(WHITE);
      if(resetGame == false) {
        Serial.println("P");
        bmpDraw("solved.bmp", 0, 0); // czwarty
        
      }
    }

  }

}

void searchFrame(String temp) {
  if (temp[0] == '1')
    startGame = true;
    if(temp[0] =='R'){
      startGame = false;
      resetGame = true;
    }
}
void readPanelPosition() {
  tp = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  pinMode(XP, OUTPUT);
  pinMode(YM, OUTPUT);
}
// Standard Adafruit tests.  will adjust to screen size



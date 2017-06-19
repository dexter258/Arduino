#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
int start=0;
int p=0;
SoftwareSerial RFID = SoftwareSerial(4,5);
#define PIXEL_PIN    6    // Digital IO pin connected to the NeoPixels.

#define PIXEL_COUNT 24
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
bool oldState = HIGH;
int showType = 0;
void setup()  
{
   strip.begin();
  strip.show();
  Serial.begin(9600);
  Serial.println("Serial Ready");

  RFID.begin(9600);
  Serial.println("RFID Ready");
}

char c;
String msg;

void loop(){

  while(RFID.available()>0){
    c=RFID.read(); 
    msg += c;
  }

  if (msg.length() > 10) {
    msg = msg.substring(1,13);
    Serial.println(msg);
 if ((msg == "A9001BE2FFAF") && (start!=2)) {
      start=1;
    }
     if ((msg == "A80063768E33")&& (start!=4)) {
      start=3;
     }
    msg = "";
  }
  
  
  if (start==1)
{
   colorWipe(strip.Color(0, 0, 0), 50);    // Black/off
           
    colorWipe(strip.Color(255, 0, 0), 50);  // Red
        
     colorWipe(strip.Color(0, 255, 0), 50);  // Green
         
   colorWipe(strip.Color(0, 0, 255), 50);  // Blue
           
     theaterChase(strip.Color(127, 127, 127), 50); // White
      
 theaterChase(strip.Color(127,   0,   0), 50); // Red
          
 theaterChase(strip.Color(  0,   0, 127), 50); // Blue
 rainbow(10);
 rainbowCycle(1);
start=2;
}
if (start==2)
  {   
    if (p==0)   
      {
        rainbowCycle(8);
        p=1;    
      }
  }
  
  if (start==3)
{
  rainbowCycle(1);
  //rainbowCycle(20);
   // delay(10000);
    colorWipe(strip.Color(0, 0, 0), 50);    // Black/off  
   start=4; 
}
  
    delay(300);
}



// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

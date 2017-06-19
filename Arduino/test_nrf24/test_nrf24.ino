#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <Wire.h>
#include "Adafruit_MCP23017.h"
int msg[1];
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int SW1 = 0;
int SW2 = 1;
int SW3 = 2;
int SW4 = 3;
int SW5 = 4;
int SW6 = 5;
int SW7 = 6;
int SW8 = 7;
int SW9 = 8;
int SW0 = 9;
Adafruit_MCP23017 mcp;
boolean wcisniety=false;
void setup()
{
 Serial.begin(9600);
 radio.begin();
 radio.openWritingPipe(pipe);
  mcp.begin();      // use default address 0
mcp.pinMode(SW0, INPUT);
  mcp.pinMode(SW1, INPUT);
    mcp.pinMode(SW2, INPUT);
      mcp.pinMode(SW3, INPUT);
       mcp.pinMode(SW4, INPUT);
    mcp.pinMode(SW5, INPUT);
      mcp.pinMode(SW6, INPUT);
        mcp.pinMode(SW7, INPUT);
    mcp.pinMode(SW8, INPUT);
      mcp.pinMode(SW9, INPUT);
  pinMode(13, OUTPUT);  // use the p13 LED as debugging
}

void loop()
{
  if (wcisniety==false){
 if (mcp.digitalRead(SW1) == HIGH)

{
 msg[0] = 50;
 wcisniety=true;
}
 if (mcp.digitalRead(SW2) == HIGH)

{
 msg[0] = 100;
 wcisniety=true;
}
 if (mcp.digitalRead(SW3) == HIGH)

{
 msg[0] = 150;
  wcisniety=true;

}
if (mcp.digitalRead(SW4) == HIGH)
{
 msg[0] = 200;
  wcisniety=true;

}
if (mcp.digitalRead(SW5) == HIGH)
{
 msg[0] = 250;
  wcisniety=true;

}
if (mcp.digitalRead(SW6) == HIGH)
{
 msg[0] = 300;
  wcisniety=true;

}
if (mcp.digitalRead(SW7) == HIGH)
{
 msg[0] = 350;
  wcisniety=true;

}
if (mcp.digitalRead(SW8) == HIGH)
{
 msg[0] = 400;
  wcisniety=true;

}
if (mcp.digitalRead(SW9) == HIGH)
{
 msg[0] = 450;
  wcisniety=true;

}
if (mcp.digitalRead(SW0) == HIGH)
{
 msg[0] = 999;
  wcisniety=true;

}
  }
  if ((mcp.digitalRead(SW3) == LOW)&&(mcp.digitalRead(SW2) == LOW)&&(mcp.digitalRead(SW1) == LOW)&&(mcp.digitalRead(SW6) == LOW)&&(mcp.digitalRead(SW5) == LOW)&&(mcp.digitalRead(SW4) == LOW)&&(mcp.digitalRead(SW9) == LOW)&&(mcp.digitalRead(SW8) == LOW)&&(mcp.digitalRead(SW7) == LOW)&&(mcp.digitalRead(SW0) == LOW)&&(wcisniety==true)){
     radio.write(msg, 2);   
     delay(1000);
       Serial.println(msg[0]);
     msg[0]=0;
      radio.write(msg, 2);
    
wcisniety=false;  
}


}

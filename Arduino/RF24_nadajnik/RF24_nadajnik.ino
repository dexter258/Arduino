#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <Wire.h>
#include "Adafruit_MCP23017.h"
int msg[1];
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int SW1 = 7;
int SW2 = 6;
Adafruit_MCP23017 mcp;
boolean wysylaj=false;

void setup()
{
 Serial.begin(9600);
 radio.begin();
 radio.openWritingPipe(pipe);
  mcp.begin();      // use default address 0

  mcp.pinMode(0, INPUT);
  pinMode(13, OUTPUT);  // use the p13 LED as debugging
}

void loop()
{
  int k=0;
  if  (mcp.digitalRead(0)==HIGH)
{
  wysylaj=true;
 msg[0] = 111;
 delay(10);
}
  if  (mcp.digitalRead(1)==HIGH)
  {
    wysylaj=true;
 msg[1] = 222;
  delay(10);
}
  if  (mcp.digitalRead(2)==HIGH)
  {
    wysylaj=true;
 msg[0] = 333;

  delay(10);
}
  if  (mcp.digitalRead(3)==HIGH)
  {
    wysylaj=true;
 msg[0] = 444;

  delay(10);
}
  if  (mcp.digitalRead(4)==HIGH)
{
  wysylaj=true;
 msg[0] = 555;

  delay(10);
}
  if  (mcp.digitalRead(5)==HIGH)
  {
    wysylaj=true;
 msg[0] = 666;

  delay(10);
}
  if  (mcp.digitalRead(6)==HIGH)
  {
    wysylaj=true;
 msg[0] = 777;

  delay(10);
}
  if  (mcp.digitalRead(7)==HIGH)
  {
    wysylaj=true;
 msg[0] = 888;
 
  delay(10);
}

for (int i=0;i<8;i++)
{
  if (mcp.digitalRead(i)==LOW){
    k++;
  }
}

if ((k==7)&& (wysylaj==true)){
  radio.write(msg, 1);
  wysylaj=false;
}
  
}

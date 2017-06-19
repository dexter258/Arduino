#include <PCF8574.h>
#include <Wire.h>

PCF8574 expander;

void setup()
{
  expander.begin(0x38);
  expander.pinMode(4, OUTPUT);
}

void loop()
{
  expander.digitalWrite(4, LOW);
  delay(1000);
  expander.digitalWrite(4, HIGH);
  delay(1000);
}

#include <PCF8574.h>
#include <Wire.h>

PCF8574 expander;

void setup()
{
  expander.begin(0x38);
  expander.pinMode(4, OUTPUT);
  expander.pinMode(3, INPUT_PULLUP);
expander.digitalWrite(4, HIGH);
// expander.pullDown(3);
}

void loop()
{
  if (expander.digitalRead(3)==LOW)
  {
  expander.digitalWrite(4, LOW);
  delay(1000);
  expander.digitalWrite(4, HIGH);
  }
}

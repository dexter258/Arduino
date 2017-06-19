#include <Wire.h>
#include"RTClib.h"

RTC_DS1307 RTC;

void setup()
{
   Serial.begin(9600);
   Wire.begin();
   RTC.begin();

   if(!RTC.isrunning())
   {
      Serial.println("RTC is NOT running!");
      // following line sets the RTC to the date & time this sketch was compiled
      RTC.adjust(DateTime(__DATE__,__TIME__));
   }
}

void loop()
{
   DateTimenow=RTC.now();
   delay(3000);
}

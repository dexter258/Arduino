#include <stdio.h>
#include <DS1302.h>


namespace {
  

const int kCePin   = 5;  // Chip Enable
const int kIoPin   = 6;  // Input/Output
const int kSclkPin = 7;  // Serial Clock
DS1302 rtc(kCePin, kIoPin, kSclkPin);

String dayAsString(const Time::Day day) {
  switch (day) {
    case Time::kSunday: return "Sunday";
    case Time::kMonday: return "Monday";
    case Time::kTuesday: return "Tuesday";
    case Time::kWednesday: return "Wednesday";
    case Time::kThursday: return "Thursday";
    case Time::kFriday: return "Friday";
    case Time::kSaturday: return "Saturday";
  }
  return "(unknown day)";
}

void printTime() {
  // Get the current time and date from the chip.
  Time t = rtc.time();

  // Name the day of the week.
  const String day = dayAsString(t.day);

  // Format the time and date and insert into the temporary buffer.
  char buf[50];
  snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d %02d:%02d:%02d",
           day.c_str(),
           t.yr, t.mon, t.date,
           t.hr, t.min, t.sec);

  // Print the formatted string to serial so we can see the time.
 // const String godz = dayAsString(t.h);
 // godz=t.hr.toInt();
  Serial.println(buf);
    if (t.hr>13 && t.hr<15)
  {
    Serial.println("dzien");
  }
  else Serial.println("noc");
  
}
}  //namespace

unsigned long previousMillis = 0;      

const long interval = 1000;

int ledPin=8;
String readString;
int kroki,kroki1,kroki2;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);

 rtc.writeProtect(false);
   rtc.halt(false);

 
   Time t(2016, 10, 6, 14, 59, 20, Time::kThursday);
   rtc.time(t);


}
void loop(){
  




   
unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
 printTime();
    previousMillis = currentMillis;

 }


  
  while (Serial.available()){
    delay(3);
    char c = Serial.read();
    readString+=c;
  }

  if (readString.length()>0){
      kroki=readString.toInt();
  if (kroki>0 && kroki<101){
    kroki1=kroki;
  }
   if (kroki>100 && kroki<201){
    kroki2=kroki;
  }
    Serial.print(readString);
    Serial.print("   kroki przeliczone na int: ");
     Serial.println(kroki);
    if (readString=="1")
    {
      digitalWrite(ledPin,HIGH);
    }
      if (readString=="100")
    {
      digitalWrite(ledPin,LOW);
    }
   
    readString="";
  }
    
  }



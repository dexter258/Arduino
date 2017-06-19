#include <SoftwareSerial.h>
#include <Servo.h>
Servo serwo;

int led = 8;
int state;
String readString;
void setup() {    
serwo.attach(9);  
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){     
      state = Serial.read(); 
     while  (Serial.available())
     {
      char c =Serial.read();
      readString += c;
     }
   
      if (readString.length()>0)
      {
        Serial.println(readString);
        if (readString=="on")
        { digitalWrite(led,HIGH);
        }
        if (readString=="off")
        {digitalWrite(led,LOW);
        }
        readString="";
      }

if (state!=120){
Serial.println(state);
serwo.write(state);  
}
  }
  delay(200);               // wait for 100ms
  
  //For debugging purpose
  //Serial.println(state);
}

// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 
//#include "Timer.h"
#include <Servo.h> 
#define led1 5 
#define led2 6 
#define led3 7 
#define led4 8 
#define led5 4 
#define led6 3 
int interval=100;
unsigned long previousMillis=0;
Servo myservo; 
Servo serwo;// create servo object to control a servo 
 
int pos = 0;     // variable to read the value from the analog pin 
  int k=0;
void setup() 
{ 
  myservo.attach(9); 
 serwo.attach(10);
 pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
   pinMode(led3,OUTPUT);
    pinMode(led4,OUTPUT);
    pinMode(led5,OUTPUT);
    pinMode(led6,OUTPUT);
      digitalWrite(led1, LOW); 
      digitalWrite(led2,LOW);
     digitalWrite(led3, LOW); 
    digitalWrite(led4, LOW);  
     digitalWrite(led5, LOW); 
    digitalWrite(led6, LOW);
//digitalWrite(8,HIGH); // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
  unsigned long currentMillis = millis();
 for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {      
      if (pos==90) {
      
       digitalWrite(led1, !digitalRead(led1)); 
      digitalWrite(led2, !digitalRead(led2));
     digitalWrite(led3, !digitalRead(led3)); 
    digitalWrite(led4, !digitalRead(led4)); 
  digitalWrite(led5, !digitalRead(led5)); 
    digitalWrite(led6, !digitalRead(led6));     
   }
  k=180-pos;
     serwo.write(pos);     // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(4);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {     
        if (pos==90) {
       digitalWrite(led1, !digitalRead(led1)); 
      digitalWrite(led2, !digitalRead(led2));
     digitalWrite(led3, !digitalRead(led3)); 
    digitalWrite(led4, !digitalRead(led4));   
    digitalWrite(led5, !digitalRead(led5)); 
    digitalWrite(led6, !digitalRead(led6)); 
   }
  k=180-pos;
     serwo.write(pos);     
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(4); 
  }    // waits for the servo to get there 
} 

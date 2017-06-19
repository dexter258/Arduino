#include <Servo.h>  //Load Servo Library
int trigPin=13; //Sensor Trip pin connected to Arduino pin 13
int echoPin=11;  //Sensor Echo pin connected to Arduino pin 11
float pingTime;  //time for ping to travel from sensor to target and return
float targetDistance; //Distance to Target in inches
float speedOfSound=776.5; //Speed of sound in miles per hour when temp is 77 degrees.
float servoAngle; //V]-]]ariable for the value we want to set servo to.
int led=8;
int ruch=9;
int start=0;
int val;
int przelacznik=5;
int potpin = 1; 
Servo serwo;  //Create a servo object called myPointer

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led,OUTPUT);
  pinMode(ruch,INPUT);
  pinMode(przelacznik,INPUT);
 serwo.attach(6);
   serwo.write(60);
   delay(1000);
   serwo.detach();
}

void loop() {
  // put your main code here, to run repeatedly: 
              // 
  digitalWrite(trigPin, LOW); //Set trigger pin low
  delayMicroseconds(9000); //Let signal settle
  digitalWrite(trigPin, HIGH); //Set trigPin high
  delayMicroseconds(15); //Delay in high state
  digitalWrite(trigPin, LOW); //ping has now been sent
  delayMicroseconds(10); //Delay in low state
  
  pingTime = pulseIn(echoPin, HIGH);  //pingTime is presented in microceconds
  pingTime=pingTime/1000000; //convert pingTime to seconds by dividing by 1000000 (microseconds in a second)
  pingTime=pingTime/3600; //convert pingtime to hourse by dividing by 3600 (seconds in an hour)
  targetDistance= speedOfSound * pingTime;  //This will be in miles, since speed of sound was miles per hour
  targetDistance=targetDistance/2; //Remember ping travels to target and back from target, so you must divide by 2 for actual target distance.
  targetDistance= targetDistance*63360;    //Convert miles to inches by multipling by 63360 (inches per mile)
  if ((targetDistance<=4) && (digitalRead(ruch)==HIGH) && (start==0) && (digitalRead(przelacznik)==LOW))
  {
    serwo.attach(6);
    delay(40);
    digitalWrite(led,HIGH);
      serwo.write(170);
 
  delay(10000); 
  serwo.detach();
  }
   else
  {
    digitalWrite(led,LOW);
  }
  if (digitalRead(przelacznik)==HIGH)
  {
    serwo.attach(6);
    delay(40);
    val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
    val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
    serwo.write(val);                  // sets the servo position according to the scaled value 
    delay(15);
    serwo.detach();
    start=0;
  }

}

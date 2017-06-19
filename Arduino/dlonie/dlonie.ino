//#include<Timer.h>
//#include<Servo.h>
//Servo serwo;
#define led1 4 
#define led2 5
unsigned long time;
unsigned long l;
int sensorPin = A0;    // select the input pin for the potentiometer
int sensorPin2 = A4;
int buzzer = 6;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;
int otwieranie=0;

void setup() {
 //serwo.attach(9);
    Serial.begin(9600);
  pinMode(buzzer, OUTPUT); 
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
// serwo.write(14);
}

void loop() {
 
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);    
  sensorValue2 = analogRead(sensorPin2); 
  // turn the ledPin on
 // Serial.print(sensorValue);
     Serial.println(sensorValue);
       Serial.print(" - ");
            Serial.println(sensorValue2);
      // delay(1000);

    
 /*if ((sensorValue>=900)&&(sensorValue2<=300))
 {
   otwieranie=1;
   digitalWrite(led1,HIGH);
   digitalWrite(led2,HIGH);
 }
 */
 /*else 
 {
     digitalWrite(led1,LOW);
     digitalWrite(led2,LOW);
     otwieranie=0;
 }
 
   if  (sensorValue>=900)
 {
   digitalWrite(led1,HIGH);
  
 }
else
 {
    digitalWrite(led1,LOW);
    otwieranie=0;
 }
  
  if  (sensorValue2<=300)
 {
   digitalWrite(led2,HIGH);
  
 }
else
 {
    digitalWrite(led2,LOW);
    otwieranie=0;
 }
 */
 while ((sensorValue>=900)&&(sensorValue2<=300))
 {
  delay(1000);
 
   digitalWrite(buzzer,HIGH);
   delay(800);
   digitalWrite(buzzer,LOW);
    while ((sensorValue>=900)&&(sensorValue2<=300))
 {
   delay(1500);
     digitalWrite(buzzer,HIGH);
   delay(800);
   digitalWrite(buzzer,LOW);
   delay(1200);
    while ((sensorValue>=900)&&(sensorValue2<=300))
 {
     digitalWrite(buzzer,HIGH);
   delay(800);
   digitalWrite(buzzer,LOW);
   delay(1000);
     digitalWrite(buzzer,HIGH);
   delay(800);
   digitalWrite(buzzer,LOW);
   delay(800);
     digitalWrite(buzzer,HIGH);
   delay(800);
   digitalWrite(buzzer,LOW);
   delay(600);
   
     digitalWrite(buzzer,HIGH);
   delay(800);
   digitalWrite(buzzer,LOW);
   delay(500);
    sensorValue = analogRead(sensorPin);    
  sensorValue2 = analogRead(sensorPin2); 
  //delay(3000);
     //serwo.write(120);
     delay(500);
     digitalWrite(led1,HIGH);
     delay(5000);
   //  serwo.write(14);
     
 }}
 }
 
}
  

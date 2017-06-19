
#include<Servo.h>
Servo serwo;

#define buzzerX 8
#define czerwony 2
#define zielony 4

int buzzer = 7;      
int sensorValue = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;
int otwieranie=0;
int l1=0;
int l2=0;
void setup() {
 serwo.attach(9);
    Serial.begin(9600);
  pinMode(buzzer, OUTPUT); 
  pinMode(buzzerX,OUTPUT);

  pinMode(czerwony,INPUT);
  pinMode(zielony,INPUT);
 serwo.write(120);
}

void loop() {

  if  (digitalRead(zielony)==HIGH)
 {
   if (l1==0)
   {
   digitalWrite(buzzerX,HIGH);
   delay(1000);
   digitalWrite(buzzerX,LOW);
   l1=1;
   }
 }
else
 {
    digitalWrite(buzzerX,LOW);
    l1=0;
    
 }
  
  if  (digitalRead(czerwony)==LOW)
 {
   if (l2==0)
   {
   digitalWrite(buzzerX,HIGH);
   delay(1000);
   digitalWrite(buzzerX,LOW);
   l2=1;
   }
 }
else
 {
    digitalWrite(buzzerX,LOW);
    l2=0;
 }
 
 while (((digitalRead(zielony)==HIGH))&&(digitalRead(czerwony)==LOW))
 {
  delay(1000);
  //sensorValue = analogRead(sensorPin);    
 // sensorValue2 = analogRead(sensorPin2); 
   digitalWrite(buzzer,HIGH);
   delay(800);
    digitalWrite(buzzer,LOW);
  while (((digitalRead(zielony)==HIGH))&&(digitalRead(czerwony)==LOW))
 {
  
   delay(1500);
 while (((digitalRead(zielony)==HIGH))&&(digitalRead(czerwony)==LOW))
 {
     digitalWrite(buzzer,HIGH);
   delay(800);
   digitalWrite(buzzer,LOW);
  while (((digitalRead(zielony)==HIGH))&&(digitalRead(czerwony)==LOW))
 {
   delay(1200);
  while (((digitalRead(zielony)==HIGH))&&(digitalRead(czerwony)==LOW))
 {
     digitalWrite(buzzer,HIGH);
   delay(800);
   digitalWrite(buzzer,LOW);
  while (((digitalRead(zielony)==HIGH))&&(digitalRead(czerwony)==LOW))
{
   delay(1000);
  while (((digitalRead(zielony)==HIGH))&&(digitalRead(czerwony)==LOW))
{
     digitalWrite(buzzer,HIGH);
   delay(800);
   digitalWrite(buzzer,LOW);
   while (((digitalRead(zielony)==HIGH))&&(digitalRead(czerwony)==LOW))
 {
   delay(800);
  while (((digitalRead(zielony)==HIGH))&&(digitalRead(czerwony)==LOW))
{
     digitalWrite(buzzer,HIGH);
   delay(800);
   digitalWrite(buzzer,LOW);
  while (((digitalRead(zielony)==HIGH))&&(digitalRead(czerwony)==LOW))
 {
   delay(600);
   while (((digitalRead(zielony)==HIGH))&&(digitalRead(czerwony)==LOW))
{
     digitalWrite(buzzer,HIGH);
   delay(800);
   digitalWrite(buzzer,LOW);
  while (((digitalRead(zielony)==HIGH))&&(digitalRead(czerwony)==LOW))
 {
   delay(500);
   
   
  while (((digitalRead(zielony)==HIGH))&&(digitalRead(czerwony)==LOW))
 {
     digitalWrite(buzzer,HIGH);
   delay(800);
   digitalWrite(buzzer,LOW);
 while (((digitalRead(zielony)==HIGH))&&(digitalRead(czerwony)==LOW))
 {
   delay(300);
   
   
 while (((digitalRead(zielony)==HIGH))&&(digitalRead(czerwony)==LOW))
 {
  
 while (((digitalRead(zielony)==HIGH))&&(digitalRead(czerwony)==LOW))
 {
   delay(500);
   while (((digitalRead(zielony)==HIGH))&&(digitalRead(czerwony)==LOW))
 {
    
     delay(3000);
      serwo.write(14);
     delay(5000);
   //  serwo.write(14);
     
 }
 }
 }
 }
 }
 }
 }
 }
 }
 }
 }
 }
 }
 }
 }
 }
 }
}

 


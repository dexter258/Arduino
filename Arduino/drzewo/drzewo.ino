
#include <Servo.h> 
 
Servo serwo;
#define ruch 8
int start=0;
void setup() {                
  pinMode(ruch, INPUT);
serwo.attach(9);  
 serwo.write(10);
}
void loop() {
  if (digitalRead(ruch)==HIGH)
  {
    delay(1000);
    start=1;
  }
  if (start==1)
  {
    serwo.write(120);
    delay(2000);
    serwo.write(10);
    start=0;
  }
}

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h> 
 
Servo myservo;
Servo servo;
LiquidCrystal_I2C lcd(0x20, 16, 2);
int polaczenie_przewodow=0;
#define przewody_1 1
#define przewody_2 2
#define pasek_led 8
int pos;
void setup()
{
 pinMode(przewody_1,INPUT);
  pinMode(przewody_2,INPUT);
   pinMode(pasek_led,OUTPUT);
	lcd.begin();
 
 lcd.setCursor ( 1, 0 );
    lcd.print("!!! AWARIA !!!");
  lcd.setCursor ( 0, 1 );
   lcd.print("PODLACZ PRZEWODY");
  digitalWrite(pasek_led,HIGH);
  
  myservo.attach(9);
  myservo.write(0);
    servo.attach(10);
    servo.write(0);
}

void loop()
{
for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);   
    servo.write(pos);// tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);  
    servo.write(pos);// tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

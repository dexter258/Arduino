#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h> 
 
Servo myservo;
Servo servo;
#define BACKLIGHT_PIN 3
LiquidCrystal_I2C lcd(0x20,2,1,0,4,5,6,7);
int polaczenie_przewodow=0;
#define przewody_1 1
#define przewody_2 2
#define pasek_led 8
void setup ()
{
  pinMode(przewody_1,INPUT);
  pinMode(przewody_2,INPUT);
   pinMode(pasek_led,OUTPUT);
  lcd.begin(16,2);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  
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

void loop ()
{
  if ((digitalRead(przewody_1)==HIGH) && (digitalRead(przewody_2)==HIGH))
  {
    
    if (polaczenie_przewodow==0)
    {
    lcd.clear();
    delay(2000);
     lcd.setBacklight(LOW);
     digitalWrite(pasek_led,LOW);
  
    delay(5000);
     myservo.write(180);
     servo.write(180);
     delay(5000);
    polaczenie_przewodow=1;
    }
     lcd.setBacklight(HIGH);
     lcd.setCursor ( 1, 0 );
    lcd.print("!!! UWAGA !!!");
    
     lcd.setCursor ( 2, 1 );
   lcd.print("BRAK PALIWA");
  }
 
}

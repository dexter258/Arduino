#include <LiquidCrystal_I2C.h>


#include <Wire.h>



#define BACKLIGHT_PIN 3
LiquidCrystal_I2C lcd(0x20,2,1,0,4,5,6,7);
LiquidCrystal_I2C lcd2(0x38,2,1,0,4,5,6,7);
void setup ()
{
  lcd.begin(16,2);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  
  lcd.home();
  lcd.print("No Escape");
  
  lcd2.begin(16,2);
  lcd2.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd2.setBacklight(HIGH);
  
  lcd2.home();
  lcd2.print("Jestem NAJLEPSZY");
  
  
}

void loop ()
{
  lcd.setCursor(0,1);
  lcd.print(millis()/10);
  lcd2.setCursor(0,1);
  lcd2.print(random(7));
  delay(500);
}

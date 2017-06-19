#include <LiquidCrystal.h>

LiquidCrystal lcd_Info(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd_additional(12, 10, 5, 4, 3, 2);
 
 
void initInfoPanel()
{
  lcd_Info.begin(16, 2);
  //lcd_Info.setCursor(0,0);
  //lcd_Info. print("Test");
  lcd_additional.begin(16, 2);
 
}

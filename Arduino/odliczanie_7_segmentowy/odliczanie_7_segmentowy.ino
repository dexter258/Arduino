#include <PCF8574.h>
#include <Wire.h>
#include "Timer.h"
Timer t;
PCF8574 expander;
PCF8574 expander2;
boolean ON=LOW;
boolean OFF=HIGH;
int i=30;
int a=10;
int b=10;
int wlacz=0;
int koniec=0;
int buzzer=6;
int przekaznik=4;
void setup()
{
  Serial.begin(9600);
  int tickEvent = t.every(1000, odliczanie);   
  pinMode(8, INPUT);
  pinMode(10, INPUT);
  pinMode(9, OUTPUT);
  pinMode(przekaznik, OUTPUT);
  expander.begin(0x38);
     expander.pinMode(0, OUTPUT);
     expander.pinMode(1, OUTPUT);
     expander.pinMode(2, OUTPUT);
     expander.pinMode(3, OUTPUT);
     expander.pinMode(4, OUTPUT);
     expander.pinMode(5, OUTPUT);
     expander.pinMode(6, OUTPUT);
     expander.pinMode(7, OUTPUT);
     
     expander2.begin(0x39);
     expander2.pinMode(0, OUTPUT);
     expander2.pinMode(1, OUTPUT);
     expander2.pinMode(2, OUTPUT);
     expander2.pinMode(3, OUTPUT);
     expander2.pinMode(4, OUTPUT);
     expander2.pinMode(5, OUTPUT);
     expander2.pinMode(6, OUTPUT);
     expander2.pinMode(7, OUTPUT);
     digitalWrite(przekaznik,LOW);
}

void loop()
{
 if (digitalRead(10)==HIGH)
 { 
   i=30;
   a=10;
   b=10;
   koniec=0;
   
   digitalWrite(przekaznik,LOW);
   wlacz=0;
 }
  if (digitalRead(8)==HIGH)
  {
    if (wlacz==0)
    {
    digitalWrite(przekaznik,HIGH);
    delay(1000);
    wlacz=1;
    }
   t.update();

  }
  if (( (i==20) || (i==15) || (i==10) || (i==8) || (i==6)  || (i==4) || (i==3) || (i==2) || (i==1)) &&  (digitalRead(8)==HIGH))
  {
      tone(buzzer,100,50);
  }
  if (i==0)
  {
    digitalWrite(9,HIGH);
    if (koniec==0)
    {
      tone(buzzer,1000,7000);
      koniec=1;  
    }
  }
  else 
  {
    digitalWrite(9,LOW);
  }
     Serial.println(i); 
     Serial.println(a);
 Serial.println(b);
switch(a) 
{
  case 0:
  {
  expander2.digitalWrite(0, ON);
  expander2.digitalWrite(1, ON);
  expander2.digitalWrite(2, ON);
  expander2.digitalWrite(3, OFF);
  expander2.digitalWrite(4, OFF);
  expander2.digitalWrite(5, ON);
  expander2.digitalWrite(6, ON);
  expander2.digitalWrite(7, ON);
  }
  break;
//JEDEN
  case 1:
  {
  expander2.digitalWrite(0, OFF);
  expander2.digitalWrite(1, OFF);
  expander2.digitalWrite(2, ON);
  expander2.digitalWrite(3, OFF);
  expander2.digitalWrite(4, OFF);
  expander2.digitalWrite(5, OFF);
  expander2.digitalWrite(6, OFF);
  expander2.digitalWrite(7, ON);
  }
  break;
 //DWA
  case 2:
  {
  expander2.digitalWrite(0, ON);
  expander2.digitalWrite(1, ON);
  expander2.digitalWrite(2, OFF);
  expander2.digitalWrite(3, OFF);
  expander2.digitalWrite(4, ON);
  expander2.digitalWrite(5, OFF);
  expander2.digitalWrite(6, ON);
  expander2.digitalWrite(7, ON);
  }
  break;
//TRZY
  case 3:
  {
  expander2.digitalWrite(0, OFF);
  expander2.digitalWrite(1, ON);
  expander2.digitalWrite(2, ON);
  expander2.digitalWrite(3, OFF);
  expander2.digitalWrite(4, ON);
  expander2.digitalWrite(5, OFF);
  expander2.digitalWrite(6, ON);
  expander2.digitalWrite(7, ON);  
  }
  break;
  //CZTERY
  case 4:
  {
  expander2.digitalWrite(0, OFF);
  expander2.digitalWrite(1, OFF);
  expander2.digitalWrite(2, ON);
  expander2.digitalWrite(3, OFF);
  expander2.digitalWrite(4, ON);
  expander2.digitalWrite(5, ON);
  expander2.digitalWrite(6, OFF);
  expander2.digitalWrite(7, ON);
  }
  break;
//PIEC
  case 5:
  {
  expander2.digitalWrite(0, OFF);
  expander2.digitalWrite(1, ON);
  expander2.digitalWrite(2, ON);
  expander2.digitalWrite(3, OFF);
  expander2.digitalWrite(4, ON);
  expander2.digitalWrite(5, ON);
  expander2.digitalWrite(6, ON);
  expander2.digitalWrite(7, OFF);
  }
  break;
//SZESC
  case 6:
  {
  expander2.digitalWrite(0, ON);
  expander2.digitalWrite(1, ON);
  expander2.digitalWrite(2, ON);
  expander2.digitalWrite(3, OFF);
  expander2.digitalWrite(4, ON);
  expander2.digitalWrite(5, ON);
  expander2.digitalWrite(6, ON);
  expander2.digitalWrite(7, OFF); 
  }
  break;
//SIEDEM
  case 7:
  {
  expander2.digitalWrite(0, OFF);
  expander2.digitalWrite(1, OFF);
  expander2.digitalWrite(2, ON);
  expander2.digitalWrite(3, OFF);
  expander2.digitalWrite(4, OFF);
  expander2.digitalWrite(5, OFF);
  expander2.digitalWrite(6, ON);
  expander2.digitalWrite(7, ON); 
  }
  break;
//OSIEM
  case 8:
  {
  expander2.digitalWrite(0, ON);
  expander2.digitalWrite(1, ON);
  expander2.digitalWrite(2, ON);
  expander2.digitalWrite(3, OFF);
  expander2.digitalWrite(4, ON);
  expander2.digitalWrite(5, ON);
  expander2.digitalWrite(6, ON);
  expander2.digitalWrite(7, ON); 
  }
  break;
//DZIEWIEC
  case 9:
  {
  expander2.digitalWrite(0, OFF);
  expander2.digitalWrite(1, ON);
  expander2.digitalWrite(2, ON);
  expander2.digitalWrite(3, OFF);
  expander2.digitalWrite(4, ON);
  expander2.digitalWrite(5, ON);
  expander2.digitalWrite(6, ON);
  expander2.digitalWrite(7, ON);  
  }
  break;
  
  case 10:
  {
  expander2.digitalWrite(0, OFF);
  expander2.digitalWrite(1, OFF);
  expander2.digitalWrite(2, OFF);
  expander2.digitalWrite(3, OFF);
  expander2.digitalWrite(4, OFF);
  expander2.digitalWrite(5, OFF);
  expander2.digitalWrite(6, OFF);
  expander2.digitalWrite(7, OFF);
  }
  break;
}
 
 
     
     
switch(b) 
{
  case 0:
  {
  expander.digitalWrite(0, ON);
  expander.digitalWrite(1, ON);
  expander.digitalWrite(2, ON);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, OFF);
  expander.digitalWrite(5, ON);
  expander.digitalWrite(6, ON);
  expander.digitalWrite(7, ON);
  }
  break;
//JEDEN
  case 1:
  {
  expander.digitalWrite(0, OFF);
  expander.digitalWrite(1, OFF);
  expander.digitalWrite(2, ON);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, OFF);
  expander.digitalWrite(5, OFF);
  expander.digitalWrite(6, OFF);
  expander.digitalWrite(7, ON);
  }
  break;
 //DWA
  case 2:
  {
  expander.digitalWrite(0, ON);
  expander.digitalWrite(1, ON);
  expander.digitalWrite(2, OFF);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, ON);
  expander.digitalWrite(5, OFF);
  expander.digitalWrite(6, ON);
  expander.digitalWrite(7, ON);
  }
  break;
//TRZY
  case 3:
  {
  expander.digitalWrite(0, OFF);
  expander.digitalWrite(1, ON);
  expander.digitalWrite(2, ON);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, ON);
  expander.digitalWrite(5, OFF);
  expander.digitalWrite(6, ON);
  expander.digitalWrite(7, ON);  
  }
  break;
  //CZTERY
  case 4:
  {
  expander.digitalWrite(0, OFF);
  expander.digitalWrite(1, OFF);
  expander.digitalWrite(2, ON);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, ON);
  expander.digitalWrite(5, ON);
  expander.digitalWrite(6, OFF);
  expander.digitalWrite(7, ON);
  }
  break;
//PIEC
  case 5:
  {
  expander.digitalWrite(0, OFF);
  expander.digitalWrite(1, ON);
  expander.digitalWrite(2, ON);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, ON);
  expander.digitalWrite(5, ON);
  expander.digitalWrite(6, ON);
  expander.digitalWrite(7, OFF);
  }
  break;
//SZESC
  case 6:
  {
  expander.digitalWrite(0, ON);
  expander.digitalWrite(1, ON);
  expander.digitalWrite(2, ON);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, ON);
  expander.digitalWrite(5, ON);
  expander.digitalWrite(6, ON);
  expander.digitalWrite(7, OFF); 
  }
  break;
//SIEDEM
  case 7:
  {
  expander.digitalWrite(0, OFF);
  expander.digitalWrite(1, OFF);
  expander.digitalWrite(2, ON);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, OFF);
  expander.digitalWrite(5, OFF);
  expander.digitalWrite(6, ON);
  expander.digitalWrite(7, ON); 
  }
  break;
//OSIEM
  case 8:
  {
  expander.digitalWrite(0, ON);
  expander.digitalWrite(1, ON);
  expander.digitalWrite(2, ON);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, ON);
  expander.digitalWrite(5, ON);
  expander.digitalWrite(6, ON);
  expander.digitalWrite(7, ON); 
  }
  break;
//DZIEWIEC
  case 9:
  {
  expander.digitalWrite(0, OFF);
  expander.digitalWrite(1, ON);
  expander.digitalWrite(2, ON);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, ON);
  expander.digitalWrite(5, ON);
  expander.digitalWrite(6, ON);
  expander.digitalWrite(7, ON);  
  }
  break;
  
  case 10:
  {
  expander.digitalWrite(0, OFF);
  expander.digitalWrite(1, OFF);
  expander.digitalWrite(2, OFF);
  expander.digitalWrite(3, OFF);
  expander.digitalWrite(4, OFF);
  expander.digitalWrite(5, OFF);
  expander.digitalWrite(6, OFF);
  expander.digitalWrite(7, OFF);
  }
  break;
}


}

void odliczanie ()
{
   i=i-1;
  if (i<=0)
  {
    i=0;
  }
  a=i%10;
  b=(i-a)/10;
  if (i>=30)
  {
    a=10;
    b=10;
  }
  
  
  
}

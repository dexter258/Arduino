
#include <Servo.h> 
#include <Wire.h>
#include "Adafruit_MCP23017.h"
#include <PCF8574.h>
PCF8574 expander;
Adafruit_MCP23017 mcp;
Servo zamek;
Servo glowa;
Servo lewa;
Servo prawa;
int kod=0;
int pos=0;
int tresc=0;
int przepowiednia=3;
int serce_poczatek=0;
int serce_wejscie=11;
int serce_wyjscie=10;
int arduino=12;
int krancowka=5;
int szuflada=2;
int palec=0;
int poczatek=13;
const byte  GPPUA =  0x0c;      
void setup() {  
  mcp.begin(0);      // use default address 0
expander.begin(0x38);
mcp.pinMode(1, INPUT);
  mcp.pinMode(2, INPUT);
  mcp.pinMode(3, INPUT);
  mcp.pinMode(4, INPUT);
  mcp.pinMode(5, INPUT);
  mcp.pinMode(6, INPUT);
  mcp.pinMode(7, INPUT);
  mcp.pinMode(8, INPUT);
   mcp.pinMode(9, INPUT);
  mcp.pinMode(10, INPUT);
  mcp.pinMode(11, INPUT);
  mcp.pinMode(12,INPUT);
   mcp.pinMode(13, INPUT);
  mcp.pinMode(14, INPUT);
  mcp.pinMode(15, INPUT);
  mcp.pinMode(0,INPUT);
  
  
  pinMode(serce_wejscie,INPUT);
  pinMode(serce_wyjscie,OUTPUT);
  pinMode(krancowka,OUTPUT);
  pinMode(szuflada,INPUT);
  pinMode(przepowiednia,OUTPUT);
 pinMode(arduino,INPUT);
  pinMode(poczatek,OUTPUT);

 expander.pinMode(1, INPUT);
  expander.pinMode(2, INPUT);
   expander.pinMode(3, INPUT);
    expander.pinMode(4, INPUT);
     expander.pinMode(5, INPUT);
      expander.pinMode(6, INPUT);
       expander.pinMode(7, INPUT);
        expander.pinMode(0, INPUT);
        zamek.attach(9); 
    digitalWrite(krancowka,LOW);
     zamek.write(160); 
        digitalWrite(8,LOW);
       delay(1000);
      zamek.detach();
}



void loop() {

if (  (mcp.digitalRead(0)==LOW)&& (mcp.digitalRead(1)==LOW)&& (mcp.digitalRead(2)==HIGH)&& (mcp.digitalRead(3)==HIGH)&& (mcp.digitalRead(4)==LOW)&& (mcp.digitalRead(5)==LOW) &&   (mcp.digitalRead(6)==LOW)&& (mcp.digitalRead(7)==HIGH)&&  (mcp.digitalRead(8)==LOW)&& (mcp.digitalRead(9)==LOW)&& (mcp.digitalRead(10)==HIGH)&& (mcp.digitalRead(11)==HIGH)&&  (mcp.digitalRead(12)==LOW)&& (mcp.digitalRead(13)==HIGH)&& (mcp.digitalRead(14)==LOW)&& (mcp.digitalRead(15)==LOW)&& (expander.digitalRead(0)==HIGH)&& (expander.digitalRead(1)==LOW)&&(expander.digitalRead(2)==HIGH)&&(expander.digitalRead(3)==LOW)&&(expander.digitalRead(4)==LOW)&&(expander.digitalRead(5)==HIGH)&&(expander.digitalRead(6)==LOW)&&(expander.digitalRead(7)==LOW)&& (kod==0))
{
  
  kod=1;
}
if (kod==1)
{
  zamek.attach(9); 
 
    zamek.write(70); 
    delay(1500);
      digitalWrite(poczatek,HIGH);
       delay(850);
       digitalWrite(poczatek,LOW);
      zamek.detach();
      kod=2;
}
if (kod==2)
{
  glowa.attach(8);
  lewa.attach(7);
  prawa.attach(6);
 for (int smiech=0; smiech<7; smiech+=1) 
 {
  for(pos = 95; pos < 150; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
  } 
   for(pos = 150; pos>=96; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5); 
  }
  if ((smiech%2)==0)
  {
    lewa.write(120);
    prawa.write(60);
  }
  else 
  {
    lewa.write(60);
     prawa.write(120);
  }
  
 }
   for (int normalnie=1; normalnie<8; normalnie+=1) 
 {
  for(pos = 95; pos < 150; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
   for(pos = 150; pos>=96; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15); 
  }
  if ((normalnie%4)==0)
  {
    lewa.write(120);
    prawa.write(60);
  }
  if (((normalnie%3)==0)&& ((normalnie%4)!=0))
  {
    lewa.write(60);
     prawa.write(120);
  }
  
}

for (int smiech=0; smiech<3; smiech+=1) 
 {
  for(pos = 95; pos < 150; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
  } 
   for(pos = 150; pos>=96; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5); 
  }
  if ((smiech%2)==0)
  {
    lewa.write(120);
    prawa.write(60);
  }
  else 
  {
    lewa.write(60);
     prawa.write(120);
  }
  
 }
   for (int normalnie=1; normalnie<15; normalnie+=1) 
 {
  for(pos = 95; pos < 150; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
   for(pos = 150; pos>=96; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15); 
  }
  if ((normalnie%4)==0)
  {
    lewa.write(120);
    prawa.write(60);
  }
  if (((normalnie%3)==0)&& ((normalnie%4)!=0))
  {
    lewa.write(60);
     prawa.write(120);
  }
  
}


for (int smiech=0; smiech<5; smiech+=1) 
 {
  for(pos = 95; pos < 150; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
  } 
   for(pos = 150; pos>=96; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5); 
  }
  if ((smiech%2)==0)
  {
    lewa.write(120);
    prawa.write(60);
  }
  else 
  {
    lewa.write(60);
     prawa.write(120);
  }
  
 }




kod=3;
glowa.detach();
lewa.detach();
prawa.detach();
}




if ((digitalRead(serce_wejscie)==HIGH) && (serce_poczatek==0))
{
  serce_poczatek=1;
}
if (serce_poczatek==1)
{
  digitalWrite(serce_wyjscie,HIGH);
  delay(850);
  digitalWrite(serce_wyjscie,LOW);
  serce_poczatek=2;
}
if (serce_poczatek==2)
{
  glowa.attach(8);
  lewa.attach(7);
  prawa.attach(6);

   for (int normalnie=1; normalnie<4; normalnie+=1) 
 {
  for(pos = 95; pos < 150; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
   for(pos = 150; pos>=96; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15); 
  }
  if ((normalnie%4)==0)
  {
    lewa.write(120);
    prawa.write(60);
  }
  if (((normalnie%3)==0)&& ((normalnie%4)!=0))
  {
    lewa.write(60);
     prawa.write(120);
  }
  
}

for (int smiech=0; smiech<4; smiech+=1) 
 {
  for(pos = 95; pos < 150; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
  } 
   for(pos = 150; pos>=96; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5); 
  }
  if ((smiech%2)==0)
  {
    lewa.write(120);
    prawa.write(60);
  }
  else 
  {
    lewa.write(60);
     prawa.write(120);
  }
  
 }

  for (int normalnie=1; normalnie<19; normalnie+=1) 
 {
  for(pos = 95; pos < 150; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
   for(pos = 150; pos>=96; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15); 
  }
  if ((normalnie%4)==0)
  {
    lewa.write(120);
    prawa.write(60);
  }
  if (((normalnie%3)==0)&& ((normalnie%4)!=0))
  {
    lewa.write(60);
     prawa.write(120);
  }
  
}







serce_poczatek=3;
glowa.detach();
lewa.detach();
prawa.detach();
}








if ((digitalRead(arduino)==HIGH) && (serce_poczatek==3)&&(palec==0))
{
tresc=1;
}

if (tresc==1)
{
  digitalWrite(przepowiednia,HIGH);
  delay(850);
  digitalWrite(przepowiednia,LOW);
  tresc=2;
}

if (tresc==2)
{
  glowa.attach(8);
  lewa.attach(7);
  prawa.attach(6);

   for (int normalnie=1; normalnie<17; normalnie+=1) 
 {
  for(pos = 95; pos < 150; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
   for(pos = 150; pos>=96; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15); 
  }
  if ((normalnie%4)==0)
  {
    lewa.write(120);
    prawa.write(60);
  }
  if (((normalnie%3)==0)&& ((normalnie%4)!=0))
  {
    lewa.write(60);
     prawa.write(120);
  }
  
}
tresc=3;
glowa.detach();
lewa.detach();
prawa.detach();
}








if ((digitalRead(szuflada)==HIGH) && (serce_poczatek==3)&&(palec==0))
{
palec=1;
}

if (palec==1)
{
  digitalWrite(krancowka,HIGH);
  delay(850);
  digitalWrite(krancowka,LOW);
  palec=2;
}

if (palec==2)
{
  glowa.attach(8);
  lewa.attach(7);
  prawa.attach(6);

   for (int normalnie=1; normalnie<4; normalnie+=1) 
 {
  for(pos = 95; pos < 150; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
   for(pos = 150; pos>=96; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15); 
  }
  if ((normalnie%4)==0)
  {
    lewa.write(120);
    prawa.write(60);
  }
  if (((normalnie%3)==0)&& ((normalnie%4)!=0))
  {
    lewa.write(60);
     prawa.write(120);
  }
  
}

 for (int smiech=0; smiech<4; smiech+=1) 
 {
  for(pos = 95; pos < 150; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
  } 
   for(pos = 150; pos>=96; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5); 
  }
  if ((smiech%2)==0)
  {
    lewa.write(120);
    prawa.write(60);
  }
  else 
  {
    lewa.write(60);
     prawa.write(120);
  }
  
 }

  for (int normalnie=1; normalnie<15; normalnie+=1) 
 {
  for(pos = 95; pos < 150; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
   for(pos = 150; pos>=96; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15); 
  }
  if ((normalnie%4)==0)
  {
    lewa.write(120);
    prawa.write(60);
  }
  if (((normalnie%3)==0)&& ((normalnie%4)!=0))
  {
    lewa.write(60);
     prawa.write(120);
  }
  
}

for (int smiech=0; smiech<4; smiech+=1) 
 {
  for(pos = 95; pos < 150; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
  } 
   for(pos = 150; pos>=96; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    glowa.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5); 
  }
  if ((smiech%2)==0)
  {
    lewa.write(120);
    prawa.write(60);
  }
  else 
  {
    lewa.write(60);
     prawa.write(120);
  }
  
 }




palec=3;
glowa.detach();
lewa.detach();
prawa.detach();
}








}

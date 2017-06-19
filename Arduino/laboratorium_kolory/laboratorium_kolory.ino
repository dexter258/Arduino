#include <Wire.h>
#include "Adafruit_MCP23017.h"
#include <LiquidCrystal_I2C.h>
#include <Servo.h> 

Adafruit_MCP23017 mcp;

Servo myservo;
Servo servo;
#define BACKLIGHT_PIN 3
LiquidCrystal_I2C lcd(0x20,2,1,0,4,5,6,7);

int polaczenie_przewodow=0;
#define przewody_1 1
#define przewody_2 2
#define pasek_led 5


int redPin[3];
int greenPin[3];
int bluePin[3];
int k=1;
int j=6;
int s2[3];
int s3[3];
int outPin[3];

int rColorStrength[3];
int gColorStrength[3];
int bColorStrength[3];
unsigned int pulseWidth[3];


void setup() {
  
    pinMode(przewody_1,INPUT);
    pinMode(przewody_2,INPUT);
    pinMode(pasek_led,OUTPUT);
  lcd.begin(16,2);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
   
   lcd.print("!!! AWARIA !!!");
   lcd.setCursor ( 0, 1 );
   lcd.print("PODLACZ PRZEWODY");
  digitalWrite(pasek_led,HIGH);
  
    myservo.attach(9);
        myservo.write(0);
    servo.attach(10);
        servo.write(0);
    
  for (int i=0; i<3; i++)
 {
   s2[i]=k;
   k++;
   s3[i]=k;
   k++;
 }
 for (int i=0; i<3; i++)
 {
   redPin[i]=k;
   k++;
   greenPin[i]=k;
   k++;
   bluePin[i]=k;
   k++;
 }
 for (int i=0; i<3; i++)
 {
   outPin[3]=j;
   j++;
 }
   mcp.begin(0);  
  Serial.begin(9600);
  
  for (int i=0; i<3; i++)
 {
  mcp.pinMode(redPin[i],OUTPUT);
  mcp.pinMode(greenPin[i],OUTPUT);
  mcp.pinMode(bluePin[i],OUTPUT);
  mcp.pinMode(s2[i],OUTPUT);
  mcp.pinMode(s3[i],OUTPUT);
  pinMode(outPin[i],INPUT);
 }
  
}

void loop() {
   // ODCZYTYWANIE WARTOŚCI POSZSCZEGÓLNYCH KOLORÓW PRZEZ ZASTOSOWANIE ODPOWIEDNICH FILTRÓW CZYTNIKA KOLORÓW
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
    if (polaczenie_przewodow==1)
    {
    lcd.setBacklight(HIGH);
     lcd.setCursor ( 1, 0 );
    lcd.print("!!! UWAGA !!!");
    
     lcd.setCursor ( 2, 1 );
   lcd.print("BRAK PALIWA");
   polaczenie_przewodow=2;
    }
   for (int i=0; i<3; i++)
     { 
   //RED  
            mcp.digitalWrite(s2[i],LOW);
            mcp.digitalWrite(s3[i],LOW);               
  
            pulseWidth[i] = pulseIn(outPin[i],LOW);
 
            rColorStrength[i] = pulseWidth[i]/10 - 1;
            rColorStrength[i] = (255-rColorStrength[i]);
             delay(50);
   //GREEN  
            mcp.digitalWrite(s2[i],HIGH);
            mcp.digitalWrite(s3[i],HIGH);
  
            pulseWidth[i] = pulseIn(outPin[i],LOW);
            gColorStrength[i] = pulseWidth[i]/10 - 1;
            gColorStrength[i] = (255-gColorStrength[i]);
             delay(50);
   //BLUE   
            mcp.digitalWrite(s2[i],LOW);
            mcp.digitalWrite(s3[i],HIGH);
  
            pulseWidth[i] = pulseIn(outPin[i],LOW);
            bColorStrength[i] = pulseWidth[i]/10 - 1;
            bColorStrength[i] = (255-bColorStrength[i]);
             delay(50);
  
      }
      
      
      //  SPRAWDZANIE KTÓRY KOLOR JEST MOCNIEJSZY I MINIMALIZOWANIE WPŁYWU POZOSTAŁYCH
  for (int i=0; i<3; i++)
     {     
            if ((rColorStrength[i]>gColorStrength[i])&&(gColorStrength[i]>bColorStrength[i]))
                {
                    rColorStrength[i]=255;
                    gColorStrength[i]= gColorStrength[i]/4;
                    bColorStrength[i]= 0;
                }
  
            if ((rColorStrength[i]>bColorStrength[i])&&(bColorStrength[i]>gColorStrength[i]))
                {
                    rColorStrength[i]=255;
                    bColorStrength[i]=bColorStrength[i]/4;
                    gColorStrength[i]=0;
                }
  
            if ((bColorStrength[i]>gColorStrength[i])&&(gColorStrength[i]>rColorStrength[i]))
                {
                    bColorStrength[i]=255;
                    gColorStrength[i]=gColorStrength[i]/4;
                    rColorStrength[i]=0;
                }  
            if ((bColorStrength[i]>rColorStrength[i])&&(rColorStrength[i]>gColorStrength[i]))
                {
                    bColorStrength[i]=255;
                    rColorStrength[i]=rColorStrength[i]/4;
                    gColorStrength[i]=0;
                }  
  
            if ((gColorStrength[i]>bColorStrength[i])&&(bColorStrength[i]>rColorStrength[i]))
                {
                    gColorStrength[i]=255;
                    bColorStrength[i]=bColorStrength[i]/4;
                    rColorStrength[i]=0;
                }  
           if ((gColorStrength[i]>rColorStrength[i])&&(rColorStrength[i]>bColorStrength[i]))
                {
                   gColorStrength[i]=255;
                   rColorStrength[i]=rColorStrength[i]/4;
                   bColorStrength[i]=0;
                }  
     }
  

  
  // PRZEPISYWANIE ODCZYTYWANYCH WARTOSCI DO MONITORA SZEREGOWEGO
    for (int i=0; i<3; i++)
     {   
        Serial.print(rColorStrength[i]);
        Serial.print("    ");
      
        Serial.print(gColorStrength[i]);
        Serial.print("    ");
  
        Serial.print(bColorStrength[i]);
        Serial.print("                            ");
     }  
   Serial.println("");
   Serial.println("");
   
   
   for (int i=0; i<3; i++)
     {  
        analogWrite(redPin[i],(255-rColorStrength[i]));
        analogWrite(greenPin[i],(255-gColorStrength[i]));
        analogWrite(bluePin[i],(255-bColorStrength[i]));
     }
   
  delay(500);
  }
}

#include <LiquidCrystal_I2C.h>


#include <Wire.h>
#define BACKLIGHT_PIN 3
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7);
#define przelacznik_zielony_lewy_gora 46
#define przelacznik_zielony_lewy_bok 44
#define przelacznik_zielony_prawy_gora 40
#define przelacznik_zielony_prawy_bok 38

#define przycisk_zielony_lewy 25
#define przycisk_zielony_prawy 27

int przycisk[10];
int led[4];
int przycisk_poprawny[6];
int dioda_lewa=22;
int dioda_prawa=23;

int led_przelacznik_zielony_lewy=42;
int led_przelacznik_zielony_prawy=34;

int lvl=0;
int wcisniety=0;
boolean potencjometr_prawy=false;
boolean potencjometr_lewy=false;
// the setup function runs once when you press reset or power the board
void setup() {
   lcd.begin(20,4);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  przycisk_poprawny[0]=6;
  przycisk_poprawny[1]=4;
  przycisk_poprawny[2]=3;
  przycisk_poprawny[3]=7;
  przycisk_poprawny[4]=8;
  przycisk_poprawny[5]=9;

  lcd.home();
  lcd.print("No Escape");
  
Serial.begin(9600);
for (int i=0; i<10;i++)
{
  przycisk[i]=2*i+35;
  pinMode(przycisk[i], INPUT);
}

for (int i=0; i<4;i++)
{
  led[i]=2*i+24;
  pinMode(led[i], OUTPUT);
}

  pinMode(dioda_lewa, OUTPUT);
  pinMode(dioda_prawa, OUTPUT);

      pinMode(led_przelacznik_zielony_lewy, OUTPUT);
      pinMode(led_przelacznik_zielony_prawy, OUTPUT);
      
pinMode(przelacznik_zielony_lewy_gora, INPUT);
pinMode(przelacznik_zielony_lewy_bok, INPUT);
pinMode(przelacznik_zielony_prawy_gora, INPUT);
pinMode(przelacznik_zielony_prawy_bok, INPUT);

pinMode(przycisk_zielony_lewy,INPUT);
pinMode(przycisk_zielony_prawy,INPUT);

digitalWrite(led_przelacznik_zielony_lewy, LOW);
 digitalWrite(led_przelacznik_zielony_prawy, LOW);
}


void loop() {
  
 /* 
   Serial.println("nowa kolejka");
  Serial.println(digitalRead(przelacznik_zielony_lewy_bok));
   Serial.println(digitalRead(przelacznik_zielony_lewy_gora));
    Serial.println(digitalRead(przelacznik_zielony_prawy_bok));
     Serial.println(digitalRead(przelacznik_zielony_prawy_gora));
     
     */
     Serial.println("A0");
   Serial.println(analogRead(A0));
    Serial.println("A1");
     Serial.println(analogRead(A1));
      Serial.println();
  if (digitalRead(przelacznik_zielony_lewy_bok)==HIGH)
    {
      digitalWrite(led_przelacznik_zielony_lewy, HIGH);
    }
     else
      { 
         digitalWrite(led_przelacznik_zielony_lewy, LOW);
      }

  if (digitalRead(przelacznik_zielony_prawy_bok)==HIGH)
     {
      digitalWrite(led_przelacznik_zielony_prawy, HIGH);
     }
     else
      { 
         digitalWrite(led_przelacznik_zielony_prawy, LOW);          
      }
      
      if (digitalRead(przycisk_zielony_prawy)==HIGH)
        {
          digitalWrite(dioda_prawa,HIGH);
        }
        else
          {
            digitalWrite(dioda_prawa,LOW);
          }
      if (digitalRead(przycisk_zielony_lewy)==HIGH)
        {
          digitalWrite(dioda_lewa,HIGH);
        }
        else
          {
            digitalWrite(dioda_lewa,LOW);
          }
          
  // wykonywanie logiki sprawdzajacej poprawnosc wykonania kombinacji    
                                                                      // przycisk, sprawdzanie na ktorym jestes lvl i czy przycisk jest wcisniety
                                                                      
      for (int p=0; p<6;p++){                                                                
          if ((digitalRead(przycisk[przycisk_poprawny[p]])==HIGH) && (lvl==p))             //oznaczanie, ze dobry przycisk jest wcisniety
    {
         wcisniety=p+1;
    }
    for (int i=0; i<(przycisk_poprawny[p]); i++){                   //resetowanie po wcisnieciu zlego przycisku
       if ((digitalRead(przycisk[i])==HIGH) && (lvl==p))
       {
         lvl=0;
            wcisniety=0;
       }
    }
    for (int i=(przycisk_poprawny[p]+1); i<10; i++){                 //resetowanie po wcisnieciu zlego przycisku
       if ((digitalRead(przycisk[i])==HIGH) && (lvl==p))
       {
         lvl=0;
         wcisniety=0;
       }
    }
       if ((digitalRead(przycisk[przycisk_poprawny[p]])==LOW) && (wcisniety==(p+1)))           //przejscie do nastepnego lvl dopiero gdy przycisk jest puszczony
    {
       lvl=p+1;
   
    }
      } 
//Serial.println(lvl);   
                              // zapalanie odpowiednich diod po osiagnieciu konkretnego poziomu
    for (int k=3;k<7;k++)
    {
      if (lvl==k)
      {
         digitalWrite(led[6-k], HIGH);
      }
    }
   
     if (lvl==0)                   // gaszenie po popelnieniu bledu
    {
      for (int i=0; i<4;i++)
        {
          digitalWrite(led[i],LOW);
        }
    }
    if (analogRead(A0)>150 && analogRead(A0)<450)
    {
      potencjometr_lewy=true;
    }
    else 
    {
       potencjometr_lewy=false;
    }
      if (analogRead(A1)>650 && analogRead(A1)<950)
    {
      potencjometr_prawy=true;
    }
    else 
    {
       potencjometr_prawy=false;
    }
    
// sprawdzanie ostatecznych usatewien
if ((lvl==6) && (potencjometr_lewy==true) && (potencjometr_prawy==true) && (digitalRead(przelacznik_zielony_lewy_bok)==HIGH) && (digitalRead(przelacznik_zielony_prawy_bok)==LOW) && (digitalRead(przycisk_zielony_lewy)==LOW) && (digitalRead(przycisk_zielony_prawy)==HIGH))
{
 Serial.println("rozwiazano"); 
}
}

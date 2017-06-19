#include "Timer.h"
#include <Password.h> //http://www.arduino.cc/playground/uploads/Code/Password.zip
#include <Keypad.h> //http://www.arduino.cc/playground/uploads/Code/Keypad.zip
#include <Wire.h> 
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include "PCF8574.h"
PCF8574 expander;
LiquidCrystal_I2C lcd(0x38,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display

//#include <Servo.h> //dołączamy niezbędne biblioteki

//Servo servo1; //dodajemy serwo
Password password = Password( "1410" ); //ustalamy hasło
unsigned long czas=301;
const byte ROWS = 4;
const byte COLS = 4;
int BLUE=0;
int lock=0;
int proby=0;
int haslo=0;
int kod=0;
int p=0;
int glosnik=11;
int koniecmuzyki=0;
int wlacz=0;
int start=0;
#define	C0 16.35
#define	Db0	17.32
#define	D0	18.35
#define	Eb0	19.45
#define	E0	20.60
#define	F0	21.83
#define	Gb0	23.12
#define	G0	24.50
#define	Ab0	25.96
#define	LA0	27.50
#define	Bb0	29.14
#define	B0	30.87
#define	C1	32.70
#define	Db1	34.65
#define	D1	36.71
#define	Eb1	38.89
#define	E1	41.20
#define	F1	43.65
#define	Gb1	46.25
#define	G1	49.00
#define	Ab1	51.91
#define	LA1	55.00
#define	Bb1	58.27
#define	B1	61.74
#define	C2	65.41
#define	Db2	69.30
#define	D2	73.42
#define	Eb2	77.78
#define	E2	82.41
#define	F2	87.31
#define	Gb2	92.50
#define	G2	98.00
#define	Ab2	103.83
#define	LA2	110.00
#define	Bb2	116.54
#define	B2	123.47
#define	C3	130.81
#define	Db3	138.59
#define	D3	146.83
#define	Eb3	155.56
#define	E3	164.81
#define	F3	174.61
#define	Gb3	185.00
#define	G3	196.00
#define	Ab3	207.65
#define	LA3	220.00
#define	Bb3	233.08
#define	B3	246.94
#define	C4	261.63
#define	Db4	277.18
#define	D4	293.66
#define	Eb4	311.13
#define	E4	329.63
#define	F4	349.23
#define	Gb4	369.99
#define	G4	392.00
#define	Ab4	415.30
#define	LA4	440.00
#define	Bb4	466.16
#define	B4	493.88
#define	C5	523.25
#define	Db5	554.37
#define	D5	587.33
#define	Eb5	622.25
#define	E5	659.26
#define	F5	698.46
#define	Gb5	739.99
#define	G5	783.99
#define	Ab5	830.61
#define	LA5	880.00
#define	Bb5	932.33
#define	B5	987.77
#define	C6	1046.50
#define	Db6	1108.73
#define	D6	1174.66
#define	Eb6	1244.51
#define	E6	1318.51
#define	F6	1396.91
#define	Gb6	1479.98
#define	G6	1567.98
#define	Ab6	1661.22
#define	LA6	1760.00
#define	Bb6	1864.66
#define	B6	1975.53
#define	C7	2093.00
#define	Db7	2217.46
#define	D7	2349.32
#define	Eb7	2489.02
#define	E7	2637.02
#define	F7	2793.83
#define	Gb7	2959.96
#define	G7	3135.96
#define	Ab7	3322.44
#define	LA7	3520.01
#define	Bb7	3729.31
#define	B7	3951.07
#define	C8	4186.01
#define	Db8	4434.92
#define	D8	4698.64
#define	Eb8	4978.03
// DURATION OF THE NOTES 
#define BPM 120    //  you can change this value changing all the others
#define H 2*Q //half 2/4
#define Q 60000/BPM //quarter 1/4 
#define E Q/2   //eighth 1/8
#define S Q/4 // sixteenth 1/16
#define W 4*Q // whole 4/4
unsigned long alarm;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
}; //tworzymy klawiaturkę

byte rowPins[ROWS] = { 9,8,7,6 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 5,4,3,2 };// Connect keypad COL0, COL1 and COL2 to these Arduino pins.

// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
Timer t;
    void gwiazdki(){ 
  for (int i=0; i<p; i++)
  {
   
    lcd.setCursor(i, 1);
    lcd.print("*");
  }
}

void elecd(){
  
    if (czas >0){
      czas--;
    lcd.setCursor(0, 0);
    lcd.print("Pozostalo: ");
    lcd.print(czas);
    lcd.print(" s.");
        }
    if (czas == 0) {
      lcd.clear();
    
      digitalWrite(BLUE, HIGH);
       digitalWrite(13, HIGH);
      digitalWrite(1,LOW);
      
      lcd.print("XXXX KONIEC XXXX");
      
      

     if (koniecmuzyki==0)
     {
      tone(glosnik,1200,6000); 
      koniecmuzyki=1;
      
     }
     
     
    }
  if ((czas<=300)&& (czas>100)&& (kod!=1) )
  {
    if (czas%10==0)
    {
  tone(glosnik,500,200);
    }   
  }     
    
    
    
    
  if ((czas<=100)&& (czas>=60)&& (kod!=1) )
  {
    if (czas%4==0)
    {
  tone(glosnik,500,200);
    }   
  } 
    
 if ((czas<60)&& (czas>=40)&& (kod!=1) )
  {
    if (czas%2==0)
    {
  tone(glosnik,500,200);
    }
  }
  
   if ((czas<40)&& (czas>=20)&& (kod!=1) )
  {
      tone(glosnik,500,200);
    }
  
 if ((czas<20)&& (czas>=10)&& (kod!=1) )
  {
  tone(glosnik,500,200);
  delay(200);
  tone(glosnik,500,200);
  delay(200);  
  }  
  if ((czas<10)&& (czas>0)&& (kod!=1) )
  {
  tone(glosnik,500,200);
  delay(200);
  tone(glosnik,500,200);
  delay(200);  
  tone(glosnik,500,200);
  delay(200);  
  }   
  
  
  
  
}

void setup(){
    lcd.init();
    pinMode(13,OUTPUT);
    pinMode(1,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
     pinMode(BLUE, OUTPUT);
    pinMode(12,INPUT);
 alarm = millis()+60000;
    keypad.addEventListener(keypadEvent); //rozpoczyna nasluch na klawiaturce
     int tickEvent = t.every(1000, elecd);
     digitalWrite(BLUE, HIGH);
     digitalWrite(13, HIGH);
     digitalWrite(1, HIGH);
}

void loop(){
  
  
if (start==0)
{delay(30000);
start=1;
}
  
if ( digitalRead(12) == HIGH)
{
  wlacz=1;
}
if (wlacz==1)
{
    if (haslo==0)
  {
  t.update();
  }
  if ((czas>0) && (kod!=1))
  {digitalWrite(BLUE, LOW);
  keypad.getKey();
  }
 }
}
void keypadEvent(KeypadEvent eKey){

switch (keypad.getState()){ //odczyt stanu klawisza
case PRESSED:

switch (eKey){
    case '#':
      checkPassword(); //po nacisnięciu # sprawdza poprawność hasła
    p=0;
    if (haslo==0)
{
      lcd.clear();
}
    gwiazdki();
      break;
    case '*': //po naciśnięciu * resetuje próbę wpisania hasła
      password.reset();
     // servo_lock();
      haslo=0;
           
     p=0;
       lcd.clear();
    gwiazdki();
    //  dioda_zapal();
      break;
    default:  
      password.append(eKey);
      p++;
          digitalWrite(10,HIGH);
       delay(100);
     digitalWrite(10,LOW);
  //    dioda_zapal();//jeśli jest to inny klawisz to dopisuje go do hasła które jest właśnie wpisywane
 

  gwiazdki();
  
}
}
}

void checkPassword(){
    if (password.evaluate()){//jeśli hasło się zgadza otwiera drzwi
     digitalWrite(13,HIGH);
     //     servo_unlock();
          // lcd.clear();
      lcd.setCursor(0, 1);
    lcd.print("Bomba Rozbrojona");
tone(glosnik,261,100);    
    delay(100);
tone(glosnik,294,100);   
digitalWrite(BLUE,HIGH);
     digitalWrite(13,HIGH);
     delay(100);
tone(glosnik,329,100);     
      digitalWrite(13,LOW);
       delay(100);
tone(glosnik,349,100);        
     digitalWrite(13,HIGH);
     delay(100);
tone(glosnik,392,100);      
      digitalWrite(13,LOW);
     delay(2000);
  //   digitalWrite(13,LOW);
      password.reset();
      haslo=1;
      kod=1;
      if (koniecmuzyki==0)
  {  
   tone(glosnik,LA3,Q); 
    delay(1+Q); //delay duration should always be 1 ms more than the note in order to separate them.
    tone(glosnik,LA3,Q);
    delay(1+Q);
    tone(glosnik,LA3,Q);
    delay(1+Q);
    tone(glosnik,F3,E+S);
    delay(1+E+S);
    tone(glosnik,C4,S);
    delay(1+S);
    
    tone(glosnik,LA3,Q);
    delay(1+Q);
    tone(glosnik,F3,E+S);
    delay(1+E+S);
    tone(glosnik,C4,S);
    delay(1+S);
    tone(glosnik,LA3,H);
    delay(1+H);

 koniecmuzyki=1;
  }      
}
else{//a jesli nie to je zamyka
digitalWrite(1,HIGH);
//servo_lock;
tone(glosnik,200,100);
    delay(100);
tone(glosnik,500,100); 
 digitalWrite(BLUE,HIGH);
     digitalWrite(1,HIGH);
     delay(100);
tone(glosnik,200,100);

      digitalWrite(1,LOW);
      delay(100);
tone(glosnik,800,100);  
     digitalWrite(1,HIGH);
     delay(100);
tone(glosnik,200,100); 
      digitalWrite(1,LOW);
    //  delay(1000);
     digitalWrite(1,HIGH);
     digitalWrite(BLUE,LOW);
haslo=0;
//dioda_zapal;
password.reset();
}


}

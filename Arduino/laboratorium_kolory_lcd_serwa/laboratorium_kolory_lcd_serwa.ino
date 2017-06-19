#include "Adafruit_Thermal.h"

#include "SoftwareSerial.h"
#define TX_PIN 1 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 0 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

int X=100;


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
#define BPM 150    //  you can change this value changing all the others
#define H 2*Q //half 2/4
#define Q 60000/BPM //quarter 1/4 
#define E Q/2   //eighth 1/8
#define S Q/4 // sixteenth 1/16
#define W 4*Q // whole 4/4
#define melodyPin 4
//Mario main theme melody
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

int piezoPin=4;




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
#define przewody_1 11
#define przewody_2 12
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

int start=0;
void setup() {
  
  mySerial.begin(9600);
  
  
  
  pinMode(piezoPin, OUTPUT);//buzzer
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
        delay(1000);
    servo.detach();
     myservo.detach();
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
//  Serial.begin(9600);
  
  for (int i=0; i<3; i++)
 {
  mcp.pinMode(redPin[i],OUTPUT);
  mcp.pinMode(greenPin[i],OUTPUT);
  mcp.pinMode(bluePin[i],OUTPUT);
  mcp.pinMode(s2[i],OUTPUT);
  mcp.pinMode(s3[i],OUTPUT);
  pinMode(outPin[i],INPUT);
 }
  lcd.begin(16,2);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
   
   lcd.print("!!! AWARIA !!!");
   lcd.setCursor ( 0, 1 );
   lcd.print("PODLACZ PRZEWODY");
    delay(500);
  
  digitalWrite(pasek_led,HIGH);
}



void loop() {
   // ODCZYTYWANIE WARTOŚCI POSZSCZEGÓLNYCH KOLORÓW PRZEZ ZASTOSOWANIE ODPOWIEDNICH FILTRÓW CZYTNIKA KOLORÓW
     if ((digitalRead(przewody_1)==HIGH) && (digitalRead(przewody_2)==HIGH))
  {
    start=1;
  }
  if (start==1)
   {
    
   if (polaczenie_przewodow==0)
    {
    lcd.clear();
     
  sing();
    //delay(2000);
     
     digitalWrite(pasek_led,LOW);
  
    delay(5000);
  myservo.attach(9);
        myservo.write(0);
         servo.attach(180);
        servo.write(180);
        delay(2000);
            myservo.detach();
   
    servo.detach();
     delay(3000);
    polaczenie_przewodow=1;
    }
    if (polaczenie_przewodow==1)
    {
      tone(piezoPin,200,1800);
       delay(2000);
        lcd.begin(16,2);
        lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
    lcd.setBacklight(HIGH);
     lcd.setCursor ( 1, 0 );
     
    lcd.print("!!! UWAGA !!!");
    
     lcd.setCursor ( 2, 1 );
   lcd.print(" BRAK PALIWA ");
   delay(2000);
     lcd.begin(16,2);
       lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
       lcd.setBacklight(HIGH);
 
   polaczenie_przewodow=2;
     lcd.setBacklight(HIGH);
     lcd.setCursor ( 1, 0 );
     lcd.print("!!! UWAGA !!!");
    
     lcd.setCursor ( 2, 1 );
     lcd.print(" BRAK PALIWA ");
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
     
     if (1==1)
     {   
       
       printer.begin();        // Init printer (same regardless of serial type)

 printer.justify('C');
 printer.setSize('L'); 

  printer.inverseOn();
    printer.doubleHeightOn();
    printer.println(F(""));
    printer.println(F(""));
  printer.println(F("NO ESCAPE"));
  printer.inverseOff();
  printer.doubleHeightOff();

   printer.setLineHeight(50);

 printer.boldOn();
   printer.println(F("PRINTER ON"));
  // Test more styles
  printer.boldOn();
   printer.boldOff();
printer.println(F("KOD:"));
 
  printer.underlineOn();
  printer.println(F("7528"));
  printer.underlineOff();

  printer.println(F(""));
   printer.println(F(""));
    printer.println(F(""));
     printer.println(F(""));
  printer.println(F(""));
   printer.println(F(""));
    printer.println(F(""));
     printer.println(F(""));
  
  printer.feed(2);
 
  
     for (int i=0; i<2; i++)
        {
          tone(piezoPin,LA3,Q); 
          delay(X+Q); //delay duration should always be 1 ms more than the note in order to separate them.
          tone(piezoPin,LA3,Q);
          delay(X+Q);
          tone(piezoPin,LA3,Q);
          delay(X+Q);
          tone(piezoPin,F3,E+S);
          delay(X+E+S);
          tone(piezoPin,C4,S);
          delay(X+S);
    
          tone(piezoPin,LA3,Q);
          delay(X+Q);
          tone(piezoPin,F3,E+S);
          delay(X+E+S);
          tone(piezoPin,C4,S);
          delay(X+S);
          tone(piezoPin,LA3,H);
          delay(X+H);
          
        

        
     }
   
  delay(5000);
  }
}

}



/////////////////////////////////////////////////////////////////
//////////////////     MUZYKA        //////////////////

int song = 0;

void sing() {
    
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++)
    {
      int noteDuration = 1000 / tempo[thisNote];

      buzz(melodyPin, melody[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      buzz(melodyPin, 0, noteDuration);

    }
  }


void buzz(int targetPin, long frequency, long length) {
  
  long delayValue = 1000000 / frequency / 2; 
  
  long numCycles = frequency * length / 1000; \
  
  for (long i = 0; i < numCycles; i++) 
  { 
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  


}



#define strzalka_1 13
#define strzalka_2 10
#define strzalka_3 9 
#define strzalka_4 11
#define strzalka_5 12
const byte melody_maxlen = 12;
const float melody_speed = 2.5f;
const byte melody_advance_level_len = 7;
const byte PWM_Audio     = 5;
const unsigned int melody_advance_level[2][melody_maxlen] PROGMEM =
{
    { 392, 392, 392, 440,  392, 494,  523, 0, 0, 0, 0, 0},    //frequency
    { 500, 250, 250, 500, 1000, 500, 2000, 0, 0, 0, 0, 0}     //duration, 1000 = 1 full beat
};
 void playMelody_from_PROGMEM(const unsigned int melody[2][12], byte melody_len)
{
    for (byte i = 0; i < melody_len; i++)
    {
        tone(PWM_Audio, pgm_read_word(&(melody[0][i])));
        delay((float) pgm_read_word(&(melody[1][i])) / melody_speed);
        noTone(PWM_Audio);
        delay(50); //otherwise the tones sound too legato
    }
}

int p=0;
int k=0;
int koniec=0;
int sensorPin = A1;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
unsigned long previousMillis = 0; 
unsigned long currentMillis=0;
unsigned long currentMillis_k=0;
     unsigned long aktualny=0;
const long interval = 1500;            // co jaki czas maja zapalac sie nastepne strzalki 
const long pisk = 300; 


void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);  
   Serial.begin(9600);
     pinMode(strzalka_1, OUTPUT);
  pinMode(strzalka_2, OUTPUT);
  pinMode(strzalka_3, OUTPUT);
  pinMode(strzalka_4, OUTPUT);
  pinMode(strzalka_5, OUTPUT);
  
    pinMode(PWM_Audio, OUTPUT);
   digitalWrite(PWM_Audio, LOW);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);    

  if (sensorValue<500)
  {
    if (p==0)
    {
     currentMillis = millis();
      p=1;
      k=0;
    }
   aktualny = millis();
    if ((aktualny-currentMillis)>100)
    {
     digitalWrite(strzalka_1, HIGH); 
    }
     if ((aktualny-currentMillis)>interval)
    {
     digitalWrite(strzalka_2, HIGH); 
    }
     if ((aktualny-currentMillis)>2*interval)
    {
     digitalWrite(strzalka_3, HIGH); 
    }
    if ((aktualny-currentMillis)>3*interval)
    {
     digitalWrite(strzalka_4, HIGH); 
    }
    if ((aktualny-currentMillis)>4*interval)
    {
     digitalWrite(strzalka_5, HIGH); 
     if (koniec==0)
     {
     playMelody_from_PROGMEM(melody_advance_level, melody_advance_level_len);
    koniec=1; 
    }
     
    }
  //digitalWrite(dzwiek, HIGH); 

  }
  else {
    
   
    if(koniec==0)
    {
      
       if (k==0)
    {
    currentMillis_k = millis();
      p=0;
      k=1;
    }
       digitalWrite(strzalka_1, LOW); 
 digitalWrite(strzalka_2, LOW); 
  digitalWrite(strzalka_3, LOW); 
  digitalWrite(strzalka_4, LOW);
    digitalWrite(strzalka_5, LOW);
   
    if ((millis()-currentMillis_k)>150)
    {
     while (millis()- currentMillis_k<pisk)
    {
        digitalWrite(PWM_Audio, HIGH);
     }
     
      digitalWrite(PWM_Audio, LOW);
    }
 
  }
 
    }
    Serial.println(currentMillis);
  Serial.println(aktualny);
//  p=0;
  
}


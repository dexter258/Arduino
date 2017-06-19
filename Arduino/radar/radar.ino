#include <Servo.h>
#include <Wire.h>      
Servo serwo;         // set a variable to map the servo
#define KS103ADD  0x74 
word distance=0;
boolean debudowanie=true;
boolean usrednianie=false;
int pos = 0;         // set a variable to store the servo position
const int numReadings = 10;   // set a variable for the number of readings to take
int index = 0;                // the index of the current reading
int total = 0;                // the total of all readings
int average = 0;              // the average
int opoznienie=25;

unsigned long pulseTime = 0;  // variable for reading the pulse
//unsigned long distance = 0;   // variable for storing distance
 

void setup() {
    Wire.begin();  
  serwo.attach(9);
  Serial.begin(9600);
  Wire.beginTransmission(KS103ADD); 
  Wire.write(byte(0x02));     
  Wire.write(0x71);    
  Wire.endTransmission();     
  delay(1000);             
} 

void loop() {
  
  for(pos = 0; pos < 180; pos++) { 
    serwo.write(pos);
    if (usrednianie==true)
    {
      for (index = 0; index<=numReadings;index++) {            
          KS103_read();
        total = total + distance;                      
        delay(10);
      }
    average = total/numReadings;                         
 
    if (index >= numReadings)  {                           
      index = 0;
      total = 0;
    }
    }

      else{
      KS103_read();
      delay(opoznienie);
      average = distance;
    }
    if (debudowanie==true)
    {
   Serial.print("X");                                      
    Serial.print(pos);                                
    Serial.print("V");    
    }                                     
    Serial.println(average);                                  
  }

  for(pos = 180; pos > 0; pos--) { 
    serwo.write(pos);
    if (usrednianie==true)
    {
    for (index = 0; index<=numReadings;index++) {
        KS103_read();
        total = total + distance;                      
        delay(10);
    }
    average = total/numReadings;
    if (index >= numReadings)  {
      index = 0;
      total = 0;
    }
    }
    else{
      KS103_read();
      delay(opoznienie);
      average = distance;
    }
    if (debudowanie==true)
    {
    Serial.print("X");
  Serial.print(pos);
  Serial.print("V");
    }
    Serial.println(average);
   }
}


word KS103_read(){ 
  Wire.beginTransmission(KS103ADD);
  Wire.write(byte(0x02));     
  Wire.write(0xb0);     
  Wire.endTransmission();     
  delay(1);                
  Wire.beginTransmission(KS103ADD); 
  Wire.write(byte(0x02));    
  Wire.endTransmission();   
  Wire.requestFrom(KS103ADD, 2);  
  if(2 <= Wire.available())   
  {
    distance = Wire.read(); 
    distance =  distance << 8;   
    distance |= Wire.read();
  }
}

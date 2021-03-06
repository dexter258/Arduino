
#include<Servo.h>
#include "mpr121.h"
#include <Wire.h>
int sygnal=5;
Servo serwo;
int dioda_czaszka=9;
int dioda_slonce=8;
int buzzer=10;
int slonce=0;
int reset=0;
int czaszka=0;
int irqpin = 2;  // Digital 2
long currentMillis=0;
long  start=0;
long k=0;
int glosy=7;
boolean touchStates[12]; //to keep track of the previous touch states
int radiowe=11;
void setup(){
 pinMode(dioda_czaszka,OUTPUT);
  pinMode(dioda_slonce,OUTPUT);
  pinMode(glosy,OUTPUT);
   pinMode(buzzer,OUTPUT);
  pinMode(irqpin, INPUT);
  pinMode(sygnal,INPUT);
  pinMode(reset,INPUT);
pinMode(radiowe,INPUT);
  digitalWrite(irqpin, HIGH); //enable pullup resistor
  serwo.attach(4);
    delay(100);
    serwo.write(120);
    delay(1000);
    serwo.detach();
  Serial.begin(9600);
  Wire.begin();
digitalWrite(glosy,LOW);
  mpr121_setup();
}

void loop(){
  readTouchInputs();
  if (digitalRead(reset)==HIGH)
  {
     serwo.attach(4);
    delay(100);
    serwo.write(14);
    delay(10000);
    serwo.write(120);
    delay(500);
    serwo.detach();
  }
  if (touchStates[2] == 1)
  {
    digitalWrite(dioda_czaszka,HIGH);
    czaszka=1;
  }
  else
  {
     digitalWrite(dioda_czaszka,LOW);
   
    czaszka=0;
  }
  if (digitalRead(sygnal)==LOW)
  {
    slonce=1;
    digitalWrite(dioda_slonce,HIGH);

  }
  else
  {
     digitalWrite(dioda_slonce,LOW);
     slonce=0;
  }
  
  
  if (start==0)
   {
   currentMillis = millis();
   }
  if((touchStates[4] == 0)&& (slonce==1)&& (czaszka==1)&& (touchStates[0] == 0)  && (touchStates[7] == 0)  && (touchStates[6] == 0)) {
  start=millis();  
  k=start-currentMillis;
    Serial.println(k);
  if ((k>=10000)|| (digitalRead(radiowe)==HIGH))
  {
    digitalWrite(glosy,HIGH);
digitalWrite(buzzer,HIGH);
delay(200);
digitalWrite(buzzer,LOW);
delay(800);
digitalWrite(glosy,LOW);
digitalWrite(buzzer,HIGH);
delay(400);
digitalWrite(buzzer,LOW);
delay(800);

digitalWrite(buzzer,HIGH);
delay(400);
digitalWrite(buzzer,LOW);
delay(600);

digitalWrite(buzzer,HIGH);
delay(600);
digitalWrite(buzzer,LOW);
delay(400);

digitalWrite(buzzer,HIGH);
delay(600);
digitalWrite(buzzer,LOW);
delay(200);

digitalWrite(buzzer,HIGH);
delay(800);
digitalWrite(buzzer,LOW);
delay(200);

digitalWrite(buzzer,HIGH);
delay(800);
digitalWrite(buzzer,LOW);
delay(200);

   serwo.attach(4);
    delay(100);
    serwo.write(14);
    delay(1000);
    serwo.detach();
   delay(60000);
  }
  }
  else 
  {
    start=0;
  }
    
}


void readTouchInputs(){
  if(!checkInterrupt()){
    
    //read the touch state from the MPR121
    Wire.requestFrom(0x5A,2); 
    
    byte LSB = Wire.read();
    byte MSB = Wire.read();
    
   

    
    for (int i=0; i < 11; i++){  // Check what electrodes were pressed
      uint16_t touched = ((MSB << 5) | LSB); //16bits that make up the touch states
      if(touched & (1<<i)){
      
        if(touchStates[i] == 0){
          //pin i was just touched
          Serial.print("pin ");
          Serial.print(i);
          Serial.println(" was just touched");
        
        }else if(touchStates[i] == 1){
          //pin i is still being touched
        }  
      
        touchStates[i] = 1;      
      }else{
        if(touchStates[i] == 1){
          Serial.print("pin ");
          Serial.print(i);
          Serial.println(" is no longer being touched");
          
          //pin i is no longer being touched
       }
        
        touchStates[i] = 0;
      }
    
    }
      
  }
}




void mpr121_setup(void){

  set_register(0x5A, ELE_CFG, 0x00); 
  
  // Section A - Controls filtering when data is > baseline.
  set_register(0x5A, MHD_R, 0x01);
  set_register(0x5A, NHD_R, 0x01);
  set_register(0x5A, NCL_R, 0x00);
  set_register(0x5A, FDL_R, 0x00);

  // Section B - Controls filtering when data is < baseline.
  set_register(0x5A, MHD_F, 0x01);
  set_register(0x5A, NHD_F, 0x01);
  set_register(0x5A, NCL_F, 0xFF);
  set_register(0x5A, FDL_F, 0x02);
  
  // Section C - Sets touch and release thresholds for each electrode
  set_register(0x5A, ELE0_T, TOU_THRESH);
  set_register(0x5A, ELE0_R, REL_THRESH);
 
  set_register(0x5A, ELE1_T, TOU_THRESH);
  set_register(0x5A, ELE1_R, REL_THRESH);
  
  set_register(0x5A, ELE2_T, TOU_THRESH);
  set_register(0x5A, ELE2_R, REL_THRESH);
  
  set_register(0x5A, ELE3_T, TOU_THRESH);
  set_register(0x5A, ELE3_R, REL_THRESH);
  
  set_register(0x5A, ELE4_T, TOU_THRESH);
  set_register(0x5A, ELE4_R, REL_THRESH);
  
  set_register(0x5A, ELE5_T, TOU_THRESH);
  set_register(0x5A, ELE5_R, REL_THRESH);
  
  set_register(0x5A, ELE6_T, TOU_THRESH);
  set_register(0x5A, ELE6_R, REL_THRESH);
  
  set_register(0x5A, ELE7_T, TOU_THRESH);
  set_register(0x5A, ELE7_R, REL_THRESH);
  
  set_register(0x5A, ELE8_T, TOU_THRESH);
  set_register(0x5A, ELE8_R, REL_THRESH);
  
  set_register(0x5A, ELE9_T, TOU_THRESH);
  set_register(0x5A, ELE9_R, REL_THRESH);
  
  set_register(0x5A, ELE10_T, TOU_THRESH);
  set_register(0x5A, ELE10_R, REL_THRESH);
  
  set_register(0x5A, ELE11_T, TOU_THRESH);
  set_register(0x5A, ELE11_R, REL_THRESH);
  
  // Section D
  // Set the Filter Configuration
  // Set ESI2
  set_register(0x5A, FIL_CFG, 0x04);
  
  // Section E
  // Electrode Configuration
  // Set ELE_CFG to 0x00 to return to standby mode
  set_register(0x5A, ELE_CFG, 0x0C);  // Enables all 12 Electrodes
  
  
  // Section F
  // Enable Auto Config and auto Reconfig
  /*set_register(0x5A, ATO_CFG0, 0x0B);
  set_register(0x5A, ATO_CFGU, 0xC9);  // USL = (Vdd-0.7)/vdd*256 = 0xC9 @3.3V   set_register(0x5A, ATO_CFGL, 0x82);  // LSL = 0.65*USL = 0x82 @3.3V
  set_register(0x5A, ATO_CFGT, 0xB5);*/  // Target = 0.9*USL = 0xB5 @3.3V
  
  set_register(0x5A, ELE_CFG, 0x0C);
  
}


boolean checkInterrupt(void){
  return digitalRead(irqpin);
}


void set_register(int address, unsigned char r, unsigned char v){
    Wire.beginTransmission(address);
    Wire.write(r);
    Wire.write(v);
    Wire.endTransmission();
}

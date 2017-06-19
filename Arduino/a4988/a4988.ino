/*     Simple Stepper Motor Control Exaple Code
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
// defines pins numbers
const int stepPin = 3; 
const int dirPin = 4; 
 const int prze=800;
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
   pinMode(6,OUTPUT);
   digitalWrite(6,HIGH);
   
   pinMode(8,INPUT);
   pinMode(9,INPUT);
   pinMode(10,INPUT);
}
void loop() {
  
  if (digitalRead(8)==HIGH){
     digitalWrite(6,LOW);
    delay(500);
    
   digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4500; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(prze); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(prze); 
  }
  delay(1000);
 digitalWrite(6,HIGH);
  }
 
 
   
 if (digitalRead(9)==HIGH){
     digitalWrite(6,LOW);
    delay(1500);
    
   digitalWrite(dirPin,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 4500; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(prze); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(prze); 
  }
  delay(1000);
 digitalWrite(6,HIGH);
  }
  
  
  
  
   if (digitalRead(10)==HIGH){
     digitalWrite(6,LOW);
    delay(2000);
    
   digitalWrite(dirPin,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 700; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(prze); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(prze); 
  }
  delay(1000);
 digitalWrite(6,HIGH);
  }
    
}






  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
  dt = clock.getDateTime();
   Serial.print(dt.hour);   Serial.print(":");
  
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");
  }

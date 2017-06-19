int sensorPin = 2;    // select the input pin for the potentiometer
int ledPin = 7;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int p=1;
void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);  
  pinMode(sensorPin, INPUT);  
   pinMode(sensorPin, INPUT);  
   Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
// sensorValue = analogRead(sensorPin);    
sensorValue= digitalRead(sensorPin);
  // turn the ledPin on
// sensorValue = map(sensorValue, 0 ,1023, 0, 100);
 //  Serial.println(sensorValue);
   if (sensorValue==LOW)
   {
     if (p==1)
  {
  digitalWrite(ledPin, HIGH); 
  delay(1000);
  p=0;
  }
  else 
  {
    digitalWrite(ledPin, LOW);
   delay(1000);
   p=1;
  }
  

 
   }
   else 
   {
   //  digitalWrite(ledPin, led);
   }
 
                
}

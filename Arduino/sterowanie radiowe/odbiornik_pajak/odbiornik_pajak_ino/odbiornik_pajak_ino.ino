
#include <VirtualWire.h>
#include <ServoTimer2.h>  // the servo library

// define the pins for the servos
#define receive_pin 11

#define yawPin   4
#define led_pin 8
#define wlacznik 2
ServoTimer2 servoRoll;    // declare variables for up to eight servos
ServoTimer2 servoPitch;
ServoTimer2 servoYaw;
int start=0;
const char *wiadomosc;
void setup() {
    // attach a pin to the servos and they will start pulsing
  Serial.begin(9600);
  servoYaw.attach(yawPin);
    // servoYaw.write(1094);
    Serial.print("Ready");
     vw_set_rx_pin(receive_pin);
    vw_setup(2000);
       vw_rx_start(); 
       pinMode(wlacznik,INPUT);
       pinMode(led_pin,OUTPUT);
        servoYaw.detach();
}


// this function just increments a value until it reaches a maximum
int incPulse(int val, int inc){
   if( val + inc  > 2000 )
	return 1000 ;
   else
	 return val + inc;
}

void loop()
{
  
 if  ((digitalRead(wlacznik)==HIGH) && (start==0))
 {
     servoYaw.attach(yawPin);
     delay(40);
     digitalWrite(led_pin,HIGH);
     servoYaw.write(1554);
     delay(500);
          servoYaw.detach();
          start=1;
      digitalWrite(led_pin,LOW);
      
 }
 else
 {
uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen)) // jeśli odbierzemy dane
    {
	int i;
        String wiadomosc;

   
        	
	for (i = 0; i < buflen; i++) // w pętli zczytujemy dane z odbiornika
	{
            wiadomosc+=char(buf[i]);
	}

	Serial.println(wiadomosc);
  if (wiadomosc=="5")
       {
         servoYaw.attach(yawPin);
         digitalWrite(led_pin,HIGH);
         delay(1000);
         servoYaw.write(1554);
         delay(1000);
         servoYaw.detach();
 // Serial.print(val);
    
   delay(5000);
       }
    }
  
       else {
          digitalWrite(led_pin,LOW);
  // val = incPulse(servoYaw.read(), 4);
   //servoYaw.write(1594);
  
 // Serial.print(val);
    
   delay(10);
       }
}
}

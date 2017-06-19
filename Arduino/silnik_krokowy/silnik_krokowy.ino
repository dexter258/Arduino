#include <Stepper.h>
//#include <VirtualWire.h>
#define receive_pin 11

#define STEPS 200

const char *wiadomosc;
int silnik=3;
int uv=4;
int glos=2;

Stepper stepper(STEPS, 5, 6, 7, 8);
int previous = 0;

void setup()
{
   stepper.setSpeed(80);
    Serial.begin(9600);
    Serial.println("setup");
    pinMode(silnik,OUTPUT);
 pinMode(uv,OUTPUT);
  pinMode(glos,OUTPUT);
  
    vw_set_rx_pin(receive_pin);
    vw_setup(2000);	
 
    vw_rx_start(); // startujemy odbieranie danych (uruchamiamy)
digitalWrite(silnik,LOW);
digitalWrite(uv,LOW);
digitalWrite(glos,LOW);

}

void loop()
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
       if ((wiadomosc=="2") &&(previous==0))
       {
    digitalWrite(silnik,HIGH);
    delay(1000);
   digitalWrite(glos,HIGH);
   delay(850);
    digitalWrite(glos,LOW);
 stepper.step(3150);
  delay(10000);
   digitalWrite(silnik,LOW);
   delay(40);
   digitalWrite(uv,HIGH);
  previous=1;
  }
     if (wiadomosc=="3")
       {
    digitalWrite(silnik,HIGH);
    delay(400);
   stepper.step(900);
  delay(4000);
   digitalWrite(silnik,LOW);
   delay(40);
  }
    if (wiadomosc=="8")
       {
   digitalWrite(silnik,HIGH);
   digitalWrite(glos,HIGH);
   delay(850);
       digitalWrite(glos,LOW);
       stepper.step(300);
    delay(2000);
    digitalWrite(silnik,LOW);
      digitalWrite(uv,HIGH);
  }
       }

    } 

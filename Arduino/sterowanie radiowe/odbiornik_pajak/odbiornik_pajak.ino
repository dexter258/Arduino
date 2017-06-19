#include <VirtualWire.h>
#include<ServoTimer2.h>
//ServoTimer2 serwo;
#define receive_pin 11
#define led_pin 8


#define yawPin   4

ServoTimer2 servoRoll;    // declare variables for up to eight servos
ServoTimer2 servoPitch;
ServoTimer2 servoYaw;

const char *wiadomosc;
void setup()
{
   servoYaw.attach(yawPin);
   // Serial.begin(9600);
   // Serial.println("setup");
  //  serwo.attach(5);
// przygotowujemy potrzebne informacje dla biblioteki
    vw_set_rx_pin(receive_pin);
    vw_setup(2000);	
   pinMode(led_pin,OUTPUT); 


    vw_rx_start(); // startujemy odbieranie danych (uruchamiamy)

 
}

void loop()
{
  // częśc wymagana do poprawnego działania biblioteki
 /*  uint8_t buf[VW_MAX_MESSAGE_LEN];
  //  uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // jeśli odbierzemy dane
    {
	int i;
        String wiadomosc;

   
        	
	for (i = 0; i < buflen; i++) // w pętli zczytujemy dane z odbiornika
	{
            wiadomosc+=char(buf[i]);
	}

	Serial.println(wiadomosc);
       if (wiadomosc=="1")
       {
         digitalWrite(led_pin, HIGH);
         delay(1000);
          servoYaw.write(1700);
           delay(4000);
       }
else
{*/
digitalWrite(led_pin, LOW);
  servoYaw.write(1050);
 // Serial.print(val);
    Serial.print("  mmm ");
   delay(1000);
      servoYaw.write(1700);
         delay(1000);

    }

    


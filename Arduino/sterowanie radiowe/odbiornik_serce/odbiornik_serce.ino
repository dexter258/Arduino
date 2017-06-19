#include <VirtualWire.h>
#define receive_pin 11
#define serce 4
#define led 6
const char *wiadomosc;
void setup()
{
 
    Serial.begin(9600);
    Serial.println("setup");

// przygotowujemy potrzebne informacje dla biblioteki
    vw_set_rx_pin(receive_pin);
    vw_setup(2000);	
   pinMode(serce,OUTPUT); 
pinMode(led,OUTPUT); 
    vw_rx_start(); // startujemy odbieranie danych (uruchamiamy)

 
}

void loop()
{
  // częśc wymagana do poprawnego działania biblioteki
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
       if (wiadomosc=="9")
       {
         digitalWrite(led, HIGH);
   digitalWrite(serce, HIGH);
   delay(2000);
   digitalWrite(serce, LOW);
          digitalWrite(led, LOW);
       }
else
{
digitalWrite(serce, LOW);

}
    }

    
}

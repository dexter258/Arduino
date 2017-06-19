#include <VirtualWire.h>
#define receive_pin 11
#define nietoperz 5
int dwojka=0;
const char *wiadomosc;
void setup()
{
 
    Serial.begin(9600);
    Serial.println("setup");
   
// przygotowujemy potrzebne informacje dla biblioteki
    vw_set_rx_pin(receive_pin);
    vw_setup(2000);	
   pinMode(nietoperz,OUTPUT); 

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
       if (wiadomosc=="1")
       {
         digitalWrite(nietoperz,HIGH);
              delay(1000);
          digitalWrite(nietoperz,LOW);
          delay(13800);
          digitalWrite(nietoperz,HIGH);
              delay(1000);
          digitalWrite(nietoperz,LOW);
       }
        if ((wiadomosc=="2") && (dwojka==0))
       {
         digitalWrite(nietoperz,HIGH);
              delay(1000);
          digitalWrite(nietoperz,LOW);
          delay(13800);
          digitalWrite(nietoperz,HIGH);
              delay(1000);
          digitalWrite(nietoperz,LOW);
          dwojka=1;
       }
         if (wiadomosc=="6")
       {
         digitalWrite(nietoperz,HIGH);
              delay(1000);
          digitalWrite(nietoperz,LOW);
          delay(13800);
          digitalWrite(nietoperz,HIGH);
              delay(1000);
          digitalWrite(nietoperz,LOW);
       }
else
{
digitalWrite(nietoperz, LOW);
 
}
    }
}

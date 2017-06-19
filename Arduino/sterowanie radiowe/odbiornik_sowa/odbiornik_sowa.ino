#include <VirtualWire.h>
#define receive_pin 11
#define  sowa 8
int dwojka=0;
#define glosnik 5
const char *wiadomosc;
void setup()
{
 
    Serial.begin(9600);
    Serial.println("setup");

// przygotowujemy potrzebne informacje dla biblioteki
    vw_set_rx_pin(receive_pin);
    vw_setup(2000);	
   pinMode(sowa,OUTPUT); 
pinMode(glosnik,OUTPUT);
digitalWrite(glosnik,LOW);
    vw_rx_start(); // startujemy odbieranie danych (uruchamiamy)

 digitalWrite(sowa,LOW);
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
 
   digitalWrite(sowa, HIGH);
   digitalWrite(glosnik,HIGH);
   delay(850);
   digitalWrite(glosnik,LOW);
    digitalWrite(sowa, LOW);

   delay(15000);
         
       }
        if ((wiadomosc=="2") && (dwojka==0))
       {
 
   digitalWrite(sowa, HIGH);
//   delay(850);
 digitalWrite(glosnik,HIGH);
   delay(850);
   digitalWrite(glosnik,LOW);

    digitalWrite(sowa, LOW);

   delay(15000);
   dwojka=1;
         
       }
            if (wiadomosc=="7")
       {
 
   digitalWrite(sowa, HIGH);
   digitalWrite(glosnik,HIGH);
//   delay(850);
 
   delay(850);
  digitalWrite(glosnik,LOW);

    digitalWrite(sowa, LOW);

   delay(15000);
         
       }
else
{
digitalWrite(sowa, LOW);

}
    }

    
}

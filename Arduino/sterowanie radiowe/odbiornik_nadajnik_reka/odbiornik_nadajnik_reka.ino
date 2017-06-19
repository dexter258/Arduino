#include <VirtualWire.h>
#define receive_pin 11
#define transmit_pin 10
#define serce 6
int switchPin = 7;
const char *wiadomosc;
int p=0;
boolean glosy=false;
const char *wiadomosc_wysylanie;
boolean gargulce=false;
void setup()
{
 
    Serial.begin(9600);
    Serial.println("setup");
vw_set_tx_pin(transmit_pin);
    vw_set_rx_pin(receive_pin);
    vw_setup(2000);	
   pinMode(serce,OUTPUT); 
pinMode(switchPin,INPUT);
    vw_rx_start(); // startujemy odbieranie danych (uruchamiamy)

 digitalWrite(serce,LOW);
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
       if (wiadomosc=="dotyk")
       {
         gargulce=true;
   digitalWrite(serce, HIGH);
   delay(2000);
   digitalWrite(serce, LOW);
         
       }
else
{
digitalWrite(serce, LOW);

}

    }
    
    if ((digitalRead(switchPin)==HIGH) && (glosy==false))
    {
      glosy=true;
      delay(7000);
      wiadomosc_wysylanie="1";
      String toSend = (wiadomosc_wysylanie); // tekst wiadomości
char msg2[23]; // tworzymy tablicę typu char
  toSend.toCharArray(msg2, toSend.length() + 1); // konwertujemy nasz tekst do tablicy charów
 vw_send((uint8_t *)msg2, strlen(msg2));// wysyłamy 
  vw_wait_tx(); 
    }

    
}

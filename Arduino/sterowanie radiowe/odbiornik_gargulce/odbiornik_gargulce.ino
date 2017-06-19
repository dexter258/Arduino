#include <VirtualWire.h>
#define receive_pin 11
#define  led 8
#define gargulec2 4
#define gargulec1 5
#define  led_niebieska0 0
#define  led_niebieska1 1
#define  led_niebieska2 2
int dwojka=0;
const char *wiadomosc;
void setup()
{
 
    Serial.begin(9600);
    Serial.println("setup");

// przygotowujemy potrzebne informacje dla biblioteki
    vw_set_rx_pin(receive_pin);
    vw_setup(2000);	
   pinMode(led,OUTPUT); 
 pinMode(gargulec1,OUTPUT); 
  pinMode(gargulec2,OUTPUT); 
  pinMode(led_niebieska0,OUTPUT); 
    pinMode(led_niebieska1,OUTPUT); 
      pinMode(led_niebieska2,OUTPUT); 
    vw_rx_start(); // startujemy odbieranie danych (uruchamiamy)
digitalWrite(led_niebieska0,LOW);
 digitalWrite(led_niebieska1,LOW);
 digitalWrite(led_niebieska2,LOW);
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
       if (wiadomosc=="1")                          // WIADOMOSC   1 
       {
   digitalWrite(led, HIGH);
   digitalWrite(gargulec1, HIGH);
   digitalWrite(gargulec2, HIGH);
   delay(850);

    digitalWrite(gargulec1, LOW);
   digitalWrite(gargulec2, LOW);
   delay(15000);
      digitalWrite(led, LOW);
         
       }
       
             if  ((wiadomosc=="2") && (dwojka==0))          // WIADOMOSC   2
       {
   digitalWrite(led, HIGH);
   digitalWrite(gargulec1, HIGH);
   digitalWrite(gargulec2, HIGH);
   delay(850);

    digitalWrite(gargulec1, LOW);
   digitalWrite(gargulec2, LOW);
   delay(15000);
      digitalWrite(led, LOW);
         dwojka=1;
       } 
        if (wiadomosc=="4")            // WIADOMOSC   4 
       {
  digitalWrite(led, HIGH);
   digitalWrite(gargulec1, HIGH);
   digitalWrite(gargulec2, HIGH);
   delay(850);

    digitalWrite(gargulec1, LOW);
   digitalWrite(gargulec2, LOW);
   delay(15000);
      digitalWrite(led, LOW);
     
       }
       
       if (wiadomosc=="0")                  // WIADOMOSC   0 
       {
   digitalWrite(led_niebieska0, HIGH);
   digitalWrite(led_niebieska1, HIGH);
   digitalWrite(led_niebieska2, HIGH);
   delay(2500);
  digitalWrite(led_niebieska0, LOW);
   digitalWrite(led_niebieska1, LOW);
    digitalWrite(led_niebieska2, LOW);
      }
       
else
{
digitalWrite(led, LOW);
    digitalWrite(gargulec1, LOW);
   digitalWrite(gargulec2, LOW);
 digitalWrite(led_niebieska0, LOW);
   digitalWrite(led_niebieska1, LOW);
    digitalWrite(led_niebieska2, LOW);
 
}
    }

    
}

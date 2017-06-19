#include <VirtualWire.h>
#define receive_pin 11
#define zielona 10
#define niebieska 2
#define zolta 7 
#define przycisk1 3
#define przycisk2 6
boolean klucz=false;
unsigned long time=0;
boolean ledState=LOW;
const char *wiadomosc;
void setup()
{
 
    Serial.begin(9600);
    Serial.println("setup");


    vw_set_rx_pin(receive_pin);
    vw_setup(2000);
  vw_rx_start(); 
  
  pinMode(zielona,OUTPUT);
   pinMode(zolta,OUTPUT);
   pinMode(niebieska,OUTPUT);
   pinMode(przycisk1,INPUT);
   pinMode(przycisk2,INPUT);
   digitalWrite(zielona,HIGH);
   digitalWrite(niebieska,LOW);
   digitalWrite(zolta,LOW);
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

	//Serial.println(wiadomosc);
       if (wiadomosc=="2")
       {
   digitalWrite(niebieska, HIGH);
       }
  if ((wiadomosc=="1") || (wiadomosc=="3")||(wiadomosc=="4")||(wiadomosc=="6")||(wiadomosc=="7")||(wiadomosc=="8")||(wiadomosc=="9")||(wiadomosc=="dotyk")){
    digitalWrite(zolta,HIGH);
    }
    if (wiadomosc=="5")
    {
      klucz=true;
      ledState=HIGH;
    }
    wiadomosc="";
    }
if (digitalRead(przycisk1)==HIGH)
{
  digitalWrite(niebieska,LOW);J
}
if (digitalRead(przycisk2)==HIGH){
  digitalWrite(zolta,LOW);
  klucz=false;
}
if (klucz==true)
{
  if (millis()-time>1000){
    time=millis();
  digitalWrite(zolta,ledState);
  ledState=!ledState;
  }
}

    
}

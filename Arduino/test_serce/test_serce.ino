#include <VirtualWire.h>
#include <SoftwareSerial.h>
#include <ServoTimer2.h>  // the servo library

SoftwareSerial RFID = SoftwareSerial(0,1);
#define rollPin 9
ServoTimer2 servoRoll;    // declare variables for up to eight servos

int tranzystor=12;
#define transmit_pin 10
#define pot_pin A0

int p=0;
boolean start=false;
const char *wiadomosc;
void setup()
{
   servoRoll.attach(rollPin);     // attach a pin to the servos and they will start pulsing

    RFID.begin(9600);
     Serial.begin(9600);
  Serial.println("Serial Ready");
  // przygotowujemy potrzebne informacje dla biblioteki
    vw_set_tx_pin(transmit_pin);
    vw_setup(2000);
   pinMode(tranzystor, OUTPUT);
}
char c;
String msg;

void loop()
{
  while(RFID.available()>0){
    c=RFID.read(); 
    msg += c;
  }

  if (msg.length() > 10) {
    msg = msg.substring(1,13);
    Serial.println(msg);
    
  }
    if ((msg=="020030BF931E")||(msg=="110016B0FA4D"))
    {
      Serial.println("ZAJEBISCIE");
wiadomosc="6";

//else { wiadomosc="0";}
  String toSend = (wiadomosc); // tekst wiadomości

char msg[23]; // tworzymy tablicę typu char
  toSend.toCharArray(msg, toSend.length() + 1); // konwertujemy nasz tekst do tablicy charów
  
  

  vw_send((uint8_t *)msg, strlen(msg));// wysyłamy 
  vw_wait_tx(); 
  start=true;
 
  //delay(6000);


    }
  msg="";
  if (start==true){
    for (int q=0;q<6;q++){
    digitalWrite(tranzystor,HIGH);
       for (int val=0;val<2000;val=val+20)
  {

   servoRoll.write(val);
      delay(10);   
  }
  digitalWrite(tranzystor,LOW);
  for (int val=2000;val>1;val=val-20)
  {
  servoRoll.write(val);
      delay(10);   
  }
  }
  start=false;
  }
}

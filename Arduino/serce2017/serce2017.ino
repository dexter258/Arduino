#include <VirtualWire.h>
#include <SoftwareSerial.h>
#include <ServoTimer2.h>  // the servo library

SoftwareSerial RFID = SoftwareSerial(0,1);
#define rollPin 9
ServoTimer2 servoRoll;    // declare variables for up to eight servos
unsigned long previousMillis = 0;
const long interval = 60000;
int tranzystor=11;
#define transmit_pin 10
#define pot_pin A0
int praca=0;
int p=0;
int koniec=950;
boolean prawo=true;
boolean start=false;
boolean servo_zalaczone=false;
const char *wiadomosc;
void setup()
{
   //servoRoll.attach(rollPin);     // attach a pin to the servos and they will start pulsing

    RFID.begin(9600);
     Serial.begin(9600);
  Serial.println("Serial Ready");
  // przygotowujemy potrzebne informacje dla biblioteki
    vw_set_tx_pin(transmit_pin);
    vw_setup(2000);
   pinMode(tranzystor, OUTPUT);
   analogWrite(tranzystor,1);
}
char c;
String msg;

void loop()
{
    unsigned long currentMillis = millis();
  while(RFID.available()>0){
    c=RFID.read(); 
    msg += c;
  }

  if (msg.length() > 10) {
    msg = msg.substring(1,13);
    Serial.println(msg);
    
  }
    if ((msg=="020030BF931E")||(msg=="110016B0FA4D") || (msg=="50008912EF24"))
    {
      Serial.println("ZAJEBISCIE");
wiadomosc="9";

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
    if (servo_zalaczone==false){
      servo_zalaczone=true;
    servoRoll.attach(rollPin);
    delay(150);
    }
    for (int q=0;q<20;q++){
    digitalWrite(tranzystor,HIGH);
       for (int val=0;val<koniec;val=val+20)
  {

   servoRoll.write(val);
      delay(10);   
  }
  digitalWrite(tranzystor,LOW);
  for (int val=koniec;val>1;val=val-20)
  {
  servoRoll.write(val);
      delay(10);   
  }
  if (q==11) start=false;
  }
  analogWrite(tranzystor,1);
  }
  if (start==false){
   if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
   // if (praca>=koniec) prawo=false;
   // if (praca==0) prawo=true;
  //  if (prawo==true) praca++;
  //  else praca--;
 //   servoRoll.write(praca);
    //  digitalWrite(tranzystor,HIGH);
    analogWrite(tranzystor,1);
    previousMillis = currentMillis;
    delay(1000);
        //  digitalWrite(tranzystor,LOW);
   }
  
  }
  delay(40);
}

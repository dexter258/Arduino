#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

int p=0;
int otwarte=0;

int cewka1=4;
int cewka2=5;
int cewka3=6;
int cewka4=7;
int odliczanie =8;
int sygnal_RF =10;
int getFingerprintIDez();
int odliczanie_stop=0;

// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
SoftwareSerial mySerial(2, 3);


Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()  
{
  
  Serial.begin(9600);
  Serial.println("fingertest");
  pinMode(9,INPUT);
  pinMode(odliczanie,OUTPUT);
  pinMode(cewka1,OUTPUT);
  pinMode(cewka2,OUTPUT);
  pinMode(cewka3,OUTPUT);
  pinMode(cewka4,OUTPUT);
  
  pinMode(sygnal_RF,OUTPUT);
  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1);
  }
  Serial.println("Waiting for valid finger...");
}

void loop()                     \
{
   getFingerprintIDez();
  delay(50);

if (otwarte==1)
  {
   if (odliczanie_stop==0)
   {
     digitalWrite(odliczanie,HIGH); //po otworzeniu wieka uruchomienie odliczania
    }
    if (digitalRead(9)==HIGH)   //sprawdzanie czy kołek został wbity w serce
      {
    digitalWrite(odliczanie,LOW);     //jeżeli tak zatrzymanie licznika
    
    digitalWrite(sygnal_RF,HIGH);          //wysyłanie sygnału aby wypadł klucz
    delay(1000);
    digitalWrite(sygnal_RF,LOW);
    odliczanie_stop=1;
  }
     
              
     
  }
  
  
}



//program do sczytywania odcisków palców
uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);

 if (finger.fingerID==2)
  {


        digitalWrite(cewka1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1500);               // wait for a second
   digitalWrite(cewka2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1500);  
   digitalWrite(cewka3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1500);               // wait for a second
   digitalWrite(cewka4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10000);
  digitalWrite(cewka1, LOW);
 delay(20); 
  digitalWrite(cewka2, LOW); 
   delay(20); 
  digitalWrite(cewka3, LOW);
  delay(20);  
  digitalWrite(cewka4, LOW); 
  otwarte=1;
  }
  
  
return finger.fingerID; 
}

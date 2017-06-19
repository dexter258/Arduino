#include <Wire.h>
#include <BH1750.h>
 
BH1750 czujnikSwiatla;        //zmienna reprezentująca czujnik
int led1=8;
int led2=9;
void setup(){
  Serial.begin(9600);         //uruchomienie monitora szeregowego
  czujnikSwiatla.begin();
  Serial.println("Uruchomiono czujnik.");
  pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
}
 
 
void loop() {
  uint16_t lux = czujnikSwiatla.readLightLevel();    //odczytanie wartości z czujnika
  Serial.print("Wartosc natezenia swiatla: ");       //wyświetlenie wyniku na monitorze szeregowym
  Serial.print(lux);                  
  Serial.println(" lx");
  if (lux<=10)
  {
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  }
  else 
  {
      digitalWrite(led1,LOW);
      digitalWrite(led2,HIGH);
  }
  delay(500);                                  //opóźnienie między kolejnymi odczytami
}

#include <EEPROM.h>
#include "Timer.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 5, 6, 7, 8);

int led = 9;
int buttonPinStart = 4;
int buttonStateStart;
int buttonPin = 11;
int buttonState;
int piezoPin = 10 ;
int buttonPinReset = 13;
int buttonStateReset;
int buttonPinKoniec = 12;
int buttonStateKoniec;
int bledy;
int liczwynik;
int p;
int piezo;

int odczyt1;
int odczyt2;
int liczydlo;

unsigned long ustawczas;
unsigned long czas;
unsigned long czaskoniec;
unsigned long zmienna;
unsigned long swieci;
unsigned long poprzedni;
unsigned long alarm;

Timer t;

void setup() {
  pinMode(led, OUTPUT);    
  pinMode(buttonPin, INPUT);
  pinMode(buttonPinStart, INPUT);
  pinMode(piezoPin, OUTPUT);

  odczyt1 = EEPROM.read(1);
  odczyt2 = EEPROM.read(2);

  ustawczas = 60;
  zmienna = 666;
  p = 0;
  alarm = millis()+60000;

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("Gra");
  lcd.setCursor(0, 1);
  lcd.print("Dotknij Mnie :) ");
  delay(1600);
  lcd.clear();

  int tickEvent = t.every(1000, elecd);

//   EEPROM.write(1, 0); //czyszczenie adresu 1
//   EEPROM.write(2, 0); //czyszczenie adresu 2

}
void poczatek(){ 
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("! UWAGA !");
  delay(random(2000, 8000));
  delay(1000);
  czas = ustawczas+1;
  czaskoniec = 0;
  bledy = 0;
  zmienna = czas;
  piezo = 1;
  tone(piezoPin,2500,500);
}

void zapisz(){
  odczyt1 = EEPROM.read(1);
  odczyt2 = EEPROM.read(2);

  if (odczyt1 == 255){
    odczyt2++;
    odczyt1 = 0;
    EEPROM.write(1, odczyt1);
    EEPROM.write(2, odczyt2);    
  }
  odczyt1++;
  liczydlo = odczyt2*255+odczyt1;
  EEPROM.write(1, odczyt1); 
}

void loop() {
  t.update();

  buttonStateKoniec = digitalRead(buttonPinKoniec);
  if(buttonStateKoniec == HIGH) {
    czaskoniec = czas;
  }

  buttonStateReset = digitalRead(buttonPinReset);
  if(buttonStateReset == HIGH) {
    bledy = 0;
  }

if (piezo == 1){
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH) {
    if (millis() >= poprzedni){  
      bledy++;
      poprzedni = millis()+600;
    }
    digitalWrite(led, HIGH);
    tone(piezoPin,700,200);
    digitalWrite(led, LOW);
  }
}

    buttonStateStart = digitalRead(buttonPinStart);
    if(buttonStateStart == HIGH) {
    poczatek();  
    }

  if (zmienna == 666 ){
    if (p >= 0 && p <= 200){
      lcd.setCursor(0, 0);
      lcd.print("Czekam na START ");  
      lcd.setCursor(0, 1);
      lcd.print("                ");  
      p++;
    }

    if (p >= 201 && p <= 450){
      lcd.setCursor(0, 0);
      lcd.print(" Ostatni wynik: ");
      lcd.setCursor(6, 1);
      lcd.print(liczwynik);
      p++;
    }          

    if (p >= 451 && p <= 650){
      liczydlo = odczyt2*255+odczyt1;      
      lcd.setCursor(0, 0);
      lcd.print("  Zagrano juz   ");
      lcd.setCursor(3, 1);
      lcd.print(liczydlo);
      lcd.write(" razy.");
      p++;
    }      

    if (p >= 651 && p <= 800){
      lcd.setCursor(0, 0);
      lcd.print("Czekam na START ");  
      lcd.setCursor(0, 1);
      lcd.print("                ");  
      p++;
    }

    if (p >= 801){
      lcd.setCursor(0, 0);
      lcd.print("   Wersja 2.6   ");
      lcd.setCursor(0, 1);
      lcd.print("by Rekin 03.2013");
      p++;
      if (p == 1000){
        p = 0;
      }
    }

    if (alarm <= millis()){
      tone(piezoPin,2500,1000);
      alarm = millis()+7000;
    }
  }

}
void pokaz(){
  tone(piezoPin,2500,200);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Wynik gry: ");
  lcd.print(liczwynik);
  lcd.setCursor(0, 1);
  lcd.print("Bledow: ");
  lcd.print(bledy);
  zapisz();
  alarm = millis()+60000;
  delay(6000);
  czas = 0;
  czaskoniec = 0;
  zmienna = 666;
  p = 0;
  piezo = 0;
}

void elecd(){

  if (czas >= 0 && czas < ustawczas+2){
    lcd.clear();
    czas = czas -1;
    lcd.setCursor(0, 0);
    lcd.print("Pozostalo: ");
    lcd.print(czas);
    lcd.print(" s.");
    lcd.setCursor(0, 1);
    lcd.print("Bledy: ");
    lcd.print(bledy);

    if (czas == 0) {
      liczwynik = 100-(bledy*25);
      pokaz();
    }

    if (czaskoniec > 0) {
      liczwynik = 100-(bledy*25)+(czaskoniec*4);
      pokaz();
    } 
  }
}

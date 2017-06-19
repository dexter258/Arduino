// --- zamek szyfrowy ... by wk@warcaby.lh.pl --------------
/* OPIS:
------------------------------------------------------------
- Klawiatura numeryczna 4X4 połączona do pinów 2-9 Arduino
- Pin 10 do połączenia BUZERA
- Pin 11 - wyjście sterujące zamkiem
- szyfr 5-cio znakowy 
- zmiana szyfru po wpisaniu kombinacji: *7#AC ( lub innej dowolnej 
 5-cio znakowej - patrz w programie )
- do konfiguracji i sprawdzenia działania połacz Serial Terminal (kabel USB)
---------------------------------------------------------- */
#include <Keypad.h>
#include<EEPROM.h>
// --- zmiennie ------------------------------------------
const byte wiersze= 4; //ilość wierszy
const byte kolumny= 4; //ilość kolumn
//definicja klawiszy (identycznie jak na klawiaturze)
char mapaklawiszy[wiersze][kolumny]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};
byte wiersze_piny[wiersze] = {9,8,7,6}; // wiersze 0-3
byte kolumny_piny[kolumny]= {5,4,3,2}; // kolumny 0-3
int pamiec[5]; // pamięc wciśniętych klawiszy - 5 znaków
volatile int szyfr=0; // szyfr=0 -> brak szyfr=1 jest aktywny
volatile int l=0; // zmienna pomocnicza, licznik znaków
volatile int result=0; // rezultat porównania ciągu 5-ciu znaków
int mykey[5]; // taklica wciśnietych znaków
Keypad myKeypad= Keypad(makeKeymap(mapaklawiszy), wiersze_piny, kolumny_piny,
 wiersze, kolumny); 
// definicja obiektu klasy Keypad
// --- funkcje programu: --------------------------------- 
void warning_0() 
  {
    digitalWrite(10,1);delay(600);digitalWrite(10,0);delay(30);
    warning_1();
  } // bipper dla OK
void warning_1() 
  {
    digitalWrite(10,1);delay(30);digitalWrite(10,0);delay(30);
  } // bipper dla wrong code
void odczyt_EEPROM() // funkcja sprawdza obecnośc szyfru w pamięci EEPROM
  {
   for (int i=0;i<5;i++) {pamiec[i]=EEPROM.read(i);} 
   if(pamiec[0]!=255 && pamiec[1]!=255 && pamiec[2]!=255 && pamiec[3]!=255 
   && pamiec[4]!=255) szyfr=1; else szyfr=0; 
   // jeśli jest KOD to szyfr =1 else szyfr =0
  }
void fnowy_kod() // funkcja ustawia nową kombinację dla szyfru
  {
   for(int i=0;i<5;i++)EEPROM.write(i,255); //kasowanie EEPROM
   Serial.println("Skasowano stary kod dostepu");
   Serial.print("Wprowadz nowy KOD dostepu: "); 
   while(l<5)
     {
     char keypressed = myKeypad.getKey();
     if (keypressed != NO_KEY)
       {
       EEPROM.write(l,keypressed);l++; // zapis pojedynczego znaku
       Serial.print(keypressed);warning_1(); // komunikacja po RS
       } 
     }
   for(int k=0;k<3;k++){
   warning_1();warning_1();warning_1();warning_1();warning_1();delay(300);}
   Serial.println(" ---> Kod dostepu zapisany");l=0; 
  }
void dostep() // funkcja sterująca zamkiem
  {
   Serial.print("Wprowadz KOD dostepu: "); 
   while(l<5)
     {
     char keypressed = myKeypad.getKey();
     if (keypressed != NO_KEY)
       {
       mykey[l]=keypressed;l++;Serial.print(keypressed);warning_1();
       } 
     }
   if( mykey[0]==pamiec[0] && mykey[1]==pamiec[1] && mykey[2]==pamiec[2] 
   && mykey[3]==pamiec[3] && mykey[4]==pamiec[4] )
     {
     warning_1();warning_1();
     Serial.println(" OK ---> OTWIERAM ZAMEK na 3 sekundy !!!");
     digitalWrite(11,HIGH);delay(1000);digitalWrite(11,LOW); 
     // otwieram zamek na 3 sek 
     } 
   // sprawdzamy czy wybrano specjalny kod do zmiany szyfru 
   else 
     {
       result++;
       if(mykey[0]=='*' && mykey[1]=='7' && mykey[2]=='#' && mykey[3]=='A' 
       && mykey[4]=='C' )
         {
         // *7#AC 
         for(int k=0;k<3;k++){
         warning_1();warning_1();warning_1();warning_1();warning_1();
         delay(300);}
         Serial.println(" ");
         Serial.print("Wykryto polecenie zmiany kodu dostepu...");
         Serial.println(" wykonuje procedure zmiany kodu");
         delay(500);l=0;fnowy_kod();
         } 
       else result++;
     }
   if(result>1){ Serial.println(" ---> Kod NIEPRAWIDLOWY");
   warning_0();delay(500);result=0;}
   l=0; 
  }
//-------------------------------------------------------
void setup()
 {
   pinMode(10,OUTPUT);
   pinMode(11,OUTPUT);
   digitalWrite(10,0);
   digitalWrite(11,0);
   Serial.begin(9600);
   Serial.flush();
 }
//--------------------------------------------------------
void loop()
 {
   odczyt_EEPROM();delay(30);
   if(szyfr==0)fnowy_kod();else dostep();
 }
// =========== KONIEC ====================================

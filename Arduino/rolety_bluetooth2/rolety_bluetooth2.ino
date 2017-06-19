#include <Wire.h>
#include <DS1307.h>

 #include <EEPROM.h>
DS1307 clock;
RTCDateTime dt;

String readString;
String wskaznik,wartosc;

boolean aktywowanie_tryb_godz_2=false; 
int wysokosc, kroki, przesuniecie_2, poziom_rolety_2, godz_noc_2,minut_noc_2,godz_dzien_2,minut_dzien_2;
int predkosc_2 = 1300;
int natezenie_2 = 400;

const int dirPin_2 = 2;
const int stepPin_2 = 3; 
const int enable_2 = 4;


boolean aktywowanie_tryb_godz_1=false; 
int   przesuniecie_1, poziom_rolety_1, godz_noc_1,minut_noc_1,godz_dzien_1,minut_dzien_1;
int predkosc_1 = 1300;
int natezenie_1= 400;

const int dirPin_1 = 5;
const int stepPin_1 = 6; 
const int enable_1 = 7;


boolean rozne_godz_noc=true;

boolean rozne_godz_dzien=true;
boolean mniejszy_lewy=false;
boolean mniejszy_prawy=false;


unsigned long previousMillis = 0;        // will store last time LED was updated
  
const long interval = 1000;  

boolean silnik_lewy=false;
boolean silnik_prawy=false;
int p=0;
int l=0;
 unsigned long time,previousMillis_1,previousMillis_2;
 boolean stan_1=LOW;
 boolean stan_2=LOW;
 boolean koniec=false;
 
 
void setup() {
  Serial.begin(9600);
   Serial.println("Inicjalizacja DS1307");
  
  clock.begin();
  if (!clock.isReady())
  {
   // clock.setDateTime(__DATE__, __TIME__);
   //clock.setDateTime(2016, 10, 18, 20, 12, 00);
  }
    pinMode(dirPin_2,OUTPUT);
    pinMode(stepPin_2,OUTPUT); 
    pinMode(enable_2,OUTPUT);
    digitalWrite(enable_2,HIGH);
    
     pinMode(dirPin_1,OUTPUT);
    pinMode(stepPin_1,OUTPUT); 
    pinMode(enable_1,OUTPUT);
    digitalWrite(enable_1,HIGH);
    
    
     poziom_rolety_1=EEPROM.read(0);
     //analogWrite(roleta_1,poziom_rolety_1);
   
      poziom_rolety_2=EEPROM.read(1);
   //   analogWrite(roleta_2,poziom_rolety_2);
}
void loop(){

  dt = clock.getDateTime();
  while (Serial.available()){
    delay(3);
    char c = Serial.read();
    readString+=c;
  }
  
  
  

  if (readString.length()>0){
    
   wskaznik=readString.substring(0,5);
   wartosc=readString.substring(5);
   Serial.print(wskaznik);
    Serial.print(wartosc);
   if (wskaznik=="_OBA_")                                 // sprawdzanie ktore silniki maja byc aktywne
   {
     silnik_lewy=true;
     silnik_prawy=true;
   }
    if (wskaznik=="LEWE_")
   {
     silnik_lewy=true;
     silnik_prawy=false;
   }
     if (wskaznik=="PRAWE")
   {
     silnik_lewy=false;
     silnik_prawy=true;
       Serial.print("Raw data: ");
  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");
   }
   
 Serial.println(silnik_lewy);
   Serial.println(silnik_prawy);
   
   
   
  if (wskaznik=="r2wys")                   // odczytywanie wyznaczonego ustawienia na suwaku i dostosowywanie pracy odpowiednich silników
   
  {
    wysokosc=wartosc.toInt();
  
      kroki=map(wysokosc,0,100,0,255);
  //  kroki_2=255-kroki_2;
  if (silnik_lewy==true){
     EEPROM.write(0,kroki);
      przesuniecie_1=kroki-poziom_rolety_1;
      
         if (przesuniecie_1!=0)
      {
     if (przesuniecie_1<0){
       digitalWrite(dirPin_1,LOW); 
     }
       if (przesuniecie_1>0){
     
       digitalWrite(dirPin_1,HIGH); 
     }
      }
       digitalWrite(enable_1,LOW);
       przesuniecie_1=abs(przesuniecie_1);
       przesuniecie_1=map(przesuniecie_1,0,255,0,3800);
      // przesuniecie=przesuniecie_1;
  }
  if (silnik_prawy==true){
     EEPROM.write(1,kroki);
     przesuniecie_2=kroki-poziom_rolety_2;
      if (przesuniecie_2!=0)
      {
     if (przesuniecie_2<0){
       digitalWrite(dirPin_2,LOW); 
     }
       if (przesuniecie_2>0){
     
       digitalWrite(dirPin_2,HIGH); 
     }
      }
       digitalWrite(enable_2,LOW);
       przesuniecie_2=abs(przesuniecie_2);
       przesuniecie_2=map(przesuniecie_2,0,255,0,4400);
  //     przesuniecie=przesuniecie_2;
  }
     delay(1800);
   
     if ((silnik_lewy==true) && (silnik_prawy==false)){                              //  RUCH ROLET tylko LEWE
      for(int x = 0; x < przesuniecie_1; x++) {
    digitalWrite(stepPin_1,HIGH); 
    delayMicroseconds(predkosc_1); 
    digitalWrite(stepPin_1,LOW); 
    delayMicroseconds(predkosc_1); 
  }
     }
    
     if ((silnik_prawy==true) && (silnik_lewy==false)){                                //  RUCH ROLET tylko PRAWE
      for(int x = 0; x < przesuniecie_2; x++) {
    digitalWrite(stepPin_2,HIGH); 
    delayMicroseconds(predkosc_2); 
    digitalWrite(stepPin_2,LOW); 
    delayMicroseconds(predkosc_2); 
  }
     }
    if ((silnik_prawy==true) && (silnik_lewy==true)) {                              //  RUCH ROLET                 OBA OKNA
   previousMillis_1=micros();   
   previousMillis_2=micros();
 do {
    unsigned long currentMillis = micros();
   
   if ((l<=(2*przesuniecie_1)) && (silnik_lewy==true))
   {
   
  if (currentMillis - previousMillis_1 >= predkosc_1) {
    l++;
   stan_1=!stan_1;
  
       digitalWrite(stepPin_1,stan_1);
        previousMillis_1=currentMillis;
  }
   }
   
    if ((p<=(2*przesuniecie_2)) && (silnik_prawy==true))
   {
   
  if (currentMillis - previousMillis_2 >= predkosc_2) {
    p++;
   stan_2=!stan_2;
  
       digitalWrite(stepPin_2,stan_2);
        previousMillis_2=currentMillis;
  }
   } 
  if  ((p>=(2*przesuniecie_2)) && (l>=(2*przesuniecie_1)))
  {
   koniec=true; 
  }
  else {koniec=false;}
 } while (koniec==false);
 p=0;
 l=0;
    }
  
  
  delay(1000);
  if (silnik_lewy==true){
  digitalWrite(enable_1,HIGH);
  poziom_rolety_1=EEPROM.read(0);
   }
  
   if (silnik_prawy==true){
  digitalWrite(enable_2,HIGH);
  poziom_rolety_2=EEPROM.read(1);
   }
  
  }
  
  
  
     
   if (wskaznik=="r2pre")                   // przypisywanie predkosci odpowiednim silnikom
   
  {
    if (silnik_lewy==true){
    predkosc_1=wartosc.toInt();
    }
    if (silnik_prawy==true){
    predkosc_2=wartosc.toInt();
    }
  }
  
    if (wskaznik=="r2nat")                          // // przypisywanie natezenia swiatla odpowiednim oknom
   
  {
    if (silnik_lewy==true){
    natezenie_1=wartosc.toInt();
    }
    if (silnik_prawy==true){
    natezenie_2=wartosc.toInt();
    }
  }
  
  if (wskaznik=="r2gno")                // przypisywanie godziny zamykania w nocy o odpowiedniej godzinie
  {
    if (wartosc.substring(1,2)==":")
    {
      if (silnik_lewy==true){
     godz_noc_1= wartosc.substring(0,1).toInt();
     minut_noc_1=wartosc.substring(2).toInt();
      }
      if (silnik_prawy==true){
     godz_noc_2= wartosc.substring(0,1).toInt();
     minut_noc_2=wartosc.substring(2).toInt();
      }
    }
   
    if (wartosc.substring(2,3)==":")
    {
      if (silnik_lewy==true){
     godz_noc_1= wartosc.substring(0,2).toInt();
     minut_noc_1=wartosc.substring(3).toInt();
      }
      if (silnik_prawy==true){
     godz_noc_2= wartosc.substring(0,2).toInt();
     minut_noc_2=wartosc.substring(3).toInt();
      }
    }  
  }
  if (wskaznik=="r2gdz")           // przypisywanie godziny otwierania w dzien o odpowiedniej godzinie
  {
    if (wartosc.substring(1,2)==":")
    {
      if (silnik_lewy==true){
     godz_dzien_1= wartosc.substring(0,1).toInt();
     minut_dzien_1=wartosc.substring(2).toInt();
      }
      if (silnik_prawy==true){
     godz_dzien_2= wartosc.substring(0,1).toInt();
     minut_dzien_2=wartosc.substring(2).toInt();
      }
    }
   
    if (wartosc.substring(2,3)==":")
    {
       if (silnik_lewy==true){
     godz_dzien_1= wartosc.substring(0,2).toInt();
     minut_dzien_1=wartosc.substring(3).toInt();
       }
        if (silnik_prawy==true){
     godz_dzien_2= wartosc.substring(0,2).toInt();
     minut_dzien_2=wartosc.substring(3).toInt();
       }
    }  
  }
  
  
  
  if (wskaznik=="r2ust")                          //      NIEGOTOWE DO KONCA
  {
    if (wartosc=="godz")                  //NIEGOTOWE zamykanie o konkretnych godzinach
    {
       if (silnik_lewy==true){
      aktywowanie_tryb_godz_1=true;
       }
        if (silnik_prawy==true){
      aktywowanie_tryb_godz_2=true;
       }
    }
    if (wartosc=="off")
    {
       if (silnik_lewy==true){
        aktywowanie_tryb_godz_1=false;
       }
        if (silnik_prawy==true){
        aktywowanie_tryb_godz_2=false;
       }
    }
     if (wartosc=="zero")                               // przypisywanie pozycji poczatkowej silnikom
     {
       if (silnik_lewy==true){
       poziom_rolety_1=0;
       EEPROM.write(0,0);
       }
       if (silnik_prawy==true){
       poziom_rolety_2=0;
       EEPROM.write(1,0);
       }
     }
     if (wartosc=="end")                        // przypisywanie pozycji koncowej silnikom
     {
       if (silnik_lewy==true){
       poziom_rolety_1=255;
       EEPROM.write(0,255);
        }
        if (silnik_prawy==true){
       poziom_rolety_2=255;
       EEPROM.write(1,255);
        }
     }
  }
  

  
    Serial.println(wskaznik);
    Serial.println(wartosc);
    Serial.println();
   readString="";
  }
  
  
  
  
  

  
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (( aktywowanie_tryb_godz_2==true) && ( aktywowanie_tryb_godz_1==true))                // OBA OKNA AKTYWNE OTWIERANE NA GODZINE 
  {
    if ((godz_noc_2==godz_dzien_2) && (minut_noc_2==minut_dzien_2))
   {
     minut_dzien_2=minut_dzien_2+1;
     if (minut_dzien_2==60)
     {
       minut_dzien_2=0;
       godz_dzien_2=(godz_dzien_2+1)%24;
     }
   }
   if ((godz_noc_1==godz_dzien_1) && (minut_noc_1==minut_dzien_1))
   {
     minut_dzien_1=minut_dzien_1+1;
     if (minut_dzien_1==60)
     {
       minut_dzien_1=0;
       godz_dzien_1=(godz_dzien_1+1)%24;
     }
   }
   
   
   if ((godz_noc_2==godz_noc_1)  &&  (minut_noc_2==minut_noc_1))
   {
     rozne_godz_noc=false;
     if ((dt.hour==godz_noc_2) && (dt.minute==minut_noc_2))         ///           zamykanie rolety  okno prawe lewe nieczynne
    {
         
   wysokosc=100;
  
      kroki=map(wysokosc,0,100,0,255);
     EEPROM.write(0,kroki);
      przesuniecie_1=kroki-poziom_rolety_1;
      
         if (przesuniecie_1!=0)
      {
     if (przesuniecie_1<0){
       digitalWrite(dirPin_1,LOW); 
     }
       if (przesuniecie_1>0){
     
       digitalWrite(dirPin_1,HIGH); 
     }
      }
       digitalWrite(enable_1,LOW);
       przesuniecie_1=abs(przesuniecie_1);
       przesuniecie_1=map(przesuniecie_1,0,255,0,3800);
      // przesuniecie=przesuniecie_1;

     EEPROM.write(1,kroki);
     przesuniecie_2=kroki-poziom_rolety_2;
      if (przesuniecie_2!=0)
      {
     if (przesuniecie_2<0){
       digitalWrite(dirPin_2,LOW); 
     }
       if (przesuniecie_2>0){
     
       digitalWrite(dirPin_2,HIGH); 
     }
      }
       digitalWrite(enable_2,LOW);
       przesuniecie_2=abs(przesuniecie_2);
       przesuniecie_2=map(przesuniecie_2,0,255,0,4400);
  //     przesuniecie=przesuniecie_2;
  
     delay(1800);
   
                              //  RUCH ROLET                 OBA OKNA
   previousMillis_1=micros();   
   previousMillis_2=micros();
 do {
    unsigned long currentMillis = micros();
   
   if (l<=(2*przesuniecie_1))
   {
   
  if (currentMillis - previousMillis_1 >= predkosc_1) {
    l++;
   stan_1=!stan_1;
  
       digitalWrite(stepPin_1,stan_1);
        previousMillis_1=currentMillis;
  }
   }
   
    if (p<=(2*przesuniecie_2))
   {
   
  if (currentMillis - previousMillis_2 >= predkosc_2) {
    p++;
   stan_2=!stan_2;
  
       digitalWrite(stepPin_2,stan_2);
        previousMillis_2=currentMillis;
  }
   } 
  if  ((p>=(2*przesuniecie_2)) && (l>=(2*przesuniecie_1)))
  {
   koniec=true; 
  }
  else {koniec=false;}
 } while (koniec==false);
 p=0;
 l=0;
  
  delay(1000);
  digitalWrite(enable_1,HIGH);
  poziom_rolety_1=EEPROM.read(0);
  digitalWrite(enable_2,HIGH);
  poziom_rolety_2=EEPROM.read(1);
   
  

    }
  
   }
   else { rozne_godz_noc=true;}
   
    if ((godz_dzien_2==godz_dzien_1)  &&  (minut_dzien_2==minut_dzien_1))
   {
     rozne_godz_dzien=false;
     if ((dt.hour==godz_dzien_2) && (dt.minute==minut_dzien_2))         ///        otwieranie obu okien o tej samej godzinie
    {
         
   wysokosc=0;
  
      kroki=map(wysokosc,0,100,0,255);
     EEPROM.write(0,kroki);
      przesuniecie_1=kroki-poziom_rolety_1;
      
         if (przesuniecie_1!=0)
      {
     if (przesuniecie_1<0){
       digitalWrite(dirPin_1,LOW); 
     }
       if (przesuniecie_1>0){
     
       digitalWrite(dirPin_1,HIGH); 
     }
      }
       digitalWrite(enable_1,LOW);
       przesuniecie_1=abs(przesuniecie_1);
       przesuniecie_1=map(przesuniecie_1,0,255,0,3800);
      // przesuniecie=przesuniecie_1;

     EEPROM.write(1,kroki);
     przesuniecie_2=kroki-poziom_rolety_2;
      if (przesuniecie_2!=0)
      {
     if (przesuniecie_2<0){
       digitalWrite(dirPin_2,LOW); 
     }
       if (przesuniecie_2>0){
     
       digitalWrite(dirPin_2,HIGH); 
     }
      }
       digitalWrite(enable_2,LOW);
       przesuniecie_2=abs(przesuniecie_2);
       przesuniecie_2=map(przesuniecie_2,0,255,0,4400);
  //     przesuniecie=przesuniecie_2;
  
     delay(1800);
   
                              //  RUCH ROLET                 OBA OKNA
   previousMillis_1=micros();   
   previousMillis_2=micros();
 do {
    unsigned long currentMillis = micros();
   
   if (l<=(2*przesuniecie_1))
   {
   
  if (currentMillis - previousMillis_1 >= predkosc_1) {
    l++;
   stan_1=!stan_1;
  
       digitalWrite(stepPin_1,stan_1);
        previousMillis_1=currentMillis;
  }
   }
   
    if (p<=(2*przesuniecie_2))
   {
   
  if (currentMillis - previousMillis_2 >= predkosc_2) {
    p++;
   stan_2=!stan_2;
  
       digitalWrite(stepPin_2,stan_2);
        previousMillis_2=currentMillis;
  }
   } 
  if  ((p>=(2*przesuniecie_2)) && (l>=(2*przesuniecie_1)))
  {
   koniec=true; 
  }
  else {koniec=false;}
 } while (koniec==false);
 p=0;
 l=0;
  
  delay(1000);
  digitalWrite(enable_1,HIGH);
  poziom_rolety_1=EEPROM.read(0);
  digitalWrite(enable_2,HIGH);
  poziom_rolety_2=EEPROM.read(1);
   
  

    }
  
   }
   else { rozne_godz_dzien=true;}
    
  }
  
  
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
    if ( aktywowanie_tryb_godz_2==true)                //aktywne tylko godzinowe otwieranie okna prawego 
  {
   if ((godz_noc_2==godz_dzien_2) && (minut_noc_2==minut_dzien_2))
   {
     minut_dzien_2=minut_dzien_2+1;
     if (minut_dzien_2==60)
     {
       minut_dzien_2=0;
       godz_dzien_2=(godz_dzien_2+1)%24;
     }
   }
   
    
    
    if ((dt.hour==godz_noc_2) && (dt.minute==minut_noc_2) && (rozne_godz_noc==true))         ///           zamykanie rolety  okno prawe lewe nieczynne
    {
         wysokosc=100;
      kroki=map(wysokosc,0,100,0,255);
     EEPROM.write(1,kroki);
      przesuniecie_2=kroki-poziom_rolety_2;
      if (przesuniecie_2!=0)
      {
     if (przesuniecie_2<0){
       digitalWrite(dirPin_2,LOW); 
     }
       if (przesuniecie_2>0){
     
       digitalWrite(dirPin_2,HIGH); 
     }
     digitalWrite(enable_2,LOW);
     delay(1800);
     
       przesuniecie_2=abs(przesuniecie_2);
       przesuniecie_2=map(przesuniecie_2,0,255,0,4400);
    for(int x = 0; x < przesuniecie_2; x++) {
    digitalWrite(stepPin_2,HIGH); 
    delayMicroseconds(predkosc_2); 
    digitalWrite(stepPin_2,LOW); 
    delayMicroseconds(predkosc_2); 
  }
  delay(1000);
  digitalWrite(enable_2,HIGH);
      }
         poziom_rolety_2=EEPROM.read(1);
  }
  
  
  if ((dt.hour==godz_dzien_2) && (dt.minute==minut_dzien_2) && (rozne_godz_dzien==true))         // otwieranie rolety okno prawe lewe nieczynne
    {
         wysokosc=0;
   
      kroki=map(wysokosc,0,100,0,255);
  
     EEPROM.write(1,kroki);
      przesuniecie_2=kroki-poziom_rolety_2;
      if (przesuniecie_2!=0)
      {
     if (przesuniecie_2<0){
       digitalWrite(dirPin_2,LOW); 
     }
       if (przesuniecie_2>0){
     
       digitalWrite(dirPin_2,HIGH); 
     }
     digitalWrite(enable_2,LOW);
     delay(1800);
     
       przesuniecie_2=abs(przesuniecie_2);
       przesuniecie_2=map(przesuniecie_2,0,255,0,4400);
    for(int x = 0; x < przesuniecie_2; x++) {
    digitalWrite(stepPin_2,HIGH); 
    delayMicroseconds(predkosc_2); 
    digitalWrite(stepPin_2,LOW); 
    delayMicroseconds(predkosc_2); 
  }
  delay(1000);
  digitalWrite(enable_2,HIGH);
      }
         poziom_rolety_2=EEPROM.read(1);
  }
    
  }
  
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  if ( aktywowanie_tryb_godz_1==true)                 //aktywne tylko godzinowe otwieranie okna lewego 
  {
   if ((godz_noc_1==godz_dzien_1) && (minut_noc_1==minut_dzien_1))
   {
     minut_dzien_1=minut_dzien_1+1;
     if (minut_dzien_1==60)
     {
       minut_dzien_1=0;
       godz_dzien_1=(godz_dzien_1+1)%24;
     }
   }
   
    
    
    if ((dt.hour==godz_noc_1) && (dt.minute==minut_noc_1) && (rozne_godz_noc==true))         ///           zamykanie rolety  okno prawe lewe nieczynne
    {
         wysokosc=100;
      kroki=map(wysokosc,0,100,0,255);
     EEPROM.write(0,kroki);
      przesuniecie_1=kroki-poziom_rolety_1;
      if (przesuniecie_1!=0)
      {
     if (przesuniecie_1<0){
       digitalWrite(dirPin_1,LOW); 
     }
       if (przesuniecie_1>0){
     
       digitalWrite(dirPin_1,HIGH); 
     }
     digitalWrite(enable_1,LOW);
     delay(1800);
     
       przesuniecie_1=abs(przesuniecie_1);
       przesuniecie_1=map(przesuniecie_1,0,255,0,4400);
    for(int x = 0; x < przesuniecie_1; x++) {
    digitalWrite(stepPin_1,HIGH); 
    delayMicroseconds(predkosc_1); 
    digitalWrite(stepPin_1,LOW); 
    delayMicroseconds(predkosc_1); 
  }
  delay(1000);
  digitalWrite(enable_1,HIGH);
      }
         poziom_rolety_1=EEPROM.read(0);
  }
  
  
  if ((dt.hour==godz_dzien_1) && (dt.minute==minut_dzien_1) && (rozne_godz_dzien==true))         // otwieranie rolety okno prawe lewe nieczynne
    {
         wysokosc=0;
   
      kroki=map(wysokosc,0,100,0,255);
  
     EEPROM.write(0,kroki);
      przesuniecie_1=kroki-poziom_rolety_1;
      if (przesuniecie_1!=0)
      {
     if (przesuniecie_1<0){
       digitalWrite(dirPin_1,LOW); 
     }
       if (przesuniecie_1>0){
     
       digitalWrite(dirPin_1,HIGH); 
     }
     digitalWrite(enable_1,LOW);
     delay(1800);
     
       przesuniecie_1=abs(przesuniecie_1);
       przesuniecie_1=map(przesuniecie_1,0,255,0,4400);
    for(int x = 0; x < przesuniecie_1; x++) {
    digitalWrite(stepPin_1,HIGH); 
    delayMicroseconds(predkosc_1); 
    digitalWrite(stepPin_1,LOW); 
    delayMicroseconds(predkosc_1); 
  }
  delay(1000);
  digitalWrite(enable_1,HIGH);
      }
         poziom_rolety_1=EEPROM.read(0);
  }
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  
  
}


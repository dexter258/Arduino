#define czytnik_lini_papilarnych 12
#define rf_gargulec_halas 4
#define rf_gargulec_przegrales_cisza 3
#define rf_gargulec_zwiciestwo_cisza_klucz 2
#define glosnik_poczatek 5
#define glosnik_zabicie_draculi 6
#define glosnik_koniec_czasu 7
#define lcd_start_odliczanie 8
#define lcd_reset 10
#define lcd_koniec_czasu  9
#define kolek 11
int start=0;
int halas_poczatek=0;
int halas_koniec=0;
int halas_kolek=0;
int porazka=0;
void setup() 
{                
  pinMode(czytnik_lini_papilarnych,INPUT);
  pinMode(rf_gargulec_halas,OUTPUT);
  pinMode(rf_gargulec_przegrales_cisza,OUTPUT);
  pinMode(rf_gargulec_zwiciestwo_cisza_klucz,OUTPUT);
  pinMode(glosnik_poczatek,OUTPUT);
  pinMode(glosnik_zabicie_draculi,OUTPUT);
  pinMode(glosnik_koniec_czasu,OUTPUT);
  pinMode(lcd_start_odliczanie ,OUTPUT);
  pinMode(lcd_reset,OUTPUT);
  pinMode(lcd_koniec_czasu,INPUT);
  pinMode(kolek,INPUT);
  
}

void loop() 
{
  if (digitalRead(czytnik_lini_papilarnych)==HIGH)  //jeżeli odczyta linie papilarne
 { 
   delay(2500);
   start=1;                        
 }
 if (start==1)
 {
   
   digitalWrite(lcd_start_odliczanie,HIGH);
  if (halas_poczatek==0)
  {

  digitalWrite(glosnik_poczatek,HIGH);
  
  delay(600);
 digitalWrite(glosnik_poczatek,LOW);
  halas_poczatek=1;
  }
  if (digitalRead(lcd_koniec_czasu)==HIGH)
   {
     porazka=1;
     start=0;
   }
 }
 if ((digitalRead(kolek)==HIGH) && (porazka==0))
 {
   start=0;
   digitalWrite(lcd_start_odliczanie,LOW);
   if (halas_kolek==0)
   {

   delay(100);
    digitalWrite(glosnik_zabicie_draculi,HIGH);
       delay(650);
   digitalWrite(glosnik_zabicie_draculi,LOW);
   
   delay(200);
   delay(1900);
   digitalWrite(rf_gargulec_zwiciestwo_cisza_klucz,HIGH);
   delay(600);
   digitalWrite(rf_gargulec_zwiciestwo_cisza_klucz,LOW);
   halas_kolek=1;
   }
}
   
   if (porazka==1)
   
   {
     if (halas_koniec==0)
   {
     digitalWrite(lcd_start_odliczanie,LOW);
     digitalWrite(rf_gargulec_przegrales_cisza,HIGH);
      delay(600);
   digitalWrite(rf_gargulec_przegrales_cisza,LOW);
   
   delay(200);
    digitalWrite(glosnik_koniec_czasu,HIGH);
       delay(850);
   digitalWrite(glosnik_koniec_czasu,LOW);

   delay(5000);
   digitalWrite(lcd_reset,HIGH);
   delay(1000);
   digitalWrite(lcd_reset,LOW);
   halas_koniec=1;
   }
   
   }
}

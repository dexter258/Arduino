int s0 = 3, s1 = 4, s2 = 5, s3 = 6; //piny modułu połączone z Arduino
int out = 2;                      //pin 2 Arduino i OUT od czujnika
int flag = 0;
byte counter = 0;
byte countR = 0, countG = 0, countB = 0;
void setup()
{
  Serial.begin(9600);             //inicjalizacja monitora szeregowego
  pinMode(s0, OUTPUT);            //ustawienie pinów jako wyjścia
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
 
}
void TCS()
{
  flag = 0;
  digitalWrite(s1, HIGH);
  digitalWrite(s0, HIGH);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  attachInterrupt(0, ISR_INTO, LOW);
  timer0_init();
 
}
void ISR_INTO()
{
  counter++;
}
void timer0_init(void)
{
  TCCR2A = 0x00;
  TCCR2B = 0x07; //częstotliwość zegara - 1024
  TCNT2 = 100;   //przepełnienie 10 ms
  TIMSK2 = 0x01; //pozwolenie na przerwanie
}
int i = 0;
ISR(TIMER2_OVF_vect)           //timer 2, 10ms przepełnienie 10ms. funkcja przerwanie wewnętrzengo przepełnienia
{
  TCNT2 = 100;
  flag++;
  if (flag == 1)                 //pobranie i wyświetlenie na ekranie składowych RGB
  {
    countR = counter;
    Serial.print("red=");
    Serial.print(countR, DEC);
    Serial.print("tt");
    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
  }
  else if (flag == 2)
  {
    countG = counter;
    Serial.print("green=");
    Serial.print(countG, DEC);
    Serial.print("t");
    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
  }
  else if (flag == 3)
  {
    countB = counter;
    Serial.print("blue=");
    Serial.print(countB, DEC);
    Serial.print("t");
    Serial.println("n");
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
 
  }
  else if (flag == 4)
  {
    flag = 0;
  }
  counter = 0;
}
void loop()                    //główna pętla programu
{
  TCS();
  delay(500);
  while (1);
 
}

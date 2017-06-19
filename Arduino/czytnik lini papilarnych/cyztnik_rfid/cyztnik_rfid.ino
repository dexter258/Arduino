#define start 10
#define wieko 12
int startt=0;
int wiekoo=0;
int cewka1=6;
int cewka2=7;
int cewka3=8;
int cewka4=9;
int dlon=5;


void setup()  
{
  Serial.begin(9600);
  Serial.println("fingertest");
  pinMode(cewka1,OUTPUT);
  pinMode(cewka2,OUTPUT);
  pinMode(cewka3,OUTPUT);
  pinMode(cewka4,OUTPUT);
  pinMode(dlon,OUTPUT);
  pinMode(start,INPUT);
  pinMode(wieko,INPUT);
  digitalWrite(cewka1, LOW);
   delay(600); 
  digitalWrite(cewka2, LOW); 
   delay(600); 
  digitalWrite(cewka3, LOW);
  delay(600);  
  digitalWrite(cewka4, LOW);

}

void loop()                     // run over and over again
{
     if ( (digitalRead(start)==HIGH) || ( digitalRead(wieko)==HIGH) )
     {
 
         if  (digitalRead(start)==HIGH)
     {
   startt=1;
  }
  if (startt==1) 
  {
  digitalWrite(cewka1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(600); 

   digitalWrite(cewka2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);  
   digitalWrite(cewka3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
   digitalWrite(cewka4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);
  digitalWrite(dlon,HIGH);
  delay(800);
  digitalWrite(dlon,LOW);
  delay(42000);
  digitalWrite(cewka1, LOW);
    delay(1000); 
  digitalWrite(cewka2, LOW); 
      delay(1000);  

   digitalWrite(cewka3, LOW);
    delay(1500);  

  digitalWrite(cewka4, LOW);
  delay(500); 
  startt=0;
  digitalWrite(cewka2, LOW);
     delay(1000);  
  digitalWrite(cewka3, LOW); 
     delay(1000);  
  digitalWrite(cewka1, LOW);
    delay(1000);   
  digitalWrite(cewka4, LOW);
    delay(500);
    digitalWrite(cewka4, LOW);
   delay(1000); 
  digitalWrite(cewka2, LOW); 
   delay(1000); 
  digitalWrite(cewka3, LOW);
  delay(1000);  
  digitalWrite(cewka1, LOW); 
  delay(1500);
  digitalWrite(cewka4, LOW);
  }
      if ( digitalRead(wieko)==HIGH) 
     {
       wiekoo=1;
     }
     if (wiekoo==1)
  {
   
  digitalWrite(cewka1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(800);
    digitalWrite(cewka2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(800);
   digitalWrite(cewka3, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(800);             // wait for a second
   digitalWrite(cewka4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(45000);
  
  digitalWrite(cewka1, LOW);
    delay(600);  
  digitalWrite(cewka2, LOW); 
      delay(1000); 
  digitalWrite(cewka3, LOW);
   delay(1500);  
  digitalWrite(cewka4, LOW);
 delay(500); 
   wiekoo=0;
     digitalWrite(cewka1, LOW);
   delay(1000); 
  digitalWrite(cewka2, LOW); 
   delay(1000); 
  digitalWrite(cewka3, LOW);
  delay(1000);  
  digitalWrite(cewka4, LOW);
    delay(500); 
     digitalWrite(cewka4, LOW);
   delay(1000); 
  digitalWrite(cewka3, LOW); 
   delay(1000); 
  digitalWrite(cewka2, LOW);
  delay(1000);  
  digitalWrite(cewka1, LOW);
    delay(1500);
  digitalWrite(cewka4, LOW);
  }
     }
     else {
          digitalWrite(cewka4, LOW);
   delay(60); 
  digitalWrite(cewka2, LOW); 
   delay(60); 
  digitalWrite(cewka3, LOW);
  delay(60);  
  digitalWrite(cewka1, LOW);
     
     }
}

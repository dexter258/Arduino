#define led_1 3
#define led_2 5
#define led_3 6
#define led_4 9
#define led_5 10
#define led_6 11
int start=0;
void setup()
{
  //zapalanie sie pierszych oczu
  pinMode(led_1, OUTPUT);
 pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
 pinMode(led_5, OUTPUT);
  pinMode(led_6, OUTPUT);
}

void loop()
{
  if (start==0)
  {
    digitalWrite(led_1,HIGH);
    digitalWrite(led_2,HIGH);
    digitalWrite(led_3,HIGH);
    digitalWrite(led_4,HIGH);
    digitalWrite(led_5,HIGH);
    digitalWrite(led_6,HIGH);
    
    delay(10000);
    
    digitalWrite(led_1,LOW);
    digitalWrite(led_2,LOW);
    digitalWrite(led_3,LOW);
    digitalWrite(led_4,LOW);
    digitalWrite(led_5,LOW);
    digitalWrite(led_6,LOW);
  start=1;
}
    
   analogWrite(led_1, 0);
   delay(1000);
   analogWrite(led_1, 1);
   delay(1200);
  for (int i=2; i<10; i++)
  {
     analogWrite(led_1, i);
     delay(random(600,1000));
  }
  for (int i=10; i<80; i++)
  {
     analogWrite(led_1, i);
     delay(random(40,80));
  }
   for (int i=80; i<255; i++)
  {
     analogWrite(led_1, i);
     delay(random(10,30));
  }
  //świecenie pierwszej diody
  delay(random(30000,45000));
  
  //gaszenie pierwszej diody
   for (int i=255; i>80; i--)
  {
     analogWrite(led_1, i);
    delay(random(10,30));
  }
   for (int i=80; i>10; i--)
  {
     analogWrite(led_1, i);
     delay(random(40,50));
  }
    for (int i=10; i>2; i--)
  {
     analogWrite(led_1, i);
    delay(random(300));
  }
   analogWrite(led_1, 0);
   //ciemność
   delay(random(100000,200000));
   
   
   
  //zapalanie drugiej diody
  analogWrite(led_2, 0);
   delay(1000);
   analogWrite(led_2, 1);
   delay(1200);
  for (int i=2; i<10; i++)
  {
     analogWrite(led_2, i);
     delay(random(600,1000));
  }
  for (int i=10; i<80; i++)
  {
     analogWrite(led_2, i);
     delay(random(40,80));
  }
   for (int i=80; i<255; i++)
  {
     analogWrite(led_2, i);
     delay(random(10,30));
  }
  
  delay(random(12000,18000));
  
  //gaszenie drugiej diody
   for (int i=255; i>80; i--)
  {
     analogWrite(led_2, i);
    delay(random(10,30));
  }
   for (int i=80; i>10; i--)
  {
     analogWrite(led_2, i);
     delay(random(40,80));
  }
    for (int i=10; i>2; i--)
  {
     analogWrite(led_2, i);
    delay(random(600,1000));
  }
   analogWrite(led_2, 1);
   delay(1200);
   analogWrite(led_2, 0);
   delay(random(1000,2000));
  
    analogWrite(led_3, 0);
   delay(1000);
   analogWrite(led_3, 1);
   delay(1200);
  for (int i=2; i<10; i++)
  {
     analogWrite(led_3, i);
     delay(random(600,1000));
  }
  for (int i=10; i<80; i++)
  {
     analogWrite(led_3, i);
     delay(random(40,80));
  }
   for (int i=80; i<255; i++)
  {
     analogWrite(led_3, i);
     delay(random(10,30));
  }
  //świecenie trzeciej diody
  delay(random(10000,20000));
  
  //gaszenie trzeciej diody
   for (int i=255; i>80; i--)
  {
     analogWrite(led_3, i);
    delay(random(10,30));
  }
   for (int i=80; i>10; i--)
  {
     analogWrite(led_3, i);
     delay(random(40,50));
  }
    for (int i=10; i>2; i--)
  {
     analogWrite(led_3, i);
    delay(random(300));
  }
   analogWrite(led_3, 0);
   //ciemność
   delay(random(100000,200000));
   
   
   
   
   
   
     
  //zapalanie czwartej diody
  analogWrite(led_4, 0);
   delay(1000);
   analogWrite(led_4, 1);
   delay(1200);
  for (int i=2; i<10; i++)
  {
     analogWrite(led_4, i);
     delay(random(600,1000));
  }
  for (int i=10; i<80; i++)
  {
     analogWrite(led_4, i);
     delay(random(40,80));
  }
   for (int i=80; i<255; i++)
  {
     analogWrite(led_4, i);
     delay(random(10,30));
  }
  
  delay(random(2000,8000));
  
  //gaszenie czwartej diody
   for (int i=255; i>80; i--)
  {
     analogWrite(led_4, i);
    delay(random(10,30));
  }
   for (int i=80; i>10; i--)
  {
     analogWrite(led_4, i);
     delay(random(40,80));
  }
    for (int i=10; i>2; i--)
  {
     analogWrite(led_4, i);
    delay(random(600,1000));
  }
   analogWrite(led_4, 1);
   delay(1200);
   analogWrite(led_4, 0);
   delay(random(1000,2000));
  
    
    
    

    analogWrite(led_5, 0);
   delay(1000);
   analogWrite(led_5, 1);
   delay(1200);
  for (int i=2; i<10; i++)
  {
     analogWrite(led_5, i);
     delay(random(600,1000));
  }
  for (int i=10; i<80; i++)
  {
     analogWrite(led_5, i);
     delay(random(40,80));
  }
   for (int i=80; i<255; i++)
  {
     analogWrite(led_5, i);
     delay(random(10,30));
  }
  //świecenie trzeciej diody
  delay(random(35000,36000));
  
  //gaszenie trzeciej diody
   for (int i=255; i>80; i--)
  {
     analogWrite(led_5, i);
    delay(random(10,30));
  }
   for (int i=80; i>10; i--)
  {
     analogWrite(led_5, i);
     delay(random(40,50));
  }
    for (int i=10; i>2; i--)
  {
     analogWrite(led_5, i);
    delay(random(300));
  }
   analogWrite(led_5, 0);
   //ciemność
   delay(random(100000,200000));
   
   
   
   
   
   
     
  //zapalanie czwartej diody
  analogWrite(led_6, 0);
   delay(1000);
   analogWrite(led_6, 1);
   delay(1200);
  for (int i=2; i<10; i++)
  {
     analogWrite(led_6, i);
     delay(random(600,1000));
  }
  for (int i=10; i<80; i++)
  {
     analogWrite(led_6, i);
     delay(random(40,80));
  }
   for (int i=80; i<255; i++)
  {
     analogWrite(led_6, i);
     delay(random(10,30));
  }
  
  delay(random(15000,28000));
  
  //gaszenie czwartej diody
   for (int i=255; i>80; i--)
  {
     analogWrite(led_6, i);
    delay(random(10,30));
  }
   for (int i=80; i>10; i--)
  {
     analogWrite(led_6, i);
     delay(random(40,80));
  }
    for (int i=10; i>2; i--)
  {
     analogWrite(led_6, i);
    delay(random(600,1000));
  }
   analogWrite(led_6, 1);
   delay(1200);
   analogWrite(led_6, 0);
   delay(random(1000,2000));    
    digitalWrite(led_1,HIGH);
   delay(2500);
       digitalWrite(led_2,HIGH);
       delay(500);
      digitalWrite(led_1,LOW);
   delay(1500);
   digitalWrite(led_1,HIGH);
   delay(1500);
   digitalWrite(led_2,LOW);
   digitalWrite(led_3,HIGH);
   delay(500);
   digitalWrite(led_1,LOW);
    delay(2000);
     digitalWrite(led_3,LOW);
     delay(1500);
    digitalWrite(led_4,HIGH);
    delay(500);
    digitalWrite(led_4,LOW);
    delay(500);
    digitalWrite(led_4,HIGH);
    delay(1500);
    digitalWrite(led_4,LOW);
    delay(500);
    digitalWrite(led_5,HIGH);
    delay(1000);
     digitalWrite(led_1,HIGH);
   delay(1500);
   
   digitalWrite(led_5,LOW);
   digitalWrite(led_6,HIGH);
   delay(1500);
    digitalWrite(led_1,HIGH);
    delay(1500);
   digitalWrite(led_6,LOW);
}


  

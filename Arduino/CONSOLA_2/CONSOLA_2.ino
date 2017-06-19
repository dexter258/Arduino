boolean debudowanie=false;

int led[8];
int przycisk[8];
boolean zolty_wcisniety[3];
boolean stan_zoltych_led[3];
int k=0;
int p=0;

boolean wcisniete=false;
int diody[18];
void setup() {
  if (debudowanie==true)
  {
//Serial.begin(9600);

  }
  for (int i=0; i<3;i++)
 {
   stan_zoltych_led[i]=false;
   zolty_wcisniety[i]=false;
 }
led[0]=1;
led[1]=3;
led[2]=5;
led[3]=7;
led[4]=51;
led[5]=47;
led[6]=43;
led[7]=39;
led[8]=35;
przycisk[0]=0;
przycisk[1]=2;
przycisk[2]=4;
przycisk[3]=6;
przycisk[8]=37;
przycisk[7]=41;
przycisk[6]=45;
przycisk[5]=49;
przycisk[4]=53;
for (int i=0;i<9;i++)
{
  pinMode(led[i], OUTPUT);
}
  

for (int i=0;i<9;i++)
{
   digitalWrite(led[i],LOW); 
}
for (int t=0;t<9;t++)
{
  pinMode(przycisk[t],INPUT);
}
 
   
for (int i=0;i<3;i++)
{
  diody[i]=8+i;
    pinMode(diody[i], OUTPUT);
}

for (int i=3;i<18;i++)
{
 diody[i]=24+2*i-6;
  pinMode(diody[i], OUTPUT);
}

}


void loop() {
 // Serial.println(analogRead(A1));
 if (analogRead(A1)<310)
 {
 k=1;
   for (int i=2;i<18;i=i+3)
{
   digitalWrite(diody[i], LOW); 
}
   for (int i=3;i<18;i=i+3)
{
   digitalWrite(diody[i], LOW); 
}
 }
  if ((analogRead(A1)>=310) && (analogRead(A1)<=670))
 {
 k=2;
    for (int i=1;i<18;i=i+3)
{
   digitalWrite(diody[i], LOW); 
}
   for (int i=3;i<18;i=i+3)
{
   digitalWrite(diody[i], LOW); 
}
 
 
 }
 if (analogRead(A1)>670)
 {
   
 k=3;
    for (int i=1;i<18;i=i+3)
{
   digitalWrite(diody[i], LOW); 
}
   for (int i=2;i<18;i=i+3)
{
   digitalWrite(diody[i], LOW); 
}
 }
  if (analogRead(A0)>600)
  {
   wcisniete=true;
  }
   if ((wcisniete==true) && (analogRead(A0)<600))
  {
    wcisniete=false;
    p++;
    if (p==7)
    {
      p=0;
       for (int i=0;i<18;i++)
{
   digitalWrite(diody[i], LOW); 

}
    }
  }
  
    
 for (int i=k;i<(p*3);i=i+3)
{
   digitalWrite(diody[i], HIGH); 

}
  for (int i=(p*3);i<(p*3);i=i+3)
{
   digitalWrite(diody[i], LOW); 

}
if ((p>0) && ((analogRead(A1)>670)))
{
 digitalWrite(8, HIGH);
}
else  
{
  digitalWrite(8, LOW);
}

 //Serial.println(digitalRead(przycisk[2]));
for (int i=0;i<3;i++)                                           //zapalanie przyciskow zielonych
{
if (digitalRead(przycisk[i])==HIGH)
{
  digitalWrite(led[i],HIGH);
}
else
{
  digitalWrite(led[i],LOW);
}
                                                         // zapalanie zoltych, inna regula bo przyciski monostabilne

for (int i=3;i<6;i++)                                          
{
if (digitalRead(przycisk[i])==HIGH)
{
  zolty_wcisniety[i-3]=true;

}

if ((zolty_wcisniety[i-3]==true) && (digitalRead(przycisk[i])==LOW))
{
  stan_zoltych_led[i-3]= !stan_zoltych_led[i-3];
  digitalWrite(led[i],stan_zoltych_led[i-3]);
  zolty_wcisniety[i-3]=false;
}
}


for (int i=6;i<8;i++)                                          //zapalanie przyciskow czerwonych
{
if (digitalRead(przycisk[i])==HIGH)
{
  digitalWrite(led[i],HIGH);
}
else
{
  digitalWrite(led[i],LOW);
}
}

if (digitalRead(37)==HIGH)                             //wyjatek do ostatniego czerwonego bo nie dziala w teblicy
{
  digitalWrite(35,HIGH);
}
else
{
  digitalWrite(35,LOW);
}


}




}

#define slonce 1
int rfid[6];
int wejscia[6];
int p=0;
boolean koniec=false;
void setup() {
  
  for(int i=0;i<6;i++)
  {
    rfid[i]=i+2;
    pinMode(rfid[i], OUTPUT);
      digitalWrite(rfid[i],LOW);
  }
  for(int i=0;i<6;i++)
  {
    wejscia[i]=i+8;
    pinMode(wejscia[i], INPUT);
  }
 pinMode(slonce,OUTPUT);
 digitalWrite(slonce,LOW);
}

// the loop function runs over and over again forever
void loop() {
  if (koniec==false)
  {
  if (p==0)
  {
     digitalWrite(rfid[0],HIGH);
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////               1  
if (digitalRead(wejscia[0])==HIGH)
{
  if (p==0)
  {
  p=1;
  digitalWrite(rfid[0],LOW);
  delay(100);
  digitalWrite(rfid[1],HIGH);
  }
}
else
{
  p=0;
   for(int i=1;i<6;i++)
{
  digitalWrite(rfid[i],LOW);
}
 digitalWrite(rfid[0],HIGH);
}
//////////////////////////////////////////////////////////////////////////////////////////////////                    2
if (digitalRead(wejscia[1])==HIGH)
{
  if (p==1)
  {
  p=2;
  digitalWrite(rfid[1],LOW);
  delay(100);
  digitalWrite(rfid[2],HIGH);
  }
}
else
{
  if (p>1)
  {
    p=1;
   for(int i=2;i<6;i++)
{
  digitalWrite(rfid[i],LOW);
}
digitalWrite(rfid[1],HIGH);
  }
}
///////////////////////////////////////////////////////////////////////////////////////////                                  3

if (digitalRead(wejscia[2])==HIGH)
{
  if (p==2)
  {
  p=3;
  digitalWrite(rfid[2],LOW);
  delay(100);
  digitalWrite(rfid[3],HIGH);
  }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////                           4
if (digitalRead(wejscia[3])==HIGH)
{
  if (p==3)
  {
  p=4;
  digitalWrite(rfid[3],LOW);
  delay(300);
  digitalWrite(rfid[4],HIGH);
  }
}
else
{
  if (p>3)
  {
    p=3;
   for(int i=4;i<6;i++)
{
  digitalWrite(rfid[i],LOW);
}
digitalWrite(rfid[3],HIGH);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////                    5
if (digitalRead(wejscia[4])==HIGH)
{
  if (p==4)
  {
  p=5;
  digitalWrite(rfid[4],LOW);
  delay(500);
  digitalWrite(rfid[5],HIGH);
  }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////                     6
if (digitalRead(wejscia[5])==HIGH  && p==5)
{
  p=0;
  koniec=true;
    for(int i=0;i<6;i++)
{
  digitalWrite(rfid[i],LOW);
}

  delay(100);
}
  }
  
if (koniec==true)
{
  digitalWrite(slonce,HIGH);
}
}

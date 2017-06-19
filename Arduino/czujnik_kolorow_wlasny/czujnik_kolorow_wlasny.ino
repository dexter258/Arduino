int redPin=13;
int greenPin=12;
int bluePin=9;

int redPin_2=11;
int greenPin_2=10;
int bluePin_2=6;


int s2=7;
int s3=8;
int outPin=4;

int s2_2=2;
int s3_2=5;
int outPin_2=3;

int rColorStrength;
int gColorStrength;
int bColorStrength;
unsigned int pulseWidth;

int rColorStrength_2;
int gColorStrength_2;
int bColorStrength_2;
unsigned int pulseWidth_2;

void setup() {
  
  
  Serial.begin(9600);
  
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  
    pinMode(redPin_2,OUTPUT);
  pinMode(greenPin_2,OUTPUT);
  pinMode(bluePin_2,OUTPUT);
  
 // digitalWrite(redPin,HIGH);
  //digitalWrite(greenPin,HIGH);
  //digitalWrite(bluePin,HIGH);
  
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(outPin,INPUT);
  
   pinMode(s2_2,OUTPUT);
  pinMode(s3_2,OUTPUT);
  pinMode(outPin_2,INPUT);
  
}


void loop() {
  //RED
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);               
  
  pulseWidth = pulseIn(outPin,LOW);
 
  rColorStrength = pulseWidth/10 - 1;
  rColorStrength = (255-rColorStrength);
   delay(100);
   //RED  2
  digitalWrite(s2_2,LOW);
  digitalWrite(s3_2,LOW);               
  
  pulseWidth_2 = pulseIn(outPin_2,LOW);
  
  rColorStrength_2 = pulseWidth_2/10 - 1;
  rColorStrength_2 = (255-rColorStrength_2);
  
   delay(100);
  
  //GREEN
  digitalWrite(s2,HIGH);
  digitalWrite(s3,HIGH);
  
  pulseWidth = pulseIn(outPin,LOW);
  gColorStrength = pulseWidth/10 - 1;
  gColorStrength = (255-gColorStrength);
   delay(100);
  //GREEN  2
  digitalWrite(s2_2,HIGH);
  digitalWrite(s3_2,HIGH);
  
  pulseWidth_2 = pulseIn(outPin_2,LOW);
  gColorStrength_2 = pulseWidth_2/10 - 1;
  gColorStrength_2 = (255-gColorStrength_2);
   delay(100);
  
   //BLUE
  digitalWrite(s2,LOW);
  digitalWrite(s3,HIGH);
  
  pulseWidth = pulseIn(outPin,LOW);
  bColorStrength = pulseWidth/10 - 1;
  bColorStrength = (255-bColorStrength);
   delay(100);
  
   //BLUE  2
  digitalWrite(s2_2,LOW);
  digitalWrite(s3_2,HIGH);
  
  pulseWidth_2 = pulseIn(outPin_2,LOW);
  bColorStrength_2 = pulseWidth_2/10 - 1;
  bColorStrength_2 = (255-bColorStrength_2);
   delay(100);

  if ((rColorStrength>gColorStrength)&&(gColorStrength>bColorStrength))
  {
    rColorStrength=255;
    gColorStrength= gColorStrength/4;
   bColorStrength=0;
  }
  
  if ((rColorStrength>bColorStrength)&&(bColorStrength>gColorStrength))
  {
    rColorStrength=255;
    bColorStrength=bColorStrength/4;
    gColorStrength=0;
  }
  
  if ((bColorStrength>gColorStrength)&&(gColorStrength>rColorStrength))
  {
     bColorStrength=255;
    gColorStrength=gColorStrength/4;
    rColorStrength=0;
  }  
   if ((bColorStrength>rColorStrength)&&(rColorStrength>gColorStrength))
  {
     bColorStrength=255;
    rColorStrength=rColorStrength/4;
    gColorStrength=0;
  }  
  
    if ((gColorStrength>bColorStrength)&&(bColorStrength>rColorStrength))
  {
     gColorStrength=255;
    bColorStrength=bColorStrength/4;
    rColorStrength=0;
  }  
   if ((gColorStrength>rColorStrength)&&(rColorStrength>bColorStrength))
  {
     gColorStrength=255;
    rColorStrength=rColorStrength/4;
   bColorStrength=0;
  }  
  
  
  /////////////////////////////////////////////////////////////
  
  if ((rColorStrength_2>gColorStrength_2)&&(gColorStrength_2>bColorStrength_2))
  {
    rColorStrength_2=255;
    gColorStrength_2= gColorStrength_2/4;
    bColorStrength_2=0;
  }
  
  if ((rColorStrength_2>bColorStrength_2)&&(bColorStrength_2>gColorStrength_2))
  {
    rColorStrength_2=255;
    bColorStrength_2=bColorStrength_2/4;
    gColorStrength_2=0;
  }
  
  if ((bColorStrength_2>gColorStrength_2)&&(gColorStrength_2>rColorStrength_2))
  {
     bColorStrength_2=255;
    gColorStrength_2=gColorStrength_2/4;
    rColorStrength_2=0;
  }  
   if ((bColorStrength_2>rColorStrength_2)&&(rColorStrength_2>gColorStrength_2))
  {
     bColorStrength_2=255;
    rColorStrength_2=rColorStrength_2/4;
    gColorStrength_2=0;
  }  
  
    if ((gColorStrength_2>bColorStrength_2)&&(bColorStrength_2>rColorStrength_2))
  {
     gColorStrength_2=255;
    bColorStrength_2=bColorStrength_2/4;
    rColorStrength_2=0;
  }  
   if ((gColorStrength_2>rColorStrength_2)&&(rColorStrength_2>bColorStrength_2))
  {
     gColorStrength_2=255;
    rColorStrength_2=rColorStrength_2/4  ;
    bColorStrength_2=0;
  }  
  
  
  
  
  
  
    Serial.print(rColorStrength);
    Serial.print("    ");
      
  Serial.print(gColorStrength);
  Serial.print("    ");
  
  Serial.print(bColorStrength);
  Serial.print("                            ");
  
  
  Serial.print(rColorStrength_2);
    Serial.print("    ");
   Serial.print(gColorStrength_2);
  Serial.print("    ");
  
  
  Serial.println(bColorStrength_2);
  Serial.println("");
  
  analogWrite(redPin,(255-rColorStrength));
  analogWrite(greenPin,(255-gColorStrength));
  analogWrite(bluePin,(255-bColorStrength));
   
  analogWrite(redPin_2,(255-rColorStrength_2));
  analogWrite(greenPin_2,(255-gColorStrength_2));
  analogWrite(bluePin_2,(255-bColorStrength_2));
  
  delay(500);
}

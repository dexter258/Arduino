#define led 5
#define sygnal 2

unsigned long time;
void setup()  
{
  Serial.begin(9600);
pinMode(led,OUTPUT);
pinMode(sygnal,OUTPUT);

  digitalWrite(sygnal,LOW);
    digitalWrite(led,LOW);
  
}

char c;
String msg;

void loop(){

  while(Serial.available()>0){
    c=Serial.read(); 
    msg += c;
  }

  if (msg.length() > 10) {
    msg = msg.substring(1,13);
  
  }
  
  
if (msg=="A9001BEDEFB0")
{
  digitalWrite(led,HIGH);
  digitalWrite(sygnal,HIGH);
  delay(100);
  time = millis();
   msg = "";
}
else
{
   if ((millis()-time)>=25000)
   {
  digitalWrite(led,LOW);
  digitalWrite(sygnal,LOW);
   msg = "";
   }
}

    delay(300);
}

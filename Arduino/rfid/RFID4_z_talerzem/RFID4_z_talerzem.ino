#define led 13
#define sygnal 2
unsigned long time;
void setup()  
{
  Serial.begin(9600);
pinMode(led,OUTPUT);
pinMode(sygnal,OUTPUT);

digitalWrite(sygnal,LOW);
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
  //  Serial.println(msg);

   
  }
if (msg=="A800926B93C2")
{
  digitalWrite(led,HIGH);
  digitalWrite(sygnal,HIGH);
  delay(100);
  
   msg = "";
   time = millis();
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
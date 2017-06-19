#define led 5
#define sygnal 2

unsigned long time;
void setup()  
{
  Serial.begin(9600);
pinMode(led,OUTPUT);
pinMode(sygnal,OUTPUT);

digitalWrite(led,LOW);
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
  }

if (msg=="A80092495724")
{
  digitalWrite(led,HIGH);
  delay(100);
  digitalWrite(sygnal,HIGH);
   msg = "";
     time = millis();
}

    delay(300);
}

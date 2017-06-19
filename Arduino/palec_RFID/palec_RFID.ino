
char readString;
int lock=1;
char c;
String msg;
#define start 9
#define przycisk_start 10
#define magnes 11
boolean wykonywanie=false;
void setup() {
  Serial.begin(9600);
 pinMode(start,OUTPUT);
  pinMode(przycisk_start,INPUT);
  pinMode(magnes,OUTPUT);
  digitalWrite(magnes,LOW);
 //digitalWrite(przycisk_start,LOW);
 digitalWrite(start,LOW);
 
}

void loop() {
  while(Serial.available()>0){
    c=Serial.read(); 
    msg += c;
  }

  if (msg.length() > 10) {
    msg = msg.substring(1,13);

    if  (msg == "87000520B012")  
    {
     digitalWrite(start,HIGH);
      delay(1000);
      digitalWrite(magnes,HIGH);
      delay(1000);
       digitalWrite(magnes,HIGH);
    digitalWrite(start,LOW); 
     digitalWrite(magnes,HIGH);
     delay(100);
      digitalWrite(magnes,HIGH);
       delay(100);
      digitalWrite(magnes,HIGH);
    delay(40000);
    digitalWrite(magnes,LOW);
    }
   // if  (msg == "020030BF931E")
   // {
  //   digitalWrite(przycisk_start,HIGH);
  //   delay(2000);
  //  digitalWrite(przycisk_start,LOW); 
 //   }


    msg = "";
  }

     if    ((digitalRead(przycisk_start)==HIGH) && (wykonywanie==false)) 
    {
      wykonywanie=true;
      if (wykonywanie==true){
     digitalWrite(start,HIGH);
      delay(1000);
      digitalWrite(magnes,HIGH);
      delay(1000);
    digitalWrite(start,LOW); 
     delay(100);
      digitalWrite(magnes,HIGH);
       delay(100);
      digitalWrite(magnes,HIGH);
    delay(40000);
    digitalWrite(magnes,LOW);
      }
    }
    if (digitalRead(przycisk_start)==LOW)
    {
       wykonywanie=false;
    }
  
    delay(300);
}

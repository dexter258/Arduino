#include <SoftwareSerial.h>
 
SoftwareSerial RFID = SoftwareSerial(4,5);
 
void setup()  
{
  Serial.begin(9600);
  Serial.println("Serial Ready");
 
  RFID.begin(9600);
  Serial.println("RFID Ready");
}
 
char c;
String msg;
 
void loop(){
 
  while(RFID.available()>0){
    c=RFID.read(); 
    msg += c;
  }
 
  if (msg.length() > 10) {
    msg = msg.substring(1,13);
    Serial.println(msg);
 
    msg = "";
  }
    delay(300);
}

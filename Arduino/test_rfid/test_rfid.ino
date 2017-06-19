#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial RFID = SoftwareSerial(0,1);

Servo servo1; 
char readString;
int lock=1;
char c;
String msg;

void servo_move(int angle) {
  servo1.attach(6); 
  servo1.write(angle); 
  delay(500);
  servo1.detach();
}

void setup() {
  //Serial.begin(9600);
  //Serial.println("Serial Ready");

  RFID.begin(9600);
 // Serial.println("RFID Ready");
  servo_move(70); 
}

void loop() {
  while(RFID.available()>0){
    c=RFID.read(); 
    msg += c;
  }

  if (msg.length() > 10) {
    msg = msg.substring(1,13);
 //  Serial.println(msg);
    if ((msg == "02003154BED9")|| (msg == "020030BF931E")){
     
        servo_move(70);
  
  
    }
if (msg == "110016B0FA4D"){
     
        servo_move(170);
  
  
    }
    msg = "";
  }
    delay(300);
}

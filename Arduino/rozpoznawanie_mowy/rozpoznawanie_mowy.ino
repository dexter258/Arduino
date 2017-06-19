#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"

VR myVR(2,3); // 2:RX 3:TX
//Bufor na odpowiedzi z modulu
uint8_t buf[64];

void setup() {
//Inicjalizuje polaczenia
myVR.begin(9600);
Serial.begin(115200);
myVR.clear();
//Laduje fraze robot
if(myVR.load((uint8_t)0) >= 0){
Serial.println("robot zladowany");
}
}

void loop() {
int ret;
while(1){
ret = myVR.recognize(buf, 50);
//Jezeli cos zostalo rozpoznane
if( ret > 0 ){
//Jezeli ktos powiedzial 'robot'
if (buf[1] == 0){
//Laduje komendy odpowiedzialne za kierunki
myVR.clear();
myVR.load((uint8_t)8);//start
myVR.load((uint8_t)9);//stop
myVR.load((uint8_t)10);//left
myVR.load((uint8_t)11);//right
myVR.load((uint8_t)12);//right
}else switch(buf[1]){
case 8:
Serial.println("on");
break;
case 9:
Serial.println("white");
break;
case 10:
Serial.println("blue");
break;
case 11:
Serial.println("black");
break;
case 12:
Serial.println("admin");
break;
}
}
}
}

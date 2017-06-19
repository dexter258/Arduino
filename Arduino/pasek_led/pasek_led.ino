#include <IRremote.h>
#define irPin 11
IRrecv irrecv(irPin);
decode_results results;
 
#define diodaPin 9
#define diodaPin1 6
#define diodaPin2 5
int jasnosc = 0;
 int jasnosc1 = 0;
  int jasnosc2 = 0;
void setup() {
   Serial.begin(9600);
   irrecv.enableIRIn();
 
    pinMode(diodaPin, OUTPUT);
     pinMode(diodaPin1, OUTPUT);
      pinMode(diodaPin2, OUTPUT);
}
 
void loop() {
   if (irrecv.decode(&results)) {
 
       switch (results.value) {
         case 0xFF30CF:
            if(jasnosc < 255) {jasnosc = jasnosc+15;}
            Serial.println(jasnosc);
            analogWrite(diodaPin, jasnosc);
            break;
 
         case 0xFF7A85:
            if(jasnosc > 0) {jasnosc = jasnosc-15;}
            Serial.println(jasnosc);
            analogWrite(diodaPin, jasnosc);
            break;
            
            case 0xFF10EF:
            if(jasnosc1 < 255) {jasnosc1 = jasnosc1+15;}
            Serial.println(jasnosc1);
            analogWrite(diodaPin1, jasnosc1);
            break;
 
         case 0xFF5AA5:
            if(jasnosc1 > 0) {jasnosc1 = jasnosc1-15;}
            Serial.println(jasnosc1);
            analogWrite(diodaPin1, jasnosc1);
            break;
             case 0xFF42BD:
            if(jasnosc2 < 255) {jasnosc2 = jasnosc2+15;}
            Serial.println(jasnosc2);
            analogWrite(diodaPin2, jasnosc2);
            break;
 
         case 0xFF52AD:
            if(jasnosc2 > 0) {jasnosc2 = jasnosc2-15;}
            Serial.println(jasnosc2);
            analogWrite(diodaPin2, jasnosc2);
            break;
            
         }
   irrecv.resume();
   }
}














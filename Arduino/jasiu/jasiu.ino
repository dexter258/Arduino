int a,b,c,d,e;

void setup() {
 Serial.begin(9600);
  pinMode(3, INPUT);
    pinMode(4, INPUT);
      pinMode(5, INPUT);
        pinMode(6, INPUT);
          pinMode(7, INPUT);
}


void loop() {
  e=digitalRead(3);
  d=digitalRead(4);
  c=digitalRead(5);
  b=digitalRead(6);
  a=digitalRead(7);
Serial.print(a);
Serial.print(", ");
Serial.print(b);
Serial.print(", ");
Serial.print(c);
Serial.print(", ");
Serial.print(d);
Serial.print(", ");
Serial.print(e);
Serial.println("");
  delay(1000);            
}

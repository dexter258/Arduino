// Basic sketch for trying out the Adafruit DRV8871 Breakout

#define MOTOR_IN1 6
#define MOTOR_IN2 5
int opoznienie=10;
int przerwa=1000;
void setup() {
  Serial.begin(9600);

  Serial.println("DRV8871 test");
  
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
}

void loop() {

  // ramp up forward
  digitalWrite(MOTOR_IN1, LOW);
  for (int i=0; i<255; i++) {
    analogWrite(MOTOR_IN2, i);
    delay(opoznienie);
  }

  // forward full speed for one second
  delay(przerwa);
  
  // ramp down forward
  for (int i=255; i>=0; i--) {
    analogWrite(MOTOR_IN2, i);
    delay(opoznienie);
  }

  // ramp up backward
  digitalWrite(MOTOR_IN2, LOW);
  for (int i=0; i<255; i++) {
    analogWrite(MOTOR_IN1, i);
    delay(opoznienie);
  }

  // backward full speed for one second
  delay(przerwa);

  // ramp down backward
  for (int i=255; i>=0; i--) {
    analogWrite(MOTOR_IN1, i);
    delay(opoznienie);
  }
  
// digitalWrite(MOTOR_IN1, 0);
//  digitalWrite(MOTOR_IN2, 140);
}

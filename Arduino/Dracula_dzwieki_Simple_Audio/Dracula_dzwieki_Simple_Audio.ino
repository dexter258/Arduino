#include <SimpleSDAudio.h>
void setup()
{ 
 Serial.begin(9600);
  SdPlay.setSDCSPin(10); // Enable if your SD card CS-Pin is not at Pin 4... 
  SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);

}

void loop(void) {
  Serial.print(digitalRead(2));
  Serial.print("    ");
    Serial.print(digitalRead(3));
  Serial.print("    ");
    Serial.print(digitalRead(4));
  Serial.print("    ");
    Serial.print(digitalRead(5));
  Serial.println("");

  
  if (digitalRead(2)==HIGH){
    SdPlay.stop();
      SdPlay.setFile("1.wav"); 
  SdPlay.play();
  delay(2000);
  }

if (digitalRead(3)==HIGH){
  SdPlay.stop();
  SdPlay.setFile("2.wav"); 
  SdPlay.play();
  delay(2000);
}
  if (digitalRead(4)==HIGH){
 SdPlay.stop();
  SdPlay.setFile("3.wav"); 
  SdPlay.play();
  delay(2000);
  }
/*  if (digitalRead(5)==HIGH){
 SdPlay.stop();
  SdPlay.setFile("1.wav"); 
  SdPlay.play();
  delay(2000);
  }*/
  
}

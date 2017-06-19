#include <SimpleSDAudio.h>
 uint8_t p=0;
void setup()
{
 
SdPlay.setSDCSPin(A0); // sd kart cs pini
if (!SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER))
{
while(1);
}
}
 
void loop(void) {
  if (p<1){
 SdPlay.setFile("14.wav"); 
  SdPlay.play();
//  delay(200); 
//SdPlay.play(); // seçilen dosyayı çal
 //delay(2000);
 delay(2000);
 SdPlay.pause();
 delay(2000);
 SdPlay.play();
 p++;
  }
//while(!SdPlay.isStopped()) { // müzik bittiğinde tekrar çal
//;
//}
}

/*
  SimpleSDAudio absolute minimum example, plays file EXAMPLE.AFM from root folder of SD card (CS on pin 4)
  through speaker/amplifier at pin 9 for ATmega328 / pin 44 for ATmega1280/2560.
*/
#include <SimpleSDAudio.h>
byte button[41];
byte buttonPrev[41];
void setup()
{
  Serial.begin(9600);
  // SdPlay.setSDCSPin(10); // Enable if your SD card CS-Pin is not at Pin 4...
  SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);
  //SdPlay.setFile("ABORT.AFM");
  // Serial.println("Test");
  /* SdPlay.play();
    delay(500);
    SdPlay.setFile("blad.afm");
    SdPlay.play();
  */

  Serial.println("Test");

  for (byte i = 0; i < 41; i++) {
    button[i] = 0;
    buttonPrev[i] = 0;
  }



}

void checkData(String info) {
  String temp;
  if (info.length() >= 42) {
    for (byte i = 1; i < 41; i++) {
      temp = "";
      temp += info[i];
      button[i] = byte(temp.toInt());
    }
  }
}
char tempChar[7];
void loop(void) {
  String msg = "";

  if (Serial.available() > 0) { // Pobieranie danych z portu szeregowego
    while (Serial.available() > 0) { // pobieraj tak długo aż bufor będzie pusty
      msg += char(Serial.read());
      delay(2);
    }
    checkData(msg);

  }

  String temp;
  for (byte i = 1; i < 41; i ++) {
    temp = "";
    if (i < 31) {
      if (button[i] == 1 && buttonPrev[i] != button[i]) {
        temp = String(i) + ".afm";
        temp.toCharArray(tempChar, 7);
        SdPlay.setFile(tempChar);
        SdPlay.play();
        Serial.println("test1 = " + temp + String(SdPlay.isPlaying()));
        if(SdPlay.isPlaying()== false){
          do{
            //SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);
            SdPlay.setFile(tempChar);
            SdPlay.play();
          }while(SdPlay.isPlaying()==false);
        }
          
      }

    }
    else if (i >= 31 && i < 36) {
      if (button[i] == 1 && buttonPrev[i] != button[i]) {
        temp = String(i) + ".afm";
        temp.toCharArray(tempChar, 7);
        SdPlay.setFile(tempChar);
        SdPlay.play();
        Serial.println("test2 = " + temp + String(SdPlay.isPlaying()));
        if(SdPlay.isPlaying()== false){
          do{
            //SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);
            SdPlay.setFile(tempChar);
            SdPlay.play();
          }while(SdPlay.isPlaying()==false);
        }

      }
      else if (button[i] == 2 && buttonPrev[i] != button[i]) {
        temp = String(i + 5) + ".afm";
        temp.toCharArray(tempChar, 7);
        SdPlay.setFile(tempChar);
        SdPlay.play();
        Serial.println("test3 = " + temp + String(SdPlay.isPlaying()));
        if(SdPlay.isPlaying()== false){
          do{
           // SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);
           SdPlay.setFile(tempChar);
            SdPlay.play();
          }while(SdPlay.isPlaying());
        }
      }
      else {
        //Nic nie rób
      }

    }
    else if ( i >= 36) {
      if (button[i] == 1 && buttonPrev[i] != button[i]) {
        temp = String(i + 5) + ".afm";
        temp.toCharArray(tempChar, 7);
        SdPlay.setFile(tempChar);
        SdPlay.play();
        Serial.println("test4 = " + temp + String(SdPlay.isPlaying()));
        if(SdPlay.isPlaying()== false){
          do{
            //SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);
            SdPlay.setFile(tempChar);
            SdPlay.play();
          }while(SdPlay.isPlaying()==false);
        }

      }
    }
    buttonPrev[i] = button[i];



  }
}

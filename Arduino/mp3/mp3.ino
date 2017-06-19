#include <SD.h>

#include <TMRpcm.h> 

TMRpcm tmrpcm; 

File root;

File entry;

const int chipSelect = 4;    

 

const int oldCard = SPI_HALF_SPEED;

const int newCard = SPI_QUARTER_SPEED;

int cardType = oldCard;

 

int wasPlaying = 0;

int inSwitch = 7;

int finished = 0;

int start = 0;

int pauseOn = 0;

unsigned long timeDiff = 0;

unsigned long timePress = 0;

 

void setup() {

  Serial.begin(9600);

  Serial.print("\nInitializing SD card...");

  pinMode(chipSelect, OUTPUT); 

  if (!SD.begin(chipSelect,cardType)) {

    Serial.println("failed!");

    return;

  }

  Serial.println("done.");

  tmrpcm.speakerPin = 9;

  pinMode(inSwitch,INPUT_PULLUP);

  digitalWrite(inSwitch,HIGH);

  root = SD.open("/");

}

 

void loop(void) {

  if(!tmrpcm.isPlaying() && wasPlaying == 1) { 

    tmrpcm.stopPlayback();

    playNext();  

  }

  if (millis() - timeDiff > 50) { // check switch every 100ms 

    timeDiff = millis(); // get current millisecond count

    if(digitalRead(inSwitch) == LOW) {

      if(start==0) {

        start=1; 

        playNext();

        delay(200);

      } 

      else {

        timePress = millis();

        while(digitalRead(inSwitch)==LOW) {

          delay(50);

        }

        if (millis() - timePress < 1000 && start == 1) {

          tmrpcm.pause();

          if (pauseOn == 0) {

            pauseOn = 1;

          } 

          else {

            pauseOn = 0;

          }

        }

        if (millis() - timePress > 1000 && start == 1) {

          if (pauseOn == 1) {

            pauseOn = 0; 

            tmrpcm.pause();

          }

          tmrpcm.stopPlayback();

          timePress = millis();

          if (finished == 0) {

            playNext(); 

          } 

          else {

            finished = 0;

            Serial.println("Restarting."); 

            root.rewindDirectory();

            playNext(); 

          }

        }

      }

    }

  }

}

 

void playNext() {

  entry = root.openNextFile();

  if (entry) {

    entry.close();

    tmrpcm.play(entry.name()); 

    wasPlaying = 1;

  } 

  else {

    if (wasPlaying == 1) {

      Serial.println( "COMPLETED playback."); 

      wasPlaying = 0;

      finished = 1;

      start = 0;

      root.rewindDirectory();

    }     

  }

}

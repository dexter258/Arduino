#include <SD.h>
#include <TMRpcm.h> 
TMRpcm tmrpcm; 

File root;
File entry;


const int chipSelect = 10;    

const int oldCard = SPI_HALF_SPEED;
const int newCard = SPI_QUARTER_SPEED;


int cardType = oldCard;

int wasPlaying = 0;
int inSwitch = 7;
int poczatek = 4;
int pauza=0;
int zwyciestwo=5;
int koniec=6;
int finished = 0;
int start = 0;
int pauseOn = 0;
unsigned long timeDiff = 0;
unsigned long timePress = 0;

void setup() 
{
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
  
if (millis() - timeDiff > 50) 
  {
     timeDiff = millis(); 
      
if(digitalRead(inSwitch) == LOW) 
{
 if (pauseOn == 1) 
        {
           pauseOn = 0;
           tmrpcm.pause();
        } 
        
 if(start==0) 
 {
   
     if ( (digitalRead(koniec)==HIGH) || (digitalRead(poczatek)==HIGH)|| (digitalRead(zwyciestwo)==HIGH) )
     {
         if (digitalRead(poczatek)==HIGH)
              {
                tmrpcm.pause();
                 tmrpcm.play("glos.wav");
                 pauza=0;
                 delay(40);
              }
         if (digitalRead(koniec)==HIGH)
              {
                tmrpcm.pause();
                 tmrpcm.play("krzyk.wav");
                 pauza=0;
                 delay(40);
               }
         if (digitalRead(zwyciestwo)==HIGH)
              {
                tmrpcm.pause();
                 tmrpcm.play("koniec.wav");
                 pauza=0;
                 delay(40);
               }
     }
     else 
       {
          if(pauza==0)
            {
              pauza=1;
              tmrpcm.pause();
            }
        }
       
        
 delay(200);
 }
 else 
 {
   if (finished == 1) 
     {
       playNext(); 
       finished = 0;
       Serial.println("Restarting."); 
       root.rewindDirectory();
       playNext(); 
     }
  }
            
}
         
else 
  {
    if (pauseOn == 0) 
        {
          pauseOn = 1;
          tmrpcm.pause();
        } 
  }
            
            
            
            
}
     
   
 
}




void playNext() 
{
  entry = root.openNextFile();
 if (entry) 
    {
    entry.close();
    tmrpcm.play(entry.name()); 
    wasPlaying = 1;
    } 
 else
   {
     if (wasPlaying == 1) 
       {
         Serial.println("Completed playback."); 
         wasPlaying = 0;
         finished = 1;
         start = 0;
         root.rewindDirectory();
       }     
   }
}

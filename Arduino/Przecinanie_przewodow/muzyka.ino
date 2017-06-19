int c=3830;    // 261 Hz 
int d=3400;    // 294 Hz 
int e=3038;    // 329 Hz 
int f=2864;    // 349 Hz 
int g=2550;    // 392 Hz 
int a=2272;    // 440 Hz 
int b=2028;    // 493 Hz 
int C=1912;    // 523 Hz 
int  R=0;

int melody[] = {  C,  b,  g,  C,  b,   e,  R,  C,  c,  g, a, C };
int beats[]  = { 16, 16, 16,  8,  8,  16, 32, 16, 16, 16, 8, 8 }; 
int MAX_COUNT = sizeof(melody) / 2; // Melody length, for looping.

long tempo = 10000;
// Set length of pause between notes
int pause = 50;
// Loop variable to increase Rest length
int rest_count = 400; //<-BLETCHEROUS HACK; See NOTES

// Initialize core variables
int tone1 = 0;
int beat = 0;
long duration  = 0;


void playTone() {
  long elapsed_time = 0;
  if (tone1 > 0) { // if this isn't a Rest beat, while the tone has 
    //  played less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < duration) {

      digitalWrite(speakerOut,HIGH);
      delayMicroseconds(tone1 / 2);

      // DOWN
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(tone1 / 2);

      // Keep track of how long we pulsed
      elapsed_time += (tone1);
    } 
  }
  else { // Rest beat; loop times delay
    for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count
      delayMicroseconds(duration);  
    }                                
  }                                 
}
void graj(){
        for (int i=0; i<MAX_COUNT; i++) {
    tone1 = melody[i];
    beat = beats[i];

    duration = beat * tempo; // Set up timing

    playTone(); 
    // A pause between notes...
    delayMicroseconds(pause);
  }
}




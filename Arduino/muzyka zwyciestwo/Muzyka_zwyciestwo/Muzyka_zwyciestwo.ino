const byte melody_maxlen = 12;
const byte PWM_Audio     = 9;      //D9: Speaker+ ("LS+")

//the larger, the quicker the melodies are played
const float melody_speed = 2.5f;

const byte melody_advance_level_len = 7;
const unsigned int melody_advance_level[2][melody_maxlen] PROGMEM =
{
    { 392, 392, 392, 440,  392, 494,  523, 0, 0, 0, 0, 0},    //frequency
    { 500, 250, 250, 500, 1000, 500, 2000, 0, 0, 0, 0, 0}     //duration, 1000 = 1 full beat
};
 void playMelody_from_PROGMEM(const unsigned int melody[2][12], byte melody_len)
{
    for (byte i = 0; i < melody_len; i++)
    {
        tone(PWM_Audio, pgm_read_word(&(melody[0][i])));
        delay((float) pgm_read_word(&(melody[1][i])) / melody_speed);
        noTone(PWM_Audio);
        delay(50); //otherwise the tones sound too legato
    }
}
void setup() {                

}




  


// the loop routine runs over and over again forever:
void loop() {
playMelody_from_PROGMEM(melody_advance_level, melody_advance_level_len); //wywołanie funkcji
}

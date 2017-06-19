PCF8574 pcf5, pcf6;
byte randomColor[4]={0,0,0,0};
#include "PCF8574.h" // Required for PCF8574
bool vowel = false;
extern bool allowSimon;
bool again = true;

byte ilosc = 2;

byte errors = 0;
byte errorsPrev = 0;
byte simonLevel = 0;

struct buttons{
  bool green=false;
  bool red=false;
  bool orange=false;
  bool blue=false;
  
  bool greenPrev;
  bool redPrev;
  bool orangePrev;
  bool bluePrev;
};

struct buttons simonButton;

void readSimonButton(){
  // Wyzerowanie stanów
  simonButton.red = false;
  simonButton.green = false;
  simonButton.orange = false;
  simonButton.blue = false;
  
  
  // Czerwony przycisk 
  if(pcf5.digitalRead(3) != simonButton.redPrev){
    delay(80);
   if(pcf5.digitalRead(3) != simonButton.redPrev){
    simonButton.red = true;
    simonButton.redPrev = pcf5.digitalRead(3);

    //Serial.println("Czer");
   }
  }
  // Zielony przycisk
  if(pcf5.digitalRead(2) != simonButton.greenPrev){
    delay(80);
    if(pcf5.digitalRead(2) != simonButton.greenPrev){
     
      simonButton.green = true;
      simonButton.greenPrev = pcf5.digitalRead(2);

       //Serial.println("Ziel");
     }
  }
   // Pomarańczowy przycisk
  if(pcf5.digitalRead(0) != simonButton.orangePrev){
    delay(80);
    if(pcf5.digitalRead(0) != simonButton.orangePrev){
      simonButton.orange = true;
      simonButton.orangePrev = pcf5.digitalRead(0);

       //Serial.println("Pom");
     }
  }


    // Niebieski przycisk 
    if(pcf5.digitalRead(1) != simonButton.bluePrev){
      delay(80);
     if(pcf5.digitalRead(1) != simonButton.bluePrev){
      simonButton.blue = true;
      simonButton.bluePrev = pcf5.digitalRead(1);

       //Serial.println("NIeb");
     }
    }
  
    
}

void randomColors(){
  randomColor[0] = random(4,8);
  
  do{
      randomColor[1] = random(4,8);
  }while(randomColor[0] == randomColor[1]);

  do{
    randomColor[2] = random(4, 8);
  }while(randomColor[0] == randomColor[2] || randomColor[1] == randomColor[2]);

  do{
     randomColor[3] = random(4, 8);
  }while(randomColor[0] == randomColor[3] || randomColor[1] == randomColor[3] || randomColor[2] == randomColor[3]);

  //Serial.println(String(randomColor[0]) + String(randomColor[1]) +String(randomColor[2]) +String(randomColor[3]));
}

void simonLevel_vowel(byte number){
  
  //Niebieski
  if(randomColor[number] == 4 ){
    if(simonButton.red && errors == 0){
      simonLevel++;
       pcf6.digitalWrite(0, HIGH);
       delay(300);
       pcf6.digitalWrite(0, LOW);
      }
   else if(simonButton.green && errors == 1){
      simonLevel++;
      pcf6.digitalWrite(1, HIGH);
      delay(300);
      pcf6.digitalWrite(1, LOW);
    }
   else if(simonButton.red && errors == 2){
      simonLevel++;
      pcf6.digitalWrite(0, HIGH);
      delay(300);
      pcf6.digitalWrite(0, LOW);
    }

    else{
      simonLevel = 0;
      errors++;
      ilosc = 2;
     
      //Serial.println("Blad N, errors = " + String(errors) + "   Number = " + String(number));
    }
 }

  //Pomarańczowy
  if(randomColor[number] == 5 ){
    if(simonButton.green && errors == 0){
      simonLevel++;
      pcf6.digitalWrite(1, HIGH);
      delay(300);
      pcf6.digitalWrite(1, LOW);
     }
    else if(simonButton.red && errors == 1){
      
      simonLevel++;
      pcf6.digitalWrite(0, HIGH);
      delay(300);
      pcf6.digitalWrite(0, LOW);
    }
   else if(simonButton.blue && errors == 2){
      
      simonLevel++;
      pcf6.digitalWrite(3, HIGH);
      delay(300);
      pcf6.digitalWrite(3, LOW);
    }
    else{
      simonLevel = 0;
      errors++;
      ilosc = 2;
      
      //Serial.println("Blad P, errors = " + String(errors) + "   Number = " + String(number));
    }
  }


  //Zielony
  if(randomColor[number] == 6 ){
    if(simonButton.orange && errors == 0){
      
      simonLevel++;
      pcf6.digitalWrite(2, HIGH);
      delay(300);
      pcf6.digitalWrite(2, LOW);
   }
   else if(simonButton.blue && errors == 1){
      
      simonLevel++;
      pcf6.digitalWrite(3, HIGH);
      delay(300);
      pcf6.digitalWrite(3, LOW);
    }
    
    else if(simonButton.orange && errors == 2){
     
      simonLevel++;
      pcf6.digitalWrite(2, HIGH);
      delay(300);
      pcf6.digitalWrite(2, LOW);
    }
    else{
     
      simonLevel = 0;
      
      errors++;
      ilosc = 2;
     
     //Serial.println("Blad Z, errors = " + String(errors) + "   Number = " + String(number));
    }
  }

  //Czerwony
  if(randomColor[number] == 7 ){
    if(simonButton.blue && errors == 0){
      simonLevel++;
      
     pcf6.digitalWrite(3, HIGH);
     delay(300);
     pcf6.digitalWrite(3, LOW);
    }
    
    else if(simonButton.orange && errors == 1){
      simonLevel++;
      pcf6.digitalWrite(2, HIGH);
      delay(300);
      pcf6.digitalWrite(2, LOW);
    
    }
   
    else if(simonButton.green && errors == 2){
     
      simonLevel++;
      pcf6.digitalWrite(1, HIGH);
      delay(300);
      pcf6.digitalWrite(1, LOW);
      
    }
    else {

      simonLevel = 0;
      
      errors++;
      ilosc = 2;
     
      //Serial.println("Blad C, errors = " + String(errors) + "   Number = " + String(number));
    }
  }

  
}

void simonLevel_non_vowel(byte number){
  
  //Niebieski
  if(randomColor[number] == 4 ){
    if(simonButton.orange && errors == 0){
      simonLevel++;
       pcf6.digitalWrite(2, HIGH);
       delay(300);
       pcf6.digitalWrite(2, LOW);
      }
   else if(simonButton.blue && errors == 1){
      simonLevel++;
      pcf6.digitalWrite(3, HIGH);
      delay(300);
      pcf6.digitalWrite(3, LOW);
    }
   else if(simonButton.green && errors == 2){
      simonLevel++;
      pcf6.digitalWrite(1, HIGH);
      delay(300);
      pcf6.digitalWrite(1, LOW);
    }

    else{
      simonLevel = 0;
      errors++;
      ilosc = 2;
     
      //Serial.println("Blad N, errors = " + String(errors) + "   Number = " + String(number));
    }
 }

  //Pomarańczowy
  if(randomColor[number] == 5 ){
    if(simonButton.red && errors == 0){
      simonLevel++;
      pcf6.digitalWrite(0, HIGH);
      delay(300);
      pcf6.digitalWrite(0, LOW);
     }
    else if(simonButton.green && errors == 1){
      
      simonLevel++;
      pcf6.digitalWrite(1, HIGH);
      delay(300);
      pcf6.digitalWrite(1, LOW);  
    }
   else if(simonButton.red && errors == 2){
      
      simonLevel++;
      pcf6.digitalWrite(0, HIGH);
      delay(300);
      pcf6.digitalWrite(0, LOW);
    }
    else{
      simonLevel = 0;
      errors++;
      ilosc = 2;
     
      //Serial.println("Blad P, errors = " + String(errors) + "   Number = " + String(number));
    }
  }


  //Zielony
  if(randomColor[number] == 6 ){
    if(simonButton.green && errors == 0){
      
      simonLevel++;
      pcf6.digitalWrite(1, HIGH);
      delay(300);
      pcf6.digitalWrite(1, LOW);
   }
   else if(simonButton.orange && errors == 1){
      
      simonLevel++;
      pcf6.digitalWrite(2, HIGH);
      delay(300);
      pcf6.digitalWrite(2, LOW);
    }
    
    else if(simonButton.blue && errors == 2){
     
      simonLevel++;
      pcf6.digitalWrite(3, HIGH);
      delay(300);
      pcf6.digitalWrite(3, LOW);
    }
    else{
     
      simonLevel = 0;
      
      errors++;
      ilosc = 2;
      
     //Serial.println("Blad Z, errors = " + String(errors) + "   Number = " + String(number));
    }
  }

  //Czerwony
  if(randomColor[number] == 7 ){
    if(simonButton.blue && errors == 0){
      simonLevel++;
      
     pcf6.digitalWrite(3, HIGH);
     delay(300);
     pcf6.digitalWrite(3, LOW);
    }
    
    else if(simonButton.red && errors == 1){
      simonLevel++;
      pcf6.digitalWrite(0, HIGH);
      delay(300);
      pcf6.digitalWrite(0, LOW);
    
    }
   
    else if(simonButton.orange && errors == 2){
     
      simonLevel++;
      pcf6.digitalWrite(2, HIGH);
      delay(300);
      pcf6.digitalWrite(2, LOW);
    }
    else {

      simonLevel = 0;
      
      errors++;
      ilosc = 2;
    
      //Serial.println("Blad C, errors = " + String(errors) + "   Number = " + String(number));
    }
  }

  
}

void simonLogicGame(){
  if(simonLevel < 1) ilosc = 2;
  else if(simonLevel >= 1 && simonLevel < 3) ilosc = 3;
  else if(simonLevel >=3 && simonLevel < 6) ilosc = 4;
  else if(simonLevel >=6 && simonLevel < 10) ilosc = 5;

  
  
    if(ilosc == 2 &&(simonButton.blue || simonButton.red || simonButton.green || simonButton.orange)){
      if(vowel){
         simonLevel_vowel(0);
      }
      else
       simonLevel_non_vowel(0);
    }
    else if(ilosc ==3 &&(simonButton.blue || simonButton.red || simonButton.green || simonButton.orange)){
      if(simonLevel == 1){
        if(vowel){
          simonLevel_vowel(0);
        }
        else
        simonLevel_non_vowel(0);
      }
      else if(simonLevel == 2){
        if(vowel){
          simonLevel_vowel(1);
        }
        else 
         simonLevel_non_vowel(1);
      }
    }


    else if(ilosc == 4 &&(simonButton.blue || simonButton.red || simonButton.green || simonButton.orange)){
      if(simonLevel == 3) {
        if(vowel){
          simonLevel_vowel(0);
        }
        else
        simonLevel_non_vowel(0);
      }
      else if(simonLevel == 4) {
        if(vowel){
          simonLevel_vowel(1);
        }
        else
        simonLevel_non_vowel(1);
      }
      else if(simonLevel == 5) {
        if(vowel){
          simonLevel_vowel(2);
        }
        else
          simonLevel_non_vowel(2);
      }
    }

    else if(ilosc == 5 &&(simonButton.blue || simonButton.red || simonButton.green || simonButton.orange)){
      if(simonLevel == 6) {
        if(vowel){
          simonLevel_vowel(0);
        }
        else 
        simonLevel_non_vowel(0);
      }
      else if(simonLevel == 7) {
        if(vowel){
          simonLevel_vowel(1);
        }
        else simonLevel_non_vowel(1);
      }
      else if(simonLevel == 8) {
        if(vowel){
          simonLevel_vowel(2);
        }
        else simonLevel_non_vowel(2);
      }
      else if(simonLevel == 9) {
        if(vowel){
          simonLevel_vowel(3);
        }
        else simonLevel_non_vowel(3);
      }
    }

    if(simonLevel==10) {
      //Serial.println("Done");
      simonLevel = 11;
      allowSimon = false;
      pcf6.digitalWrite(0, HIGH);
      pcf6.digitalWrite(1, HIGH);
      pcf6.digitalWrite(2, HIGH);
      pcf6.digitalWrite(3, HIGH);
      for(byte i = 4; i < 8; i++){
      pcf5.digitalWrite(i, HIGH);
      Serial.println("S");
      }
    }
}




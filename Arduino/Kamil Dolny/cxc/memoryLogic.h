
extern byte error;
byte randomBig;
byte randomSmall[4] ={0,0,0,0};
bool memoryFlag = true;
byte memoryLevel = 1;
byte choiceNumber[4] = {0,0,0,0};
byte selectedButton[4] = {0,0,0,0};

void randomNumber(){

  //Losowanie dużej liczby
  randomBig = random(1,5);

  //Losowanie małych liczb, każda inna
  randomSmall[0] = random(1,5);
  do{
      randomSmall[1] = random(1,5);
  }while(randomSmall[0] == randomSmall[1]);

  do{
    randomSmall[2] = random(1, 5);
  }while(randomSmall[0] == randomSmall[2] || randomSmall[1] == randomSmall[2]);

  do{
     randomSmall[3] = random(1, 5);
  }while(randomSmall[0] == randomSmall[3] || randomSmall[1] == randomSmall[3] || randomSmall[2] == randomSmall[3]);

  
}

//Poziom pierwszy, pozostałe poziomy działają na tej samej zasadzie

void memoryLevel1(byte button){

  //Jesli wyświetlane jest 1 lub dwa to nalezy przycisnac przyci 2
  if((randomBig == 1 || randomBig == 2) && button == 2){
     memoryLevel ++; // zwiększenie poziomu
     choiceNumber[0] = randomSmall[button-1]; // zapisanie informacji  o tym jaka cyfra była nad naciśniętym przyciskiem
     selectedButton[0] = button; // zapisanie ifnormacji o tym jaki przycisk przycięnięto
  }
   
  else if(randomBig == 1 || randomBig == 2){
    error ++; // jeśli pomyłka to zwiększenie błędu
  }

  if(randomBig == 3 && button == 3){
    memoryLevel ++;
     choiceNumber[0] = randomSmall[button-1];
     selectedButton[0] = button;
    
  }
  else if(randomBig == 3){
    error ++;
  }

  if(randomBig == 4 && button == 4){
    memoryLevel ++;
     choiceNumber[0] = randomSmall[button-1];
     selectedButton[0] = button;
     
  }
  else if(randomBig == 4){
    error ++;
  }

  memoryFlag = true;
}

void memoryLevel2(byte button){

  if(randomBig == 1 && randomSmall[button-1] == 4){
    memoryLevel++;
     choiceNumber[1] = randomSmall[button-1];
     selectedButton[1] = button;
     
  }
  else if(randomBig == 1){
    error++;
    memoryLevel = 1;
  }

  if(randomBig == 2 && button == selectedButton[0]/*== 2*/){
    memoryLevel++;
    choiceNumber[1] = randomSmall[button-1];
    selectedButton[1] = button;
    
  }
  else if(randomBig == 2){
    error++;
    memoryLevel = 1;
  }

  if(randomBig == 3 && button == 1){
    memoryLevel++;
    choiceNumber[1] = randomSmall[button-1];
    selectedButton[1] = button;
    
  }
  else if(randomBig == 3){
    memoryLevel = 1;
    error++;
  }

  if(randomBig == 4 && button == selectedButton[0]/* == 4*/){
    memoryLevel++;
    choiceNumber[1] = randomSmall[button-1];
    selectedButton[1] = button;
    
  }
  else if(randomBig == 4)
  {
    error ++;
    memoryLevel = 1;
  }
  memoryFlag = true;
  Serial.println("Cyfra = " + String(randomSmall[button-1]));
}

void memoryLevel3(byte button){

   if(randomBig == 1 && choiceNumber[1] == randomSmall[button-1]){
    memoryLevel++;
    choiceNumber[2] = randomSmall[button-1];
    selectedButton[2] = button;
   }
   else if(randomBig == 1){
    error++;
    memoryLevel = 1;
   }

   if(randomBig == 2 && choiceNumber[0] == randomSmall[button-1]){
    memoryLevel++;
    choiceNumber[2] = randomSmall[button-1];
    selectedButton[2] = button;
   
   }
   else if(randomBig == 2){
    error++;
    memoryLevel = 1;
   }

   if(randomBig == 3 && button == 3){
    memoryLevel++;
    choiceNumber[2] = randomSmall[button-1];
    selectedButton[2] = button;
    
   }
   else if(randomBig == 3){
    error++;
    memoryLevel++;
   }
   if(randomBig == 4 && randomSmall[button-1] == 4){
    memoryLevel++;
    choiceNumber[2] = randomSmall[button-1];
    selectedButton[2] = button;
  
   }
   else if(randomBig == 4){
    error++;
    memoryLevel = 1;
   }
   memoryFlag = true;
}

void memoryLevel4(byte button){
  if(randomBig == 1 && button == selectedButton[0] /*== 2*/){
    memoryLevel++;
    choiceNumber[3] = randomSmall[button-1];
    selectedButton[3] = button;
    
  }
  else if(randomBig ==1){
    memoryLevel = 1;
    error++;
  }
  if(randomBig == 2 && button ==1){
    memoryLevel++;
    choiceNumber[3] = randomSmall[button-1];
    selectedButton[3] = button;
  }
  else if(randomBig == 2){
    memoryLevel = 1; 
    error++;
  }
  
  if((randomBig == 3 || randomBig == 4) && button == selectedButton[1]/*== 1*/){
    memoryLevel++;
    choiceNumber[3] = randomSmall[button-1];
    selectedButton[3] = button;
  }
  else if(randomBig == 3 || randomBig == 4){
    memoryLevel = 1;
    error++;
  }
  memoryFlag = true;
}

void memoryLevel5(byte button){
  if(randomBig == 1 && choiceNumber[0] == randomSmall[button-1]){
    memoryLevel++;
    
  }
  else if(randomBig == 1){
    error++;
    memoryLevel = 1;
  }

  if(randomBig == 2 && choiceNumber[1] == randomSmall[button-1]){
    memoryLevel++;
   
  }
  else if(randomBig == 2){
    error++;
    memoryLevel = 1;
  }

  if(randomBig == 3 && choiceNumber[3] == randomSmall[button-1]){
    memoryLevel++;
    
    
  }
  else if(randomBig == 3){
    error++;
    memoryLevel = 1;
  }

  if(randomBig == 4 && choiceNumber[2] == randomSmall[button-1]){
    memoryLevel++;
    
  }
  else if(randomBig == 4){
    error++;
    memoryLevel = 1;
    
  }
  memoryFlag = true;
}

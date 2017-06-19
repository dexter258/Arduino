
void dzwieki_przyciskow(){
  if ((bombardment.digitalRead(15)==HIGH) && (sound[0]==false)){                                              //przycisk "HA"
             SdPlay.stop();   
      if(!SdPlay.setFile("HA.wav")) {while(1); }
             SdPlay.play();
    sound[0]=true;
  }
     if (bombardment.digitalRead(15)==LOW) sound[0]=false;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
 if ((bombardment.digitalRead(14)==HIGH) && (sound[1]==false)){                                              //przycisk "HAHA"
             SdPlay.stop();   
      if(!SdPlay.setFile("HAHA.wav")) {while(1); }
             SdPlay.play();
    sound[1]=true;
  }
     if (bombardment.digitalRead(14)==LOW) sound[1]=false;
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   if ((bombardment.digitalRead(13)==HIGH) && (sound[2]==false)){                                              //przycisk "HAHAHA"
             SdPlay.stop();   
      if(!SdPlay.setFile("HAHAHA.wav")) {while(1); }
             SdPlay.play();
    sound[2]=true;
  }
     if (bombardment.digitalRead(13)==LOW) sound[2]=false;
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
           if ((gravity.digitalRead(0)==HIGH) && (sound[3]==false)){                                              //przycisk "XD"
             SdPlay.stop();   
      if(!SdPlay.setFile("XD.wav")) {while(1); }
             SdPlay.play();
    sound[3]=true;
  }
     if (gravity.digitalRead(0)==LOW) sound[3]=false;
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if ((gravity.digitalRead(1)==HIGH) && (sound[4]==false)){                                              //przycisk "OVER"
             SdPlay.stop();   
      if(!SdPlay.setFile("OVER.wav")) {while(1); }
             SdPlay.play();
    sound[4]=true;
  }
     if (gravity.digitalRead(1)==LOW) sound[4]=false;
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
           if ((gravity.digitalRead(3)==HIGH) && (sound[5]==false)){                                              //przycisk "SRODEK"
             SdPlay.stop();   
      if(!SdPlay.setFile("SRODEK.wav")) {while(1); }
             SdPlay.play();
    sound[5]=true;
  }
     if (gravity.digitalRead(3)==LOW) sound[5]=false;
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
         if ((gravity.digitalRead(5)==HIGH) && (sound[6]==false)){                                              //przycisk "COVERS"
             SdPlay.stop();   
      if(!SdPlay.setFile("COVERS.wav")) {while(1); }
             SdPlay.play();
    sound[6]=true;
  }
     if (gravity.digitalRead(5)==LOW) sound[6]=false;
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
           if ((gravity.digitalRead(7)==HIGH) && (sound[7]==false)){                                              //przycisk "XP"
             SdPlay.stop();   
      if(!SdPlay.setFile("XP.wav")) {while(1); }
             SdPlay.play();
    sound[7]=true;
  }
     if (gravity.digitalRead(7)==LOW) sound[7]=false;
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     if ((system.digitalRead(10)==HIGH) && (sound[9]==false)){                                              //przycisk "FART"
             SdPlay.stop();   
      if(!SdPlay.setFile("FART.wav")) {while(1); }
             SdPlay.play();
    sound[9]=true;
  }
     if (system.digitalRead(10)==LOW) sound[9]=false;
     ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
   if ((system.digitalRead(12)==HIGH) && (sound[10]==false)){                                              //przycisk "COFFE"
             SdPlay.stop();   
      if(!SdPlay.setFile("COFFE.wav")) {while(1); }
             SdPlay.play();
    sound[10]=true;
  }
     if (system.digitalRead(12)==LOW) sound[10]=false; 
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if ((bombardment.digitalRead(12)==HIGH) && (sound[11]==false)){                                              //przycisk "GRAVITY"
             SdPlay.stop();   
      if(!SdPlay.setFile("GRAV.wav")) {while(1); }
             SdPlay.play();
    sound[11]=true;
  }
     if (bombardment.digitalRead(12)==LOW) sound[11]=false;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
   if ((bombardment.digitalRead(8)==HIGH) && (sound[12]==false)){                                              //przełącznik "BLASTERS"
             SdPlay.stop();   
      if(!SdPlay.setFile("BLAST.wav")) {while(1); }
             SdPlay.play();
    sound[12]=true;
  }
     if (bombardment.digitalRead(8)==LOW) sound[12]=false;
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if ((bombardment.digitalRead(9)==HIGH) && (sound[13]==false)){                                               //przełącznik "MISSILES"
             SdPlay.stop();   
      if(!SdPlay.setFile("MISS.wav")) {while(1); }
             SdPlay.play();
    sound[13]=true;
  }
     if (bombardment.digitalRead(9)==LOW) sound[13]=false;
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if ((bombardment.digitalRead(10)==HIGH) && (sound[14]==false)){                                              //przełącznik "NUKES"
             SdPlay.stop();   
      if(!SdPlay.setFile("NUKE.wav")) {while(1); }
             SdPlay.play();
    sound[14]=true;
  }
     if (bombardment.digitalRead(10)==LOW) sound[14]=false;
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if ((bombardment.digitalRead(11)==HIGH) && (sound[15]==false)){                                                //przełącznik "BOOMSTICK"
             SdPlay.stop();   
      if(!SdPlay.setFile("BOOM.wav")) {while(1); }
             SdPlay.play();
    sound[15]=true;
  }
     if (bombardment.digitalRead(11)==LOW) sound[15]=false;
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
     if ((bombardment.digitalRead(0)==HIGH) && (sound[16]==false)){                                              //przycisk "BLASTERS"
             SdPlay.stop();   
      if(!SdPlay.setFile("BLASTX.wav")) {while(1); }
             SdPlay.play();
    sound[16]=true;
  }
     if (bombardment.digitalRead(0)==LOW) sound[16]=false;
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if ((bombardment.digitalRead(2)==HIGH) && (sound[17]==false)){                                               //przycisk "MISSILES"
             SdPlay.stop();   
      if(!SdPlay.setFile("MISSX.wav")) {while(1); }
             SdPlay.play();
    sound[17]=true;
  }
     if (bombardment.digitalRead(2)==LOW) sound[17]=false;
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if ((bombardment.digitalRead(4)==HIGH) && (sound[18]==false)){                                              //przycisk "NUKES"
             SdPlay.stop();   
      if(!SdPlay.setFile("NUKEX.wav")) {while(1); }
             SdPlay.play();
    sound[18]=true;
  }
     if (bombardment.digitalRead(4)==LOW) sound[18]=false;
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if ((bombardment.digitalRead(6)==HIGH) && (sound[19]==false)){                                                //przycisk "BOOMSTICK"
             SdPlay.stop();   
      if(!SdPlay.setFile("BOOMX.wav")) {while(1); }
             SdPlay.play();
    sound[19]=true;
  }
     if (bombardment.digitalRead(6)==LOW) sound[19]=false;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   if ((spindle.digitalRead(10)==HIGH) && (sound[20]==false)){                                                //przycisk "LESS ROCK"
             SdPlay.stop();   
      if(!SdPlay.setFile("LESS.wav")) {while(1); }
             SdPlay.play();
    sound[20]=true;
  }
     if (spindle.digitalRead(10)==LOW) sound[20]=false;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if ((spindle.digitalRead(14)==HIGH) && (sound[21]==false)){                                                //przycisk "MORE ROCK"
             SdPlay.stop();   
      if(!SdPlay.setFile("MORE.wav")) {while(1); }
             SdPlay.play();
    sound[21]=true;
  }
     if (spindle.digitalRead(14)==LOW) sound[21]=false;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     if ((spindle.digitalRead(0)==HIGH) && (sound[22]==false)){                                                //przycisk "LEWY"
             SdPlay.stop();   
      if(!SdPlay.setFile("LEWY.wav")) {while(1); }
             SdPlay.play();
    sound[22]=true;
  }
     if (spindle.digitalRead(0)==LOW) sound[22]=false;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      if ((spindle.digitalRead(15)==HIGH) && (sound[23]==false)){                                                //przycisk "PRAWY"
             SdPlay.stop();   
      if(!SdPlay.setFile("PRAWY.wav")) {while(1); }
             SdPlay.play();
    sound[23]=true;
  }
     if (spindle.digitalRead(15)==LOW) sound[23]=false;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       if ((spindle.digitalRead(1)==HIGH) && (sound[24]==false)){                                                //przelacznik "TUTTI"
             SdPlay.stop();   
      if(!SdPlay.setFile("TUTTI.wav")) {while(1); }
             SdPlay.play();
    sound[24]=true;
  }
     if (spindle.digitalRead(1)==LOW) sound[24]=false;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if ((spindle.digitalRead(2)==HIGH) && (sound[25]==false)){                                                //przelacznik "FRUTTI"
             SdPlay.stop();   
      if(!SdPlay.setFile("FRUTTI.wav")) {while(1); }
             SdPlay.play();
    sound[25]=true;
  }
     if (spindle.digitalRead(2)==LOW) sound[25]=false;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         if ((spindle.digitalRead(3)==HIGH) && (sound[26]==false)){                                                //przelacznik "DOL"
             SdPlay.stop();   
      if(!SdPlay.setFile("DOL.wav")) {while(1); }
             SdPlay.play();
    sound[26]=true;
  }
     if (spindle.digitalRead(3)==LOW) sound[26]=false;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         if ((spindle.digitalRead(4)==HIGH) && (sound[27]==false)){                                                //przelacznik "ALVARO"
             SdPlay.stop();   
      if(!SdPlay.setFile("ALVARO.wav")) {while(1); }
             SdPlay.play();
    sound[27]=true;
  }
     if (spindle.digitalRead(4)==LOW) sound[27]=false;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         if ((spindle.digitalRead(5)==HIGH) && (sound[28]==false)){                                                //przelacznik "AMIGO"
             SdPlay.stop();   
      if(!SdPlay.setFile("AMIGO.wav")) {while(1); }
             SdPlay.play();
    sound[28]=true;
  }
     if (spindle.digitalRead(5)==LOW) sound[28]=false;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       if ((spindle.digitalRead(12)==HIGH) && (sound[29]==false)){                                                //przycisk "IGNITION"
             SdPlay.stop();   
     if(!SdPlay.setFile("POWTORZ.wav")) {while(1); }
        //    if(!SdPlay.setFile("14.wav")) {while(1); }
             SdPlay.play();
    sound[29]=true;
  }
     if (spindle.digitalRead(12)==LOW) sound[29]=false;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (sound[28]==true){
  lvl++;
}

for (int i=0;i<29;i++){
  if (sound[i]!=zapamietane_stany[i]){
  if ((sound[i]==true)&&(zapamietane_stany[i]==false)){
    wcisniety[i]==true;                                     //wyznaczanie aktualnie wcisnietych przelacznikow
  }
  else wcisniety[i]==false;
  }
  else wcisniety[i]==false;
  
  zapamietane_stany[i]=sound[i];                             //przypisanie aktualnych stanow
}
suma=0;
for (int i=0;i<29;i++){
  suma+=wcisniety[i];
}

  if ((lvl==1)&&(wcisniety[1]==false)&&(suma>0)) lvl=0;
  if ((lvl==2)&&(wcisniety[4]==false)&&(suma>0)) lvl=0;
  if ((lvl==3)&&(wcisniety[22]==false)&&(suma>0)) lvl=0;
    if ((lvl==4)&&(wcisniety[19]==false)&&(suma>0)) lvl=0;
        if ((lvl==5)&&(wcisniety[7]==false)&&(suma>0)) lvl=0;
if (wcisniety[28]==true){
  lvl=1;
}
  if ((lvl==1)&&(wcisniety[1]==true)){
    lvl=2;
  }
    if ((lvl==2)&&(wcisniety[4]==true)){
    lvl=3;
  }
      if ((lvl==3)&&(wcisniety[22]==true)){
    lvl=4;
  }
        if ((lvl==4)&&(wcisniety[19]==true)){
    lvl=5;
  }
          if ((lvl==5)&&(wcisniety[7]==true)){
    lvl=6;
  }
   if (lvl==0){
 system.digitalWrite(13,LOW);
    system.digitalWrite(2,LOW);
     system.digitalWrite(5,LOW);
      system.digitalWrite(8,LOW);
        system.digitalWrite(9,LOW);
    system.digitalWrite(11,LOW);
 }
 if (lvl==2){
 system.digitalWrite(13,HIGH);
 }
 if (lvl==3){
   system.digitalWrite(2,HIGH);
 }
  if (lvl==4){
   system.digitalWrite(5,HIGH);
 }
   if (lvl==5){
   system.digitalWrite(8,HIGH);
 }
    if (lvl==6){
  system.digitalWrite(9,HIGH);
    system.digitalWrite(11,HIGH);
    koniecc=true;
 }
   
   
 }
 
 
  













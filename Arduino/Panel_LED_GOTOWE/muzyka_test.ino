
void dzwieki_przyciskow(){
 
  if ((bombardment.digitalRead(15)==HIGH) && (sound[0]==0)){                                              //przycisk "HA"
             SdPlay.stop();   
      if(!SdPlay.setFile("HA.wav")) {while(1); }
             SdPlay.play();
    sound[0]=1;
  }
     if (bombardment.digitalRead(15)==LOW) sound[0]=0;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
 if ((bombardment.digitalRead(14)==HIGH) && (sound[1]==0)){                                              //przycisk "HAHA"
             SdPlay.stop();   
      if(!SdPlay.setFile("HAHA.wav")) {while(1); }
             SdPlay.play();
    sound[1]=1;
  }
     if (bombardment.digitalRead(14)==LOW) sound[1]=0;
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   if ((bombardment.digitalRead(13)==HIGH) && (sound[2]==0)){                                              //przycisk "HAHAHA"
             SdPlay.stop();   
      if(!SdPlay.setFile("HAHAHA.wav")) {while(1); }
             SdPlay.play();
    sound[2]=1;
  }
     if (bombardment.digitalRead(13)==LOW) sound[2]=0;
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
           if ((gravity.digitalRead(0)==HIGH) && (sound[3]==0)){                                              //przycisk "XD"
             SdPlay.stop();   
      if(!SdPlay.setFile("XD.wav")) {while(1); }
             SdPlay.play();
    sound[3]=1;
  }
     if (gravity.digitalRead(0)==LOW) sound[3]=0;
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if ((gravity.digitalRead(1)==HIGH) && (sound[4]==0)){                                              //przycisk "OVER"
             SdPlay.stop();   
      if(!SdPlay.setFile("OVER.wav")) {while(1); }
             SdPlay.play();
    sound[4]=1;
  }
     if (gravity.digitalRead(1)==LOW) sound[4]=0;
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
           if ((gravity.digitalRead(3)==HIGH) && (sound[5]==0)){                                              //przycisk "SRODEK"
             SdPlay.stop();   
      if(!SdPlay.setFile("SRODEK.wav")) {while(1); }
             SdPlay.play();
    sound[5]=1;
  }
     if (gravity.digitalRead(3)==LOW) sound[5]=0;
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
         if ((gravity.digitalRead(5)==HIGH) && (sound[6]==0)){                                              //przycisk "COVERS"
             SdPlay.stop();   
      if(!SdPlay.setFile("COVERS.wav")) {while(1); }
             SdPlay.play();
    sound[6]=1;
  }
     if (gravity.digitalRead(5)==LOW) sound[6]=0;
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
           if ((gravity.digitalRead(7)==HIGH) && (sound[7]==0)){                                              //przycisk "XP"
             SdPlay.stop();   
      if(!SdPlay.setFile("XP.wav")) {while(1); }
             SdPlay.play();
    sound[7]=1;
  }
     if (gravity.digitalRead(7)==LOW) sound[7]=0;
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     if ((system.digitalRead(10)==HIGH) && (sound[9]==0)){                                              //przycisk "FART"
             SdPlay.stop();   
      if(!SdPlay.setFile("FART.wav")) {while(1); }
             SdPlay.play();
    sound[9]=1;
  }
     if (system.digitalRead(10)==LOW) sound[9]=0;
     ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
   if ((system.digitalRead(12)==HIGH) && (sound[10]==0)){                                              //przycisk "COFFE"
             SdPlay.stop();   
      if(!SdPlay.setFile("COFFE.wav")) {while(1); }
             SdPlay.play();
    sound[10]=1;
  }
     if (system.digitalRead(12)==LOW) sound[10]=0; 
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if ((bombardment.digitalRead(12)==HIGH) && (sound[11]==0)){                                              //przycisk "GRAVITY"
             SdPlay.stop();   
      if(!SdPlay.setFile("GRAV.wav")) {while(1); }
             SdPlay.play();
    sound[11]=1;
  }
     if (bombardment.digitalRead(12)==LOW) sound[11]=0;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
   if ((bombardment.digitalRead(8)==HIGH) && (sound[12]==0)){                                              //przełącznik "BLASTERS"
             SdPlay.stop();   
      if(!SdPlay.setFile("BLAST.wav")) {while(1); }
             SdPlay.play();
    sound[12]=1;
  }
     if (bombardment.digitalRead(8)==LOW) sound[12]=0;
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if ((bombardment.digitalRead(9)==HIGH) && (sound[13]==0)){                                               //przełącznik "MISSILES"
             SdPlay.stop();   
      if(!SdPlay.setFile("MISS.wav")) {while(1); }
             SdPlay.play();
    sound[13]=1;
  }
     if (bombardment.digitalRead(9)==LOW) sound[13]=0;
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if ((bombardment.digitalRead(10)==HIGH) && (sound[14]==0)){                                              //przełącznik "NUKES"
             SdPlay.stop();   
      if(!SdPlay.setFile("NUKE.wav")) {while(1); }
             SdPlay.play();
    sound[14]=1;
  }
     if (bombardment.digitalRead(10)==LOW) sound[14]=0;
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if ((bombardment.digitalRead(11)==HIGH) && (sound[15]==0)){                                                //przełącznik "BOOMSTICK"
             SdPlay.stop();   
      if(!SdPlay.setFile("BOOM.wav")) {while(1); }
             SdPlay.play();
    sound[15]=1;
  }
     if (bombardment.digitalRead(11)==LOW) sound[15]=0;
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
     if ((bombardment.digitalRead(0)==HIGH) && (sound[16]==0)){                                              //przycisk "BLASTERS"
             SdPlay.stop();   
      if(!SdPlay.setFile("BLASTX.wav")) {while(1); }
             SdPlay.play();
    sound[16]=1;
  }
     if (bombardment.digitalRead(0)==LOW) sound[16]=0;
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if ((bombardment.digitalRead(2)==HIGH) && (sound[17]==0)){                                               //przycisk "MISSILES"
             SdPlay.stop();   
      if(!SdPlay.setFile("MISSX.wav")) {while(1); }
             SdPlay.play();
    sound[17]=1;
  }
     if (bombardment.digitalRead(2)==LOW) sound[17]=0;
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if ((bombardment.digitalRead(4)==HIGH) && (sound[18]==0)){                                              //przycisk "NUKES"
             SdPlay.stop();   
      if(!SdPlay.setFile("NUKEX.wav")) {while(1); }
             SdPlay.play();
    sound[18]=1;
  }
     if (bombardment.digitalRead(4)==LOW) sound[18]=0;
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if ((bombardment.digitalRead(6)==HIGH) && (sound[19]==0)){                                                //przycisk "BOOMSTICK"
             SdPlay.stop();   
      if(!SdPlay.setFile("BOOMX.wav")) {while(1); }
             SdPlay.play();
    sound[19]=1;
  }
     if (bombardment.digitalRead(6)==LOW) sound[19]=0;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   if ((spindle.digitalRead(10)==HIGH) && (sound[20]==0)){                                                //przycisk "LESS ROCK"
             SdPlay.stop();   
      if(!SdPlay.setFile("LESS.wav")) {while(1); }
             SdPlay.play();
    sound[20]=1;
  }
     if (spindle.digitalRead(10)==LOW) sound[20]=0;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if ((spindle.digitalRead(14)==HIGH) && (sound[21]==0)){                                                //przycisk "MORE ROCK"
             SdPlay.stop();   
      if(!SdPlay.setFile("MORE.wav")) {while(1); }
             SdPlay.play();
    sound[21]=1;
  }
     if (spindle.digitalRead(14)==LOW) sound[21]=0;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     if ((spindle.digitalRead(0)==HIGH) && (sound[22]==0)){                                                //przycisk "LEWY"
             SdPlay.stop();   
      if(!SdPlay.setFile("LEWY.wav")) {while(1); }
             SdPlay.play();
    sound[22]=1;
  }
     if (spindle.digitalRead(0)==LOW) sound[22]=0;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      if ((spindle.digitalRead(15)==HIGH) && (sound[23]==0)){                                                //przycisk "PRAWY"
             SdPlay.stop();   
      if(!SdPlay.setFile("PRAWY.wav")) {while(1); }
             SdPlay.play();
    sound[23]=1;
  }
     if (spindle.digitalRead(15)==LOW) sound[23]=0;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       if ((spindle.digitalRead(1)==HIGH) && (sound[24]==0)){                                                //przelacznik "TUTTI"
             SdPlay.stop();   
      if(!SdPlay.setFile("TUTTI.wav")) {while(1); }
             SdPlay.play();
    sound[24]=1;
  }
     if (spindle.digitalRead(1)==LOW) sound[24]=0;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if ((spindle.digitalRead(2)==HIGH) && (sound[25]==0)){                                                //przelacznik "FRUTTI"
             SdPlay.stop();   
      if(!SdPlay.setFile("FRUTTI.wav")) {while(1); }
             SdPlay.play();
    sound[25]=1;
  }
     if (spindle.digitalRead(2)==LOW) sound[25]=0;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         if ((spindle.digitalRead(3)==HIGH) && (sound[26]==0)){                                                //przelacznik "DOL"
             SdPlay.stop();   
      if(!SdPlay.setFile("DOL.wav")) {while(1); }
             SdPlay.play();
    sound[26]=1;
  }
     if (spindle.digitalRead(3)==LOW) sound[26]=0;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         if ((spindle.digitalRead(4)==HIGH) && (sound[27]==0)){                                                //przelacznik "ALVARO"
             SdPlay.stop();   
      if(!SdPlay.setFile("ALVARO.wav")) {while(1); }
             SdPlay.play();
    sound[27]=1;
  }
     if (spindle.digitalRead(4)==LOW) sound[27]=0;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         if ((spindle.digitalRead(5)==HIGH) && (sound[28]==0)){                                                //przelacznik "AMIGO"
             SdPlay.stop();   
      if(!SdPlay.setFile("AMIGO.wav")) {while(1); }
             SdPlay.play();
    sound[28]=1;
  }
     if (spindle.digitalRead(5)==LOW) sound[28]=0;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       if ((spindle.digitalRead(12)==HIGH) && (sound[29]==0)){                                                //przycisk "IGNITION"
             SdPlay.stop();   
     if(!SdPlay.setFile("mix832s.wav")) {while(1); }
        //    if(!SdPlay.setFile("14.wav")) {while(1); }
             SdPlay.play();
    sound[29]=1;
  }
     if (spindle.digitalRead(12)==LOW) sound[29]=0;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


  for (int i=0;i<29;i++){
  if (sound[i]!=zapamietane[i]){
  if ((sound[i]==1)&&(zapamietane[i]==0)){
    wcisniety[i]=1;                                     //wyznaczanie aktualnie wcisnietych przelacznikow
  }
  else wcisniety[i]=0;
  }
  else wcisniety[i]=0;
  
                          //przypisanie aktualnych stanow
}
for(int i=0;i<29;i++){
  zapamietane[i]=sound[i];   
}
suma=0;
for (int i=0;i<29;i++){
  suma=wcisniety[i]+suma;
}


  if ((lvl==1)&&(wcisniety[1]==0)&&(suma>0)) lvl=0;
  if ((lvl==2)&&(wcisniety[22]==0)&&(suma>0)) lvl=0;
  if ((lvl==3)&&(wcisniety[15]==0)&&(suma>0)) lvl=0;
    if ((lvl==4)&&(wcisniety[26]==0)&&(suma>0)) lvl=0;
        if ((lvl==5)&&(wcisniety[3]==0)&&(suma>0)) lvl=0;
if (wcisniety[28]==1){
  lvl=1;
}
  if ((lvl==1)&&(wcisniety[1]==1)){
    lvl=2;
  }
    if ((lvl==2)&&(wcisniety[22]==1)){
    lvl=3;
  }
      if ((lvl==3)&&(wcisniety[15]==1)){
    lvl=4;
  }
        if ((lvl==4)&&(wcisniety[26]==1)){
    lvl=5;
  }
          if ((lvl==5)&&(wcisniety[3]==1)){
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
 if (lvl==1){
 system.digitalWrite(2,HIGH);
  system.digitalWrite(13,LOW);
     system.digitalWrite(5,LOW);
      system.digitalWrite(8,LOW);
        system.digitalWrite(9,LOW);
    system.digitalWrite(11,LOW);
 }
 if (lvl==2){
   system.digitalWrite(8,HIGH);
 }
  if (lvl==3){
   system.digitalWrite(5,HIGH);
 }
   if (lvl==4){
   system.digitalWrite(13,HIGH);
 }
  if (lvl==5){
  system.digitalWrite(9,HIGH);
 }
    if (lvl==6){
    system.digitalWrite(11,HIGH);
    koniecc=true;
 }
   
   
 }
 
 
  













void zwyciestwo(){
  digitalWrite(2,LOW);                       //niebieski
digitalWrite(3,LOW);                         //czerwony
  digitalWrite(4,LOW);                        //zielony
 digitalWrite(5,LOW);                           //czerwony
digitalWrite(6,LOW);                           //zielony
digitalWrite(7,LOW);                            //niebieski
digitalWrite(10,LOW);         //zielony
digitalWrite(A1,LOW);         //czerwony
digitalWrite(8,LOW);           //niebieski
gravity.digitalWrite(12,LOW) ;        //czerwnoy
gravity.digitalWrite(15,LOW);         //niebieski
gravity.digitalWrite(9,LOW);  



for (int j=0;j<3;j++){                      //ZIELONO MI
digitalWrite(panele[2][j],HIGH);
}
gravity.digitalWrite(panele[2][3],HIGH); 
delay(100);
for (int j=0;j<3;j++){
digitalWrite(panele[2][j],LOW);
}
gravity.digitalWrite(panele[2][3],LOW); 
delay(150);
for (int k=0;k<3;k++){
for (int j=0;j<3;j++){                           //zmienianie kolorów w kółko
for (int i=0;i<3;i++){
digitalWrite(panele[j][i],HIGH);
delay(400-j*50-k*100);
if (i==2)gravity.digitalWrite(panele[j][3],HIGH);  
}
delay(600-j*50-k*150);
for (int i=0;i<3;i++){
digitalWrite(panele[j][i],LOW);
delay(400-j*50-k*100);
if (i==2)gravity.digitalWrite(panele[j][3],LOW);  
}
}
}
for (int k=0;k<3;k++){
for (int j=0;j<3;j++){                    //zmienianie kolorow calosc
for (int i=0;i<3;i++){
digitalWrite(panele[j][i],HIGH);
//delay(400-j*100);
if (i==2)gravity.digitalWrite(panele[j][3],HIGH);  
}
delay(400-k*50);
for (int i=0;i<3;i++){
digitalWrite(panele[j][i],LOW);
//delay(400-j*100);
if (i==2)gravity.digitalWrite(panele[j][3],LOW);  
}
}
}
for (int i=0;i<20;i++){
x1=random(0,3);
x2=random(0,3);
x3=random(0,3);
x4=random(0,3);

digitalWrite(panele[x1][0],HIGH);
digitalWrite(panele[x2][1],HIGH);
digitalWrite(panele[x3][2],HIGH);
gravity.digitalWrite(panele[x4][3],HIGH);  
delay(random(100,200));
digitalWrite(panele[x1][0],LOW);
digitalWrite(panele[x2][1],LOW);
digitalWrite(panele[x3][2],LOW);
gravity.digitalWrite(panele[x4][3],LOW);  
}
}





void initErrorsPanel(){
  pinMode(45, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(49, OUTPUT);

  digitalWrite(45, LOW);
  digitalWrite(47, LOW);
  digitalWrite(49, LOW);
}

void setErrors(byte number){

  
    digitalWrite(45, LOW);
    digitalWrite(47, LOW);
    digitalWrite(49, LOW);
  
  if(number == 1){
    digitalWrite(49, HIGH);  
  }
  else if(number == 2){
    digitalWrite(49, HIGH);  
    digitalWrite(47, HIGH);
    
  }
  else if(number >= 3){
    digitalWrite(49, HIGH);  
    digitalWrite(47, HIGH);
    digitalWrite(45, HIGH);
  }
  
}


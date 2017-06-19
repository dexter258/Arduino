extern bool on1, on2, on3, on4, on5;

extern PCF8574 pcf;
byte switches[5] = {0,0,0,0,0};

void readSwitches(){
  if(digitalRead(2) == LOW){
    switches[0] = 1;
    pcf.digitalWrite(1, HIGH);
    on1=false;
  }
  else if(digitalRead(3) == LOW){
    switches[0] = 2;
    pcf.digitalWrite(1, HIGH);
    on1=true;
  }
  else{
    switches[0] = 0;
    pcf.digitalWrite(1, LOW);
    on1 = false;
  }

  if(digitalRead(4) == LOW){
    switches[1] = 1;
    pcf.digitalWrite(2, HIGH);
    on2 = false;
  }
  else if(digitalRead(5) == LOW){
    switches[1] = 2;
    pcf.digitalWrite(2, HIGH);
    on2 = true;
  }
  else{
    switches[1] = 0;
    pcf.digitalWrite(2, LOW);
    on2 = false;
  }

  if(digitalRead(6) == LOW){
    switches[2] = 1;
    pcf.digitalWrite(3, HIGH);
    on3=false;
  }
  else if(digitalRead(7) == LOW){
    switches[2] = 2;
    pcf.digitalWrite(3, HIGH);
    on3 = true;
  }
  else{
    switches[2] = 0;
    pcf.digitalWrite(3, LOW);
    on3 = false;
  }

  if(digitalRead(8) == LOW){
    switches[3] = 1;
    pcf.digitalWrite(4, HIGH);
    on4 = false;
  }
  else if(digitalRead(9) == LOW){
    switches[3] = 2;
    pcf.digitalWrite(4, HIGH);
    on4 = true;
  }
  else{
    switches[3] = 0;
    pcf.digitalWrite(4, LOW);
    on4 = false;
  }

  if(digitalRead(10) == LOW){
    switches[4] = 1;
    pcf.digitalWrite(5, HIGH);
    on5 = false;
  }
  else if(digitalRead(11) == LOW){
    switches[4] = 2;
    pcf.digitalWrite(5, HIGH);
    on5 = true;
  }
  else{
    switches[4] = 0;
    pcf.digitalWrite(5, LOW);
    on5 = false;
  }
  
}


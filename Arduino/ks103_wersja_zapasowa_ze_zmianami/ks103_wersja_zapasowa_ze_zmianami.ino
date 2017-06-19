#include <Wire.h>
#define KS103ADD  0x74 
word distance=0;
void setup()
{
  Wire.begin();                    
  Serial.begin(9600);             
  Wire.beginTransmission(KS103ADD); 
  Wire.write(byte(0x02));     
  Wire.write(0x72);   // 发送降噪指令    
  Wire.endTransmission();     
  delay(1000);                    
}
void loop()
{Serial.print("mm");
    if (Serial.read() == 's') {
      while(Serial.read() != 'o'){
        KS103_read();
        Serial.print(distance); 
        Serial.print("mm");
        Serial.println();
        delay(250); 
      }
    }
    delay(1000); 
}
 
word KS103_read(){ 
  Wire.beginTransmission(KS103ADD);
  Wire.write(byte(0x02));     
  Wire.write(0xbc);     //量程设置为10m 带温度补偿
  Wire.endTransmission();     
  delay(1);                
  Wire.beginTransmission(KS103ADD); 
  Wire.write(byte(0x02));    
  Wire.endTransmission();   
  Wire.requestFrom(KS103ADD, 2);  
  if(2 <= Wire.available())   
  {
    distance = Wire.read(); 
    distance =  distance << 8;   
    distance |= Wire.read();
  }
}

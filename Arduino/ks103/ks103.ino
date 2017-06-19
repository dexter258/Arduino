#include <Wire.h>
#define KS103ADD  0x74 
word distance=0;
void setup()
{
  Wire.begin();                    
  Serial.begin(9600);             
  Wire.beginTransmission(KS103ADD); 
  Wire.write(byte(0x02));     
  Wire.write(0x71);    
  Wire.endTransmission();     
  delay(1000);                    
}
void loop()
{
  KS103_read();
  Serial.println(distance); 
  delay(200); 
}
 
word KS103_read(){ 
  Wire.beginTransmission(KS103ADD);
  Wire.write(byte(0x02));     
  Wire.write(0xb0);     //量程设置为5m 不带温度补偿
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

#include <Servo.h> 

#include <Password.h> 
#include <Keypad.h>
 /////////////////////////////////////////////////////////////
                                                                                  // ustawienie hasel
Password password = Password( "1234" );        
Password password2 = Password( "124" );
const byte ROWS = 4; // Four rows
const byte COLS = 4; //  columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = { 26,27,28,29 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 22,23,24,25, };// Connect keypad COL0, COL1 and COL2 to these Arduino pins.


// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
////////////////////////////////////////////////////////////////////////////////////
                                                                                // usatwienia serwów 
Servo servo_naped;  // create servo object to control a servo 

 Servo servo_blokada;          // a maximum of eight servo objects can be created 
 int poczatek_blokada=50;
 int koniec_blokada=132;
  int poczatek_naped=0;
 int koniec_naped=164;
int pos = 0;    // variable to store the servo position 
 boolean start=false;


////////////////////////////////////////////////////////////////////////////////////
                                                                                // elektromagnesy i ledy
 #define przycisk 7
 #define odnowa 5
 #define led 4

#define elektromagnesy_przejscie 30
#define elektromagnesy_R2D2 31
$define elektromagnesy_szafa 32


void setup(){

  Serial.begin(9600);
  keypad.addEventListener(keypadEvent); //add an event listener for this keypad
  
  
   servo_blokada.attach(9);  
  servo_naped.attach(8);  
  pinMode(przycisk,INPUT);
   pinMode(odnowa,INPUT);
   pinMode(led,OUTPUT);
   analogWrite(led,0);
   servo_naped.write(poczatek_naped); 
     delay(2500);
    servo_blokada.write(poczatek_blokada); 
   
   delay(1800);
 //   servo_blokada.detach();  
  servo_naped.detach();  
}

void loop(){
  keypad.getKey();
   if (start==true){
      servo_blokada.write(koniec_blokada);
     delay(1000); 
   servo_naped.write(koniec_naped); 
    servo_blokada.detach();  
  }
}

//take care of some special events
void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
    case PRESSED:
	Serial.print("Pressed: ");
	Serial.println(eKey);
	switch (eKey){
	  case '#': checkPassword(); password.reset();  password2.reset(); break;
	  case '*': password.reset(); password2.reset(); break;
	  default: password.append(eKey);password2.append(eKey);
     }
  }
}

void checkPassword(){
  if (password.evaluate()){
    Serial.println("Success");
   start=true;
         servo_blokada.attach(9);  
  servo_naped.attach(8);  
  analogWrite(led,200);
  }else{
    Serial.println("Wrong");
    //add code to run if it did not work
  }
  if (password2.evaluate()){
     start=false;
  servo_blokada.attach(9); 
     servo_naped.write(poczatek_naped); 
     delay(5500);
    servo_blokada.write(poczatek_blokada); 
   
   delay(1800);
 //   servo_blokada.detach();  
  servo_naped.detach(); 
  analogWrite(led,0);
  }
}

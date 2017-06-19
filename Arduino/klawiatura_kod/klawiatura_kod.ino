#include <Password.h> //http://www.arduino.cc/playground/uploads/Code/Password.zip
#include <Keypad.h> //http://www.arduino.cc/playground/uploads/Code/Keypad.zip

#include <Servo.h> //dołączamy niezbędne biblioteki

Servo servo1; //dodajemy serwo
Password password = Password( "1410" ); //ustalamy hasło

const byte ROWS = 4;
const byte COLS = 4;
int lock=0;
int proby=0;
int dioda=0;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
}; //tworzymy klawiaturkę

byte rowPins[ROWS] = { 9,8,7,6 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 5,4,3,2 };// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
short but1=0;
short but2=0;

// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void servo_lock(){ //funkcja blokująca drzwi
    servo1.attach(12);
    servo1.write(25);
    delay(500);
    servo1.detach();}

void servo_unlock(){ //funkcja otwierająca drzwi
    servo1.attach(12);
    servo1.write(155);
    delay(500);
    servo1.detach();}

void setup(){
    pinMode(13,OUTPUT);
    pinMode(1,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);

    keypad.addEventListener(keypadEvent); //rozpoczyna nasluch na klawiaturce
}

void loop(){

but1=analogRead(0);
but2=analogRead(5);

if(but1>900){
    servo_lock();
    but1=0;
}

if(but2>900){
    servo_unlock();
    but2=0; // otwieranie i zamykanie drzwi z wewnątrz
}
keypad.getKey();
}

void keypadEvent(KeypadEvent eKey){

switch (keypad.getState()){ //odczyt stanu klawisza
case PRESSED:

switch (eKey){
    case '#':
      checkPassword(); //po nacisnięciu # sprawdza poprawność hasła
    //  dioda_zapal();
      break;
    case '*': //po naciśnięciu * resetuje próbę wpisania hasła
      password.reset();
      servo_lock();
      dioda=0;
    //  dioda_zapal();
      break;
    default:  
      password.append(eKey);
      dioda++;
  //    dioda_zapal();//jeśli jest to inny klawisz to dopisuje go do hasła które jest właśnie wpisywane
}
}
}

void checkPassword(){
    if (password.evaluate()){//jeśli hasło się zgadza otwiera drzwi
     digitalWrite(13,HIGH);
          servo_unlock();
    delay(100);
     digitalWrite(13,LOW);
     delay(100);
      digitalWrite(13,HIGH);
       delay(100);
     digitalWrite(13,LOW);
     delay(100);
      digitalWrite(13,HIGH);
     delay(2000);
     digitalWrite(13,LOW);
      password.reset();
      dioda=0;
     // dioda_zapal();
     
}
else{//a jesli nie to je zamyka
digitalWrite(1,HIGH);
servo_lock;
    delay(100);
     digitalWrite(1,LOW);
     delay(100);
      digitalWrite(1,HIGH);
      delay(100);
     digitalWrite(1,LOW);
     delay(100);
      digitalWrite(1,HIGH);
      delay(1000);
     digitalWrite(1,LOW);
dioda=0;
//dioda_zapal;
password.reset();
}}

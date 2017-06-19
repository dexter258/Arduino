
#include <VirtualWire.h>
#include <ServoTimer2.h>  // the servo library
#define transmit_pin 10
#define yawPin   4
const char *wiadomosc;
ServoTimer2 servoRoll;    // declare variables for up to eight servos
ServoTimer2 servoPitch;
ServoTimer2 servoYaw;
void setup()
{
servoYaw.attach(yawPin);
servoYaw.write(1094);
    vw_set_tx_pin(transmit_pin);
    vw_setup(2000);
      servoYaw.detach();
}
void loop()
{

      servoYaw.attach(yawPin);
       delay(40);
  servoYaw.write(1554); 
wiadomosc="9";
String toSend = (wiadomosc); // tekst wiadomości

char msg[23]; // tworzymy tablicę typu char
  toSend.toCharArray(msg, toSend.length() + 1); // konwertujemy nasz tekst do tablicy charów

  vw_send((uint8_t *)msg, strlen(msg));// wysyłamy 
  vw_wait_tx(); 
  delay(1000);
  servoYaw.write(1094);
  delay(1000);
}

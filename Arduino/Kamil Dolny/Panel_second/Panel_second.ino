#include "setLeds.h"

char buf [100];
volatile byte pos;
volatile boolean process_it;


void setup() {
  // put your setup code here, to run once:
  mcp0.begin(0); 
  mcp1.begin(1);
  mcp2.begin(2);
  mcp3.begin(3);
  mcp4.begin(4);

  pcf.begin(0x3F);

  // turn on SPI in slave mode
  SPCR |= bit (SPE);

  // have to send on master in, *slave out*
  pinMode(MISO, OUTPUT);

  // get ready for an interrupt
  pos = 0;   // buffer empty
  process_it = false;

  // now turn on interrupts
  SPI.setBitOrder(LSBFIRST);                //LSBFIRST or MSBFIRST
  SPI.setDataMode(SPI_MODE3);               //CPOL=1 CPHA=1
  SPI.setClockDivider(SPI_CLOCK_DIV64);
  SPI.attachInterrupt();


  for (byte i = 1; i < 16; i++) {
    mcp0.pinMode(i, OUTPUT);

    mcp0.digitalWrite(i, LOW);

    mcp1.pinMode(i, OUTPUT);
    mcp1.digitalWrite(i, LOW);

    mcp2.pinMode(i, OUTPUT);
    mcp2.digitalWrite(i, LOW);

    mcp3.pinMode(i, OUTPUT);
    mcp3.digitalWrite(i, LOW);

    mcp4.pinMode(i, OUTPUT);
    mcp4.digitalWrite(i, HIGH);

  }
  mcp4.pinMode(0, OUTPUT);
  mcp4.digitalWrite(0, HIGH);
  for (byte i = 0; i < 8; i++) {
    pcf.pinMode(i, OUTPUT);
    pcf.digitalWrite(i, HIGH);
  }

  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  Serial.begin(9600);

}
ISR (SPI_STC_vect)
{
  byte c = SPDR;  // grab byte from SPI Data Register

  //Serial.println("OK");
  // add to buffer if room
  if (pos < sizeof buf)
  {
    buf [pos++] = c;

    // example: newline means time to process buffer
    if (c == 'K')
      process_it = true;

  }  // end of room available
}  // end of interrupt routine SPI_STC_vect


void loop() {
  /*String msg = "";
    if (Serial.available() > 0) { // Pobieranie danych z portu szeregowego
    while (Serial.available() > 0) { // pobieraj tak długo aż bufor będzie pusty
      msg += char(Serial.read());
      delay(5);
    }
    if (msg[0] == 'F') {
      setLeds(msg);
    }

    }*/

 

  if (process_it)
  {
    buf [pos] = 0;
    //Serial.println(buf);
    setLeds(String(buf));
    //Serial.println (buf);
    pos = 0;
    process_it = false;

  }  // end of flag se

}

void setLeds(String temp) {
  if (temp[0] == 'F') {
    for (byte i = 1; i < 31; i++) {
      if (i < 16) {
        if (temp[i] == '1') {
          mcp0.digitalWrite(i, 0);
          mcp1.digitalWrite(i, 1);
        }
        else if (temp[i] == '2') {
          mcp0.digitalWrite(i, 1);
          mcp1.digitalWrite(i, 0);
        }
        else {
          mcp0.digitalWrite(i, 0);
          mcp1.digitalWrite(i, 0);
        }
      }
      else {
        if (temp[i] == '1') {
          mcp2.digitalWrite(i - 15, 0);
          mcp3.digitalWrite(i - 15, 1);
        }
        else if (temp[i] == '2') {
          mcp2.digitalWrite(i - 15, 1);
          mcp3.digitalWrite(i - 15, 0);
        }
        else {
          mcp2.digitalWrite(i - 15, 0);
          mcp3.digitalWrite(i - 15, 0);
        }
      }

    }
  }
  else if (temp[0] == 'R') {
    Serial.println(temp);
  }
  else if (temp[0] == 'L') {
    setLedsGame(temp);
  }
}

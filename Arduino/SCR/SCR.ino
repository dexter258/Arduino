#include <ZumoBuzzer.h>
#include <ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>
#define LED 13
 
ZumoBuzzer buzzer;
ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON); 
// zdefiniowanie liczby sensorow odbiciowych w zastosowanej listwie sensorow
#define NUM_SENSORS 6
int speed=200

unsigned int sensor_values[NUM_SENSORS];

/* Utworzenie obiektu 'sensors' zwiazanego z zastosowana listwa z sensorami odbiciowymi
 */
ZumoReflectanceSensorArray sensors;

/* Definicja paramtru zwiazanego ze sposobem dzialania czujnikow odbiciwych - czasu rozladowania
 * kondensatora w obwodzie fototranzystora. Czas rozladowania tego kondensatora jest proporcjonalny
 * do "ilosci" swiatla wyslanego poprzez nadajnik a powracajacego do fototranzystora.
 * Czas rozny w roznych warunkach oswietleniowych.
 * Przy duzym natezeniu swiatla odbitego (jasna - biala barwa podloza), czas rozladowania kondensatora bedzie
 * oscylowal w granicach kilku mikrosekund, natomiast przy braku odbicia (czarna barwa podloza) wzrosnie do kilku milisekund.
 */
#define QTR_THRESHOLD  1500 // microseconds


void setup()
{
   
  digitalWrite(LED, HIGH);

  // Inicjalizacja obslugi komunikacji przez port szeregowy
  Serial.begin(9600);
  
  // Inicjalizacja obslugi listwy z sensorami odbiciowymi 
  sensors.init();  
  
  Serial.println("Zaczynamy zabawe z sensorami czarnej linii");

  button.waitForButton();                        // czekaj na przyciniecie przez urzytkownika przycisku ... 
  
  for(int i = 1; i < 2; i++){                    // ... a pozniej, czekaj jeszcze przez 5 sekund.
	delay(1000);
        buzzer.playNote(NOTE_G(3), 50, 12);	
  }  
  
  digitalWrite(LED, LOW);
}

void loop()
{
  
   int speed_L;
  int speed_P;
  int U=10;
  // Odczytanie stanu poszczegolnych sensorow zamontowanych na listwie
  sensors.read(sensor_values);
  
  if (sensor_values[0] > QTR_THRESHOLD)
  {
    speed_L = speed-U;
    speed_P = speed+U;    
    motors.setSpeeds(speed_L, speed_P);
    delay(2);

  }
  else if (sensor_values[5] > QTR_THRESHOLD)
  {
    speed_L = speed+U;
    speed_P = speed-U;    
    motors.setSpeeds(speed_L, speed_P);
    delay(2);

  }

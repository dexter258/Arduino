#include "components.h"
#define N 4

byte image[N];
byte column;
byte sequence[N];
uint8_t pass = 0;
uint8_t stepInGame = 0;
void initRandomImage() {
  randomSeed(analogRead(A5));
}

void randomImage() {
  column = random(1, 6);
  image[0] = random(1, 7);

  do {
    image[1] = random(1, 7);
  } while ( image[1] == image[0]);

  do {
    image[2] = random(1, 7);
  } while (image[2] == image[0] || image[2] == image[1]);

  do {
    image[3] = random(1, 7);
  } while (image[3] == image[0] || image[3] == image[1] || image[3] == image[2]);


  byte minimum[4] = {10, 10, 10, 10};

  for (byte j = 0; j < 4; j++) {
    for ( byte i = 0; i < 4; i++) {
      if (image[i] < minimum[j] && j == 0 ) {
        sequence[j] = i + 1;
        minimum[j] = image[i];
      }
      else if (image[i] < minimum[j] && image[i] > minimum[j - 1]) {
        minimum[j] = image[i];
        sequence[j] = i + 1;
      }
    }
  }

  //Serial.println(column);
  for (int i = 0; i < N; i++) {
    //Serial.print(String(image[i]) + ", " );

  }
  //Serial.println();
  for (int i = 0; i < N; i++) {
    //Serial.print(String(sequence[i]) + ", " );

  }
  //Serial.println();


}
int whichSquare(int *x, int *y) {

  if (*x > 0 && *x < 240 && *y > 0 && *y < 160)
    return 1;
  else if ( *x >= 240 && *x < 480 && *y > 0 && *y < 160)
    return 2;
  else if ( *x > 0 && *x < 240 && *y >= 160 && *y < 320)
    return 3;
  else if ( *x >= 240 && *x < 480 && *y >= 160 && *y < 320)
    return 4;
  return 0;

}

char * filesName (byte column, byte image) {
  char buf[9];
  String temp = "k" + String(column) + "z" + String(image) + ".bmp";
  temp.toCharArray(buf, 9);
  return buf;
}
void selectCorrect(byte * number, int color) {

  if (*number == 1) drawRectangle(0, 0, 240, 160, color);
  else if (*number == 2) drawRectangle(240, 0, 240, 160, color);
  else if (*number == 3) drawRectangle(0, 160, 240, 160, color);
  else if (*number == 4) drawRectangle(240, 160, 240, 160, color);
}
bool fail;
void selectedSequence(int x, int y) {
  bool correct = false;



  //fail = false;

  //Serial.println("wybor = " + String(whichSquare(&x, &y)));
  if (pass == 0 && stepInGame ==  0 && whichSquare(&x, &y) == sequence[0]) {
    pass = 1;
    correct = true;

    selectCorrect(&sequence[0], GREEN);

  }
  else if (pass == 0 && stepInGame ==  0 && whichSquare(&x, &y) != sequence[0]) {

    fail = true;
  }

  if (pass == 1 && stepInGame == 1 && whichSquare(&x, &y) == sequence[1] ) {
    pass = 2;
    correct = true;
    selectCorrect(&sequence[1], GREEN);
  }
  else if (pass == 1 && stepInGame == 1 && whichSquare(&x, &y) != sequence[1]) {
    pass = 0;
    stepInGame = 0;

    fail = true;
  }

  if (pass == 2 && stepInGame == 2 && whichSquare(&x, &y) == sequence[2] ) {
    pass = 3;
    correct = true;
    selectCorrect(&sequence[2], GREEN);
  }
  else if (pass == 2 && stepInGame == 2 && whichSquare(&x, &y) != sequence[2]) {
    pass = 0;
    stepInGame = 0;

    fail = true;
  }

  if (pass == 3 && stepInGame == 3 && whichSquare(&x, &y) == sequence[3] ) {
    pass = 4;
    correct = true;
    selectCorrect(&sequence[3], GREEN);
  }
  else if (pass == 3 && stepInGame == 3 && whichSquare(&x, &y) != sequence[3]) {
    pass = 0;
    stepInGame = 0;

    fail = true;
  }

  if (fail) {
    drawRectangle(0, 0, 240, 160, RED);
    drawRectangle(240, 0, 240, 160, RED);
    drawRectangle(0, 160, 240, 160, RED);
    drawRectangle(240, 160, 240, 160, RED);
    delay(750);
    drawRectangle(0, 0, 240, 160, WHITE);
    drawRectangle(240, 0, 240, 160, WHITE);
    drawRectangle(0, 160, 240, 160, WHITE);
    drawRectangle(240, 160, 240, 160, WHITE);
  }
  if (correct)
    stepInGame++;
  //Serial.println("Pass = " + String(pass) + " Step = " + String(stepInGame));





}







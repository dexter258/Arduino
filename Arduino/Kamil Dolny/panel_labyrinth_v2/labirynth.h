#include <Wire.h>
#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp, mcp1;

byte randomLab;
byte xR=1, yR=1;
byte error=0;
byte errorPrev = 0;
byte directionLab = 0;
bool flagX = true;
bool flagY = true;
bool change = false;
bool firstLab[17][17] = { {0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                          {0, 1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  1,  1,  0},
                          {0, 1,  0,  1,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  0,  0,  0},
                          {0, 1,  0,  1,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  0,  1,  0},
                          {0, 1,  0,  0,  0,  0,  0,  0,  0,  1,  0,  1,  1,  1,  0,  1,  0},
                          {0, 1,  0,  1,  1,  1,  0,  1,  1,  1,  1,  1,  0,  1,  0,  1,  0},
                          {0, 1,  0,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  1,  0,  1,  0},
                          {0, 1,  0,  1,  1,  1,  1,  1,  1,  1,  0,  1,  0,  1,  0,  1,  0},
                          {0, 1,  0,  1,  1,  1,  1,  1,  1,  1,  0,  1,  0,  0,  0,  1,  0},
                          {0, 1,  1,  1,  0,  0,  0,  1,  1,  1,  0,  1,  1,  1,  1,  1,  0},
                          {0, 1,  1,  1,  0,  1,  0,  0,  0,  1,  0,  1,  0,  0,  0,  1,  0},
                          {0, 1,  1,  1,  0,  1,  0,  1,  1,  1,  1,  1,  0,  1,  1,  1,  0},
                          {0, 1,  1,  1,  0,  1,  0,  1,  0,  0,  0,  0,  0,  0,  0,  1,  0},
                          {0, 1,  1,  1,  0,  1,  0,  1,  0,  1,  1,  1,  0,  1,  1,  1,  0},
                          {0, 1,  1,  1,  0,  1,  0,  1,  0,  1,  1,  1,  0,  1,  1,  1,  0},
                          {0, 1,  1,  1,  1,  1,  0,  1,  1,  1,  1,  1,  0,  1,  1,  1,  0},
                          {0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}};

bool secondLab[17][17] = {{0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                          {0, 1,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  1,  1,  1,  1,  0},
                          {0, 1,  0,  1,  1,  1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  1,  0},
                          {0, 1,  0,  1,  1,  1,  0,  1,  1,  1,  0,  1,  1,  1,  0,  1,  0},
                          {0, 1,  0,  1,  0,  0,  0,  1,  0,  1,  0,  1,  0,  0,  0,  1,  0},
                          {0, 1,  0,  1,  0,  1,  1,  1,  0,  1,  0,  1,  1,  1,  1,  1,  0},
                          {0, 1,  0,  1,  0,  1,  1,  1,  0,  1,  0,  0,  0,  0,  0,  0,  0},
                          {0, 1,  0,  1,  0,  1,  1,  1,  0,  1,  0,  1,  1,  1,  1,  1,  0},
                          {0, 1,  0,  1,  0,  0,  0,  0,  0,  1,  0,  1,  1,  1,  1,  1,  0},
                          {0, 1,  0,  1,  1,  1,  1,  1,  0,  1,  0,  1,  1,  1,  1,  1,  0},
                          {0, 1,  0,  1,  0,  0,  0,  0,  0,  1,  0,  1,  0,  0,  0,  0,  0},
                          {0, 1,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0},
                          {0, 1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  0},
                          {0, 1,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  0,  1,  1,  1,  0},
                          {0, 1,  0,  0,  0,  0,  0,  1,  0,  1,  1,  1,  0,  1,  1,  1,  0},
                          {0, 1,  1,  1,  1,  1,  0,  1,  1,  1,  1,  1,  0,  1,  1,  1,  0},
                          {0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}};
                          
bool thirdLab[17][17] = { {0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                            {0, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0},
                            {0, 1,  1,  1,  1,  1,  0,  1,  0,  1,  0,  0,  0,  0,  0,  1,  0},
                            {0, 1,  1,  1,  1,  1,  0,  1,  0,  1,  0,  1,  1,  1,  0,  1,  0},
                            {0, 0,  0,  0,  0,  0,  0,  1,  0,  1,  0,  1,  1,  1,  0,  1,  0},
                            {0, 1,  1,  1,  1,  1,  1,  1,  0,  1,  0,  1,  1,  1,  0,  1,  0},
                            {0, 1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  1,  0},
                            {0, 1,  0,  1,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  1,  1,  0},
                            {0, 1,  0,  1,  1,  1,  0,  0,  0,  1,  0,  1,  0,  0,  0,  0,  0},
                            {0, 1,  0,  1,  1,  1,  0,  1,  1,  1,  0,  1,  1,  1,  0,  1,  0},
                            {0, 1,  0,  1,  0,  0,  0,  1,  1,  1,  0,  1,  1,  1,  0,  1,  0},
                            {0, 1,  0,  1,  1,  1,  0,  1,  1,  1,  1,  1,  1,  1,  0,  1,  0},
                            {0, 1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0},
                            {0, 1,  0,  1,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0},
                            {0, 1,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                            {0, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0},
                            {0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}};

bool fourthLab[17][17] = {{0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                          {0, 1,  0,  1,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  0,  1,  0},
                          {0, 1,  0,  1,  1,  1,  0,  1,  1,  1,  0,  1,  0,  0,  0,  1,  0},
                          {0, 1,  0,  1,  1,  1,  0,  1,  1,  1,  0,  1,  1,  1,  1,  1,  0},
                          {0, 1,  0,  0,  0,  0,  0,  1,  1,  1,  0,  0,  0,  0,  0,  1,  0},
                          {0, 1,  1,  1,  1,  1,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0},
                          {0, 0,  0,  0,  0,  1,  0,  1,  1,  1,  0,  1,  1,  1,  0,  0,  0},
                          {0, 1,  1,  1,  1,  1,  0,  1,  1,  1,  0,  1,  1,  1,  0,  1,  0},
                          {0, 0,  0,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  1,  0,  1,  0},
                          {0, 1,  0,  1,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  0,  1,  0},
                          {0, 1,  0,  1,  0,  1,  0,  1,  1,  1,  0,  1,  0,  1,  0,  1,  0},
                          {0, 1,  0,  1,  0,  1,  0,  1,  1,  1,  0,  1,  0,  1,  0,  1,  0},
                          {0, 1,  0,  1,  0,  1,  0,  1,  1,  1,  0,  1,  0,  1,  0,  1,  0},
                          {0, 1,  0,  1,  0,  1,  0,  1,  1,  1,  0,  1,  0,  1,  0,  1,  0},
                          {0, 1,  0,  1,  0,  1,  0,  0,  0,  1,  0,  1,  0,  1,  0,  1,  0},
                          {0, 1,  1,  1,  0,  1,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  0},
                          {0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}};

bool fifthLab[17][17] = { {0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                          {0, 1,  1,  1,  1,  1,  0,  1,  1,  1,  0,  1,  1,  1,  0,  1,  0},
                          {0, 1,  1,  1,  1,  1,  0,  1,  0,  0,  0,  1,  0,  1,  0,  1,  0},
                          {0, 1,  1,  1,  1,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0},
                          {0, 1,  0,  0,  0,  0,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0},
                          {0, 1,  1,  1,  1,  1,  0,  1,  0,  1,  0,  1,  0,  1,  1,  1,  0},
                          {0, 1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0},
                          {0, 1,  0,  1,  0,  1,  0,  1,  1,  1,  0,  1,  0,  1,  0,  1,  0},
                          {0, 1,  0,  1,  0,  1,  0,  0,  0,  1,  0,  0,  0,  1,  0,  1,  0},
                          {0, 1,  0,  1,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  1,  0},
                          {0, 0,  0,  1,  0,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  1,  0},
                          {0, 1,  1,  1,  0,  1,  1,  1,  1,  1,  0,  1,  1,  1,  1,  1,  0},
                          {0, 0,  0,  0,  0,  0,  0,  1,  0,  1,  0,  0,  0,  0,  0,  0,  0},
                          {0, 1,  1,  1,  1,  1,  0,  1,  0,  1,  0,  1,  1,  1,  1,  1,  0},
                          {0, 1,  0,  0,  0,  0,  0,  1,  0,  1,  0,  1,  1,  1,  1,  1,  0},
                          {0, 1,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  1,  1,  1,  1,  0},
                          {0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}};

bool sixthLab[17][17] = { {0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                          {0, 1,  1,  1,  1,  1,  0,  1,  1,  1,  0,  1,  1,  1,  1,  1,  0},
                          {0, 1,  0,  1,  1,  1,  0,  1,  1,  1,  0,  1,  0,  1,  0,  1,  0},
                          {0, 1,  0,  1,  1,  1,  0,  1,  1,  1,  0,  1,  0,  1,  0,  1,  0},
                          {0, 1,  0,  1,  0,  0,  0,  1,  0,  1,  0,  1,  0,  0,  0,  1,  0},
                          {0, 1,  0,  1,  1,  1,  1,  1,  0,  1,  0,  1,  0,  1,  1,  1,  0},
                          {0, 1,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  1,  0,  1,  0},
                          {0, 1,  1,  1,  0,  1,  1,  1,  0,  1,  0,  1,  1,  1,  0,  1,  0},
                          {0, 1,  1,  1,  0,  0,  0,  1,  0,  1,  0,  1,  1,  1,  0,  1,  0},
                          {0, 1,  1,  1,  1,  1,  1,  1,  0,  1,  0,  1,  1,  1,  0,  1,  0},
                          {0, 0,  0,  0,  0,  0,  0,  1,  0,  1,  0,  1,  0,  0,  0,  0,  0},
                          {0, 1,  0,  1,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  1,  1,  0},
                          {0, 1,  0,  1,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  1,  0},
                          {0, 1,  0,  1,  1,  1,  1,  1,  0,  1,  0,  1,  1,  1,  0,  1,  0},
                          {0, 1,  0,  1,  1,  1,  1,  1,  0,  1,  0,  1,  1,  1,  0,  1,  0},
                          {0, 1,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  1,  1,  1,  1,  0},
                          {0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}};

 
byte labirynthCombination[6][4] = {{4, 7,   7, 5},
                                   {2, 4,   7, 7},
                                   {1, 2,   8, 7},
                                   {2, 2,   4, 7},
                                   {1, 5,   7, 8},
                                   {2, 7,   6, 1}};


byte currentPosition[2][1] = {{15}, // y
                              {15}}; // x
                              
void changePosition(byte kierunek, bool lab[17][17]){
  
  if(kierunek == 6 && lab[currentPosition[0][0]][currentPosition[1][0] + 1] == 1){
    //Serial.println("Lab = " + String(lab[currentPosition[0][1]][currentPosition[1][1] + 1]));
    currentPosition[1][0] = currentPosition[1][0] + 2;
    xR--;

    
    //Serial.println("Xr = " + String(xR));
  }

  else if(kierunek == 4 && lab[currentPosition[0][0]][currentPosition[1][0] - 1] == 1){
    currentPosition[1][0] = currentPosition[1][0] - 2;
    xR++;

    //Serial.println("Xr = " + String(xR));
  }

  else if(kierunek == 2 && lab[currentPosition[0][0] + 1][currentPosition[1][0]] == 1){
    currentPosition[0][0] = currentPosition[0][0] + 2;
    yR--;

    //Serial.println("Yr = " + String(yR));
  }

  else if(kierunek == 8 && lab[currentPosition[0][0] - 1][currentPosition[1][0]] == 1){
    currentPosition[0][0] = currentPosition[0][0] - 2;
    yR++;

    //Serial.println("Yr = " + String(yR));
  }
  else{
    error++;

    //Serial.println("Error =" + String(error));
  }
}

void randomLabirynth(){
  randomLab = random(0,6);
  
}
void newLab(){
   /* randomLab++;
   if(randomLab > 5){
    randomLab = 0;
   }
*/
   
  //randomLabirynth();
}
void initLabyrinthPanel(){
     mcp.begin(0);      // use default address 0
     mcp1.begin(1);

     randomSeed(analogRead(A0));

    // timer_int.attach(0,2000, newLab);
     
   for(byte i = 0; i< 16; i++){
      mcp1.pinMode(i, OUTPUT);
      mcp1.digitalWrite(i, HIGH);
   }

   for(byte i = 0; i < 4; i++){
      mcp.pinMode(i+4, OUTPUT);
      mcp.pinMode(i+8, OUTPUT);

      mcp.pinMode(i, OUTPUT);
      mcp.pinMode(i+12, OUTPUT);

      mcp.digitalWrite(i+4, LOW);
      mcp.digitalWrite(i+8, LOW);

      mcp.digitalWrite(i, HIGH);
      mcp.digitalWrite(i+12, HIGH);
   }

   pinMode(A1, INPUT);
   pinMode(A2, INPUT);
   
}


void setGreen(byte x, byte y){
  
  byte setX, setY;
  
  
    
    if(x < 5) {
        mcp.digitalWrite(x+7, HIGH);
        setX = x+7;

        
      
    }
    else{
        mcp.digitalWrite(x-1, HIGH);
        setX = x-1;

        
      
    }
    

      if(y < 5){
       
          mcp.digitalWrite(y+11, LOW);
          setY = y+11;
          
      }
      else {
        mcp.digitalWrite(y-5, LOW);
        setY = y-5;
       
      }
;
 mcp.digitalWrite(setX, LOW);
 mcp.digitalWrite(setY, HIGH);
  
}

void setBlue(byte x, byte y){
  
  byte setX, setY;
    if(x < 5) {
        mcp.digitalWrite(x+7, HIGH);
        setX = x+7;
    }
    else{
        mcp.digitalWrite(x-1, HIGH);
        setX = x-1;
    }
    
  mcp1.digitalWrite(16-y, LOW);
  setY = 16-y;

  mcp.digitalWrite(setX, LOW);
  mcp1.digitalWrite(setY, HIGH);
  
}


void setRed(byte x, byte y){
  
  byte setX, setY;
  
  
    
    if(x < 5) {
        mcp.digitalWrite(x+7, HIGH);
        setX = x+7;
    }
    else{
        mcp.digitalWrite(x-1, HIGH);
        setX = x-1;
     }

          mcp1.digitalWrite(y-1, LOW);
          setY = y-1;

 mcp.digitalWrite(setX, LOW);
 mcp1.digitalWrite(setY, HIGH);
  
}

void readJoystick(){
  int y = analogRead(A1);
  int x = analogRead(A2);
  directionLab = 0;
  if(flagX == true && x >= 1022 && flagY == true){
    directionLab = 6;
    flagX = false;
  }
  else if(flagX == true && x <= 1  && flagY == true){
    directionLab = 4;
    flagX = false;
  }

  else if(flagX == true && y <=1 && flagY == true){
    directionLab = 2;
    flagY = false;
    
  }

  else if(flagX == true && y>=1022 && flagY == true){
    directionLab = 8;
    flagY = false;
  }

  if(flagX == false && x <= 600 && x >= 400){
    flagX = true;
  }

  if(flagY == false && y<= 600 && y>= 400){
    flagY = true;
  }
}

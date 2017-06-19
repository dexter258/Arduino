bool pyroButton[7] = {false, false, false, false, false, false, false};
bool pyroButtonFirst[7] = {false, false, false, false, false, false, false};
bool pyroButtonPrev[7] = {false, false, false, false, false, false, false};
bool pyroPass = false;
bool war[6] = {false, false, false, false, false, false};
bool pyr[4] = {false, false, false, false};
extern String mainInfoText[10][7];
extern byte randomMainInfo;
extern bool starGames[9];
extern bool debug;
extern byte status1[15];
extern byte deuterRandom;
bool pyroFirst = true;
bool pyro2First = true;
//Zmienna w której przechowywana jest informacja o tym ile jest aktywnych statusów w STATUSII
extern byte amountActiveStatus2;

//Zmienna w której przechowywana jest informacja o tym ile jest awaryjnych statusów w STATUS II
extern byte amountErrorStatus2;

void readPyroButtons(String info) {



  String temp;
  for (byte i = 0; i < 7; i ++) {
    temp = "";
    temp += info[i + 3];
    //pyroButton[i] = bool(temp.toInt());
    pyroButtonPrev[i] = pyroButtonFirst[i];
    pyroButtonFirst[i] = bool(temp.toInt());
    if (pyroButtonFirst[i] == true &&  pyroButtonPrev[i] == false) {
      pyroButton[i] = bool(temp.toInt());

      if (debug == true) Serial.println("Button Pyro " + String(i) + " = " + String(pyroButton[i]));
    }
    else {
      pyroButton[i] = false;
    }


  }

}
void warunki() {

  if (amountActiveStatus2 > amountErrorStatus2) {
    war[0] = true;
  }
  else war[0] = false;

  if ( (deuterRandom == 0 || deuterRandom == 2 || deuterRandom == 4) && error == 2) {        //sprawdzanie warunków dla drugiego podpunktu
    war[1] = true;
  }
  else war[1] = false;

  if   (startGames[6] == true && mainInfoText[randomMainInfo][4] == "Y") {
    war[2] = true;
  }
  else war[2] = false;


  if (status1[7] == 1 && status1[12] == 1) {
    war[3] = true;
  }
  else war[3] = false;


  if (deuterRandom == 1) {
    war[4] = true;
  }
  else war[4] = false;


  if (deuterRandom == 0 || deuterRandom == 2 || deuterRandom == 3) {
    war[5] = true;
  }
  else  war[5] = false;
}

void pyrotechnicsGame() {

   warunki();

    if (startGames[4] == true && pyroFirst == true) {
      if (pyroButtonFirst[0] == true || pyroButtonFirst[1] == true || pyroButtonFirst[2] == true || pyroButtonFirst[3] == true || pyroButtonFirst[4] == true || pyroButtonFirst[5] == true || pyroButtonFirst[6] == true) {
      for (byte j = 0; j < 6; j ++) {
        war[j] = false;
      }
    
      }
      pyroFirst = false;
    
    }

  if (pyroButton[0] == 1 || pyroButton[1] == 1 || pyroButton[2] == 1 || pyroButton[3] == 1 || pyroButton[4] == 1 || pyroButton[5] == 1 || pyroButton[6] == 1) {

 
    if ( war[0] == true && pyroButtonFirst[0] == true && (pyroButton[0] == true || pyr[0] == true) && pyr[2] == false) { //warunki dla pierwszego podpunktu
      pyr[0] = true;
      if (pyroButtonFirst[5] == true && pyroButton[5] == true) {

        if (pyroButtonFirst[0] == true && pyroButtonFirst[5] == true) {         //sprawdzanie czy przełączniki są włączone
          pyroPass = true;

        }
      }

    }
    else if ( war[0] == true && pyroButtonFirst[5] == true && (pyroButton[5] == true || pyr[2] == true) ) { //warunki dla pierwszego podpunktu
      pyr[2] = true;
      if (pyroButtonFirst[0] == true && pyroButton[0] == true) {

        if (pyroButtonFirst[0] == true && pyroButtonFirst[5] == true) {         //sprawdzanie czy przełączniki są włączone
          pyroPass = true;

        }
      }
    }

    else if ( war[0] == false  && war[1] == true && pyroButtonFirst[1] == true && pyroButtonFirst[1] == true) {  //sprawdzanie przelaczenia dla drugiego podpunktu
      pyroPass = true;

    }

    else if ( war[0] == false  && war[1] == false  &&  war[2] == true  && pyroButtonFirst[2] == true &&  pyroButton[2] == true) {
      pyroPass = true;

    }

    else if ( war[0] == false  && war[1] == false  &&  war[2] == false && war[3] == true &&  pyroButtonFirst[3] == true  && (pyroButton[3] == true || pyr[1] == true) && pyr[3] == false )  {
      pyr[1] = true;
      if (pyroButtonFirst[6] == true && pyroButton[6] == true) {
        if (pyroButtonFirst[3] == true && pyroButtonFirst[6] == true) {
          pyroPass = true;

        }
      }
    }

    else if (war[0] == false  && war[1] == false  &&  war[2] == false && war[3] == true &&  pyroButtonFirst[6] == true  && (pyroButton[6] == true || pyr[3] == true) )  {
      pyr[3] = true;
      if (pyroButtonFirst[3] == true && pyroButton[3] == true) {
        if (pyroButtonFirst[3] == true && pyroButtonFirst[6] == true) {
          pyroPass = true;

        }
      }
    }

    else if ( war[0] == false  && war[1] == false  &&  war[2] == false && war[3] == false && war[4] == true && pyroButtonFirst[2] == true && pyroButton[2] == true) {
      pyroPass = true;
    }

    else if (  war[0] == false  && war[1] == false  &&  war[2] == false && war[3] == false && war[4] == false && war[5] == true && pyroButtonFirst[4] == true && pyroButton[4] == true) {
      pyroPass = true;

    }
    else {
      if ((war[0] == true  ||  war[1] == true|| war[2] == true || war[3] == true || war[4] == true || war[5] == true) || (pyro2First == false))  {
        for (byte i = 0; i < 4; i ++) {
          pyr[i] = false;
        }
        error++;
      }
    }

if  (pyroFirst == false && pyro2First == true){
  pyro2First = false;
}




    if ((pyr[0] == true || pyr[2] == true)  && (pyroButton[1] == true || pyroButton[2] == true || pyroButton[3] == true || pyroButton[4] == true || pyroButton[6] == true)) {

      for (byte i = 0; i < 4; i ++) {
        pyr[i] = false;
      }
      error++;
    }


    if ((pyr[1] == true || pyr[3] == true)  && (pyroButton[0] == true || pyroButton[1] == true || pyroButton[2] == true || pyroButton[4] == true || pyroButton[5] == true)) {

      for (byte i = 0; i < 4; i ++) {
        pyr[i] = false;
      }
      error++;
    }


  }

}





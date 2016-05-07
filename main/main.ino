int btnPowerPins = {6,7,8};     // pins to power rows of buttons
int btnInputPins = {9,10,11};   // pins to revieve input from columns of buttons
int pwrMux[] = {2,3};           // pins to power rows of LEDs
int gndMux[] = {4,5};           // pins to ground columns of LEDs
int nullState = 12;             // pin to write when no leds should be powered

int inputRows = 3;
int inputCols = 3;
int inputGrid[][];

int ledRows = 4;
int ledCols = 4;

void setup() {
  for (int i =0; i < (sizeof(btnInputPins)/sizeof(int)); i++){
    pinMode(btnInputPins[i], INPUT);
  }
  for (int i =0; i < (sizeof(btnPowerPins)/sizeof(int)); i++){
    pinMode(btnPowerPins[i], OUTPUT);
  }
  for (int i =0; i < (sizeof(powerMux)/sizeof(int)); i++){
    pinMode(pwrMux[i], OUTPUT);
  }
  for (int i =0; i < (sizeof(gndMux)/sizeof(int)); i++){
    pinMode(gndMux[i], OUTPUT);
  }
}

void loop() {
  // check inputs
  for (int row = 0; row < inputRows; row++){
    // send power to column
    digitalWrite(btnPowerPins[i], HIGH);

    // write to input grid
    inputGrid[row][0] = digitalRead(btnInputPins[0]);
    inputGrid[row][1] = digitalRead(btnInputPins[1]);
    inputGrid[row][2] = digitalRead(btnInputPins[2]);
  }

  // send outputs
  // loop through rows and columns
  for(int row = 0; row < ledRows; row++){
    for(int col = 0; col < ledCols; col++){
      // turn off all leds
      clearLeds();
      if(row-1 != -1 && col-1 != -1){ // check if the button on the top left of the led exists
        if(inputGrid[row-1][col-1] == HIGH){ // check if that button is pressed
          ledOn(row, col);
        }
      } else if(row-1 != -1 && !(col >= inputCols)) { // check if the button on the top right of the led exists
         if(inputGrid[row-1][col] == HIGH){ // check if that button is pressed
          ledOn(row, col);
        }
      } else if(!(row >= inputRows) && col-1 != -1) { // check if the button on the bottom left of the led exists
         if(inputGrid[row][col-1] == HIGH){ // check if that button is pressed
          ledOn(row, col);
        }
      } else if(!(row >= inputRows) && !(col >= inputCols)) { // check if the button on the bottom right of the led exists
         if(inputGrid[row][col] == HIGH){ // check if that button is pressed
          ledOn(row, col);
        }
      } 
    }
  }
}

void clearLeds(){
  // write LOW to both pwrMux pins
  pwrRow(0);
  // write HIGH to nullState pin so that nothing is getting powered
  digitalWrite(nullState, HIGH);
}

// turn on led
void ledOn(int row, int col){
    pwrRow(row);
    gndCol(col);
}

// write binary form of row to pwrMux pins
void pwrRow(int row){
  // loop through pins
  for (int j = 0; j < (sizeof(pwrMux)/sizeof(int)); j++){
    // check if pin index j has a 1 in the binary number for int row
    if (bitRead(row, j)==1){
      digitalWrite(pwrMux[j], HIGH);
    } else {
      digitalWrite(pwrMux[j], LOW);
    }
  }
}

// write binary form of col to gndMux pins
void gndCol(int col){
    // loop through pins
    for (int j = 0; j < (sizeof(gndMux)/sizeof(int)); j++){
      // check if pin index j has a 1 in the binary number for int row
      if (bitRead(col, j)==1){
        digitalWrite(gndMux[j], HIGH);
      } else {
        digitalWrite(gndMux[j], LOW);
      }
    }
}

int btnPowerPins[] = {8,7,6};     // pins to power rows of buttons
int btnInputPins[] = {9,10,11};   // pins to revieve input from columns of buttons
int pwrMux[] = {2,3};           // pins to power rows of LEDs
int gndMux[] = {4,5};           // pins to ground columns of LEDs
int nullState = 12;             // pin to write when no leds should be powered

int inputRows = 3;
int inputCols = 3;
int inputGrid[3][3]; // make sure bound are the same as preceeding variables

int ledRows = 4;
int ledCols = 4;

bool hasInput = false;

void setup() {
  for (int i =0; i < (sizeof(btnInputPins)/sizeof(int)); i++){
    pinMode(btnInputPins[i], INPUT_PULLUP);
  }
  for (int i =0; i < (sizeof(btnPowerPins)/sizeof(int)); i++){
    pinMode(btnPowerPins[i], OUTPUT);
  }
  for (int i =0; i < (sizeof(pwrMux)/sizeof(int)); i++){
    pinMode(pwrMux[i], OUTPUT);
  }
  for (int i =0; i < (sizeof(gndMux)/sizeof(int)); i++){
    pinMode(gndMux[i], OUTPUT);
  }
  pinMode(nullState, OUTPUT);
}

void loop() {
  // check inputs
  hasInput = false;
  for (int row = 0; row < inputRows; row++){
    // reset power pins
    digitalWrite(btnPowerPins[0], HIGH);
    digitalWrite(btnPowerPins[1], HIGH);
    digitalWrite(btnPowerPins[2], HIGH);
    
    // send power to row
    digitalWrite(btnPowerPins[row], LOW);

    //delay(1);
    
    // write to input grid
    for (int j = (sizeof(btnInputPins)/sizeof(int))-1; j >= 0; j--){
      //row = row + 
      inputGrid[j][row] = digitalRead(btnInputPins[j]);
      if(inputGrid[j][row] == LOW){
        hasInput = true;
      }
    }
  }

  // send outputs
  if(hasInput == true){
    // clear nullState
    digitalWrite(nullState, LOW);
    
    for(int row = 0; row < ledRows; row++){
      for(int col = 0; col < ledCols; col++){
        // turn off all leds
        //clearLeds();
        if(row-1 != -1 && col-1 != -1){ // check if the button on the top left of the led exists
          if(inputGrid[row-1][col-1] == LOW){ // check if that button is pressed
            ledOn(row, col);
          }
        }
        if(row-1 != -1 && !(col >= inputCols)) { // check if the button on the top right of the led exists
           if(inputGrid[row-1][col] == LOW){ // check if that button is pressed
            ledOn(row, col);
          }
        }
        if(!(row >= inputRows) && col-1 != -1) { // check if the button on the bottom left of the led exists
           if(inputGrid[row][col-1] == LOW){ // check if that button is pressed
            ledOn(row, col);
          }
        }
        if(!(row >= inputRows) && !(col >= inputCols)) { // check if the button on the bottom right of the led exists
           if(inputGrid[row][col] == LOW){ // check if that button is pressed
            ledOn(row, col);
          }
        } 
        delay(1);
      }
    }
  } else {
    digitalWrite(nullState, HIGH);  
  }
}

void clearLeds(){
  // write 8 to mux
  digitalWrite(pwrMux[0], HIGH);
  digitalWrite(pwrMux[1], HIGH);
  digitalWrite(nullState, HIGH);
}

// turn on led
void ledOn(int row, int col){
    pwrRow(row);
    gndCol(col);
}

// write binary form of row to pwrMux pins
void pwrRow(int row){
  // convert int to bin on pins
  if(row == 0){
    digitalWrite(pwrMux[0], LOW);
    digitalWrite(pwrMux[1], LOW);
  } else if(row == 1){
    digitalWrite(pwrMux[0], HIGH);
    digitalWrite(pwrMux[1], LOW);
  } else if(row == 2){
    digitalWrite(pwrMux[0], LOW);
    digitalWrite(pwrMux[1], HIGH);
  } else if(row == 3){
    digitalWrite(pwrMux[0], HIGH);
    digitalWrite(pwrMux[1], HIGH);
  }
  // loop through pins
  /*for (int j = 0; j < (sizeof(pwrMux)/sizeof(int)); j++){
    // check if pin index j has a 1 in the binary number for int row
    if (bitRead(row, j)==1){
      digitalWrite(pwrMux[j], HIGH);
    } else {
      digitalWrite(pwrMux[j], LOW);
    }
  }*/
}

// write binary form of col to gndMux pins
void gndCol(int col){
  // convert int to bin on pins
  if(col == 0){
    digitalWrite(gndMux[0], LOW);
    digitalWrite(gndMux[1], LOW);
  } else if(col == 1){
    digitalWrite(gndMux[0], HIGH);
    digitalWrite(gndMux[1], LOW);
  } else if(col == 2){
    digitalWrite(gndMux[0], LOW);
    digitalWrite(gndMux[1], HIGH);
  } else if(col == 3){
    digitalWrite(gndMux[0], HIGH);
    digitalWrite(gndMux[1], HIGH);
  }
  // loop through pins
  /*for (int j = 0; j < (sizeof(gndMux)/sizeof(int)); j++){
    // check if pin index j has a 1 in the binary number for int row
    if (bitRead(col, j)==1){
      digitalWrite(gndMux[j], HIGH);
    } else {
      digitalWrite(gndMux[j], LOW);
    }
  }*/
}

int btnPowerPins = {6,7,8};     // pins to power rows of buttons
int btnInputPins = {9,10,11};   // pins to revieve input from columns of buttons
int powerMux[] = {2,3};         // pins to power rows of LEDs
int gndMux[] = {4,5};           // pins to ground columns of LEDs

int inputRows = 3;
int inputColumns = 3;
int inputGrid[][];

void setup() {
  for (int i =0; i < (sizeof(btnInputPins)/sizeof(int)); i++){
    pinMode(btnInputPins[i], INPUT);
  }
  for (int i =0; i < (sizeof(btnPowerPins)/sizeof(int)); i++){
    pinMode(btnPowerPins[i], OUTPUT);
  }
  for (int i =0; i < (sizeof(powerMux)/sizeof(int)); i++){
    pinMode(powerMux[i], OUTPUT);
  }
  for (int i =0; i < (sizeof(gndMux)/sizeof(int)); i++){
    pinMode(gndMux[i], OUTPUT);
  }
}

void loop() {
  // check inputs
  for (int i = 0; i < inputRows - 1; i++){
    // send power to column
    digitalWrite(btnPowerPins[i], HIGH);

    // write to input grid
    inputGrid[i][0] = digitalRead(btnInputPins[0]);
    inputGrid[i][1] = digitalRead(btnInputPins[1]);
    inputGrid[i][2] = digitalRead(btnInputPins[2]);
  }

  // send outputs
  for (int i =0; i < inputColumns - 1; i++){
    // power column
    // MAKE THIS A FUNCTION
    for (int j = 0; j < (sizeof(powerPins)/sizeof(int)); j++){
      if (bitRead(i, j)==1){
        digitalWrite(powerPins[j], HIGH);
      } else {
        digitalWrite(powerPins[j], LOW);
      }
    }

    // close circuit based on input values
    for (int j = 0; j < inputRows - 1; j++){
      if(inputGrid[i][j] == HIGH){
        // close circuit
        // MAKE THIS A FUNCTION
        for (int j = 0; j < (sizeof(powerPins)/sizeof(int)); j++){
          if (bitRead(i, j)==1){
            digitalWrite(powerPins[j], HIGH);
          } else {
            digitalWrite(powerPins[j], LOW);
          }
        }
      } else {
        // open circuit
      }
    }
  }
}

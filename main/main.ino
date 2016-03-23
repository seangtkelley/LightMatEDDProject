int inputRowPins[] = {1,2,3};
int inputColumnPins[] = {4,5,6};
int powerPins[] = {7,8,9};
int switchPins[] = {10,11,12};

int inputRows = 3;
int inputColumns = 3;
int inputGrid[][];

void setup() {
  for (int i =0; i < (sizeof(inputPins)/sizeof(int)); i++){
    pinMode(inputPins[i], INPUT);
  }
  for (int i =0; i < (sizeof(outputPins)/sizeof(int)); i++){
    pinMode(outputPins[i], OUTPUT);
  }
  for (int i =0; i < (sizeof(powerPins)/sizeof(int)); i++){
    pinMode(powerPins[i], OUTPUT);
  }
}

void loop() {
  // check inputs
  for (int i = 0; i < inputColumns - 1; i++){
    // send power to column
    digitalWrite(inputColumnPins[i], HIGH);

    // write to input grid
    inputGrid[i][0] = digitalRead(inputRowPins[0]);
    inputGrid[i][1] = digitalRead(inputRowPins[1]);
    inputGrid[i][2] = digitalRead(inputRowPins[2]);
  }

  // send outputs
  for (int i =0; i < inputColumns - 1; i++){
    // power column
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
      } else {
        // open circuit
      }
    }
  }
}

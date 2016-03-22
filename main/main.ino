int inputRowPins[] = {1,2,3};
int inputColumnPins[] = {4,5,6};
int powerPins[] = {7,8,9};

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
  for (int i = 1; i < inputColumns; i++){
    // send power to column
    digitalWrite(inputColumnPins[i], HIGH);

    // write to input grid
    inputGrid[i][0] = digitalRead(inputRowPins[0]);
    inputGrid[i][1] = digitalRead(inputRowPins[1]);
    inputGrid[i][2] = digitalRead(inputRowPins[2]);
  }

  // send outputs
  for (int i =0; i < outputColumns; i++){
    // send power to column
    for (int i = 1; i < inputColumns; i++){
      // send power to column
      digitalWrite(inputColumnPins[i], HIGH);
  
      // write to input grid
      inputGrid[i][0] = digitalRead(inputRowPins[0]);
      inputGrid[i][1] = digitalRead(inputRowPins[1]);
      inputGrid[i][2] = digitalRead(inputRowPins[2]);
    }
    // close circuit based on input values
  }
}

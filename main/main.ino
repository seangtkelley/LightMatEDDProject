int inputPins[]  = {1,2,3};
int outputPins[] = {4,5,6};
int powerPins[]  = {7,8,9};

int inputRows = 3;
int inputColumns = 3;
int inputGrid[][];

int outputRows = 3;
int outputColumns = 3;

void setup() {
  for (int i =0; i < (sizeof(inputPins)/sizeof(int)); i++){
    pinMode(inputPins[i], INPUT);
  }
  for (int i =0; i < (sizeof(outputPins)/sizeof(int)); i++){
    pinMode(outputPins[i], OUTPUT);
  }
}

void loop() {
  // check inputs
  for (int i = 1; i < inputColumns; i++){
    // send power to column
    for (int j = 0; j < (sizeof(outputPins)/sizeof(int)); j++){
      if (bitRead(i, j) == 1){
        digitalWrite(outputPins[j], HIGH);
      } else {
        digitalWrite(outputPins[j], LOW);
      }
    }

    // check input ports
    for (int j = 0; j < (sizeof(inputPins)/sizeof(int)); j++){
      inputGrid[i][j] = digitalRead(inputPins[j]);;
    }

    // write to input grid
  }

  // send outputs
  for (int i =0; i < outputColumns; i++){
    // send power to column

    // close circuit based on input values
  }
}

int inputPins[]  = {1,2,3,4};
int outputPins[] = {5,6,7,8};

int inputRows = 3;
int inputColumns = 3;
int inputGrid[][];

int outputRows = 4;
int outputColumns = 4;

void setup() {
  for (int i =0; i < (sizeof(ledPin)/sizeof(int)); i++)
  {
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() {
  // check inputs
  for (int i =0; i < inputColumns; i++)
  {
    // send power to column

    // check input ports

    // write to input grid
  }
  
  // send outputs
  for (int i =0; i < outputColumns; i++)
  {
    // send power to column

    // close circuit based on input values
  }
}

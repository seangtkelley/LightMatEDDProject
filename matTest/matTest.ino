int btnPowerPins[] = {6,7,8};     // pins to power rows of buttons
int btnInputPins[] = {9,10,11};   // pins to revieve input from columns of buttons
int pwrMux[] = {2,3};           // pins to power rows of LEDs
int gndMux[] = {4,5};           // pins to ground columns of LEDs
int nullState = 12;             // pin to write when no leds should be powered

int inputRows = 3;
int inputCols = 3;
int inputGrid[3][3]; // make sure bound are the same as preceeding variables

int ledRows = 4;
int ledCols = 4;

int r, c;

int inputRowCounter = -1;

void setup() {
  for (int i =0; i < (sizeof(btnInputPins)/sizeof(int)); i++){
    pinMode(btnInputPins[i], INPUT);
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

   //Serial.begin(9600);
}

void loop() {
  /*
   * INPUT TESTING
   */
    /*
   for (int row = 0; row < inputRows; row++){
    // reset power pins
    digitalWrite(btnPowerPins[0], LOW);
    digitalWrite(btnPowerPins[1], LOW);
    digitalWrite(btnPowerPins[2], LOW);
    
    // send power to row
    digitalWrite(btnPowerPins[row], HIGH);

    delay(10);

    // write to input grid
    inputGrid[row][0] = digitalRead(btnInputPins[0]);
    inputGrid[row][1] = digitalRead(btnInputPins[1]);
    inputGrid[row][2] = digitalRead(btnInputPins[2]);
  }

  Serial.println("|" + String(inputGrid[0][0]) + " " + String(inputGrid[0][1]) + " " + String(inputGrid[0][2]) + "|");
  Serial.println("|" + String(inputGrid[1][0]) + " " + String(inputGrid[1][1]) + " " + String(inputGrid[1][2]) + "|");
  Serial.println("|" + String(inputGrid[2][0]) + " " + String(inputGrid[2][1]) + " " + String(inputGrid[2][2]) + "|");
  Serial.println();
  while(Serial.available() == 0){}
  Serial.read();*/
  
  /*Serial.println("Row: ");
  while(Serial.available() == 0){}
  inputRowCounter = Serial.read();
  inputRowCounter -= 48;
  Serial.println("Powering row " + String(inputRowCounter));

  // reset power pins
  digitalWrite(btnPowerPins[0], LOW);
  digitalWrite(btnPowerPins[1], LOW);
  digitalWrite(btnPowerPins[2], LOW);

  delay(10);
   
  // send power to row
  digitalWrite(btnPowerPins[inputRowCounter], HIGH);
  
   delay(10);
  
  if(digitalRead(btnInputPins[0]) == HIGH){
    Serial.println("Button pressed (" + String(inputRowCounter) + "," + String(0) + ")");
  }

  if(digitalRead(btnInputPins[1]) == HIGH){
    Serial.println("Button pressed (" + String(inputRowCounter) + "," + String(1) + ")");
  }

  if(digitalRead(btnInputPins[2]) == HIGH){
    Serial.println("Button pressed (" + String(inputRowCounter) + "," + String(2) + ")");
  }*/

  // write to input grid
  /*inputGrid[row][0] = digitalRead(btnInputPins[0]);
  inputGrid[row][1] = digitalRead(btnInputPins[1]);
  inputGrid[row][2] = digitalRead(btnInputPins[2]);*/
  
  /*
   * OUTPUT TESTING
   */
  /*Serial.println("Row: ");
  while(Serial.available() == 0){}
  r = Serial.read();
  Serial.println("Column: ");
  while(Serial.available() == 0){}
  c = Serial.read();
  r -= 48;
  c -= 48;
  Serial.println("Turning on (" + String(r) + "," + String(c) + ")");
  ledOn(r, c);*/
  
  for(int row = 0; row < ledRows; row++){
    for(int col = 0; col < ledCols; col++){
      //clearLeds();    
      ledOn(row, col);
      //Serial.println("Turning on (" + String(row) + "," + String(col) + ")");
      //while(Serial.available() == 0){}
      //Serial.read();
      delay(100);
    }
  }

  /*digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);*/
}

void clearLeds(){
  // write 8 to mux
  digitalWrite(pwrMux[0], HIGH);
  digitalWrite(pwrMux[1], HIGH);
  digitalWrite(nullState, HIGH);
}

// turn on led
void ledOn(int row, int col){
  // turn off nullState
  //digitalWrite(nullState, LOW);
  // turn on row and ground column
  pwrRow(row);
  gndCol(col);
}

// write binary form of row to pwrMux pins
void pwrRow(int row){
  // loop through pins
  /*for (int j = 0; j < (sizeof(pwrMux)/sizeof(int)); j++){
    // check if pin index j has a 1 in the binary number for int row
    if (bitRead(row, j)==1){
      digitalWrite(pwrMux[j], HIGH);
    } else {
      digitalWrite(pwrMux[j], LOW);
    }
  }*/
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
}

// write binary form of col to gndMux pins
void gndCol(int col){
  // loop through pins
  /*for (int j = 0; j < (sizeof(gndMux)/sizeof(int)); j++){
    // check if pin index j has a 1 in the binary number for int row
    if (bitRead(col, j)==1){
      digitalWrite(gndMux[j], HIGH);
    } else {
      digitalWrite(gndMux[j], LOW);
    }
  }*/
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
}

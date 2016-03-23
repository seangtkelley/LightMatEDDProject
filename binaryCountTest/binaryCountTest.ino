int ledPin[] = {2,3};

void setup(){
  for (int i =0; i < (sizeof(ledPin)/sizeof(int)); i++){
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop(){
  for (byte counter =0;counter<=3; counter++){
    displayBinary(counter);
    delay(2000);
  }
}

void displayBinary(byte numToShow){
  for (int i =0; i < (sizeof(ledPin)/sizeof(int)); i++){
    if (bitRead(numToShow, i)==1){
      digitalWrite(ledPin[i], HIGH);
    } else {
      digitalWrite(ledPin[i], LOW);
    }
  }
}

int ledPin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(ledPin == 2){
    digitalWrite(9, LOW);
  } else {
    digitalWrite(ledPin-1, LOW);
  }
  digitalWrite(ledPin, HIGH);
  if(ledPin == 9){
    ledPin = 2;
  } else {
    ledPin += 1;
  }
  delay(1000);
}

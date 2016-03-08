int ledPin[] = {2,3,4};

void setup()
{
  for (int i =0;i<3;i++)
  {
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() 
{
  for (byte counter =0;counter<=7; counter++)
  {
    displayBinary(counter);
    delay(500); 
  }
}

void displayBinary(byte numToShow)
{
  for (int i =0;i<3;i++)
  {
    if (bitRead(numToShow, i)==1)
    {
      digitalWrite(ledPin[i], HIGH); 
    }
    else
    {
      digitalWrite(ledPin[i], LOW); 
    }
  }

}

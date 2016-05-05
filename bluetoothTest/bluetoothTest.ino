#include "SoftwareSerial.h"
#include "C:/Program Files (x86)/Arduino/libraries/PNG-Arduino-Framework-master/Bluetooth/Bluetooth.h"

Bluetooth *blue = new Bluetooth(0, 1);

void setup(){
  Serial.begin(9600);
  blue->setupBluetooth();
}

void loop(){
  String msg = blue->read();
  if(msg.length() > 1){
    Serial.print("Received: ");
    Serial.println(msg);
  }
  if(Serial.available()){
    blue->send("Example message#");
  }
}

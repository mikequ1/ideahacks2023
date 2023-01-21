#include "BluetoothSender.h"
#include <HardwareSerial.h>

BluetoothSender* bs;

HardwareSerial SerialPort(2);

void setup() {
  // put your setup code here, to run once:
  Serial.println("begin");
  SerialPort.begin(9600, SERIAL_8N1, 16, 17);
  //bs = new BluetoothSender();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  char b = SerialPort.read();
  Serial.println(b);
  //bs->BluetoothSenderLoop();
}

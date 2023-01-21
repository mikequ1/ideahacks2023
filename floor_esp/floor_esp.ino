#include "BluetoothSender.h"

BluetoothSender* bs;
void setup() {
  // put your setup code here, to run once:
  bs = new BluetoothSender();
}

void loop() {
  // put your main code here, to run repeatedly:
  bs->BluetoothSenderLoop();
}

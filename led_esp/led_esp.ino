#include "BluetoothReceive.h"

BluetoothReceive* br;

void setup() {
  br = new BluetoothReceive();
}

void loop() {
  // put your main code here, to run repeatedly:
  br->BluetoothReceiveLoop();
}

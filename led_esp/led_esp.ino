#include "BluetoothReceive.h"
#include "LEDController.h"

BluetoothReceive* br;
LEDController* lc;

void setup() {
  br = new BluetoothReceive();
  lc = new LEDController();
  lc->dispColorModes('b');
}

void loop() {
  // put your main code here, to run repeatedly:
  br->BluetoothReceiveLoop();
}

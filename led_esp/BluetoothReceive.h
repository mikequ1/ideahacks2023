#ifndef BT_REC_H
#define BT_REC_H

#include "BluetoothSerial.h"
#include "Arduino.h"
#include "LEDController.h"

const String name = "led";

class BluetoothReceive {
public:
    BluetoothReceive();
    void BluetoothReceiveLoop();
    void BluetoothReceiveString();
private:
    BluetoothSerial SerialBT;
    LEDController* lc;
};

#endif

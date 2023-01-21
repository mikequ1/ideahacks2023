#ifndef BT_REC_H
#define BT_REC_H

#include "BluetoothSerial.h"
#include "Arduino.h"

const String name = "led";

class BluetoothReceive {
public:
    BluetoothReceive();
    void BluetoothReceiveLoop();
private:
    BluetoothSerial SerialBT;
};

#endif
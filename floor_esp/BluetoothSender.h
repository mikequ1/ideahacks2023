#ifndef BTSENDER_H
#define BTSENDER_H

#include "BluetoothSerial.h"
#include "Arduino.h"

const uint8_t address[6] = {0xC0, 0x49, 0xEF, 0xCF, 0x0D, 0x48};
const String name = "led"; //Device name, should be consistent on the bluetooth receiver

class BluetoothSender {
public:
    BluetoothSender();
    void BluetoothSenderLoop();
private:
    BluetoothSerial SerialBT;
    int i = 0;
    bool connected;
};

#endif
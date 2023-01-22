#include "BluetoothReceive.h"

BluetoothReceive::BluetoothReceive() {
    #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
    #error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
    #endif
    Serial.begin(9600);
    SerialBT.begin(name);
    Serial.println("The device started, now you can pair it with bluetooth!");
}

void BluetoothReceive::BluetoothReceiveLoop() {
    if (Serial.available()) {
        SerialBT.write(Serial.read());
    }
    if (SerialBT.available()) {
        Serial.write(SerialBT.read());
    }
    delay(20);
}

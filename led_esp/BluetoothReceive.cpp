#include "BluetoothReceive.h"

BluetoothReceive::BluetoothReceive() {
    #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
    #error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
    #endif
    Serial.begin(9600);
    SerialBT.begin(name);
    Serial.println("The device started, now you can pair it with bluetooth!");
    lc = new LEDController();
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

void BluetoothReceive::BluetoothReceiveString() {
    char buf[128];
    int idx = 0;
    while (SerialBT.available()) {
      char cur_char = SerialBT.read();
      if (cur_char != '\0') {
        buf[idx] = cur_char;
        idx++;
      }
      else {
        buf[idx] = cur_char;
        String cmd(buf);
        lc->stringDecode(cmd);
        lc->printRGB();
        lc->dispRGB(lc->getR(), lc->getG(), lc->getB());
        memset(buf, 0, 128);
        idx = 0;
        delay(20);
      }
      delay(10);
    }
}

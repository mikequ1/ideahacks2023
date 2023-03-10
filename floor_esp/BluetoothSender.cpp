#include "BluetoothSender.h"

BluetoothSender::BluetoothSender(){
    SerialBT.begin("ESP32testm", true); 
    Serial.println("The device started in master mode, make sure remote BT device is on!");
    
    // connect(address) is fast (upto 10 secs max), connect(name) is slow (upto 30 secs max) as it needs
    // to resolve name to address first, but it allows to connect to different devices with the same name.
    // Set CoreDebugLevel to Info to view devices bluetooth address and device names
    connected = SerialBT.connect(name);
    //connected = SerialBT.connect(address);
    
    if(connected) {
        Serial.println("Connected Succesfully!");
    } else {
        while(!SerialBT.connected(10000)) {
        Serial.println("Failed to connect. Make sure remote device is available and in range, then restart app."); 
        }
    }
    // disconnect() may take upto 10 secs max
    if (SerialBT.disconnect()) {
        Serial.println("Disconnected Succesfully!");
    }
    // this would reconnect to the name(will use address, if resolved) or address used with connect(name/address).
    SerialBT.connect();
}

void BluetoothSender::BluetoothSenderLoop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}

void BluetoothSender::BluetoothStringSend(char* cstr) {
  int idx = 0;
  while (cstr[idx] != '\0'){
    SerialBT.write(cstr[idx]);
    ++idx;
  }
  SerialBT.write(cstr[idx]);
  
}

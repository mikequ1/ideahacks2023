#include "BluetoothSender.h"
#include <HardwareSerial.h>

BluetoothSender* bs;

HardwareSerial SerialPort(2);

char buffer[128];
char out[128];
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("begin");

  SerialPort.begin(9600, SERIAL_8N1, 16, 17);
  bs = new BluetoothSender();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (SerialPort.available() > 0) {
    char readch = SerialPort.read();
    if (readch != '\0'){
      buffer[pos] = readch;
      pos++;
    } else {
      buffer[pos] = '\0';
      pos = 0;
      strcpy(out, buffer);
      memset(buffer, 0, 128);
      Serial.println(out);
      while (True){
        bs->BluetoothStringSend(out);
      }
    }
  }
  
}

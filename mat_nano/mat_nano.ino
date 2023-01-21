#define LED_PIN 13
#include <SoftwareSerial.h>

const byte rxPin = 2;
const byte txPin = 1;

SoftwareSerial mySerial (rxPin, txPin);

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  mySerial.write("achyuta");
}

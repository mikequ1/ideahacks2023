#define LED_PIN 13
#include <SoftwareSerial.h>

const byte rxPin = 2;
const byte txPin = 1;


void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial1.write("achyuta");
  Serial1.write('\0');
  delay(200);
  Serial1.write("Yadunandan");
  Serial1.write('\0');
  Serial.println("Achjuta");
  delay(200);
}

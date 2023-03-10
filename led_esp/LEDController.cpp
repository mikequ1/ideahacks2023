#include "LEDController.h"

LEDController::LEDController(){
    strip.begin();
    strip.setBrightness(30); //adjust brightness here
    strip.show(); // Initialize all pixels to 'off'
}

void LEDController::colorWipe(uint32_t c, uint8_t wait) {
    for (uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, c);
        strip.show();
        delay(wait);
    }
}

void LEDController::rainbow(uint8_t wait) {
    uint16_t i, j;

    for(j=0; j<256; j++) {
        for(i=0; i<strip.numPixels(); i++) {
            strip.setPixelColor(i, Wheel((i+j) & 255));
        }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void LEDController::rainbowCycle(uint8_t wait) {
    uint16_t i, j;

    for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
        for(i=0; i< strip.numPixels(); i++) {
            strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
        }
        strip.show();
        delay(wait);
    }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t LEDController::Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

void LEDController::dispColorModes(char md) {
    switch(md) {
        case 'r':
            colorWipe(strip.Color(10, 0, 0, 0), 50);
            break;
        case 'g':
            colorWipe(strip.Color(0, 10, 0, 0), 50);
            break;
        case 'b':
            colorWipe(strip.Color(0, 0, 10, 0), 50);
            break;
        case 'w':
            colorWipe(strip.Color(0, 0, 0, 10), 50);
            break;
    }
}

void LEDController::dispRGB(int r, int g, int b) {
  colorWipe(strip.Color(r, g, b, 0), 10);
}


void LEDController::stringDecode(String command){
  String redDecode = "", greenDecode = "", blueDecode = "";
  int currDecode = 1;
  int lengthString =  command.length();
  for (int i = 0; i < lengthString; i++){
    String currentChar = (String)command[i];
    if (currentChar == ","){
      currDecode++;
    }
    else {
      if (currDecode == 1){
        redDecode = redDecode + currentChar;
      }
      else if (currDecode == 2){
        greenDecode = greenDecode + currentChar;
      }
      else if (currDecode == 3){
        blueDecode = blueDecode + currentChar;
      }
    }
  }
  redDecoded = redDecode.toInt();
  greenDecoded = greenDecode.toInt();
  blueDecoded = blueDecode.toInt();
  /*Serial.print(redDecoded); Serial.print("!");
  Serial.print(greenDecoded); Serial.print("!");
  Serial.println(blueDecoded);*/
}

void LEDController::printRGB(){
  Serial.print(redDecoded);
  Serial.print(", ");
  Serial.print(greenDecoded);
  Serial.print(", ");
  Serial.println(blueDecoded);
}

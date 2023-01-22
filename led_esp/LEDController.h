#ifndef LEDCTRL_H
#define LEDCTRL_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN 5

class LEDController {
public:
    LEDController();
    void colorWipe(uint32_t c, uint8_t wait);
    void rainbow(uint8_t wait);
    void rainbowCycle(uint8_t wait);
    uint32_t Wheel(byte WheelPos);
    void dispColorModes(char md);
    void dispRGB(int r, int g, int b);

    void stringDecode(String command);
    void printRGB();

    int getR() const {
      return redDecoded;
    }
    int getG() const {
      return greenDecoded;
    }
    int getB() const {
      return blueDecoded;
    }
private:
    Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, PIN, NEO_GRBW + NEO_KHZ800);
    int redDecoded;
    int greenDecoded;
    int blueDecoded;
};

#endif

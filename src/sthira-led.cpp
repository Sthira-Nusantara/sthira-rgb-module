#include "sthira-led.h"
#include <Arduino.h>
#include <FastLED.h>

void changeLedColor(CRGB color, int numberOfLed, CRGB leds[])
{
    for (int i = 0; i <= numberOfLed; i++)
    {
        leds[i] = color;
    }
    FastLED.show();
}
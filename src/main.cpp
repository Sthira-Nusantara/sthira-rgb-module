#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <SPI.h>
#include <FastLED.h>
#include "sthira-opening.h"
#include "sthira-wifi.h"
#include "sthira-led.h"

#define NUM_LEDS 1
#define DATA_PIN 0

WiFiClientSecure deviceClient;
WiFiClient espClient;

CRGB leds[NUM_LEDS];

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  printOpening();

  SPI.begin(); // Init SPI bus
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFi.setSleepMode(WIFI_NONE_SLEEP);

  delay(100);
  changeLedColor(CRGB::Red, NUM_LEDS, leds);

  delay(100);
  setup_wifi();

  Serial.println("Setup done");
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (WiFi.status() != WL_CONNECTED)
  {
    setup_wifi();
  }
}

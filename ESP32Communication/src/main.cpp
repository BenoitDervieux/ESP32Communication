#include <Arduino.h>
#include <FastLED.h>
// #include <WiFi.h>
#include "esp_wifi.h"

#include "Network.h"

#define NUM_LEDS 10
#define DATA_PIN_1 23
#define BRIGHTNESS 100

CRGB leds[NUM_LEDS];

void setup() {

    Serial.begin(9600);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }

  FastLED.addLeds<WS2812B, DATA_PIN_1, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();

  Network network(leds);
  network.scanWifi("ESP32", "12345678");
}

void loop() { 
    fill_solid(leds, NUM_LEDS, CRGB::Red);
    FastLED.show();

}

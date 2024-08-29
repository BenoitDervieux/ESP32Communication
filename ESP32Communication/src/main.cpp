#include <Arduino.h>
#include <FastLED.h>
#include <ArduinoJSON.h>

#include "Network.h"

Network network;

void setup() {

    Serial.begin(9600);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }
    network.instantiate();
    network.wifi_init();
}

void loop() { 

    network.run();
}

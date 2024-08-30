#include <Arduino.h>
#include <FastLED.h>
#include <ArduinoJSON.h>

#include "Network.h"
#include <../../variables.h>

Network network;

// Wi-Fi credentials
const char* ssid = SSIDME;
const char* password = PASSME;

void setup() {

    Serial.begin(9600);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi!");
    network.instantiate();
    network.wifi_init();
}

void loop() { 

    network.run();
}

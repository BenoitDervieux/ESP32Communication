#ifndef NETWORK_H
#define NETWORK_H
#include <FastLED.h>
// #include <WiFi.h>
#include <iostream> 
#include <string> // for string class 
using namespace std;
#include <SPI.h>

#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_event_loop.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "nvs_flash.h"

class Network {

    public: 

        Network(CRGB leds[]);
        void scanWifi(string ssid, string password);
        static void test_wifi_scan_all();
        static void wifi_scan(void);
        static esp_err_t event_handler(void *ctx, system_event_t *event);

};

#endif
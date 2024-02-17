#include <Arduino.h>
#include <GL.hpp>
#include <SPIFFS.h>
#include <ESPmDNS.h>
#include <WiFi.h>
#include "core/image_loader.hpp"
#include "core/server.hpp"

// Display settings
#define SHARP_CLK  25
#define SHARP_MOSI 26
#define SHARP_CS   27

#define SHARPMEM_WIDTH 400
#define SHARPMEM_HEIGHT 240

SPIDriver spi(SHARP_CLK, SHARP_MOSI, -1);
GL graphics(SHARP_CS, SHARPMEM_WIDTH, SHARPMEM_HEIGHT);

#ifndef U_SSID
#define U_SSID "TVOJA MT"
#endif

#ifndef U_PASSWORD
#define U_PASSWORD ""
#endif

void setup() {
    Serial.begin(115200);
    delay(2000);
    Serial.printf("Flash size: %i\n", ESP.getFlashChipSize());
    graphics.initGL();

    WiFi.softAP(U_SSID, U_PASSWORD);

    Serial.println(WiFi.status());

    if(!SPIFFS.begin(true)){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }
    Serial.println("SPIFFS mounted");

    if (!MDNS.begin("home")) {   // Set the hostname to "esp32.local"
        Serial.println("Error setting up MDNS responder!");
        while(true) {
            delay(1000);
        }
    }
    Serial.println("mDNS responder started");

    delay(2000);

    init_server();
    init_loader(&graphics);

    Serial.println(WiFi.softAPIP());
    graphics.clearDisplay();

    bool res = load_image("/desk.img");

    if(!res) {
        Serial.println("Failed to load image");
    } else {
        Serial.println("Image loaded");
    }
}

void loop() {
    graphics.refresh();
    server.handleClient();
}
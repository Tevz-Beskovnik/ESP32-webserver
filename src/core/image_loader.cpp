//
// Created by Tevz on 9. 02. 24.
//
#include "core/image_loader.hpp"
#include <GL.hpp>
#include <SPIFFS.h>

GL* gl = nullptr;

void init_loader(GL* gfx){
    gl = gfx;
}

bool load_image(const char *file_path) {
    if (gl == nullptr)
        return false;

    uint8_t* buffer = (uint8_t*)malloc(sizeof(uint8_t) * 12000);
    File file = SPIFFS.open(file_path, "r");

    if(!file) {
        return false;
    }

    while(file.available()) {
        file.read(buffer, 12000);
    }

    Serial.println("Read image");

    delay(2000);

    gl->clearTexture(TEXTURE_BINDING_0);
    gl->loadTexture(buffer, 400, 240, TEXTURE_BINDING_0);
    gl->drawTexture(0, 0, TEXTURE_BINDING_0);

    refresh_top_to_bottom(240);

    return true;
}

void refresh_top_to_bottom(uint16_t height) {
    for(int i = 0; i < height; i++)
    {
        gl->refresh(i);
        delay(50);
    }
}
//
// Created by Tevz on 9. 02. 24.
//

#ifndef BORED_PROGRAMING_IMAGE_LOADER_HPP
#define BORED_PROGRAMING_IMAGE_LOADER_HPP

#include <GL.hpp>

void init_loader(GL* gl);

bool load_image(const char *file_path);

void refresh_top_to_bottom(uint16_t height);

#endif //BORED_PROGRAMING_IMAGE_LOADER_HPP

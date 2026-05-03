#pragma once

#ifndef FONT_ENGINE_H
#define FONT_ENGINE_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct {
    uint64_t address;

} font_engine;

void font_render(uint32_t mode, uint64_t address, uint32_t width,
                 uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);



#endif

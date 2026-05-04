#pragma once

#ifndef FONT_ENGINE_H
#define FONT_ENGINE_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct {
    uint64_t address;
    uint64_t stage_row;
    uint64_t stage_column;

} font_engine;

void font_engine_init(font_engine* font_engine);

void font_selector(font_engine* font_engine, char character, int i);

void font_clear(font_engine* font_engine);

void font_render(uint32_t mode, uint64_t address, font_engine* font_engine, char character, uint32_t width,
                 uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);


#endif

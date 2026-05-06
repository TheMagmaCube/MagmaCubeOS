#pragma once

#ifndef FONT_COMPOSER_H
#define FONT_COMPOSER_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../include/font_engine.h"

typedef struct{
    uint32_t stage_row;
    uint32_t stage_column;

} font_composer;

void font_composer_init(font_composer* font_composer, uint64_t address, uint32_t width, uint32_t height, uint32_t bpp_mode);

void word_render(font_composer* fc, font_engine* fe, uint32_t number_of_args, ...);

#endif

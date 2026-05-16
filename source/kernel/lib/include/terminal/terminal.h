#pragma once

#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/ps2_keyboard_driver/ps2_keyboard_driver.h"
#include "../../include/video/screen_manager.h"
#include "../../include/video/font_composer.h"
#include "../../include//video/font_engine.h"


typedef struct{
    //1920 / 8 = 240 chars per row
    //1080 / 16 = 67.5 columns

    char chars_map[67][240];

    ps2_keyboard_driver ps2_keyboard_driver_instance;

}terminal;

void init_ps2_keyboard_driver_instance(terminal* terminal_instance);

void init_terminal(terminal* terminal_instance);

void sync_data_ps2_keyboard_driver(terminal* terminal_instance);

void sync_font_composer_instance(font_composer* fc, uint8_t row, uint8_t column);

void sync_video(terminal* terminal_instance ,font_composer* fc, font_engine* fe);

void terminal_main_loop(terminal* terminal_instance);

#endif

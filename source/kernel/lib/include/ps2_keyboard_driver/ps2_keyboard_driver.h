#pragma once

#ifndef PS2_KEYBOARD_DRIVER_H
#define PS2_KEYBOARD_DRIVER_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "../video/font_engine.h"
#include "../video/font_composer.h"


typedef struct{
    char Key_pressed;
    char Key_relesed;

} ps2_keyboard_scan_code_set_one;

void char_selector(ps2_keyboard_scan_code_set_one* ps_driver, uint8_t char_code);

void key_check(ps2_keyboard_scan_code_set_one* ps_driver, font_composer* fc, font_engine* fe);


#endif

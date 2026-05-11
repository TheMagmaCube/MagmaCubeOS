#pragma once

#ifndef PS2_KEYBOARD_DRIVER_H
#define PS2_KEYBOARD_DRIVER_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/ps2_keyboard_driver/ps2_keyboard_io.h"
#include "../../include/video/font_engine.h"
#include "../../include/video/font_composer.h"



typedef struct{
    char key_pressed;
    char key_released;
    char control_key_pressed;
    char control_key_released;
    uint8_t code;
    uint8_t status;

} ps2_keyboard_scan_code_set_one;

void char_selector(ps2_keyboard_scan_code_set_one* ps_driver, uint8_t char_code);

void control_key_selector(ps2_keyboard_scan_code_set_one* ps_driver, uint8_t char_code);

void control_key_check(ps2_keyboard_scan_code_set_one* ps_driver, font_composer* fc, font_engine* fe);

void key_check(ps2_keyboard_scan_code_set_one* ps_driver, font_composer* fc, font_engine* fe);

void control_key_managment(ps2_keyboard_scan_code_set_one* ps_driver, font_composer* fc, font_engine* fe);


#endif

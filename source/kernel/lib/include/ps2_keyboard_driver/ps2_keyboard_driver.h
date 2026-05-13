#pragma once

#ifndef PS2_KEYBOARD_DRIVER_H
#define PS2_KEYBOARD_DRIVER_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/ps2_keyboard_driver/ps2_keyboard_io.h"


typedef struct{

    char key_pressed;
    char key_released;

    uint8_t key_code;

    uint8_t left_shift_pressed;

    uint8_t right_shift_pressed;

    uint8_t left_ctrl_pressed;

    uint8_t right_ctrl_pressed;

    uint8_t left_alt_pressed;

    uint8_t right_alt_pressed;

    uint8_t enter_pressed;

    uint8_t backspace_pressed;

    uint16_t port_address;

    uint8_t extended; //0 = false

    //1 = true
    //0 = false

} ps2_keyboard_driver;

void ps2_keyboard_driver_init(ps2_keyboard_driver* ps2_keyboard_driver);

void char_validator(ps2_keyboard_driver* ps2_keyboard_driver, uint8_t key_code);

void char_key_cleaner(ps2_keyboard_driver* ps2_keyboard_driver);

void key_code_cleaner(ps2_keyboard_driver* ps2_keyboard_driver);

void shortcut_key_validator(ps2_keyboard_driver* ps2_keyboard_driver, uint8_t key_code);

void shortcut_key_cleaner(ps2_keyboard_driver* ps2_keyboard_driver);

void main_ps2_keyboard_driver_loop(ps2_keyboard_driver* ps2_keyboard_driver);


#endif

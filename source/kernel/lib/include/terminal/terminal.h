#pragma once

#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/ps2_keyboard_driver/ps2_keyboard_driver.h"


typedef struct{
    //1920 / 8 = 240 chars per row
    //1080 / 16 = 67.5 columns

    char chars_map[67][240];

    ps2_keyboard_driver ps2_keyboard_driver_instance;

}terminal;

void init_ps2_keyboard_driver_instance(terminal* terminal_instance);

void init_terminal(terminal* terminal_instance);

#endif

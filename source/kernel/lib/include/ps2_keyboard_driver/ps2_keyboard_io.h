#pragma once

#ifndef PS2_KEYBOARD_IO_H
#define PS2_KEYBOARD_IO_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

uint8_t load_data_from_register(uint16_t address_of_port);


#endif

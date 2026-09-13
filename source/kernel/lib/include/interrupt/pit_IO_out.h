#pragma once

#ifndef PIT_IO_OUT_H
#define PIT_IO_OUT_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

void pit_IO_out(uint16_t address_of_port, uint8_t value);


#endif

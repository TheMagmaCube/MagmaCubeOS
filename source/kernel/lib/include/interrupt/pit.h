#pragma once

#ifndef PIT_H
#define PIT_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/interrupt/pit_IO_out.h"
#include "../../include/interrupt/pit_IO_in.h"


typedef struct{

    uint16_t channel_zero;
    uint16_t channel_first;
    uint16_t channel_second;
    uint16_t channel_command;
    uint32_t base_value_clock;
    uint8_t target_value_clock;
    uint16_t target_value_clock_valid;

    uint8_t startup_command;

} pit;

void pit_values_init();

void pit_init();

#endif

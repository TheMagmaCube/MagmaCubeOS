#pragma once

#ifndef GDT_H
#define GDT_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/cpu/gdt_load.h"

typedef struct{

    uint16_t limit_low;
    uint16_t base_low;

    uint8_t base_middle;
    uint8_t access;
    uint8_t flags;
    uint8_t base_high;
} __attribute__ ((packed)) gdt;

void gdt_init();

#endif

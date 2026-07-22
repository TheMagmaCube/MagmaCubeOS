#pragma once

#ifndef IDT_H
#define IDT_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct{
    uint16_t offset_low;
    uint16_t selector;

    uint8_t ist;
    uint8_t type_attr;

    uint16_t offset_mid;
    uint32_t offset_high;

    uint32_t zero;

} __attribute__ ((packed)) idt;

#endif

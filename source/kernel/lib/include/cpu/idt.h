#pragma once

#ifndef IDT_H
#define IDT_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/cpu/idt_load.h"
#include "../../include/cpu/interrupts.h"

typedef struct{
    uint16_t offset_low;
    uint16_t selector;

    uint8_t ist;
    uint8_t type_attr;

    uint16_t offset_mid;
    uint32_t offset_high;

    uint32_t zero;

} __attribute__ ((packed)) idt;

void idt_set_irq(int vector, uint64_t handler, idt *idt_instance);

void idt_init();

#endif

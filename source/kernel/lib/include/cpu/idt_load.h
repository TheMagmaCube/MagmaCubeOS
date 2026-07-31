#pragma once

#ifndef IDT_LOAD_H
#define IDT_LOAD_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct{

    uint16_t limit;
    uint64_t base;

} __attribute__ ((packed)) idt_pointer;

void idt_load_pointer_to_cpu(idt_pointer *idt_pointer);

#endif

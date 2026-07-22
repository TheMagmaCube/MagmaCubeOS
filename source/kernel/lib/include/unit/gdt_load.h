#pragma once

#ifndef GDT_LOAD_H
#define GDT_LOAD_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct{

    uint16_t limit;
    uint64_t base;

} __attribute__((packed)) gdt_pointer;

void gdt_load_pointer_to_cpu(gdt_pointer *gdt_pointer);

#endif

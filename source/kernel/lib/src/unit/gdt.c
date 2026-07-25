//Main lib for GDT

//Including libs

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/unit/gdt_load.h"

typedef struct{

    uint16_t limit_low;
    uint16_t base_low;

    uint8_t base_middle;
    uint8_t access;
    uint8_t flags;
    uint8_t base_high;

} gdt;

gdt gdt_table[3];

void gdt_init(){

    gdt_table[0] = (gdt){0};

    gdt_table[1] = (gdt){0};
    gdt_table[1].access = 0x9A;

    gdt_table[1].limit_low = 0xFFFF;
    gdt_table[1].flags = 0xAF;

    gdt_table[2] = (gdt){0};
    gdt_table[2].access = 0x92;

    gdt_table[2].limit_low = 0xFFFF;
    gdt_table[2].flags = 0xAF;

    gdt_pointer gdt_ptr;

    gdt_ptr.base = (uint64_t)&gdt_table;
    gdt_ptr.limit = sizeof(gdt_table)-1;


    gdt_load_pointer_to_cpu(&gdt_ptr);

}

//Main IDT lib

//Including libs

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/unit/idt_load.h"
#include "../../include/unit/interrupts.h"

extern void isr0();

typedef struct{
    uint16_t offset_low;
    uint16_t selector;

    uint8_t ist;
    uint8_t type_attr;

    uint16_t offset_mid;
    uint32_t offset_high;

    uint32_t zero;

} __attribute__ ((packed)) idt;

void idt_set_gate(int vector, uint64_t handler, idt *idt_instance){

    idt_instance[vector].selector = 0x08;
    idt_instance[vector].ist = 0;
    idt_instance[vector].type_attr = 0x8E;
    idt_instance[vector].offset_low = handler & 0xFFFF;
    idt_instance[vector].offset_mid = (handler >> 16) & 0xFFFF;
    idt_instance[vector].offset_high = (handler >> 32);
    idt_instance[vector].zero = 0;
}

idt idt_instance[256];

void idt_init(){

    idt_pointer idt_ptr;

    for(int i = 0; i < 256; i++){
        idt_instance[i] = (idt){0};
    }

    idt_set_gate(0, (uint64_t)isr0, idt_instance);
    idt_set_gate(8, (uint64_t)isr0, idt_instance);
    idt_set_gate(6, (uint64_t)isr0, idt_instance);

    idt_ptr.base = (uint64_t)&idt_instance;
    idt_ptr.limit = sizeof(idt_instance) -1;

    idt_load_pointer_to_cpu(&idt_ptr);

}

//Main IDT lib

//Including libs

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

void idt_set_irq(uint16_t vector, uint64_t handler, idt *idt_instance){

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

    //divide zero
    idt_set_irq(0, (uint64_t)isr0, idt_instance);

    //PIC timer interrupt
    idt_set_irq(32, (uint64_t)isr0, idt_instance);

    idt_ptr.base = (uint64_t)&idt_instance;
    idt_ptr.limit = sizeof(idt_instance) -1;

    idt_load_pointer_to_cpu(&idt_ptr);

}

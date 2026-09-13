#pragma once

#ifndef PIC_H
#define PIC_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/interrupt/pic_IO_out.h"
#include "../../include/interrupt/pic_IO_in.h"

typedef struct{

    //addresses

    uint16_t PIC_Master_Command;
    uint16_t PIC_Master_Data;

    uint16_t PIC_Slave_Command;
    uint16_t PIC_Slave_Data;

    //values

    uint8_t ICW1;
    uint8_t first_irq;
    uint8_t eight_irq;

    uint8_t x86_mode;

} pic;

void pic_values_init();

void pic_init();



#endif

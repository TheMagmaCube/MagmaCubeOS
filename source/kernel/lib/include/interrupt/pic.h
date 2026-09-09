#pragma once

#ifndef PIC_H
#define PIC_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct{

    uint16_t PIC_Master_Command;
    uint16_t PIC_Master_Data;

    uint16_t PIC_Slave_Command;
    uint16_t PIC_Slave_Data;

} pic;

void pic_init(pic *pic_instance);

#endif

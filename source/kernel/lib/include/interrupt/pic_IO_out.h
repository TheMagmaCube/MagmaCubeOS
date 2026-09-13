#pragma once

#ifndef PIC_IO_OUT_H
#define PIC_IO_OUT_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

void pic_IO_out(uint16_t address_of_port, uint8_t value);


#endif

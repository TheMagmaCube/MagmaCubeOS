#pragma once

#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/cpu/EOI_IO_out.h"

void isr0(void);

#endif

//Main lib for PIT

//Including libs
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/interrupt/pit_IO_out.h"
#include "../../include/interrupt/pit_IO_in.h"


typedef struct{

    uint16_t channel_zero;
    uint16_t channel_first;
    uint16_t channel_second;
    uint16_t channel_command;
    uint32_t base_value_clock;
    uint8_t target_value_clock;
    uint16_t target_value_clock_valid;

    uint8_t startup_command;

} pit;

pit pit_instance;

void pit_values_init(){

    pit_instance.channel_zero = 0x40;
    pit_instance.channel_first = 0x41;
    pit_instance.channel_second = 0x42;
    pit_instance.channel_command = 0x43;

    pit_instance.base_value_clock = 1193182;
    pit_instance.target_value_clock = 100;
    pit_instance.target_value_clock_valid = pit_instance.base_value_clock / 100;

    pit_instance.startup_command = 0x36;

}


void pit_init(){

    //Initializing pit

    pit_IO_out(pit_instance.channel_command, pit_instance.startup_command);

    //Sending target_value_clock;

    pit_IO_out(pit_instance.channel_zero, pit_instance.target_value_clock_valid & 0xFF);

    pit_IO_out(pit_instance.channel_zero, (pit_instance.target_value_clock_valid) >> 8 & 0xFF);

}

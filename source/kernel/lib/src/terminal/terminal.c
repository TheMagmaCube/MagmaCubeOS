//Main lib for terminal


//Including libs
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/ps2_keyboard_driver/ps2_keyboard_driver.h"


typedef struct{
    //1920 / 8 = 240 chars per row
    //1080 / 16 = 67.5 columns

    char chars_map[67][240];

    ps2_keyboard_driver ps2_keyboard_driver_instance;

    uint8_t row;
    uint8_t column;

}terminal;


void init_ps2_keyboard_driver_instance(terminal* terminal_instance){

    ps2_keyboard_driver_init(&terminal_instance->ps2_keyboard_driver_instance);

}

void init_terminal(terminal* terminal_instance){

    for(uint8_t i = 0; i < 67; i++){
        for(uint8_t j = 0; j < 240; j++){
            terminal_instance->chars_map[i][j] = '\0';
        }
    }

    init_ps2_keyboard_driver_instance(terminal_instance);

    terminal_instance->row = 0;
    terminal_instance->column = 0;
}

void sync_data_ps2_keyboard_driver(terminal* terminal_instance){

    char temp_char_pressed = '\0';
    char temp_char_released = '\0';

    temp_char_pressed = terminal_instance->ps2_keyboard_driver_instance.key_pressed;
    temp_char_released = terminal_instance->ps2_keyboard_driver_instance.key_released;


    if(temp_char_pressed != '\0'){

        if(temp_char_pressed != temp_char_released){

            terminal_instance->chars_map[terminal_instance->column][terminal_instance->row] = temp_char_pressed;

            terminal_instance->row++;

            if(terminal_instance->row == 240){

                terminal_instance->column++;
            }
        }

    }

}

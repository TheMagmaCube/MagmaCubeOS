//Main lib for terminal


//Including libs
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/ps2_keyboard_driver/ps2_keyboard_driver.h"
#include "../../include/video/screen_manager.h"
#include "../../include/video/font_composer.h"
#include "../../include//video/font_engine.h"


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

void sync_font_composer_instance(font_composer* fc, uint8_t row, uint8_t column){

    fc->row = row;
    fc->column = column;

}

void sync_video(terminal* terminal_instance ,font_composer* fc, font_engine* fe){

    uint8_t row = 0;
    uint8_t column = 0;

    for(uint8_t i = 0; i < 67; i++){

        column = i;
        sync_font_composer_instance(fc, row, column);


        for (uint8_t j = 0; j < 240; j++){

            row = j;
            sync_font_composer_instance(fc, row, column);

            word_render(fc, fe, 1, terminal_instance->chars_map[row][column]);


        }
    }
}

void terminal_main_loop(terminal* terminal_instance, font_composer* fc, font_engine* fe){

    clear_screen(fc->bpp_mode, fc->address, fc->width, fc->height);

    sync_data_ps2_keyboard_driver(terminal_instance);

    uint8_t row = terminal_instance->row;
    uint8_t column = terminal_instance->column;

    sync_video(terminal_instance, fc, fe);

}

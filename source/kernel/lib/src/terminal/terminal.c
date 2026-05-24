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

    uint8_t total_rows;
    uint8_t total_columns;

    ps2_keyboard_driver ps2_keyboard_driver_instance;

    uint8_t row;
    uint8_t column;

}terminal;


void init_ps2_keyboard_driver_instance(terminal* terminal_instance){

    ps2_keyboard_driver_init(&terminal_instance->ps2_keyboard_driver_instance);

}

void init_terminal(terminal* terminal_instance, uint32_t mode, uint64_t address, uint32_t width, uint32_t height){

    terminal_instance->total_rows = 240;
    terminal_instance->total_columns = 67;

    uint8_t temp_total_rows = terminal_instance->total_rows;
    uint8_t temp_total_columns = terminal_instance->total_columns;

    for(uint8_t i = 0; i < temp_total_columns; i++){
        for(uint8_t j = 0; j < temp_total_rows; j++){
            terminal_instance->chars_map[i][j] = ' ';
        }
    }

    init_ps2_keyboard_driver_instance(terminal_instance);

    terminal_instance->row = 0;
    terminal_instance->column = 0;

    clear_screen(mode, address, width, height);

}

void sync_data_ps2_keyboard_driver(terminal* terminal_instance){

    main_ps2_keyboard_driver_loop(&terminal_instance->ps2_keyboard_driver_instance);

    char temp_char_pressed = '\0';
    char temp_char_released = '\0';

    temp_char_pressed = terminal_instance->ps2_keyboard_driver_instance.key_pressed;
    temp_char_released = terminal_instance->ps2_keyboard_driver_instance.key_released;

    uint8_t temp_total_rows = terminal_instance->total_rows;
    uint8_t temp_total_columns = terminal_instance->total_columns;


    if(temp_char_pressed != '\0'){

        if(temp_char_pressed != temp_char_released){

            terminal_instance->chars_map[terminal_instance->column][terminal_instance->row] = temp_char_pressed;

            terminal_instance->row++;

            if(terminal_instance->row == temp_total_rows){

                terminal_instance->column++;

                terminal_instance->row = 0;
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

    uint8_t temp_total_rows = terminal_instance->total_rows;
    uint8_t temp_total_columns = terminal_instance->total_columns;


    for(uint8_t i = 0; i < temp_total_columns; i++){

        column = i;

        for (uint8_t j = 0; j < temp_total_rows; j++){

            row = j;
            sync_font_composer_instance(fc, row, column);

            if(terminal_instance->chars_map[column][row] != '\0'){

                word_render(fc, fe, 1, terminal_instance->chars_map[column][row]);

            }
        }
    }
}

void terminal_main_loop(terminal* terminal_instance, font_composer* fc, font_engine* fe){

    sync_data_ps2_keyboard_driver(terminal_instance);

    sync_video(terminal_instance, fc, fe);


}

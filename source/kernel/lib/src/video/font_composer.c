// Main font_composer lib

// including libs

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>
#include "../../include/video/font_engine.h"
#include "../../include/video/screen_manager.h"
#include "../../../fonts/font.h"


//Define font_composer structure
typedef struct{
    uint32_t row;
    uint32_t column;

    uint64_t address;
    uint32_t width;
    uint32_t height;
    uint32_t bpp_mode; // 1 = rgb, 2 = bgr

} font_composer;

//font_composer_init func need for init all variables that font_composer variable should have definied
void font_composer_init(font_composer* font_composer, uint64_t address, uint32_t width, uint32_t height, uint32_t bpp_mode){
    font_composer->row = 0;
    font_composer->column = 0;
    font_composer->address = address;
    font_composer->width = width;
    font_composer->height = height;
    font_composer->bpp_mode = bpp_mode;
}

//word_render func need for printing words on a screen, func using font_engine
void word_render(font_composer* fc, font_engine* fe, uint32_t number_of_args, ...){
    va_list args;
    va_start(args, number_of_args);

    for(uint32_t i = 0; i < number_of_args; i++){

        char character = va_arg(args, int);

        font_render(fc->bpp_mode, fc->address, fe, character, fc->row, fc->column, fc->width, 0, 255, 0, 0);

        if(character != '\n'){
            fc->row++;
        }
    }
}

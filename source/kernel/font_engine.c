// Main font_render lib

// including libs
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "./fonts/font.h"
#include "framebuffer.c"

typedef struct {
    uint64_t address;

} font_engine;


void font_render(uint32_t mode, uint64_t address, uint32_t width,
                 uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha){

    uint64_t x = 1;
    uint64_t y = 1;

    for(int i = 0; i < 24; i++){
        int body[12];


        for(int j = 0; j < 12; j++){
            body[j] = font_A.body[i][j];


        }

        for(int k = 0; k < 12; k++){

            uint64_t real_x = x * k * 12;
            uint64_t real_y = i;

            if (body[k] == 1){
                put_pixel(mode, address, width, real_x, real_y, 0, 255, 0, 0);
            }
        }
    }
}

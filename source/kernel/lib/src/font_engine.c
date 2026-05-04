// Main font_render lib

// including libs
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../fonts/font.h"
#include "../include/screen_manager.h"

typedef struct {
    int stage_row;
    int stage_column;
    int body[12];

} font_engine;

void font_engine_init(font_engine* font_engine){
    font_engine->stage_row = 0;
    font_engine->stage_column = 0;
}

void font_selector(font_engine* font_engine, char character, int i){

    for(int j = 0; j < 12; j++){

        switch(character){
            case 'A':
                font_engine->body[j] = font_A.body[i][j];
                break;
            case 'B':
                font_engine->body[j] = font_B.body[i][j];
                break;
            case 'C':
                font_engine->body[j] = font_C.body[i][j];
                break;
            case 'D':
                font_engine->body[j] = font_D.body[i][j];
                break;
            case 'E':
                font_engine->body[j] = font_E.body[i][j];
                break;
            case 'F':
                font_engine->body[j] = font_F.body[i][j];
                break;
            case 'G':
                font_engine->body[j] = font_G.body[i][j];
                break;
            case 'H':
                font_engine->body[j] = font_H.body[i][j];
                break;
            case 'I':
                font_engine->body[j] = font_I.body[i][j];
                break;
            case 'J':
                font_engine->body[j] = font_J.body[i][j];
                break;
            case 'K':
                font_engine->body[j] = font_K.body[i][j];
                break;
            case 'L':
                font_engine->body[j] = font_L.body[i][j];
                break;
            case 'M':
                font_engine->body[j] = font_M.body[i][j];
                break;
            case 'N':
                font_engine->body[j] = font_N.body[i][j];
                break;
            case 'O':
                font_engine->body[j] = font_O.body[i][j];
                break;
            case 'P':
                font_engine->body[j] = font_P.body[i][j];
                break;
            case 'Q':
                font_engine->body[j] = font_Q.body[i][j];
                break;
            case 'R':
                font_engine->body[j] = font_R.body[i][j];
                break;
            case 'S':
                font_engine->body[j] = font_S.body[i][j];
                break;
            case 'T':
                font_engine->body[j] = font_T.body[i][j];
                break;
            case 'U':
                font_engine->body[j] = font_U.body[i][j];
                break;
            case 'W':
                font_engine->body[j] = font_W.body[i][j];
                break;
            case 'X':
                font_engine->body[j] = font_X.body[i][j];
                break;
            case 'Y':
                font_engine->body[j] = font_B.body[i][j];
                break;
            case 'Z':
                font_engine->body[j] = font_Z.body[i][j];
                break;
        }
    }
}

void font_clear(font_engine* font_engine){
    for(int i = 0; i < 12; i++){
        font_engine->body[i] = 0;
    }
}


void font_render(uint32_t mode, uint64_t address, font_engine* font_engine, char character, uint32_t width,
                 uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha){

    for(int i = 0; i < 24; i++){

        font_clear(font_engine);
        font_selector(font_engine, character, i);

        for(int k = 0; k < 12; k++){

            uint64_t real_x = k + (font_engine->stage_row * 12);
            uint64_t real_y = i;

            if (font_engine->body[k] == 1){
                put_pixel(mode, address, width, real_x, real_y, 0, 255, 0, 0);
            }
        }
    }
    font_engine->stage_row++;
}

//Main lib for ps2_keyboard_driver


//Including libs
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/ps2_keyboard_driver/ps2_keyboard_io.h"
#include "../../include/video/font_engine.h"
#include "../../include/video/font_composer.h"

typedef struct{
    char key_pressed;
    char key_relesed;

} ps2_keyboard_scan_code_set_one;

void char_selector(ps2_keyboard_scan_code_set_one* ps_driver, uint8_t char_code){

    switch(char_code){
        case 0x1E:
            ps_driver->key_pressed = 'A';
            break;
        case 0x30:
            ps_driver->key_pressed = 'B';
            break;
        case 0x2E:
            ps_driver->key_pressed = 'C';
            break;
        case 0x20:
            ps_driver->key_pressed = 'D';
            break;
        case 0x12:
            ps_driver->key_pressed = 'E';
            break;
        case 0x21:
            ps_driver->key_pressed = 'F';
            break;
        case 0x22:
            ps_driver->key_pressed = 'G';
            break;
        case 0x23:
            ps_driver->key_pressed = 'H';
            break;
        case 0x17:
            ps_driver->key_pressed = 'I';
            break;
        case 0x24:
            ps_driver->key_pressed = 'J';
            break;
        case 0x25:
            ps_driver->key_pressed = 'K';
            break;
        case 0x26:
            ps_driver->key_pressed = 'L';
            break;
        case 0x32:
            ps_driver->key_pressed = 'M';
            break;
        case 0x31:
            ps_driver->key_pressed = 'N';
            break;
        case 0x18:
            ps_driver->key_pressed = 'O';
            break;
        case 0x19:
            ps_driver->key_pressed = 'P';
            break;
        case 0x10:
            ps_driver->key_pressed = 'Q';
            break;
        case 0x13:
            ps_driver->key_pressed = 'R';
            break;
        case 0x1F:
            ps_driver->key_pressed = 'S';
            break;
        case 0x14:
            ps_driver->key_pressed = 'T';
            break;
        case 0x16:
            ps_driver->key_pressed = 'U';
            break;
        case 0x2F:
            ps_driver->key_pressed = 'V';
            break;
        case 0x11:
            ps_driver->key_pressed = 'W';
            break;
        case 0x2D:
            ps_driver->key_pressed = 'X';
            break;
        case 0x15:
            ps_driver->key_pressed = 'Y';
            break;
        case 0x2C:
            ps_driver->key_pressed = 'Z';
            break;
        case 0x39:
            ps_driver->key_pressed = ' ';
        case 0x1E + 0x80:
            ps_driver->key_relesed = 'A';
            break;
        case 0x30 + 0x80:
            ps_driver->key_relesed = 'B';
            break;
        case 0x2E + 0x80:
            ps_driver->key_relesed = 'C';
            break;
        case 0x20 + 0x80:
            ps_driver->key_relesed = 'D';
            break;
        case 0x12 + 0x80:
            ps_driver->key_relesed = 'E';
            break;
        case 0x21 + 0x80:
            ps_driver->key_relesed = 'F';
            break;
        case 0x22 + 0x80:
            ps_driver->key_relesed = 'G';
            break;
        case 0x23 + 0x80:
            ps_driver->key_relesed = 'H';
            break;
        case 0x17 + 0x80:
            ps_driver->key_relesed = 'I';
            break;
        case 0x24 + 0x80:
            ps_driver->key_relesed = 'J';
            break;
        case 0x25 + 0x80:
            ps_driver->key_relesed = 'K';
            break;
        case 0x26 + 0x80:
            ps_driver->key_relesed = 'L';
            break;
        case 0x32 + 0x80:
            ps_driver->key_relesed = 'M';
            break;
        case 0x31 + 0x80:
            ps_driver->key_relesed = 'N';
            break;
        case 0x18 + 0x80:
            ps_driver->key_relesed = 'O';
            break;
        case 0x19 + 0x80:
            ps_driver->key_relesed = 'P';
            break;
        case 0x10 + 0x80:
            ps_driver->key_relesed = 'Q';
            break;
        case 0x13 + 0x80:
            ps_driver->key_relesed = 'R';
            break;
        case 0x1F + 0x80:
            ps_driver->key_relesed = 'S';
            break;
        case 0x14 + 0x80:
            ps_driver->key_relesed = 'T';
            break;
        case 0x16 + 0x80:
            ps_driver->key_relesed = 'U';
            break;
        case 0x2F + 0x80:
            ps_driver->key_relesed = 'V';
            break;
        case 0x11 + 0x80:
            ps_driver->key_relesed = 'W';
            break;
        case 0x2D + 0x80:
            ps_driver->key_relesed = 'X';
            break;
        case 0x15 + 0x80:
            ps_driver->key_relesed = 'Y';
            break;
        case 0x2C + 0x80:
            ps_driver->key_relesed = 'Z';
            break;
        case 0xB9:
            ps_driver->key_pressed = ' ';
    }
}

void key_check(ps2_keyboard_scan_code_set_one* ps_driver, font_composer* fc, font_engine* fe){
    uint8_t code = load_data_from_register(0x60);

    char_selector(ps_driver, code);

    uint32_t number_of_args = 1;

    if(ps_driver->key_pressed != ps_driver->key_relesed){
        word_render(fc, fe, number_of_args, ps_driver->key_pressed);
    }

    ps_driver->key_pressed = '+';
    ps_driver->key_relesed = '+';

    for(uint32_t i = 0; i < 7999999 * 7; i++){

    }

}

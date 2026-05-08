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
    char control_key_pressed;
    char control_key_relesed;

} ps2_keyboard_scan_code_set_one;

//Q = left shift
//W = right shift
//A = left ctrl
//S = right ctrl
//E = enter
//B = backspace
//for control key

void char_selector(ps2_keyboard_scan_code_set_one* ps_driver, uint8_t char_code){

    switch(char_code){
        case 0x1E:
            ps_driver->key_pressed = 'a';
            break;
        case 0x30:
            ps_driver->key_pressed = 'b';
            break;
        case 0x2E:
            ps_driver->key_pressed = 'c';
            break;
        case 0x20:
            ps_driver->key_pressed = 'd';
            break;
        case 0x12:
            ps_driver->key_pressed = 'e';
            break;
        case 0x21:
            ps_driver->key_pressed = 'f';
            break;
        case 0x22:
            ps_driver->key_pressed = 'g';
            break;
        case 0x23:
            ps_driver->key_pressed = 'h';
            break;
        case 0x17:
            ps_driver->key_pressed = 'i';
            break;
        case 0x24:
            ps_driver->key_pressed = 'j';
            break;
        case 0x25:
            ps_driver->key_pressed = 'k';
            break;
        case 0x26:
            ps_driver->key_pressed = 'l';
            break;
        case 0x32:
            ps_driver->key_pressed = 'm';
            break;
        case 0x31:
            ps_driver->key_pressed = 'n';
            break;
        case 0x18:
            ps_driver->key_pressed = 'o';
            break;
        case 0x19:
            ps_driver->key_pressed = 'p';
            break;
        case 0x10:
            ps_driver->key_pressed = 'q';
            break;
        case 0x13:
            ps_driver->key_pressed = 'r';
            break;
        case 0x1F:
            ps_driver->key_pressed = 's';
            break;
        case 0x14:
            ps_driver->key_pressed = 't';
            break;
        case 0x16:
            ps_driver->key_pressed = 'u';
            break;
        case 0x2F:
            ps_driver->key_pressed = 'v';
            break;
        case 0x11:
            ps_driver->key_pressed = 'w';
            break;
        case 0x2D:
            ps_driver->key_pressed = 'x';
            break;
        case 0x15:
            ps_driver->key_pressed = 'y';
            break;
        case 0x2C:
            ps_driver->key_pressed = 'z';
            break;
        case 0x39:
            ps_driver->key_pressed = ' ';
            break;
        case 0x02:
            ps_driver->key_pressed = '1';
            break;
        case 0x03:
            ps_driver->key_pressed = '2';
            break;
        case 0x04:
            ps_driver->key_pressed = '3';
            break;
        case 0x05:
            ps_driver->key_pressed = '4';
            break;
        case 0x06:
            ps_driver->key_pressed = '5';
            break;
        case 0x07:
            ps_driver->key_pressed = '6';
            break;
        case 0x08:
            ps_driver->key_pressed = '7';
            break;
        case 0x09:
            ps_driver->key_pressed = '8';
            break;
        case 0x0A:
            ps_driver->key_pressed = '9';
            break;
        case 0x0B:
            ps_driver->key_pressed = '0';
            break;
        case 0x2A:
            ps_driver->control_key_pressed = 'Q';
            break;
        case 0x36:
            ps_driver->control_key_pressed = 'W';
            break;
        case 0x1C:
            ps_driver->control_key_pressed = 'E';
            break;
        case 0x0E:
            ps_driver->control_key_pressed = 'B';
            break;
        case 0x1D:
            ps_driver->control_key_pressed = 'A';
            break;
        case 0xE0:
            ps_driver->control_key_pressed = 'S';
            break;
        case 0x0C:
            ps_driver->key_pressed = '-';
            break;
        case 0x0D:
            ps_driver->key_pressed = '=';
            break;
        case 0x1A:
            ps_driver->key_pressed = '[';
            break;
        case 0x1B:
            ps_driver->key_pressed = ']';
            break;
        case 0x27:
            ps_driver->key_pressed = ';';
            break;
        case 0x28:
            ps_driver->key_pressed = '\'';
            break;
        case 0x29:
            ps_driver->key_pressed = '`';
            break;
        case 0x2B:
            ps_driver->key_pressed = '\\';
            break;
        case 0x33:
            ps_driver->key_pressed = ',';
            break;
        case 0x34:
            ps_driver->key_pressed = '.';
            break;
        case 0x35:
            ps_driver->key_pressed = '/';
            break;


        case 0x1E + 0x80:
            ps_driver->key_relesed = 'a';
            break;
        case 0x30 + 0x80:
            ps_driver->key_relesed = 'b';
            break;
        case 0x2E + 0x80:
            ps_driver->key_relesed = 'c';
            break;
        case 0x20 + 0x80:
            ps_driver->key_relesed = 'd';
            break;
        case 0x12 + 0x80:
            ps_driver->key_relesed = 'e';
            break;
        case 0x21 + 0x80:
            ps_driver->key_relesed = 'f';
            break;
        case 0x22 + 0x80:
            ps_driver->key_relesed = 'g';
            break;
        case 0x23 + 0x80:
            ps_driver->key_relesed = 'h';
            break;
        case 0x17 + 0x80:
            ps_driver->key_relesed = 'i';
            break;
        case 0x24 + 0x80:
            ps_driver->key_relesed = 'j';
            break;
        case 0x25 + 0x80:
            ps_driver->key_relesed = 'k';
            break;
        case 0x26 + 0x80:
            ps_driver->key_relesed = 'l';
            break;
        case 0x32 + 0x80:
            ps_driver->key_relesed = 'm';
            break;
        case 0x31 + 0x80:
            ps_driver->key_relesed = 'n';
            break;
        case 0x18 + 0x80:
            ps_driver->key_relesed = 'o';
            break;
        case 0x19 + 0x80:
            ps_driver->key_relesed = 'p';
            break;
        case 0x10 + 0x80:
            ps_driver->key_relesed = 'q';
            break;
        case 0x13 + 0x80:
            ps_driver->key_relesed = 'r';
            break;
        case 0x1F + 0x80:
            ps_driver->key_relesed = 's';
            break;
        case 0x14 + 0x80:
            ps_driver->key_relesed = 't';
            break;
        case 0x16 + 0x80:
            ps_driver->key_relesed = 'u';
            break;
        case 0x2F + 0x80:
            ps_driver->key_relesed = 'v';
            break;
        case 0x11 + 0x80:
            ps_driver->key_relesed = 'w';
            break;
        case 0x2D + 0x80:
            ps_driver->key_relesed = 'x';
            break;
        case 0x15 + 0x80:
            ps_driver->key_relesed = 'y';
            break;
        case 0x2C + 0x80:
            ps_driver->key_relesed = 'z';
            break;
        case 0x39 + 0x80:
            ps_driver->key_relesed = ' ';
            break;
        case 0x02 + 0x80:
            ps_driver->key_relesed = '1';
            break;
        case 0x03 + 0x80:
            ps_driver->key_relesed = '2';
            break;
        case 0x04 + 0x80:
            ps_driver->key_relesed = '3';
            break;
        case 0x05 + 0x80:
            ps_driver->key_relesed = '4';
            break;
        case 0x06 + 0x80:
            ps_driver->key_relesed = '5';
            break;
        case 0x07 + 0x80:
            ps_driver->key_relesed = '6';
            break;
        case 0x08 + 0x80:
            ps_driver->key_relesed = '7';
            break;
        case 0x09 + 0x80:
            ps_driver->key_relesed = '8';
            break;
        case 0x0A + 0x80:
            ps_driver->key_relesed = '9';
            break;
        case 0x0B + 0x80:
            ps_driver->key_relesed = '0';
            break;
        case 0x2A + 0x80:
            ps_driver->control_key_pressed = 'Q';
            break;
        case 0x36 + 0x80:
            ps_driver->control_key_pressed = 'W';
            break;
        case 0x1C + 0x80:
            ps_driver->control_key_pressed = 'E';
            break;
        case 0x0E + 0x80:
            ps_driver->control_key_pressed = 'B';
            break;
        case 0x1D + 0x80:
            ps_driver->control_key_pressed = 'A';
            break;
        case 0xE0 + 0x80:
            ps_driver->control_key_pressed = 'S';
            break;
        case 0x0C + 0x80:
            ps_driver->key_pressed = '-';
            break;
        case 0x0D + 0x80:
            ps_driver->key_pressed = '=';
            break;
        case 0x1A + 0x80:
            ps_driver->key_pressed = '[';
            break;
        case 0x1B + 0x80:
            ps_driver->key_pressed = ']';
            break;
        case 0x27 + 0x80:
            ps_driver->key_pressed = ';';
            break;
        case 0x28 + 0x80:
            ps_driver->key_pressed = '\'';
            break;
        case 0x29 + 0x80:
            ps_driver->key_pressed = '`';
            break;
        case 0x2B + 0x80:
            ps_driver->key_pressed = '\\';
            break;
        case 0x33 + 0x80:
            ps_driver->key_pressed = ',';
            break;
        case 0x34 + 0x80:
            ps_driver->key_pressed = '.';
            break;
        case 0x35 + 0x80:
            ps_driver->key_pressed = '/';
            break;

    }
}

void key_check(ps2_keyboard_scan_code_set_one* ps_driver, font_composer* fc, font_engine* fe){
    uint8_t code = load_data_from_register(0x60);

    char_selector(ps_driver, code);

    uint32_t number_of_args = 1;

    if(ps_driver->key_pressed != ps_driver->key_relesed){
        word_render(fc, fe, number_of_args, ps_driver->key_pressed);
    }

    ps_driver->control_key_pressed = 'W';
    ps_driver->control_key_relesed = 'W';

    ps_driver->key_pressed = '`';
    ps_driver->key_relesed = '`';

    for(uint32_t i = 0; i < 7999999 * 7; i++){

    }

}

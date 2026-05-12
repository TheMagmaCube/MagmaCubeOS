//Main lib for ps2_keyboard_driver


//Including libs
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/ps2_keyboard_driver/ps2_keyboard_io.h"

typedef struct{

    char key_pressed;
    char key_released;

    uint8_t key_code;

    uint8_t left_shift_pressed;
    uint8_t left_shift_released;
    uint8_t right_shift_pressed;
    uint8_t right_shift_released;
    uint8_t left_ctrl_pressed;
    uint8_t left_ctrl_released;
    uint8_t enter_pressed;
    uint8_t enter_released;
    uint8_t backspace_pressed;
    uint8_t backspace_released;

    //1 = true
    //0 = false

} ps2_keyboard_driver;


void ps2_keyboard_driver_init(ps2_keyboard_driver* ps2_keyboard_driver){

    ps2_keyboard_driver->key_pressed = '\0';
    ps2_keyboard_driver->key_released = '\0';

    ps2_keyboard_driver->key_code = '\0';

    ps2_keyboard_driver->left_shift_pressed = 0;
    ps2_keyboard_driver->left_shift_released = 0;
    ps2_keyboard_driver->right_shift_pressed = 0;
    ps2_keyboard_driver->right_shift_released = 0;
    ps2_keyboard_driver->left_ctrl_pressed = 0;
    ps2_keyboard_driver->left_ctrl_released = 0;
    ps2_keyboard_driver->enter_pressed = 0;
    ps2_keyboard_driver->enter_released = 0;
    ps2_keyboard_driver->backspace_pressed = 0;
    ps2_keyboard_driver->backspace_released = 0;

}


void char_validator(ps2_keyboard_driver* ps2_keyboard_driver, uint8_t key_code){

    switch(key_code){
        case 0x1E:
            ps2_keyboard_driver->key_pressed = 'a';
            break;
        case 0x30:
            ps2_keyboard_driver->key_pressed = 'b';
            break;
        case 0x2E:
            ps2_keyboard_driver->key_pressed = 'c';
            break;
        case 0x20:
            ps2_keyboard_driver->key_pressed = 'd';
            break;
        case 0x12:
            ps2_keyboard_driver->key_pressed = 'e';
            break;
        case 0x21:
            ps2_keyboard_driver->key_pressed = 'f';
            break;
        case 0x22:
            ps2_keyboard_driver->key_pressed = 'g';
            break;
        case 0x23:
            ps2_keyboard_driver->key_pressed = 'h';
            break;
        case 0x17:
            ps2_keyboard_driver->key_pressed = 'i';
            break;
        case 0x24:
            ps2_keyboard_driver->key_pressed = 'j';
            break;
        case 0x25:
            ps2_keyboard_driver->key_pressed = 'k';
            break;
        case 0x26:
            ps2_keyboard_driver->key_pressed = 'l';
            break;
        case 0x32:
            ps2_keyboard_driver->key_pressed = 'm';
            break;
        case 0x31:
            ps2_keyboard_driver->key_pressed = 'n';
            break;
        case 0x18:
            ps2_keyboard_driver->key_pressed = 'o';
            break;
        case 0x19:
            ps2_keyboard_driver->key_pressed = 'p';
            break;
        case 0x10:
            ps2_keyboard_driver->key_pressed = 'q';
            break;
        case 0x13:
            ps2_keyboard_driver->key_pressed = 'r';
            break;
        case 0x1F:
            ps2_keyboard_driver->key_pressed = 's';
            break;
        case 0x14:
            ps2_keyboard_driver->key_pressed = 't';
            break;
        case 0x16:
            ps2_keyboard_driver->key_pressed = 'u';
            break;
        case 0x2F:
            ps2_keyboard_driver->key_pressed = 'v';
            break;
        case 0x11:
            ps2_keyboard_driver->key_pressed = 'w';
            break;
        case 0x2D:
            ps2_keyboard_driver->key_pressed = 'x';
            break;
        case 0x15:
            ps2_keyboard_driver->key_pressed = 'y';
            break;
        case 0x2C:
            ps2_keyboard_driver->key_pressed = 'z';
            break;
        case 0x39:
            ps2_keyboard_driver->key_pressed = ' ';
            break;
        case 0x02:
            ps2_keyboard_driver->key_pressed = '1';
            break;
        case 0x03:
            ps2_keyboard_driver->key_pressed = '2';
            break;
        case 0x04:
            ps2_keyboard_driver->key_pressed = '3';
            break;
        case 0x05:
            ps2_keyboard_driver->key_pressed = '4';
            break;
        case 0x06:
            ps2_keyboard_driver->key_pressed = '5';
            break;
        case 0x07:
            ps2_keyboard_driver->key_pressed = '6';
            break;
        case 0x08:
            ps2_keyboard_driver->key_pressed = '7';
            break;
        case 0x09:
            ps2_keyboard_driver->key_pressed = '8';
            break;
        case 0x0A:
            ps2_keyboard_driver->key_pressed = '9';
            break;
        case 0x0B:
            ps2_keyboard_driver->key_pressed = '0';
            break;
        case 0x0C:
            ps2_keyboard_driver->key_pressed = '-';
            break;
        case 0x0D:
            ps2_keyboard_driver->key_pressed = '=';
            break;
        case 0x1A:
            ps2_keyboard_driver->key_pressed = '[';
            break;
        case 0x1B:
            ps2_keyboard_driver->key_pressed = ']';
            break;
        case 0x27:
            ps2_keyboard_driver->key_pressed = ';';
            break;
        case 0x28:
            ps2_keyboard_driver->key_pressed = '\'';
            break;
        case 0x29:
            ps2_keyboard_driver->key_pressed = '`';
            break;
        case 0x2B:
            ps2_keyboard_driver->key_pressed = '\\';
            break;
        case 0x33:
            ps2_keyboard_driver->key_pressed = ',';
            break;
        case 0x34:
            ps2_keyboard_driver->key_pressed = '.';
            break;
        case 0x35:
            ps2_keyboard_driver->key_pressed = '/';
            break;


        case 0x1E + 0x80:
            ps2_keyboard_driver->key_released = 'a';
            break;
        case 0x30 + 0x80:
            ps2_keyboard_driver->key_released = 'b';
            break;
        case 0x2E + 0x80:
            ps2_keyboard_driver->key_released = 'c';
            break;
        case 0x20 + 0x80:
            ps2_keyboard_driver->key_released = 'd';
            break;
        case 0x12 + 0x80:
            ps2_keyboard_driver->key_released = 'e';
            break;
        case 0x21 + 0x80:
            ps2_keyboard_driver->key_released = 'f';
            break;
        case 0x22 + 0x80:
            ps2_keyboard_driver->key_released = 'g';
            break;
        case 0x23 + 0x80:
            ps2_keyboard_driver->key_released = 'h';
            break;
        case 0x17 + 0x80:
            ps2_keyboard_driver->key_released = 'i';
            break;
        case 0x24 + 0x80:
            ps2_keyboard_driver->key_released = 'j';
            break;
        case 0x25 + 0x80:
            ps2_keyboard_driver->key_released = 'k';
            break;
        case 0x26 + 0x80:
            ps2_keyboard_driver->key_released = 'l';
            break;
        case 0x32 + 0x80:
            ps2_keyboard_driver->key_released = 'm';
            break;
        case 0x31 + 0x80:
            ps2_keyboard_driver->key_released = 'n';
            break;
        case 0x18 + 0x80:
            ps2_keyboard_driver->key_released = 'o';
            break;
        case 0x19 + 0x80:
            ps2_keyboard_driver->key_released = 'p';
            break;
        case 0x10 + 0x80:
            ps2_keyboard_driver->key_released = 'q';
            break;
        case 0x13 + 0x80:
            ps2_keyboard_driver->key_released = 'r';
            break;
        case 0x1F + 0x80:
            ps2_keyboard_driver->key_released = 's';
            break;
        case 0x14 + 0x80:
            ps2_keyboard_driver->key_released = 't';
            break;
        case 0x16 + 0x80:
            ps2_keyboard_driver->key_released = 'u';
            break;
        case 0x2F + 0x80:
            ps2_keyboard_driver->key_released = 'v';
            break;
        case 0x11 + 0x80:
            ps2_keyboard_driver->key_released = 'w';
            break;
        case 0x2D + 0x80:
            ps2_keyboard_driver->key_released = 'x';
            break;
        case 0x15 + 0x80:
            ps2_keyboard_driver->key_released = 'y';
            break;
        case 0x2C + 0x80:
            ps2_keyboard_driver->key_released = 'z';
            break;
        case 0x39 + 0x80:
            ps2_keyboard_driver->key_released = ' ';
            break;
        case 0x02 + 0x80:
            ps2_keyboard_driver->key_released = '1';
            break;
        case 0x03 + 0x80:
            ps2_keyboard_driver->key_released = '2';
            break;
        case 0x04 + 0x80:
            ps2_keyboard_driver->key_released = '3';
            break;
        case 0x05 + 0x80:
            ps2_keyboard_driver->key_released = '4';
            break;
        case 0x06 + 0x80:
            ps2_keyboard_driver->key_released = '5';
            break;
        case 0x07 + 0x80:
            ps2_keyboard_driver->key_released = '6';
            break;
        case 0x08 + 0x80:
            ps2_keyboard_driver->key_released = '7';
            break;
        case 0x09 + 0x80:
            ps2_keyboard_driver->key_released = '8';
            break;
        case 0x0A + 0x80:
            ps2_keyboard_driver->key_released = '9';
            break;
        case 0x0B + 0x80:
            ps2_keyboard_driver->key_released = '0';
            break;
        case 0x0C + 0x80:
            ps2_keyboard_driver->key_released = '-';
            break;
        case 0x0D + 0x80:
            ps2_keyboard_driver->key_released = '=';
            break;
        case 0x1A + 0x80:
            ps2_keyboard_driver->key_released = '[';
            break;
        case 0x1B + 0x80:
            ps2_keyboard_driver->key_released = ']';
            break;
        case 0x27 + 0x80:
            ps2_keyboard_driver->key_released = ';';
            break;
        case 0x28 + 0x80:
            ps2_keyboard_driver->key_released = '\'';
            break;
        case 0x29 + 0x80:
            ps2_keyboard_driver->key_released = '`';
            break;
        case 0x2B + 0x80:
            ps2_keyboard_driver->key_released = '\\';
            break;
        case 0x33 + 0x80:
            ps2_keyboard_driver->key_released = ',';
            break;
        case 0x34 + 0x80:
            ps2_keyboard_driver->key_released = '.';
            break;
        case 0x35 + 0x80:
            ps2_keyboard_driver->key_released = '/';
            break;

    }
}

void char_key_cleaner(ps2_keyboard_driver* ps2_keyboard_driver){

    ps2_keyboard_driver->key_pressed = '\0';
    ps2_keyboard_driver->key_released = '\0';

}

void key_code_cleaner(ps2_keyboard_driver* ps2_keyboard_driver){

    ps2_keyboard_driver->key_code = '\0';

}

void shortcut_key_validator(ps2_keyboard_driver* ps2_keyboard_driver, uint8_t key_code){

    switch(key_code){
        case 0x2A:
            ps2_keyboard_driver->left_shift_pressed = '1';
            break;
        case 0x36:
            ps2_keyboard_driver->right_shift_pressed = '1';
            break;
        case 0x1C:
            ps2_keyboard_driver->enter_pressed = '1';
            break;
        case 0x0E:
            ps2_keyboard_driver->backspace_pressed = '1';
            break;
        case 0x1D:
            ps2_keyboard_driver->left_ctrl_pressed = '1';
            break;

        case 0x2A + 0x80:
            ps2_keyboard_driver->left_shift_pressed = '0';
            break;
        case 0x36 + 0x80:
            ps2_keyboard_driver->right_shift_pressed = '0';
            break;
        case 0x1C + 0x80:
            ps2_keyboard_driver->enter_pressed = '0';
            break;
        case 0x0E + 0x80:
            ps2_keyboard_driver->backspace_pressed = '0';
            break;
        case 0x1D + 0x80:
            ps2_keyboard_driver->left_ctrl_pressed = '0';
            break;
    }
}

void shortcut_key_cleaner(ps2_keyboard_driver* ps2_keyboard_driver){

    ps2_keyboard_driver->left_shift_pressed = 0;
    ps2_keyboard_driver->right_shift_pressed = 0;
    ps2_keyboard_driver->enter_pressed = 0;
    ps2_keyboard_driver->backspace_pressed = 0;
    ps2_keyboard_driver->left_ctrl_pressed = 0;

}

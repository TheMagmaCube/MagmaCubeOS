//Main lib for ps2_keyboard_driver


//Including libs
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/ps2_keyboard_driver/ps2_keyboard_io.h"

typedef struct{
    char key_pressed;
    char key_relesed;

} ps2_keyboard_scan_code_set_one;

void char_selector(ps2_keyboard_scan_code_set_one* ps_driver, uint8_t char_code){

    switch(char_code){
        case 0x1E:
            ps_driver->key_pressed = 'A';
        case 0x30:
            ps_driver->key_pressed = 'B';
        case 0x2E:
            ps_driver->key_pressed = 'C';
        case 0x20:
            ps_driver->key_pressed = 'D';
        case 0x12:
            ps_driver->key_pressed = 'E';
        case 0x21:
            ps_driver->key_pressed = 'F';
        case 0x22:
            ps_driver->key_pressed = 'G';
        case 0x23:
            ps_driver->key_pressed = 'H';
        case 0x17:
            ps_driver->key_pressed = 'I';
        case 0x24:
            ps_driver->key_pressed = 'J';
        case 0x25:
            ps_driver->key_pressed = 'K';
        case 0x26:
            ps_driver->key_pressed = 'L';
        case 0x32:
            ps_driver->key_pressed = 'M';
        case 0x31:
            ps_driver->key_pressed = 'N';
        case 0x18:
            ps_driver->key_pressed = 'O';
        case 0x19:
            ps_driver->key_pressed = 'P';
        case 0x10:
            ps_driver->key_pressed = 'Q';
        case 0x13:
            ps_driver->key_pressed = 'R';
        case 0x1F:
            ps_driver->key_pressed = 'S';
        case 0x14:
            ps_driver->key_pressed = 'T';
        case 0x16:
            ps_driver->key_pressed = 'U';
        case 0x2F:
            ps_driver->key_pressed = 'V';
        case 0x11:
            ps_driver->key_pressed = 'W';
        case 0x2D:
            ps_driver->key_pressed = 'X';
        case 0x15:
            ps_driver->key_pressed = 'Y';
        case 0x2C:
            ps_driver->key_pressed = 'Z';
        case 0x1E + 0x80:
            ps_driver->key_relesed = 'A';
        case 0x30 + 0x80:
            ps_driver->key_relesed = 'B';
        case 0x2E + 0x80:
            ps_driver->key_relesed = 'C';
        case 0x20 + 0x80:
            ps_driver->key_relesed = 'D';
        case 0x12 + 0x80:
            ps_driver->key_relesed = 'E';
        case 0x21 + 0x80:
            ps_driver->key_relesed = 'F';
        case 0x22 + 0x80:
            ps_driver->key_relesed = 'G';
        case 0x23 + 0x80:
            ps_driver->key_relesed = 'H';
        case 0x17 + 0x80:
            ps_driver->key_relesed = 'I';
        case 0x24 + 0x80:
            ps_driver->key_relesed = 'J';
        case 0x25 + 0x80:
            ps_driver->key_relesed = 'K';
        case 0x26 + 0x80:
            ps_driver->key_relesed = 'L';
        case 0x32 + 0x80:
            ps_driver->key_relesed = 'M';
        case 0x31 + 0x80:
            ps_driver->key_relesed = 'N';
        case 0x18 + 0x80:
            ps_driver->key_relesed = 'O';
        case 0x19 + 0x80:
            ps_driver->key_relesed = 'P';
        case 0x10 + 0x80:
            ps_driver->key_relesed = 'Q';
        case 0x13 + 0x80:
            ps_driver->key_relesed = 'R';
        case 0x1F + 0x80:
            ps_driver->key_relesed = 'S';
        case 0x14 + 0x80:
            ps_driver->key_relesed = 'T';
        case 0x16 + 0x80:
            ps_driver->key_relesed = 'U';
        case 0x2F + 0x80:
            ps_driver->key_relesed = 'V';
        case 0x11 + 0x80:
            ps_driver->key_relesed = 'W';
        case 0x2D + 0x80:
            ps_driver->key_relesed = 'X';
        case 0x15 + 0x80:
            ps_driver->key_relesed = 'Y';
        case 0x2C + 0x80:
            ps_driver->key_relesed = 'Z';
    }
}

void key_check(ps2_keyboard_scan_code_set_one* ps_driver){
    uint8_t code = load_data_from_register(0x60);

    char_selector(ps_driver, code);



}

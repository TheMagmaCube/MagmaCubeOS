#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "../../include/ps2_keyboard_driver/ps2_keyboard_io.h"
#include "../../include/ps2_keyboard_driver/ps2_keyboard_driver.h"
#include "../../include/video/font_engine.h"
#include "../../include/video/font_composer.h"

typedef struct{
    uint8_t row;

} virt_terminal;


void control_key_managment(virt_terminal* virt_terminal, ps2_keyboard_scan_code_set_one* ps_driver, font_composer* fc){

    if(ps_driver->control_key_pressed != ps_driver->control_key_released){
        if(ps_driver->control_key_pressed == 'E'){
            fc->column++;
            fc->row = 0;
        }
    }
    if(ps_driver->control_key_pressed != ps_driver->control_key_released){
        if(ps_driver->control_key_pressed == 'B'){
            fc->row -=1;
            word_render()

        }
    }
}

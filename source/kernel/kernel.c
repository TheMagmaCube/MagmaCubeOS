//kernel code
#include "./lib/include/video/framebuffer.h"
#include "./lib/include/video/font_engine.h"
#include "./lib/include/video/screen_manager.h"
#include "./lib/include/video/font_composer.h"
#include "./lib/include/ps2_keyboard_driver/ps2_keyboard_driver.h"


//Main kernel loop
//Getting parameters about GOP from entry.s

int kernel_main(framebuffer* fb_from_bootloader){

    //Initializing local framebufer variable

    framebuffer fb;
    font_engine fe;
    font_composer fc;
    ps2_keyboard_scan_code_set_one ps2_driver;

    //Framebuffer variable init
    framebuffer_init(fb_from_bootloader, &fb);

    //Framebuffer check
    framebuffer_mode_check(&fb);

    //Font composer init
    font_composer_init(&fc, fb.address, fb.width, fb.height, fb.bpp_mode);

    //Clearing screen

    clear_screen(fb.bpp_mode, fb.address, fb.width, fb.height);

    //Testing fonts
    word_render(&fc, &fe, 7, 'M', 'A', 'G', 'M', 'A', 'O', 'S');

    //add_screen_overlay(fb.bpp_mode, fb.address, fb.width);

    //Loop for kernel because we don't want to kernel
    //stop

    while(1){
        key_check(&ps2_driver, &fc, &fe);

    }
    //return for readability
    return(0);
}

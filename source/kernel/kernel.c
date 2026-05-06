//kernel code
#include "./lib/include/framebuffer.h"
#include "./lib/include/font_engine.h"
#include "./lib/include/screen_manager.h"
#include "./lib/include/font_composer.h"


//Main kernel loop
//Getting parameters about GOP from entry.s

int kernel_main(framebuffer* fb_from_bootloader){

    //Initializing local framebufer variable

    framebuffer fb;
    font_engine fe;
    font_composer fc;

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


    }
    //return for readability
    return(0);
}

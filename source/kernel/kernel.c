//kernel code
#include "./lib/include/framebuffer.h"
#include "./lib/include/font_engine.h"
#include "./lib/include/screen_manager.h"


//Main kernel loop
//Getting parameters about GOP from entry.s

int kernel_main(framebuffer* fb_from_bootloader){

    //Initializing local framebufer variable

    framebuffer fb;
    font_engine fe;

    //Framebuffer variable init
    framebuffer_init(fb_from_bootloader, &fb);

    //Font engine variable init
    font_engine_init(&fe);

    //Framebuffer check
    framebuffer_mode_check(&fb);

    //Clearing screen

    clear_screen(fb.bpp_mode, fb.address, fb.width, fb.height);

    //Adding overlay to teh screen
    font_render(fb.bpp_mode, fb.address, &fe, 'D', fb.width, 0, 255,0, 0);

    //add_screen_overlay(fb.bpp_mode, fb.address, fb.width);

    //Loop for kernel because we don't want to kernel
    //stop

    while(1){


    }
    //return for readability
    return(0);
}

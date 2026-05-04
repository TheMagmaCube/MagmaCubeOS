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

    //Printing chars
    while(1){
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 0, 255,0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'B', fb.width, 0, 255,0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'C', fb.width, 0, 255,0, 0);
    for(uint32_t i = 0; i < 999999999;i++){
    }
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 0, 0, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'B', fb.width, 0, 0, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'C', fb.width, 0, 0, 255, 0);
    for(uint32_t i = 0; i < 999999999;i++){
    }
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'B', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'C', fb.width, 255, 0, 0, 0);
    for(uint32_t i = 0; i < 999999999;i++){
    }
    clear_screen(fb.bpp_mode, fb.address, fb.width, fb.height);
    }
    //add_screen_overlay(fb.bpp_mode, fb.address, fb.width);

    //Loop for kernel because we don't want to kernel
    //stop

    while(1){


    }
    //return for readability
    return(0);
}

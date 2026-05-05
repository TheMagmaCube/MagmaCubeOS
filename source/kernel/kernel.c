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

    //Testing fonts

    uint32_t counter = 0;
    while(1){
    fe.stage_column = 0;
    fe.stage_row = 0 + counter;
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 0, 255, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'G', fb.width, 0, 100, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'O', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'S', fb.width, 0, 255, 255, 0);
    fe.stage_column = 1;
    fe.stage_row = 8 + counter;
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 0, 255, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'G', fb.width, 0, 100, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'O', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'S', fb.width, 0, 255, 255, 0);
    fe.stage_column = 2;
    fe.stage_row = 16 + counter;
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 0, 255, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'G', fb.width, 0, 100, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'O', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'S', fb.width, 0, 255, 255, 0);
    fe.stage_column = 3;
    fe.stage_row = 24 + counter;
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 0, 255, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'G', fb.width, 0, 100, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'O', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'S', fb.width, 0, 255, 255, 0);
    fe.stage_column = 4;
    fe.stage_row = 32 + counter;
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 0, 255, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'G', fb.width, 0, 100, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'O', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'S', fb.width, 0, 255, 255, 0);
    fe.stage_column = 5;
    fe.stage_row = 40 + counter;
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 0, 255, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'G', fb.width, 0, 100, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'O', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'S', fb.width, 0, 255, 255, 0);
    fe.stage_column = 6;
    fe.stage_row = 48 + counter;
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 0, 255, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'G', fb.width, 0, 100, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'O', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'S', fb.width, 0, 255, 255, 0);
    fe.stage_column = 7;
    fe.stage_row = 56 + counter;
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 0, 255, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'G', fb.width, 0, 100, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'O', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'S', fb.width, 0, 255, 255, 0);
    fe.stage_column = 8;
    fe.stage_row = 64 + counter;
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 0, 255, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'G', fb.width, 0, 100, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'O', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'S', fb.width, 0, 255, 255, 0);
    fe.stage_column = 9;
    fe.stage_row = 72 + counter;
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 0, 255, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'G', fb.width, 0, 100, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'O', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'S', fb.width, 0, 255, 255, 0);
    fe.stage_column = 10;
    fe.stage_row = 80 + counter;
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 0, 255, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'G', fb.width, 0, 100, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'O', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'S', fb.width, 0, 255, 255, 0);
    fe.stage_column = 11;
    fe.stage_row = 88 + counter;
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 0, 255, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'G', fb.width, 0, 100, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'M', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'A', fb.width, 255, 0, 0, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'O', fb.width, 255, 255, 255, 0);
    font_render(fb.bpp_mode, fb.address, &fe, 'S', fb.width, 0, 255, 255, 0);

    for(uint32_t i = 0; i < 9999999 * 5;i++){
    }
    clear_screen(fb.bpp_mode, fb.address, fb.width, fb.height);
    counter++;
    }
    //add_screen_overlay(fb.bpp_mode, fb.address, fb.width);

    //Loop for kernel because we don't want to kernel
    //stop

    while(1){


    }
    //return for readability
    return(0);
}

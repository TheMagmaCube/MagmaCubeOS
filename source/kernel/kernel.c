//kernel code
#include "./lib/include/video/framebuffer.h"
#include "./lib/include/video/font_engine.h"
#include "./lib/include/video/screen_manager.h"
#include "./lib/include/video/font_composer.h"
#include "./lib/include/ps2_keyboard_driver/ps2_keyboard_driver.h"
#include "./lib/include/terminal/terminal.h"


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

    terminal t;

    init_terminal(&t);

    while(1){

        terminal_main_loop(&t, &fc, &fe);

    }
    //return for readability
    return(0);
}

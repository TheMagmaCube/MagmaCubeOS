//kernel code
#include "./lib/include/drivers/video_framebuffer/framebuffer.h"
#include "./lib/include/drivers/video_framebuffer/font_engine.h"
#include "./lib/include/drivers/video_framebuffer/screen_manager.h"
#include "./lib/include/drivers/video_framebuffer/font_composer.h"
#include "./lib/include/drivers/ps2_keyboard_driver/ps2_keyboard_driver.h"
#include "./lib/include/terminal/terminal.h"
#include "./lib/include/cpu/gdt.h"
#include "./lib/include/cpu/idt.h"
#include "./lib/include/interrupt/pic.h"

#include <stdint.h>


//Main kernel loop
//Getting parameters about GOP from entry.s

int kernel_main(framebuffer* fb_from_bootloader){

    //Initializing gdt

    gdt_init();

    //Initializing idt

    idt_init();

    //Initializing pic

    pic_values_init();
    pic_init();

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

    init_terminal(&t, fb.bpp_mode, fb.address, fb.width, fb.height);


    volatile uint32_t a = 1;
    volatile uint32_t b = 0;

    volatile uint32_t c = a / b;



    while(1){

        terminal_main_loop(&t, &fc, &fe);

    }
    //return for readability
    return(0);
}

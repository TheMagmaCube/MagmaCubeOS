//kernel code
#include "framebuffer.c"

int kernel_main(framebuffer* fb_from_bootloader){
    framebuffer fb;
    framebuffer_init(fb_from_bootloader, &fb);

    clear_screen(fb.address, fb.width, fb.height);

    add_screen_overlay(fb.address, fb.width);

    while(1){


    }
    //return
    return(0);
}

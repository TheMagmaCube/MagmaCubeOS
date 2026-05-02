//kernel code
#include "framebuffer.c"


//Main kernel loop
//Getting parameters about GOP from entry.s

int kernel_main(framebuffer* fb_from_bootloader){

    //Initializing local framebufer variable

    framebuffer fb;

    //Framebuffer variable init
    framebuffer_init(fb_from_bootloader, &fb);

    //Clearing screen

    clear_screen(fb.bpp_mode,fb.address, fb.width, fb.height);

    //Adding overlay to teh screen

    add_screen_overlay(fb.bpp_mode, fb.address, fb.width);

    //Loop for kernel because we don't want to kernel
    //stop

    while(1){


    }
    //return for readability
    return(0);
}

//kernel code
#include "framebuffer.c"

int kernel_main(framebuffer* fb_from_bootloader){

    framebuffer fb;

    framebuffer_init(fb_from_bootloader, &fb);

    while(1){

    }
    return(0);
}

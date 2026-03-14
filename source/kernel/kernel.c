//kernel code
#include "framebuffer.c"

int kernel_main(framebuffer* fb_from_bootloader){
    framebuffer fb;
    framebuffer_init(fb_from_bootloader, &fb);

    put_pixel(fb.address, fb.width, 100, 100, 0, 0, 255, 0);
    clear_screen(fb.address, fb.width, fb.height);
    while(1){
        for(int i = 0; i < 100; i+=1){
            put_pixel(fb.address, fb.width, 100 + i, 100, 0, 0, 255, 0);
        }
    }
    return(0);
}

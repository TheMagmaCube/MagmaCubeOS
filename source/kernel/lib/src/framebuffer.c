//Main framebuffer lib

//Including standard libs

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

//Definies framebuffer structure

typedef struct {
    uint64_t address;
    uint32_t width;
    uint32_t height;
    uint32_t pitch;
    uint32_t bits_per_pixel;
    uint32_t RGB_graphic_mode;
    uint32_t BGR_graphic_mode;
    uint32_t bpp_mode; // 1 = rgb, 2 = bgr
} framebuffer;

//Framebuffer init void for framebuffer structure
//needs have Framebuffer parameters

void framebuffer_init(framebuffer *fb_from_bootloader, framebuffer *fb){
    fb->address = fb_from_bootloader->address;
    fb->height = fb_from_bootloader->height;
    fb->width = fb_from_bootloader->width;
    fb->pitch = fb_from_bootloader->pitch;
    fb->bits_per_pixel = fb_from_bootloader->bits_per_pixel;
    fb->RGB_graphic_mode = fb_from_bootloader->RGB_graphic_mode;
    fb->BGR_graphic_mode = fb_from_bootloader->BGR_graphic_mode;
    fb->bpp_mode = 0;
}

//Framebuffer mode check
void framebuffer_mode_check(framebuffer *fb){
    if(fb->RGB_graphic_mode == 1){
        fb->bpp_mode = 1;
    }else if(fb->BGR_graphic_mode == 1){
        fb->bpp_mode = 2;
    }
}


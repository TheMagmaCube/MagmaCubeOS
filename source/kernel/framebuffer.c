#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    uint64_t address;
    uint32_t width;
    uint32_t height;
    uint32_t pitch;
    uint32_t bits_per_pixel;
} framebuffer;

void framebuffer_init(framebuffer *fb_from_bootloader, framebuffer *fb){
    fb->address = fb_from_bootloader->address;
    fb->height = fb_from_bootloader->height;
    fb->width = fb_from_bootloader->width;
    fb->pitch = fb_from_bootloader->pitch;
    fb->bits_per_pixel = fb_from_bootloader->bits_per_pixel;
}

void put_pixel(uint64_t address, int x, int y, uint32_t color){


}

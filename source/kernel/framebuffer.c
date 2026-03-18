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
} framebuffer;

//Framebuffer init void for framebuffer structure
//needs have Framebuffer parameters

void framebuffer_init(framebuffer *fb_from_bootloader, framebuffer *fb){
    fb->address = fb_from_bootloader->address;
    fb->height = fb_from_bootloader->height;
    fb->width = fb_from_bootloader->width;
    fb->pitch = fb_from_bootloader->pitch;
    fb->bits_per_pixel = fb_from_bootloader->bits_per_pixel;
}

//Put pixel void for puting pixel on screen
//needs have Framebuffer parameters

void put_pixel(uint64_t address, uint64_t width, uint64_t x, uint64_t y,
               uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha){

    //pixel address

    uint64_t pixel_address = address + (y * width + x) * 4;

    //Writing pixel data directly to addresses in RAM

    *(uint8_t*)pixel_address = blue;
    *((uint8_t*)pixel_address + 1) = green;
    *((uint8_t*)pixel_address + 2) = red;
    *((uint8_t*)pixel_address + 3) = alpha;
}

//Clear screen void for clearing the screen
//needs have Framebuffer parameters

void clear_screen(uint64_t address, uint32_t width, uint32_t height){

    for(uint32_t h = 0; h <= height; h++){
        for(uint32_t w = 0; w <= width; w++){
            put_pixel(address, width, w, h, 0, 0, 0, 0);
        }
    }
}

//Add sreen overlay void for the screen
//needs have Framebuffer parameters

void add_screen_overlay(uint64_t address, uint32_t width){

    for(int i = 0; i < 1200; i+=1){
        put_pixel(address, width, 30 + i, 30, 0, 255, 0, 0);
    }
    for(int i = 0; i < 750; i+=1){
        put_pixel(address, width, 30, 30 + i, 0, 255, 0, 0);
    }
    for(int i = 0; i < 1200; i+=1){
        put_pixel(address, width, 30 + i, 780, 0, 255, 0, 0);
    }
    for(int i = 0; i < 750; i+=1){
        put_pixel(address, width, 1230, 30 + i, 0, 255, 0, 0);
    }
}

//Fonts

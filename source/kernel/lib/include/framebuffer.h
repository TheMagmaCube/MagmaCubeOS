#pragma once

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct{
    uint64_t address;
    uint32_t width;
    uint32_t height;
    uint32_t pitch;
    uint32_t bits_per_pixel;
    uint32_t RGB_graphic_mode;
    uint32_t BGR_graphic_mode;
    uint32_t bpp_mode; // 1 = rgb, 2 = bgr
} framebuffer;

void framebuffer_init(framebuffer *fb_from_bootloader, framebuffer *fb);

void framebuffer_mode_check(framebuffer *fb);

#endif

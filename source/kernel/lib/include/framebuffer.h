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

void put_pixel(uint32_t mode, uint64_t address, uint64_t width, uint64_t x, uint64_t y,
               uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

void clear_screen(uint32_t mode, uint64_t address, uint32_t width, uint32_t height);

void add_screen_overlay(uint32_t mode, uint64_t address, uint32_t width);

#endif

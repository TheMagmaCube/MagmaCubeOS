#pragma once

#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct{
    uint32_t width;
    uint32_t height;
} screen_manager;

void put_pixel(uint32_t mode, uint64_t address, uint64_t width, uint64_t x, uint64_t y,
               uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

void clear_screen(uint32_t mode, uint64_t address, uint32_t width, uint32_t height);

void add_screen_overlay(uint32_t mode, uint64_t address, uint32_t width);

#endif

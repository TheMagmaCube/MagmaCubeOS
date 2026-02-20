#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct{
    int VGA_COLOR_BLACK;
    int VGA_COLOR_BLUE;
    int VGA_COLOR_GREEN;
    int VGA_COLOR_CYAN;
    int VGA_COLOR_RED;
    int VGA_COLOR_MAGENTA;
    int VGA_COLOR_BROWN;
    int VGA_COLOR_LIGHT_GREY;
    int VGA_COLOR_DARK_GREY;
    int VGA_COLOR_LIGHT_BLUE;
    int VGA_COLOR_LIGHT_GREEN;
    int VGA_COLOR_LIGHT_CYAN;
    int VGA_COLOR_LIGHT_RED;
    int VGA_COLOR_LIGHT_MAGENTA;
    int VGA_COLOR_LIGHT_BROWN;
    int VGA_COLOR_WHITE;
} Vga;

void Set_vga_parameters(Vga * vga){
    vga->VGA_COLOR_BLACK = 0;
    vga->VGA_COLOR_BLUE = 1;
    vga->VGA_COLOR_GREEN = 2;
    vga->VGA_COLOR_CYAN = 3;
    vga->VGA_COLOR_RED = 4;
    vga->VGA_COLOR_MAGENTA = 5;
    vga->VGA_COLOR_BROWN = 6;
    vga->VGA_COLOR_LIGHT_GREY = 7;
    vga->VGA_COLOR_DARK_GREY = 8;
    vga->VGA_COLOR_LIGHT_BLUE = 9;
    vga->VGA_COLOR_LIGHT_GREEN = 10;
    vga->VGA_COLOR_LIGHT_CYAN = 11;
    vga->VGA_COLOR_LIGHT_RED = 12;
    vga->VGA_COLOR_LIGHT_MAGENTA = 13;
    vga->VGA_COLOR_LIGHT_BROWN = 14;
    vga->VGA_COLOR_WHITE = 15;
}

void initialize_vga(){
    Vga vga;
    Set_vga_parameters(&vga);
}

void set_char(Vga * vga, int front_color, int background_color, char character){
    uint8_t color =  (background_color << 4) | front_color;
    uint8_t text = character;

    uint16_t vga_unit = (color << 8) | text;

    uint16_t *ptr = (uint16_t *) 0xB8000;

    *ptr = vga_unit;
}

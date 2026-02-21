//kernel code
#include "video.c"

int kernel_main(){

    Vga vga = initialize_vga();


    set_char(&vga ,vga.VGA_COLOR_BLUE, vga.VGA_COLOR_WHITE, 'A');

    while(0);

    return 0;
}

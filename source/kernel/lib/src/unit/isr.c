#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

void divide_handler(){
        asm volatile("hlt");
}

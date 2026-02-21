.section .text
.global vga_setup

vga_setup:
    mov $0x67, %al
    mov $0x3C2, %dx
    out %al, %dx
    ret

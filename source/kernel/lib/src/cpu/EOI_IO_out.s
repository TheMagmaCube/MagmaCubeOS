.intel_syntax noprefix
.section .text
.global eoi_io_out

eoi_io_out:

    mov dx, 0x20
    mov al, 0x20

    out dx, al

    ret

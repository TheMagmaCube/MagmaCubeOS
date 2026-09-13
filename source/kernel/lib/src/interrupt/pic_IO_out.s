.intel_syntax noprefix
.section .text
.global pic_IO_out

pic_IO_out:
    mov al, dl
    mov dx, cx
    out dx, al

    ret


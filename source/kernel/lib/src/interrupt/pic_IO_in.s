.intel_syntax noprefix
.section .text
.global pic_IO_in

pic_IO_in:
    mov dx, cx
    in al, dx

    ret


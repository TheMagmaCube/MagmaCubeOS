.intel_syntax noprefix
.section .text
.global pic_IO_in

pic_IO_in:
    mov r8, cx
    in r9, r8

    ret


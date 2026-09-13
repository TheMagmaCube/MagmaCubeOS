.intel_syntax noprefix
.section .text
.global pic_IO_out

pic_IO_out:
    mov r8, cx
    mov r9, dx

    out r9, cx

    ret


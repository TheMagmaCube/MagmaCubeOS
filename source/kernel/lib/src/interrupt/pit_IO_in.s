.intel_syntax noprefix
.section .text
.global pit_IO_in

pit_IO_in:
    mov r8, cx
    in r9, r8

    ret

.intel_syntax noprefix
.section .text
.global pit_IO_out

pit_IO_out:
    mov r8, cx
    mov r9, dx

    out r8, r9

    ret

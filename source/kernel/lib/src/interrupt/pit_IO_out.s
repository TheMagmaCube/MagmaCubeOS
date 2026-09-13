.intel_syntax noprefix
.section .text
.global pit_IO_out

pit_IO_out:
    mov dx, cx
    out dx, al

    ret

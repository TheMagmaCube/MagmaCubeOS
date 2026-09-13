.intel_syntax noprefix
.section .text
.global pit_IO_in

pit_IO_in:
    mov dx, cx
    in al, dx

    ret

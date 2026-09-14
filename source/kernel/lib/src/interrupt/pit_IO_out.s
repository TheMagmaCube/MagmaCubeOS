.intel_syntax noprefix
.section .text
.global pit_IO_out

pit_IO_out:
    mov al, dl
    mov dx, cx
    out dx, al
    #Enable masked interrupts
    sti
    ret

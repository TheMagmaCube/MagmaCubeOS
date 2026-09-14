.intel_syntax noprefix
.section .text
.global isr0

.extern eoi_io_out

isr0:

    #push rax
    #push rdx

    call eoi_io_out

    #pop rdx
    #pop rax

    iretq

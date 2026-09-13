.intel_syntax noprefix
.section .text
.global isr0

.extern eoi_io_out

isr0:

    call eoi_io_out

    iretq

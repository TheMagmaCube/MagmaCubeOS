.intel_syntax noprefix
.section .text
.global isr0

extern EOI_IO_out

isr0:

    EOI_IO_out

    iretq

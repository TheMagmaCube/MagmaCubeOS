.intel_syntax noprefix
.section .text
.global EOI_IO_out

EOI_IO_out:

    out 0x20, 0x20

    ret

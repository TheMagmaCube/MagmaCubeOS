.intel_syntax noprefix
.section .text
.global gdt_load_pointer_to_cpu


#loading pointer gdt_table to cpu register lgdt
gdt_load_pointer_to_cpu:

    lgdt [rcx]

    ret

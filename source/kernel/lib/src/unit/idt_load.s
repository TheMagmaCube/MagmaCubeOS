.intel_syntax noprefix
.section .text
.global idt_load_pointer_to_cpu


idt_load_pointer_to_cpu:

    lidt [rcx]

    ret

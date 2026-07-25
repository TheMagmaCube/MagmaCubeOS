.intel_syntax noprefix
.section .text
.global gdt_load_pointer_to_cpu


reload_cs:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov ss, ax


#loading pointer gdt_table to cpu register lgdt
gdt_load_pointer_to_cpu:

    lgdt [rcx]

    #call reload_cs
    push 0x08
    lea rax, [rip + reload_cs]
    push rax
    retfq

    ret

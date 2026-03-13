.intel_syntax noprefix
.section .text
.global _start
.extern kernel_main

_start:
    mov rcx, rax
    call kernel_main

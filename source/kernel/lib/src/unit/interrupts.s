.intel_syntax noprefix
.section .text
.global isr0
.extern divide_handler

isr0:

    #push rax
    #push rbx
    #push rcx
    #push rdx

    sub rsp, 32

    call divide_handler

    sub rsp, 32

    #pop rdx
    #pop rcx
    #pop rbx
    #pop rax

    iretq

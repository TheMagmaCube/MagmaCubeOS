.intel_syntax noprefix
.section .text
.global load_data_from_register

load_data_from_register:
    mov dx, cx
    in al, dx

    ret

.section .text
.global _start

_start:
    cli         # wyłącz przerwania

.hang:
    hlt         # zatrzymaj CPU do następnego przerwania
    jmp .hang   # wróć do HLT w nieskończonej pętli

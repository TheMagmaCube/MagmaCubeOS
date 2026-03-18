#kernel jump

#Setting intel_syntax noprefix
#it must be done to parameters from bootloader
#works, because in other way this
#will generate a error when asm go to line
#mov rcx, rax

.intel_syntax noprefix
.section .text
.global _start

#externing kernel_main function
#from kernel.c file

.extern kernel_main

_start:

    #Relocating parameters
    #This should be done
    #Because in MS abi
    #In default diffrent register give
    #parameters to other called function
    #And in default that calling function
    #Expect to have parameter in diferent register
    #that is why >> mov rcx, rax

    mov rcx, rax

    #Calling kernel (moving to c function kernel)

    call kernel_main

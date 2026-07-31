.intel_syntax noprefix
.section .text
.global load_data_from_register

load_data_from_register:
    # getting port value np 0x60
    # from parameter in this function that c gives when call this function
    mov dx, cx

    # copy value that is in dx, al because it have 8 bits same as code form 0x60
    # add it will return this value
    in al, dx

    # returning value from al
    ret

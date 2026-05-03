ENTRY(_start)
PHDRS
{
    text PT_LOAD FLAGS(5);
    data PT_LOAD FLAGS(6);
}
SECTIONS
{
    . = 0x100000000;
    .text : { *(.text*) } :text
    .rodata : { *(.rodata*) } :text
    .eh_frame : { *(.eh_frame*) } :text
    .data : { *(.data*) } :data
    .bss : { *(.bss*) } :data
}


ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rwx):  ORIGIN = 0x0, LENGTH = 0x100000
    RAM (rx):    ORIGIN = 0x20000000, LENGTH = 0x40000
}


SECTIONS
{
    .text : 
    {
        KEEP(*(.isr_vector))
        *(.text)
        *(.text.*)
        *(.rodata)
        _sidata = .;
    } > FLASH

    .data : AT(_sidata)
    {
        *(.data)
        *(.data.*)
    } > RAM

    .bss : 
    {
        *(.bss)
        *(.bss.*)
    } > RAM

    _estack = ORIGIN(RAM) + LENGTH(RAM);
}




SEARCH_DIR(.)
GROUP(-lgcc -lc -lnosys)

ENTRY(Reset_Handler)


MEMORY
{
    FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 0x100000
    RAM(rwx)    : ORIGIN = 0x20000000, LENGTH = 0x40000
}

SECTIONS
{
    .text :
    {
        KEEP(*(.isr_vector))
        *(.text)
    } > FLASH

    . = ALIGN(4);
    __etext = .;

    .data : AT (__etext)
    {
        __data_start__ = .;
        *(vtable)
        *(.data*)

        __data_end__ = .;

    } > RAM



    .bss : 
    {
        . = ALIGN(4);
        __bss_start__ = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
    } > RAM
}



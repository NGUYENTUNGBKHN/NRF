
SEARCH_DIR(.)
GROUP(-lgcc -lc -lnosys)

ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rw) : ORIGIN = 0x0, LENGTH = 0x100000
    RAM (rwx) :  ORIGIN = 0x20000000, LENGTH = 0x40000
}


SECTIONS
{
    .text : 
    {
        KEEP(*(.isr_vector))
        
        *(.text*)
        KEEP(*(.init))
        *(.rodata)
    }   > FLASH

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
        . = ALIGN(4);
        __bss_end__ = .;
    } > RAM
    
    /* Check if text sections + data exceeds FLASH limit */
    DataInitFlashUsed = __bss_start__ - __data_start__;
    CodeFlashUsed = __etext - ORIGIN(FLASH);
    TotalFlashUsed = CodeFlashUsed + DataInitFlashUsed;
}




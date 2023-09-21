
SEARCH_DIR(.)
GROUP(-lgcc -lc -lnosys)

ENTRY(Reset_Handler)


MEMORY
{
    FLASH (rx) : ORIGIN = 0x0, LENGTH = 0x100000
    RAM (rwx) :  ORIGIN = 0x20000000, LENGTH = 0x40000
}

SECTIONS
{
    .text :
    {
        KEEP(*(.isr_vector))
        *(.text)
        *(.text.*)
        *(.rodata)
        _sromdev = .;
        _eromdev = .;
        _sidata = .;
    } > FLASH

    .data : AT(_sidata)
    {
        _sdata = .;
        *(.data)
        *(.data*)
        _edata = .;
    } > RAM

    .bss : 
    {
        _sbss = .;
        *(.bss)
        _ebss = .;
    } > RAM

    _estack = ORIGIN(RAM) + LENGTH(RAM);
}



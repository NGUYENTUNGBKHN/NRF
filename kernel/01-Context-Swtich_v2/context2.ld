
ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x0, LENGTH = 0x100000
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 0x40000
}

SECTIONS
{
    .text :
    {
        KEEP(*(.isr_vector))

        *(.text*)
        *(.rodata)
    } > FLASH

    . = ALIGN(4);
    __extext = .;

    .data : AT(__extext)
    {
        __data_start__ = .;
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

    .heap (COPY):
    {
        __HeapBase = .;
        __end__ = .;
        PROVIDE(end = .);
        KEEP(*(.heap*))
        __HeapLimit = .;
    } > RAM

    .stack_dummy (COPY):
    {
        KEEP(*(.stack*))
    } > RAM

    __StackTop = ORIGIN(RAM) + LENGTH(RAM);
    _StackLimit = __StackTop - SIZEOF(.stack_dummy);
    PROVIDE(__stack = __StackTop);
}






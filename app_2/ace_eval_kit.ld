

ENTRY(Reset_Handler)

MEMORY
{
    FLASH(rx): ORIGIN = 0x0, LENGTH = 0x100000
    RAM(rwx): ORIGIN = 0x20000000, LENGTH = 0x40000
}

SECTIONS
{
    .text :
    {
        *(.isr_vector)
        *(.text)
        *(.rodata)
        __etext = .;
    } >  FLASH

    .data :
    {
        *(.data)
    } > SRAM AT> FLASH

    .bss :
    {
        *(.bss)
    } > SRAM
}





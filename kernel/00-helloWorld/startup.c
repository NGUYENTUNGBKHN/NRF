#include <stdint.h>

extern void main();
/* start address for the initialization values of the .data section. */
/* defined in linker script */
extern uint32_t _sidata;
/* start address for the .data section. defined in linker script */
extern uint32_t _sdata;
/* end address for the .data section. defined in linker script */
extern uint32_t _edata;
/* start address for the .bss section. defined in linker script */
extern uint32_t _sbss;
/* end address for the .bss section. defined in linker script */
extern uint32_t _ebss;
/* end address for the stack. defined in linker script */
extern uint32_t _estack;



void Reset_Handler(void)
{
    /* Copy the data segment initializers from flash to SRAM */
    uint32_t *idata_begin = &_sidata;
    uint32_t *data_begin = &_sdata;
    uint32_t *data_end = &_edata;
    while(data_begin < data_end)
    {
        *data_begin++ = *idata_begin++;
    }
    /* Zero fill the bss segment */
    uint32_t *bss_begin = &_sbss;
    uint32_t *bss_end = &_ebss;
    while (bss_begin > bss_end)
    {
        *bss_begin++= 0;
    }
    
    main();
}

__attribute((section(".isr_vector")))
uint32_t *isr_vectors[] = {
    (uint32_t*) &_estack,
    (uint32_t*)Reset_Handler,
};


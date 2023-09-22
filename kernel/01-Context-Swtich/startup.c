#include <stdint.h>

extern void main();

/* start address for the initialization values of the .data section */
extern uint32_t _sidata; // start initislization .data section
/* start address .data section */
extern uint32_t _sdata;
/* end address .data section */
extern uint32_t _edata;
/* start address .bss */
extern uint32_t _sbss;
/* end address .bss */
extern uint32_t _ebss;

extern uint32_t _estack;

void Reset_Handler(void)
{
    /* Copy the data segment initializer from flash to RAM */
    uint32_t *idata_begin = &_sidata;
    uint32_t *data_begin = &_sdata;
    uint32_t *data_end = &_edata;

    while(data_begin < data_end)
    {
        *data_begin++ = *idata_begin++;
    }
    /* initialied .bss segment */
    uint32_t *bss_begin = &_sbss;
    uint32_t *bss_end = &_ebss;

    while (bss_begin < bss_end)
    {
        *bss_begin++ = 0;
    }
    

    main();
}

void NMI_Handler()
{
    while(1);
}

void Hardfault_Handler()
{
    while(1);
}

__attribute((section(".isr_vector")))
uint32_t *isr_vectors[] = {
    (uint32_t*) &_estack,
    (uint32_t*) Reset_Handler,
    (uint32_t*) NMI_Handler,
    (uint32_t*) Hardfault_Handler,
};





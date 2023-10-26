#include <stdint.h>

extern void main();

// start initialized data
extern uint32_t _sidata;
// start address data
extern uint32_t _sdata;
// end address data
extern uint32_t _edata;

extern uint32_t _sbss;
extern uint32_t _ebss;

extern uint32_t _estack;

void Reset_Handler()
{
    uint32_t *idata_begin = &_sidata;
    uint32_t *data_begin = &_sdata;
    uint32_t *data_end = &_edata;

    while(data_begin < data_end)
    {
        *data_begin++ = *idata_begin++;
    }

    main();
}


__attribute((section(".isr_vector")))
uint32_t *isr_vector[] = {
    (uint32_t*) &_estack,
    (uint32_t*) Reset_Handler,
};




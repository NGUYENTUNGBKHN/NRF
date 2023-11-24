#include <stdint.h>

extern void main(void);
extern uint32_t _estack;

extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;

extern uint32_t _sbss;
extern uint32_t _ebss;

void Reset_Handler(void)
{
    uint32_t *p_sidata = &_sidata;
    uint32_t *p_sdata = &_sdata;
    uint32_t *p_edata = &_edata;
    uint32_t *p_sbss = &_sbss;
    uint32_t *p_ebss = &_ebss;

    while(p_sdata < p_edata)
    {
        *p_sdata++ = *p_sidata++;
    }

    while (p_sbss < p_ebss)
    {
        /* code */
        *p_sbss++ = 0;
    }

    main();
}

void default_handler(void)
{
    while (1)
    {
        /* code */
    }
    
}

void NMI_Handler(void) __attribute((weak, alias("default_handler")));
void HardFault_Handler(void) __attribute((weak, alias("default_handler")));
void MemManage_Handler(void) __attribute((weak, alias("default_handler")));
void BusFault_Handler(void) __attribute((weak, alias("default_handler")));
void UsageFault_Handler(void) __attribute((weak, alias("default_handler")));
void SVC_Handler(void) __attribute((weak, alias("default_handler")));

__attribute((section(".isr_vector")))
uint32_t *_isr_vector[] = {
    (uint32_t*) &_estack,
    (uint32_t*) Reset_Handler,
    (uint32_t*) NMI_Handler,
    (uint32_t*) HardFault_Handler,
    (uint32_t*) MemManage_Handler,
    (uint32_t*) BusFault_Handler,
    (uint32_t*) UsageFault_Handler,
    0,
    0,
    0,
    0,
    (uint32_t*) SVC_Handler,
};



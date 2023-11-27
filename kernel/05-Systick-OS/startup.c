#include <stdint.h>

#define __STARTUP_CONFIG_STACK_ALIGNEMENT 3

extern uint32_t _estack;
extern void main();

void Reset_Handler(void)
{
    main();
}

void Default_Handler(void)
{
    while (1)
    {
        /* code */
    }
    
}

void HardFault_Handler(void)
{
    while (1)
    {
        /* code */
    }
    
}

void default_handler(void)
{
    while(1);
}

void NMI_Handler(void) __attribute((weak, alias("default_handler")));
// void HardFault_Handler(void) __attribute((weak, alias("default_handler")));
void MemoryManagement_Handler(void) __attribute((weak, alias("default_handler")));
void BusFault_Handler(void) __attribute((weak, alias("default_handler")));
void UsageFault_Handler(void) __attribute((weak, alias("default_handler")));
void SVC_Handler(void) __attribute((weak, alias("default_handler")));
void DebugMon_Handler(void) __attribute((weak, alias("default_handler")));
void PendSV_Handler(void) __attribute((weak, alias("default_handler")));
void Systick_Handler(void) __attribute((weak, alias("default_handler")));

__attribute((section(".isr_vector")))
uint32_t *p_isr_vector[] = {
    (uint32_t*) &_estack,
    (uint32_t*) Reset_Handler,
    (uint32_t*) NMI_Handler,
    (uint32_t*) HardFault_Handler,
    (uint32_t*) MemoryManagement_Handler,
    (uint32_t*) BusFault_Handler,
    (uint32_t*) UsageFault_Handler,
    0,
    0,
    0,
    0,
    (uint32_t*) SVC_Handler,
    (uint32_t*) DebugMon_Handler,
    0,
    (uint32_t*) PendSV_Handler,
    (uint32_t*) Systick_Handler,
};





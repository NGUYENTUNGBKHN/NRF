#include <stdint.h>

extern uint32_t _estack;
extern void main();

void Reset_Handler(void)
{
    main();
}


__attribute((section(".isr_vector")))
uint32_t *p_isr_vector[] = {
    (uint32_t*) &_estack,
    (uint32_t*) Reset_Handler,
    0,
};





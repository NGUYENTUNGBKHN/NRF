#include <stdint.h>

extern void main();
void Reset_Handler(void)
{
    main();
}

__attribute((section(".isr_vector")))
uint32_t *isr_vectors[] = {
    0,
    (uint32_t*)Reset_Handler,
};


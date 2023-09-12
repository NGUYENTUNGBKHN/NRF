#include <stdint.h>

extern void main();
void reset_handler()
{
    main();
}

__attribute((section("isr_vector")))
uint32_t *isr_vectors[] = {
    0,
    (uint32_t*)reset_handler,
};


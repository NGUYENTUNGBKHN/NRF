
#ifndef _OSKERNEL_H_
#define _OSKERNEL_H_
#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "nrf.h"                        // Device header


/* CODE */
void osKernelLaunch(uint32_t quanta);

void osKernelInit(void);

uint8_t osKernelAddThreads(void(*task0)(void),
                            void(*task1)(void),
                            void(*task2)(void));

#ifdef __cplusplus
}
#endif
#endif

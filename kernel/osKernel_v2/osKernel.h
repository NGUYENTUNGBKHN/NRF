/******************************************************************************/
/*! @addtogroup Group2
    @file       osKernel.h
    @brief      
    @date       2023/09/09
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/

#ifndef _OSKERNEL_H_
#define _OSKERNEL_H_
#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "nrf.h"                        // Device header


typedef struct tcb_s
{
    int32_t *stackPt;
    struct tcb_s *nextPt; 
}tcb_t, *tcb_p;

void osKernelLaunch(uint32_t quanta);

void osKernelInit(void);

uint8_t osKernelAddThreads(void(*task0)(void),
                            void(*task1)(void),
                            void(*task2)(void));



/* CODE */

#ifdef __cplusplus
}
#endif
#endif



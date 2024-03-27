/******************************************************************************/
/*! @addtogroup Group2
    @file       osKernel.h
    @brief      
    @date       2024/03/27
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
#include "reg.h"

/* CODE */
typedef struct CONTROL_BLOCK_S
{
    uint32_t *stackPt;
    struct CONTROL_BLOCK_S *next;
}tcb_t, *tcb_p;

extern tcb_t *tcb_curr;

extern void osKernelInit();
extern void osKernelAddThreads(void(*task0)(void*),
                                void(*task1)(void*),
                                void(*task2)(void*));
extern void osKernelLaunch(uint32_t time);


#ifdef __cplusplus
}
#endif
#endif




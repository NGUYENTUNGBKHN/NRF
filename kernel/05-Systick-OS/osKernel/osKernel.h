/******************************************************************************/
/*! @addtogroup Group2
    @file       osKernel.h
    @brief      
    @date       2023/11/24
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

/* CODE */
#include "reg.h"


typedef struct TCB_S
{
    int32_t *stackPt;
    struct TCB_S *next;
}tcb_t, *tcb_p;

void osKernelInit(void);

void osKernelAddThreads(void(*task0)(void*),
                        void(*task1)(void*),
                        void(*task2)(void*));

void osKernelLaunch(int quatan);

#ifdef __cplusplus
}
#endif
#endif



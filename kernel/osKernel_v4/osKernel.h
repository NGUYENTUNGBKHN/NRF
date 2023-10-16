/******************************************************************************/
/*! @addtogroup Group2
    @file       osKernel.h
    @brief      
    @date       2023/09/25
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

#include "nrf.h"                        // Device header


/* CODE */
typedef struct tcb_s
{
    int32_t *stackPt;
    struct tcb_s *nextPt;
}tcb_t, *tcb_p;


void osKernelInit(void);

void osKernelAddThread( void(*task0)(void*),
                        void(*task1)(void*),
                        void(*task2)(void*));

void osKernelLaunch(int quatan);

void osThreadYield(void);


#ifdef __cplusplus
}
#endif
#endif






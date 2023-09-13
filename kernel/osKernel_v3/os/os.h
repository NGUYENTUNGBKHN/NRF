/******************************************************************************/
/*! @addtogroup Group2
    @file       os.h
    @brief      
    @date       2023/09/13
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/
#ifndef _OS_H_
#define _OS_H_
#ifdef __cplusplus
extern "C"
{
#endif

/* CODE */
#include <stdint.h>
#include "core_cm4.h"
#include "config.h"


typedef struct tcb_s
{
    /* Pointer to current value in stack */
    int32_t stackPt;
    /* Next thread in the list */
    struct tcb_s *nextPt;
    /* nonzero if blocked on this semaphore */
    int32_t *blocked;
    /* nonezero if this thread is sleeping */
    int32_t sleeping;
    /* Priority of thread */
    uint8_t priority;
    /* To check whether the thread slot is in use or not */
    uint8_t valid;
}tcb_t, *tcb_p;


void OS_Init(void);

void OS_AddThread(void(*func_thread)(void), uint32_t priority);

void OS_Launch(uint32_t theTimeSlice);

void OS_Suspend(void);

void OS_Sleep(uint32_t sleepTime);

void OS_InitSemaphore(int32_t *semaPt, int32_t value);

void OS_Wait(int32_t *semaPt);

void OS_Signal(int32_t *semaPt);

void SetInitialStack(int i);

void StartOS(void);

#ifdef __cplusplus
}
#endif
#endif

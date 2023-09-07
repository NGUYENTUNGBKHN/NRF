/******************************************************************************/
/*! @addtogroup Group2
    @file       osKernel.c
    @brief      
    @date       2023/09/07
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/

// Scheduler 
// TCB 
// Stack
#include "osKernel.h"

#define NUM_OF_THREADS  3
#define STACKSIZE       100
struct tcb {
    int32_t *stackPt;
    struct tcb *nextPt;
};

typedef struct tcb tcbType;

tcbType tcbs[NUM_OF_THREADS];
tcbType *currentPt;

int32_t TCB_STACK[NUM_OF_THREADS][STACKSIZE];

void osKernelStackInit(int i)
{
    tcbs[i].stackPt = &TCB_STACK[i][STACKSIZE - 16];
    TCB_STACK[i][STACKSIZE - 1] = 0x01000000;
}

uint8_t osKernelAddThreads(void(*task0)(void),
                            void(*task1)(void),
                            void(*task2)(void));
{

    __disable_irq();
    tcbs[0].nextPt = &tcbs[1];
    tcbs[1].nextPt = &tcbs[2];
    tcbs[2].nextPt = &tcbs[0];

    osKernelInit(0);
    TCB_STACK[0][STACKSIZE - 2] = (int32_t)(task0);

    osKernelInit(1);
    TCB_STACK[1][STACKSIZE - 2] = (int32_t)(task1);

    osKernelInit(2);
    TCB_STACK[2][STACKSIZE - 2] = (int32_t)(task2);


    __enable_irq();
    return 1;
}


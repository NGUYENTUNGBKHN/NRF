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

#define SYSPRI3         (*(volatile uint32_t*)0xE000ED20)

#define BUS_FREQ   16000000
uint32_t MILLIS_PRESCALER;

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


void osSchedulerLaunch(void);

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

    currentPt = &tcbs[0];

    __enable_irq();
    return 1;
}

void osKernelInit(void)
{
    __disable_irq();
    MILLIS_PRESCALER=(BUS_FREQ/1000);
}

void osKernelLaunch(uint32_t quanta)
{
    SysTick->CTRL = 0;
    SysTick->VAL = 0;
    SysTick->LOAD = (quanta* MILLIS_PRESCALER) - 1;
    SYSPRI3 = (SYSPRI3&0x00FFFFFF) | 0xE0000000;

    SysTick->CTRL = 0x00000007;
    osSchedulerLaunch();

}


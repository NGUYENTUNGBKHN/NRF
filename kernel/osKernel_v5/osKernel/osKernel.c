/******************************************************************************/
/*! @addtogroup Group2
    @file       osKernel.c
    @brief      
    @date       2024/03/27
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/
#include "osKernel.h"

#define LIMIT_TASK 3
#define STACK_SIZE 256
#define NUM_OF_SYS_REG 16

/* exception return non-floating-point */
#define HANDLER_MSP 0xFFFFFFF1
#define THREAD_MSP  0xFFFFFFF9
#define THREAD_PSP  0xFFFFFFFD


tcb_t main_tcb[LIMIT_TASK];

tcb_t *tcb_curr;

uint32_t TCB_STACK[LIMIT_TASK][STACK_SIZE];

uint32_t MILLIS_PRESCALER;

void osSchedulerLaunch();

static void osKernelStackInit(uint32_t index, void(*func)(void*))
{
    main_tcb[index].stackPt = &TCB_STACK[index][STACK_SIZE - NUM_OF_SYS_REG];
    TCB_STACK[index][STACK_SIZE - 1] = 0x01000000; /* PSR set thumb bit*/
    TCB_STACK[index][STACK_SIZE - 2] = (uint32_t) (func);
}

void osKernelInit()
{
    __disable_irq();
    MILLIS_PRESCALER = (BUS_FREQ/1000);
}

void osKernelAddThreads(void(*task0)(void*),
                        void(*task1)(void*),
                        void(*task2)(void*))
{
    __disable_irq();
    // Add task0
    main_tcb[0].next = &main_tcb[1];
    osKernelStackInit(0, task0);
    // Add task1
    main_tcb[1].next = &main_tcb[2];
    osKernelStackInit(1, task1);
    // Add task2
    main_tcb[2].next = &main_tcb[0];
    osKernelStackInit(2, task2);

    tcb_curr = &main_tcb[0];
    __enable_irq();

}

void osKernelLaunch(uint32_t time)
{
    /* Setup systick*/
    SysTick_Type *pSysTick = (SysTick_Type*)SysTick_BASE;
    // pSysTick->CALIB = 
    pSysTick->CTRL = SYSTICK_CTRL_COUNTER_EN | 
                    SYSTICK_CTRL_TICKINIT_EN |
                    SYSTICK_CTRL_CLKSRC_PROCESSOR;
    pSysTick->LOAD = time * MILLIS_PRESCALER - 1;
    pSysTick->VAL = 0;
    osSchedulerLaunch(); 
}






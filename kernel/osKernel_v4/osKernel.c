/******************************************************************************/
/*! @addtogroup Group2
    @file       osKernel.c
    @brief      
    @date       2023/09/25
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/

#include "osKernel.h"

#define SYSTICK_CTRL_ENB        0
#define SYSTICK_CTRL_TICKINT    1
#define SYSTICK_CTRL_CLKSOURCE  2
#define SYSTICK_CTRL_COUNTFLAG  16

#define SYSTICK_CTRL_COUNTER_EN         (1 << SYSTICK_CTRL_ENB)
#define SYSTICK_CTRL_COUNTER_DIS        (0 << SYSTICK_CTRL_ENB)
#define SYSTICK_CTRL_TICKINIT_EN        (1 << SYSTICK_CTRL_TICKINT)
#define SYSTICK_CTRL_TICKINIT_DIS       (0 << SYSTICK_CTRL_TICKINT)
#define SYSTICK_CTRL_CLKSRC_PROCESSOR   (1 << SYSTICK_CTRL_CLKSOURCE)
#define SYSTICK_CTRL_CLKSRC_EXTERNAL    (0 << SYSTICK_CTRL_CLKSOURCE)


#define BUS_FREQ    64000000

#define NUM_OF_THREADS  3
#define STACK_SIZES     100

/* block control for thread*/
tcb_t main_tcb[NUM_OF_THREADS];
/* block control excuting thread */
tcb_t *tcb_curr;

int32_t TCB_STACK[NUM_OF_THREADS][STACK_SIZES];
/* systick parameters */
uint32_t MILLIS_PRESCALER;

void osSchedulerLaunch();

void osKernelStackInit(int index, void (*func)(void))
{
    main_tcb[index].stackPt = &TCB_STACK[index][STACK_SIZES - 16];  // 
    TCB_STACK[index][STACK_SIZES - 1] = 0x01000000;                 // xPSR register
    TCB_STACK[index][STACK_SIZES - 2] = (int32_t)(func);            // PC register
}

void osKernelInit(void)
{
    __disable_irq();
    MILLIS_PRESCALER = (BUS_FREQ/1000);
}

void osKernelAddThread( void(*task0)(*void),
                        void(*task1)(*void),
                        void(*task2)(*void))
{
    __disable_irq();
    
    /* Thread 0 */
    main_tcb[0].nextPt = &main_tcb[1];
    osKernelStackInit(0, task0);
    /* Thread 1 */
    main_tcb[1].nextPt = &main_tcb[2];
    osKernelStackInit(1, task1);
    /* Thread 2 */
    main_tcb[2].nextPt = &main_tcb[0];
    osKernelStackInit(2, task2);

    // set tcb current 
    tcb_curr = &main_tcb[0];

    __enable_irq();
}

void osKernelLaunch(int quatan)
{
    /* setup systick */
    SysTick_Type *pSysTick = SysTick_BASE;
    // pSysTick->CALIB = 
    pSysTick->CTRL = SYSTICK_CTRL_COUNTER_EN | 
                    SYSTICK_CTRL_TICKINIT_EN |
                    SYSTICK_CTRL_CLKSRC_PROCESSOR;
    pSysTick->LOAD = quatan * MILLIS_PRESCALER - 1;
    pSysTick->VAL = 0;
    osSchedulerLaunch();
}








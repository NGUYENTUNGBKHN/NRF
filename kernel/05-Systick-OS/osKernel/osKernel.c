#include "osKernel.h"

#define NUM_OF_SYS_REG  16
#define NUM_OF_THREADS  3
#define STACK_SIZE      100

tcb_t m_tcb[NUM_OF_THREADS];

tcb_t *tcb_curr;

int32_t TCB_STACK[NUM_OF_THREADS][STACK_SIZE];

uint32_t MILLIS_PRESCALER;

void osSchedulerLaunch();


void osKernelStackInit(int index, void (*func)(void*))
{
     // stack pointer assign to array thread control block
    m_tcb[index].stackPt = &TCB_STACK[index][STACK_SIZE - NUM_OF_SYS_REG]; 
    TCB_STACK[index][STACK_SIZE - 1] = 0x01000000;                          
    TCB_STACK[index][STACK_SIZE - 2] = (int32_t) (func);
}

void osKernelInit(void)
{
    __disable_irq();
    MILLIS_PRESCALER = (BUS_FREQ/1000);
}

void osKernelAddThreads(void(*task0)(void*),
                        void(*task1)(void*),
                        void(*task2)(void*))
{
    __disable_irq();
    /* TASK 0 */
    m_tcb[0].next = &m_tcb[1];
    osKernelStackInit(0, task0);
    /* TASK 1 */
    m_tcb[1].next = &m_tcb[2];
    osKernelStackInit(0, task1);
    /* TASK 2 */
    m_tcb[2].next = &m_tcb[0];
    osKernelStackInit(0, task2);


    tcb_curr = &m_tcb[0];
    __enable_irq();
}

void osKernelLaunch(int quatan)
{
    /* Setup systick*/
    SysTick_Type *pSysTick = (SysTick_Type*)SysTick_BASE;
    // pSysTick->CALIB = 
    pSysTick->CTRL = SYSTICK_CTRL_COUNTER_EN | 
                    SYSTICK_CTRL_TICKINIT_EN |
                    SYSTICK_CTRL_CLKSRC_PROCESSOR;
    pSysTick->LOAD = quatan * MILLIS_PRESCALER - 1;
    pSysTick->VAL = 0;
    osSchedulerLaunch();       

}

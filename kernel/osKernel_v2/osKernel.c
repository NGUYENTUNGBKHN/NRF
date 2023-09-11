#include "osKernel.h"


#define SYSPRI3         (*(volatile uint32_t*)0xE000ED20)
#define SYSPRI3_SYSTICK_POS         24

#define NUM_OF_THREADS  3
#define STACKSIZE       100

#define BUS_FREQ 16000000

// systick regiter
#define SYST_CSR_ENABLE     0
#define SYST_CSR_TICKINT    1
#define SYST_CSR_CLKSRC     2
#define SYST_CSR_CNTFLAG    16

uint32_t MILLIS_PRESCALER;

tcb_t m_tcb[NUM_OF_THREADS];
tcb_t *tcb_current;

int32_t TCB_STACK[NUM_OF_THREADS][STACKSIZE];

void osSchedulerLaunch(void);

void osKernelStackInit(int i)
{
    m_tcb[i].stackPt = &TCB_STACK[i][STACKSIZE - 16];
    TCB_STACK[i][STACKSIZE - 1] = 0x01000000;
}


void osKernelInit(void)
{
    __disable_irq();
    MILLIS_PRESCALER = (BUS_FREQ/1000);
}

uint8_t osKernelAddThreads(void(*task0)(void),
                            void(*task1)(void),
                            void(*task2)(void))
{
    // turn off interrupt
    __disable_irq();

    m_tcb[0].nextPt = &m_tcb[1];
    m_tcb[1].nextPt = &m_tcb[2];
    m_tcb[2].nextPt = &m_tcb[0];

    // init stack control block
    osKernelStackInit(0);
    osKernelStackInit(1);
    osKernelStackInit(2);
    // set fucntion -> PC register
    TCB_STACK[0][STACKSIZE - 2] = (int32_t)(task0);
    TCB_STACK[1][STACKSIZE - 2] = (int32_t)(task1);
    TCB_STACK[2][STACKSIZE - 2] = (int32_t)(task2);

    // init tcb_currrent
    tcb_current = &m_tcb[0];

    // turn on interrupt
    __enable_irq();
}

void osKernelLaunch(uint32_t quanta)
{
    SysTick_Type *sys = SysTick;

     sys->CTRL = (uint32_t)((1 << SYST_CSR_ENABLE) |
                            (1 << SYST_CSR_TICKINT) |
                            (1 << SYST_CSR_CLKSRC));
    sys->VAL = 0;
    sys->LOAD = (quanta * MILLIS_PRESCALER) - 1;

    SYSPRI3 = (SYSPRI3&0x00FFFFFF) | (0xE0 << SYSPRI3_SYSTICK_POS);
    osSchedulerLaunch();

}



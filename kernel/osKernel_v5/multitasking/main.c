/******************************************************************************/
/*! @addtogroup Group2
    @file       main.c
    @brief      
    @date       2024/03/18
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/


#include "stdint.h"
#include "log.h"
// #include "context_sw.h"
#include "mul.h"


#define STACK_SIZE 256
#define LIMIT_TASK 2

/* exception return non-floating-point */
#define HANDLER_MSP 0xFFFFFFF1
#define THREAD_MSP  0xFFFFFFF9
#define THREAD_PSP  0xFFFFFFFD

void thread_init()
{
    uint32_t empty[32];
    init_kernel(empty + 32);
}

uint32_t *create_thread(uint32_t *stack, void(*func)(void*))
{
    stack += STACK_SIZE - 17; /* 17 register r0 -> psr */
    stack[8] = THREAD_PSP;      /* link return  */
    stack[15] = (uint32_t) func;           /* PC */
    stack[16] = 0x01000000;     /* PSR */

    stack = (stack);

    return stack;
}


void thread1_func(void *p)
{

    logPrintf("thread1 : start \n");
    syscall();
    while (1)
    {
        /* code */
        logPrintf("thread1 : excu \n");
        syscall();
    }
    
}

void thread2_func(void *p)
{

    logPrintf("thread2 : start \n");
    syscall();
    while (1)
    {
        /* code */
        logPrintf("thread2 : excu \n");
        syscall();
    }
    
}


int main()
{
    uint32_t thread_stack[LIMIT_TASK][STACK_SIZE];
    uint32_t *pThread[LIMIT_TASK];
    uint32_t thread_count = 0;
    uint32_t thread_current;

    logInit();
    thread_init();
    logPrintf("main : start \n");

    pThread[0] = create_thread(thread_stack[0], thread1_func);
    thread_count += 1;

    pThread[1] = create_thread(thread_stack[1], thread2_func);
    thread_count += 1;

    logPrintf("\n main : Start multitasking, back to OS till task yield!\n");
    thread_current = 0;

    while(1)
    {
        logPrintf("main : thread next \n");
        pThread[thread_current] = activate(pThread[thread_current]);

        thread_current = (thread_current == (thread_count - 1)) ? 0 : (thread_current + 1);
    }
}





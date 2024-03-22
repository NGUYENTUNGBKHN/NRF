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
#include "context_sw.h"



void task_test()
{
    logPrintf("task test \n");
    logPrintf("User mode step 1 \n");
    syscall();
    while (1)
    {
        /* code */
    }
    
}

int main()
{
    uint32_t thread_stack[256];
    /* r4, r5, r6, r7, r8, r9, r10, r11, lr */
    uint32_t *pThread_stack = &thread_stack[0];
    pThread_stack = pThread_stack + 256 - 16;
    pThread_stack[8] = (uint32_t)&task_test;

    logInit();

    logPrintf("osKernel ver 5 \n");
    logPrintf("Kernel mode step 1 \n");
    pThread_stack = activate(pThread_stack);
    logPrintf("Kernel mode step 2 \n");

    while(1)
    {

    }
}





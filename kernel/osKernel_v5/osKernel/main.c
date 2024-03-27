/******************************************************************************/
/*! @addtogroup Group2
    @file       main.c
    @brief      
    @date       2024/03/25
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/
#include <stdint.h>
#include "log.h"
#include "osKernel.h"

void thread_task0(void *p)
{
    logPrintf("task0 \n");
    while (1)
    {
        /* code */
    }
    
}

void thread_task1(void *p)
{
    logPrintf("task1 \n");
    while (1)
    {
        /* code */
    }
}

void thread_task2(void *p)
{
    logPrintf("task2 \n");
    while (1)
    {
        /* code */
    }
}

int main()
{

    logInit();
    logPrintf("osKernel \n");
    osKernelInit();
    osKernelAddThreads(thread_task0,
                    thread_task1,
                    thread_task2);
    osKernelLaunch(10);
    logPrintf(" start \n");
    while (1)
    {
        /* code */
    }
    
}



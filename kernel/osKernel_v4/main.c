/******************************************************************************/
/*! @addtogroup Group2
    @file       main.c
    @brief      
    @date       2023/09/25
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/


#include "osKernel.h"

static int count0, count1, count2;

void Thread_task0()
{
    while(1)
    {
        count0++;
    }
}

void Thread_task1()
{
    while(1)
    {
        count1++;
    }
}

void Thread_task2()
{   
    while(1)
    {
        count2++;
    }
}

int main()
{
    osKernelInit();
    osKernelAddThread(Thread_task0, Thread_task1, Thread_task2);
    osKernelLaunch(10);

    while(1);
}








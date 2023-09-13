/******************************************************************************/
/*! @addtogroup Group2
    @file       main.c
    @brief      
    @date       2023/09/13
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/

#include "osKernel.h"

#define QUANTAN 10
static uint32_t cout1, cout2, cout3;

void Task0(void)
{
    while(1)
    {
        cout1++;
    }
}

void Task1(void)
{
    while(1)
    {
        cout2++;
    }
}

void Task2(void)
{
    while(1)
    {
        cout3++;
    }
}

int main()
{
    osKernelInit();
    osKernelAddThreads(&Task0, &Task1, &Task2);
    osKernelLaunch(QUANTAN);

    while (1)
    {
        /* code */
    }  
}







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
    while (1)
    {
        /* code */
    }
    
}

int main()
{
    logInit();

    logPrintf("osKernel ver 5 \n");

    activate((uint32_t*)&task_test);

    while(1)
    {

    }

    return 0;
}





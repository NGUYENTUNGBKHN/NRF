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

int main()
{

    logInit();
    logPrintf("osKernel \n");
    

    while (1)
    {
        /* code */
    }
    
}



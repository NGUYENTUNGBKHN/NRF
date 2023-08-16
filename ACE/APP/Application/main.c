/******************************************************************************/
/*! @addtogroup Group2
    @file       main.c
    @brief      
    @date       2023/06/20
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/
#include "main.h"

#define APP_ADDRESS 0x000E0000

int main()
{
    SCB->VTOR = APP_ADDRESS;
    log_init();
    log_print("application\n");
    log_print("NGUYEN THANH TUNG\n");   
    // after hardware Init

    while (1)
    {
        /* code */
    }
}



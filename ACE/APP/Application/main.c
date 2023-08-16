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

#define APP_ADDRESS 0x100000

int main()
{
    // SCB->VTOR = APP_ADDRESS;
    SEGGER_RTT_printf(0, "Application\n");
    log_init();
    log_print("Bootloader\n");
    log_print("NGUYEN THANH TUNG\n");   
    // after hardware Init

    while (1)
    {
        /* code */
    }
}



/******************************************************************************/
/*! @addtogroup Group2
    @file       startup.c
    @brief      
    @date       2024/03/18
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/

#include "stdint.h"

extern uint32_t _estack;
extern void main();

void Reset_Handler()
{
    main();
}



_attribute((section(".isr_vector")))
uint32_t *__isr_vector[] = 
{
    (uint32_t*) &_estack,
    (uint32_t*) Reset_Handler,
    (uint32_t*) 0,
}




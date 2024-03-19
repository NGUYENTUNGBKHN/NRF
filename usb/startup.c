/******************************************************************************/
/*! @addtogroup Group2
    @file       startup.c
    @brief      
    @date       2024/03/12
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/
#include "stdint.h"

extern uint32_t _estack;
extern int main();

void Reset_Handler(void)
{

    main();
}

void NMI_Handler()
{
    while(1);
}

void Hardfault_Handler()
{
    while(1);
}


__attribute((section(".isr_vector")))
uint32_t *p_isr_vector[] = {
    (uint32_t*)(&_estack),
    (uint32_t*) Reset_Handler,
};






/******************************************************************************/
/*! @addtogroup Group2
    @file       context_sw.c
    @brief      
    @date       2024/03/19
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/
#include "context_sw.h"

void activate(uint32_t *stack)
{
    // __asm volatile ("msr ip, psr");
    __asm volatile ("push {r4, r5, r6, r7, r8, r9, r10, r11, ip, lr}");
    __asm ("mrs psp, r0" : "=r"(stack) ::);
    __asm volatile ("movs r0, #3");
    __asm volatile ("msr control, r0");
    __asm volatile ("pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}");
    __asm volatile ("bx lr");
}




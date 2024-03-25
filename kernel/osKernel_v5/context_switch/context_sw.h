/******************************************************************************/
/*! @addtogroup Group2
    @file       context_sw.h
    @brief      
    @date       2024/03/19
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/


#ifndef _CONTEXT_SW_H_
#define _CONTEXT_SW_H_
#ifdef __cplusplus
extern "C"
{
#endif

#include "stdint.h"
/* CODE */
extern uint32_t *activate(uint32_t *stack);
extern void task_init_env(uint32_t *stack);
extern void syscall();


#ifdef __cplusplus
}
#endif
#endif




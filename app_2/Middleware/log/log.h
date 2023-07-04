/******************************************************************************/
/*! @addtogroup Group2
    @file       log.h
    @brief      
    @date       2023/06/29
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/


#ifndef _LOG_H_
#define _LOG_H_
#ifdef __cplusplus
extern "C"
{
#endif

#include "common.h"
#include "nrf52_eval_kit.h"
#include "drv_uart.h"

/* CODE */
app_error_t log_init();

void log_print(char *format, ...);

#ifdef __cplusplus
}
#endif
#endif

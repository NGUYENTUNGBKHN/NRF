/******************************************************************************/
/*! @addtogroup Group2
    @file       log.c
    @brief      
    @date       2023/06/29
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/

#include "log.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

app_error_t log_init()
{
    // drv_uart_config();
    return APP_ERROR_OK;
}

void log_print(char *format, ...)
{
    char str[80];

    va_list args;
    va_start(args, format);
    vsprintf(str, format, args);

    va_end(args);
}


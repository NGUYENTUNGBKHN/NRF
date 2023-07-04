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

#define LOG_ONOFF 1
static bool flag_log_init = false;

void log_uart_handle(uint32_t event, void *mess)
{
    switch (event)
    {
    case DRV_UART_EVT_TX:
        break;
    case DRV_UART_EVT_RX:
        break;
    case DRV_UART_EVT_ERR:
        break;
    default:
        break;
    }
}

app_error_t log_init()
{
    app_error_t err;
    drv_uart_config(DRV_UART_INSTAN_0,
                    DRV_UART_BAUDRATE_115200, 
                    DRV_UART_HWFC_DIS,
                    ACE_KIT_DEBUG_TX,
                    ACE_KIT_DEBUG_RX,
                    0,
                    0);
    err = drv_uart_init(DRV_UART_INSTAN_0,log_uart_handle);
    if (err == APP_ERROR_FAIL || err == APP_ERROR_EXISTED)
    {
        return APP_ERROR_FAIL;
    }
    flag_log_init = true;
    return APP_ERROR_OK;
}

void log_print(char *format, ...)
{
    if (!flag_log_init)
    {
        return ;
    }
    char str[80];

    va_list args;
    va_start(args, format);
    vsprintf(str, format, args);
#if LOG_ONOFF
    drv_uart_transmit(DRV_UART_INSTAN_0, (uint8_t*)str, strlen(str));
#endif // LOG_ONOFF
    va_end(args);
}


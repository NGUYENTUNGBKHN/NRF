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

#define LOG_USE_UART
#undef LOG_USE_SEGGER_RTT
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

sta_code_t log_init()
{
#ifdef LOG_USE_SEGGER_RTT

#else
    sta_code_t err;
    drv_uart_config(DRV_UART_INSTAN_0,
                    DRV_UART_BAUDRATE_115200, 
                    DRV_UART_HWFC_DIS,
                    ACE_KIT_DEBUG_TX,
                    ACE_KIT_DEBUG_RX,
                    0,
                    0);
    err = drv_uart_init(DRV_UART_INSTAN_0,log_uart_handle);
    if (err == STA_CODE_FAIL || err == STA_CODE_EXISTED)
    {
        SEGGER_RTT_printf(0, "ERROR %s %d code = %d \n",__func__,__LINE__, err);
        return STA_CODE_FAIL;
    }
    
#endif // LOG_USE_SEGGER_RTT
    flag_log_init = true;
    return STA_CODE_OK;
}

void log_print(const char *format, ...)
{
    if (!flag_log_init)
    {
        return ;
    }
#ifdef LOG_USE_SEGGER_RTT  
    // SEGGER_RTT_printf();
#else
    
    char str[80];

    va_list args;
    va_start(args, format);
    vsprintf(str, format, args);
#ifdef LOG_USE_UART
    drv_uart_transmit(DRV_UART_INSTAN_0, (uint8_t*)str, strlen(str));
#endif // LOG_USE_UART
    va_end(args);
#endif // LOG_USE_SEGGER_RTT
}


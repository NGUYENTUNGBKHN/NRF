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
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

// create driver uart instance

void error_hander();

void uart_init();
void send_data(uint8_t *data, uint8_t len, uint32_t timeout);

void logPrint(char *format, ...)
{
    char str[80];

    va_list args;
    va_start(args, format);
    vsprintf(str, format, args);
    send_data((uint8_t*)str, strlen(str), 100);
    va_end(args);
}

int main()
{
    uart_init();
    logPrint("bootloader\n");
    logPrint("NGUYEN THANH TUNG\n");
    while (1)
    {
        /* code */
        

    }
}



void uart_init()
{
    
}

void send_data(uint8_t *data, uint8_t len, uint32_t timeout)
{
    nrf_drv_uart_tx(&uart_instance, data, len);
    while(nrf_drv_uart_tx_in_progress(&uart_instance))
    {

    }
}

void error_hander()
{
    while (1)
    {

    }

}



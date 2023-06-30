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
static nrf_drv_uart_t uart_instance = NRF_DRV_UART_INSTANCE(APP_UART_DRIVER_INSTANCE);
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

 void uart_handler(nrf_drv_uart_event_t * p_event, void * p_context)
 {
    switch (p_event->type)
    {
    case NRF_DRV_UART_EVT_TX_DONE:
        break;
    case NRF_DRV_UART_EVT_RX_DONE:
        break;
    case NRF_DRV_UART_EVT_ERROR;
        break;
    default:
        break;
    }
 }

void uart_init()
{
    ret_code_t err;
    nrf_drv_uart_config_t uart_config;

    uart_config.baudrate = NRF_UART_BAUDRATE_115200;
    uart_config.hwfc = NRF_UART_HWFC_DISABLED;
    uart_config.parity = NRF_UART_PARITY_EXCLUDED;
    uart_config.pseltxd = TX_PIN_NUMBER;
    uart_config.pselrxd = RX_PIN_NUMBER;
    uart_config.interrupt_priority = 7;

    err = nrf_drv_uart_init(&uart_instance, &uart_config, uart_handler);
    if (err != NRF_SUCCESS)
    {
        error_hander();
    }
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



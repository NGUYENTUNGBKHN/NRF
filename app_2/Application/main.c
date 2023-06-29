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

// create driver uart instance
static nrf_drv_uart_t uart_instance = NRF_DRV_UART_INSTANCE(APP_UART_DRIVER_INSTANCE);

int main()
{
    while (1)
    {
        /* code */
        

    }
    return 0;
}


void uart_init()
{
    ret_code_t err;
    nrf_drv_uart_config_t uart_config;

    uart_config.baudrate = ;
    uart_config.hwfc = ;
    uart_config.p_context = ;
    uart_config.parity = ;

    err = nrf_drv_uart_init(uart_instance, uart_config);


}





/******************************************************************************/
/*! @addtogroup Group2
    @file       drv_uart.c
    @brief      
    @date       2023/06/29
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/
#include "drv_uart.h"

static nrf_drv_uart_t uart_instance0 = NRF_DRV_UART_INSTANCE(DRV_UART_INSTAN_0);
static nrf_drv_uart_t uart_instance1 = NRF_DRV_UART_INSTANCE(DRV_UART_INSTAN_1);


 void drv_uart_handler(nrf_drv_uart_event_t * p_event, void * p_context)
 {
    switch (p_event->type)
    {
    case NRF_DRV_UART_EVT_TX_DONE:
        break;
    case NRF_DRV_UART_EVT_RX_DONE:
        break;
    case NRF_DRV_UART_EVT_ERROR:
        break;
    default:
        break;
    }
 }

app_error_t drv_uart_init(drv_uart_t *drv_uart, drv_uart_instance_t inst_no)
{
    if (drv_uart == NULL)
    {
        return APP_ERROR_FAIL;
    }

    if (inst_no < DRV_UART_INSTAN_MIN || inst_no >= DRV_UART_INSTAN_MAX)
    {
        return APP_ERROR_FAIL;
    }

    ret_code_t err;
    

    drv_uart->uart_config.baudrate = NRF_UART_BAUDRATE_115200;
    drv_uart->uart_config.hwfc = NRF_UART_HWFC_DISABLED;
    drv_uart->uart_config.parity = NRF_UART_PARITY_EXCLUDED;
    drv_uart->uart_config.pseltxd = TX_PIN_NUMBER;
    drv_uart->uart_config.pselrxd = RX_PIN_NUMBER;
    drv_uart->uart_config.interrupt_priority = 7;

    if (inst_no == DRV_UART_INSTAN_0)
    {
        drv_uart->drv_inst = uart_instance0;
    }
    else
    {
        drv_uart->drv_inst = uart_instance1;
    }
    

    err = nrf_drv_uart_init(&drv_uart->drv_inst, &drv_uart->uart_config, drv_uart_handler);
    if (err != NRF_SUCCESS)
    {
        return APP_ERROR_FAIL;
    }
}

void drv_uart_deInit()
{

}

void drv_uart_transmit()
{

}

void drv_uart_received()
{
    
}

bool drv_uart_isOpen(drv_uart_t *drv_uart)
{    
    if (drv_uart == NULL)
    {
        //TODO: add error
        return FALSE;
    }
    return drv_uart->drv_sta;
}


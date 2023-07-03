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

static nrf_drv_uart_t uart_instance0 = NRF_DRV_UART_INSTANCE(0);
static nrf_drv_uart_t uart_instance1 = NRF_DRV_UART_INSTANCE(1);

static drv_uart_t drv_uart_0;
static drv_uart_t drv_uart_1;

static bool drv_uart_isOpen(drv_uart_t *drv_uart);


static void drv_uart_handler(nrf_drv_uart_event_t *p_event, void *p_context)
{
    switch (p_event->type)
    {
    case NRF_DRV_UART_EVT_TX_DONE:
        if (drv_uart_0.uart_handle != NULL)
        {
            drv_uart_0.uart_handle(DRV_UART_EVT_TX, NULL);
        }
        if (drv_uart_1.uart_handle != NULL)
        {
            drv_uart_1.uart_handle(DRV_UART_EVT_TX, NULL);
        }
        break;
    case NRF_DRV_UART_EVT_RX_DONE:
        if (drv_uart_0.uart_handle != NULL)
        {
            drv_uart_0.uart_handle(DRV_UART_EVT_RX, NULL);
        }
        if (drv_uart_1.uart_handle != NULL)
        {
            drv_uart_1.uart_handle(DRV_UART_EVT_RX, NULL);
        }
        break;
    case NRF_DRV_UART_EVT_ERROR:
        if (drv_uart_0.uart_handle != NULL)
        {
            drv_uart_0.uart_handle(DRV_UART_EVT_ERR, NULL);
        }
        if (drv_uart_1.uart_handle != NULL)
        {
            drv_uart_1.uart_handle(DRV_UART_EVT_ERR, NULL);
        }
        break;
    default:
        break;
    }
}

void drv_uart_config(drv_uart_instance_t inst_no,
                    drv_uart_baudrate_t baudrate,
                    drv_uart_hwfc_t hwFc,
                    uint32_t tx_pin,
                    uint32_t rx_pin,
                    uint32_t cts_pin,
                    uint32_t rts_pin)
{
    if (inst_no == DRV_UART_INSTAN_0)
    {
        drv_uart_0.drv_inst = uart_instance0;
        drv_uart_0.uart_config.baudrate = baudrate;
        drv_uart_0.uart_config.hwfc = hwFc;
        drv_uart_0.uart_config.parity = NRF_UART_PARITY_EXCLUDED;
        drv_uart_0.uart_config.pseltxd = tx_pin;
        drv_uart_0.uart_config.pselrxd = rx_pin;
        drv_uart_0.uart_config.pselcts = cts_pin;
        drv_uart_0.uart_config.pselrts = rts_pin;
    }
    else
    {
        drv_uart_1.drv_inst = uart_instance1;
        drv_uart_1.uart_config.baudrate = baudrate;
        drv_uart_1.uart_config.hwfc = hwFc;
        drv_uart_1.uart_config.parity = NRF_UART_PARITY_EXCLUDED;
        drv_uart_1.uart_config.pseltxd = tx_pin;
        drv_uart_1.uart_config.pselrxd = rx_pin;
        drv_uart_1.uart_config.pselcts = cts_pin;
        drv_uart_1.uart_config.pselrts = rts_pin;
    }
}

app_error_t drv_uart_init(drv_uart_instance_t inst_no, drv_uart_hanlde_t drv_uart_handle)
{
    if (drv_uart_handle == NULL)
    {
        return APP_ERROR_FAIL;
    }

    if (inst_no < DRV_UART_INSTAN_MIN || inst_no >= DRV_UART_INSTAN_MAX)
    {
        return APP_ERROR_FAIL;
    }

    ret_code_t err;
    drv_uart_t *temp;
    

    if (inst_no == DRV_UART_INSTAN_0)
    {
        temp = &drv_uart_0;
    }
    else
    {
        temp = &drv_uart_1;
    }

     // check uart open?
    if (drv_uart_isOpen(temp))
    {
        return APP_ERROR_FAIL;
    }

    temp->uart_handle = drv_uart_handle;
    temp->drv_sta = true;

    err = nrf_drv_uart_init(&temp->drv_inst, &temp->uart_config, drv_uart_handler);
    if (err != NRF_SUCCESS)
    {
        temp->drv_sta = false;
        return APP_ERROR_FAIL;
    }
    return APP_ERROR_OK;
}

void drv_uart_deInit()
{

}

app_error_t drv_uart_transmit(drv_uart_instance_t inst_no, uint8_t *data, uint8_t len)
{
    drv_uart_t *temp;

    if (inst_no == DRV_UART_INSTAN_0)
    {
        temp = &drv_uart_0;
    }
    else
    {
        temp = &drv_uart_1;
    }

    // check uart open?
    if (drv_uart_isOpen(temp))
    {
        return APP_ERROR_FAIL;
    }
    nrf_drv_uart_tx(&temp->drv_inst, data, len);
    while(nrf_drv_uart_tx_in_progress(&temp->drv_inst))
    {

    }
    return APP_ERROR_OK;
}

void drv_uart_received()
{
    
}

static bool drv_uart_isOpen(drv_uart_t *drv_uart)
{    
    if (drv_uart == NULL)
    {
        //TODO: add error
        return false;
    }
    return drv_uart->drv_sta;
}


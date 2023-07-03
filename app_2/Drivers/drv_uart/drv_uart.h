/******************************************************************************/
/*! @addtogroup Group2
    @file       drv_uart.h
    @brief      
    @date       2023/06/29
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/
#ifndef _DRV_UART_H_
#define _DRV_UART_H_
#ifdef __cplusplus
extern "C"
{
#endif

#include "common.h"
#include "nrf_drv_uart.h"

#define drv_uart_baudrate_t nrf_uart_baudrate_t 
#define drv_uart_hwfc_t     nrf_uart_hwfc_t

/* CODE */
typedef void (*drv_uart_hanlde_t)(uint32_t event, void *mess);

typedef enum DRV_UART_EVT_E
{
    DRV_UART_EVT_TX,
    DRV_UART_EVT_RX,
    DRV_UART_EVT_ERR
}drv_uart_evt_t;

typedef enum DRV_UART_INSTAN_E
{
    DRV_UART_INSTAN_MIN = 0,
    DRV_UART_INSTAN_0 = DRV_UART_INSTAN_MIN,
    DRV_UART_INSTAN_1,
    DRV_UART_INSTAN_MAX
}drv_uart_instance_t;

typedef enum DRV_UART_STA_E
{
    DRV_UART_STA_ON,
    DRV_UART_STA_OFF
}drv_uart_sta_t;

typedef struct DRV_UART_S
{
    nrf_drv_uart_t drv_inst;
    nrf_drv_uart_config_t uart_config;
    drv_uart_sta_t  drv_sta;
    drv_uart_hanlde_t uart_handle;
}drv_uart_t;

#ifdef __cplusplus
}
#endif
#endif



/******************************************************************************/
/*! @addtogroup Group2
    @file       drv_gpio.h
    @brief      
    @date       2023/06/29
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/

#ifndef _DRV_GPIO_H_
#define _DRV_GPIO_H_
#ifdef __cplusplus
extern "C"
{
#endif

#include "common.h"
#include "nrf_gpio.h"

/* CODE */
typedef struct drv_gpio_cfg_s
{
    uint32_t pin_no;
    uint8_t dir;
    uint8_t pull_mode;
    uint8_t input_buffer;
    uint8_t drive_mode;
    uint8_t pin_sense;
}drv_gpio_cfg_t;


typedef struct drv_gpio_s
{
    drv_gpio_cfg_t cfg;
    
}drv_gpio_t;

#ifdef __cplusplus
}
#endif
#endif


/******************************************************************************/
/*! @addtogroup Group2
    @file       reg.h
    @brief      
    @date       2023/09/13
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/

#ifndef _REG_H_
#define _REG_H_
#ifdef __cplusplus
extern "C"
{
#endif

/* CODE */

typedef struct UartType_s
{
    uint32_t TASKS_STARTRX;     /* Start UART receiver */
    uint32_t TASKS_STOPRX;      /* Stop UART receviver */
    uint32_t TASKS_STARTTX;     /* Start UART transmitter */
    uint32_t TASKS_STOPTX;      /* Stop UART transmitter */
    uint32_t TASKS_SUSPEND;
    uint32_t EMPTY[17];
    uint32_t BAUDRATE;              /* Baud Rate. ACCuracy depends on the HFCLK source selected */
    uint32_t CONFIG;               /* configuration of parity and hardware flow control */
}UartType_t, *UartType_p;


/* UART Register*/
#define UART_BASE_ADDRESS 0x40002000

#define UART_CONFIG_HWFC_POS        0
#define UART_CONFIG_PARITY_POS      3
#define UART_CONFIG_STOP_POS        4 
#define 


#define uart0 (UartType_t*)(UART_BASE_ADDRESS)     



#ifdef __cplusplus
}
#endif
#endif

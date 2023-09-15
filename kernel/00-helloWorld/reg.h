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
#include <stdint.h>


typedef struct UartType_s
{
    uint32_t TASKS_STARTRX;     /* Start UART receiver */
    uint32_t TASKS_STOPRX;      /* Stop UART receviver */
    uint32_t TASKS_STARTTX;     /* Start UART transmitter */
    uint32_t TASKS_STOPTX;      /* Stop UART transmitter */
    uint32_t TASKS_SUSPEND;
    uint32_t EVENTS_CTS;
    uint32_t EVENTS_NCTS;
    uint32_t EVENTS_RXDRDY;
    uint32_t EVENTS_TXDRDY;
    uint32_t EVENTS_ERROR;
    uint32_t EVENTS_RXTO;
    uint32_t SHORTS;
    uint32_t INTENSET;
    uint32_t INTENCLR;
    uint32_t ERRORSRC;
    uint32_t ENABLE;
    uint32_t PSEL_RTS;
    uint32_t PSEL_TXD;
    uint32_t PSEL_CTS;
    uint32_t PSEL_RXD;
    uint32_t RXD;
    uint32_t TXD;
    uint32_t BAUDRATE;              /* Baud Rate. ACCuracy depends on the HFCLK source selected */
    uint32_t CONFIG;               /* configuration of parity and hardware flow control */
}UartType_t, *UartType_p;


/* UART Register*/
#define UART_BASE_ADDRESS 0x40002000

#define UART_CONFIG_HWFC_POS        0
#define UART_CONFIG_PARITY_POS      1
#define UART_CONFIG_STOP_POS        4 

/* interrupt */
#define UART_INTENSET_CTS_POS       0
#define UART_INTENSET_NCTS_POS      1
#define UART_INTENSET_RXDRDY_POS    2
#define UART_INTENSET_TXDRDY_POS    7
#define UART_INTENSET_ERROR_POS     9
#define UART_INTENSET_RXTO_POS      17

#define UART_INTENSET_CTS_EN        (1 << UART_INTENSET_CTS_POS)
#define UART_INTENSET_CTS_DIS       (0 << UART_INTENSET_CTS_POS)
#define UART_INTENSET_NCTS_EN        (1 << UART_INTENSET_NCTS_POS)
#define UART_INTENSET_NCTS_DIS       (0 << UART_INTENSET_NCTS_POS)
#define UART_INTENSET_RXDRDY_EN        (1 << UART_INTENSET_RXDRDY_POS)
#define UART_INTENSET_RXDRDY_DIS       (0 << UART_INTENSET_RXDRDY_POS)
#define UART_INTENSET_TXDRDY_EN        (1 << UART_INTENSET_TXDRDY_POS)
#define UART_INTENSET_TXDRDY_DIS       (0 << UART_INTENSET_TXDRDY_POS)
#define UART_INTENSET_ERROR_EN        (1 << UART_INTENSET_ERROR_POS)
#define UART_INTENSET_ERROR_DIS       (0 << UART_INTENSET_ERROR_POS)
#define UART_INTENSET_RXTO_EN        (1 << UART_INTENSET_RXTO_POS)
#define UART_INTENSET_RXTO_DIS       (0 << UART_INTENSET_RXTO_POS)

/* TXD Register */
#define UART_TXD_PIN_POS            0
#define UART_TXD_PORT_POS           5
#define UART_TXD_CONNECT_POS        31
#define UART_TXD_CONNECT            (1 << UART_TXD_CONNECT_POS)
#define UART_TXD_DISCONNECT         (0 << UART_TXD_CONNECT_POS)

/*RXD Register  */
#define UART_RXD_PIN_POS            0
#define UART_RXD_PORT_POS           5
#define UART_RXD_CONNECT_POS        31
#define UART_RXD_CONNECT            (1 << UART_RXD_CONNECT_POS)
#define UART_RXD_DISCONNECT         (0 << UART_RXD_CONNECT_POS)

/* ENABLE REGITER */
#define UART_ENABLE_REGISTER_EN     0x04
#define UART_ENABLE_REGISTER_DIS    0x00

/* BaudRate */
#define UART_BAUDRATE_1200          0x0004F000
#define UART_BAUDRATE_2400          0x0009D000
#define UART_BAUDRATE_4800          0x0009D000
#define UART_BAUDRATE_9600          0x00275000
#define UART_BAUDRATE_14400         0x003B0000
#define UART_BAUDRATE_19200         0x004EA000
#define UART_BAUDRATE_28800         0x0075F000
#define UART_BAUDRATE_31250         0x00800000
#define UART_BAUDRATE_38400         0x009D5000
#define UART_BAUDRATE_56000         0x00E50000
#define UART_BAUDRATE_57600         0x00EBF000
#define UART_BAUDRATE_76800         0x013A9000
#define UART_BAUDRATE_115200        0x01D7E000
#define UART_BAUDRATE_230400        0x03AFB000
#define UART_BAUDRATE_250000        0x04000000
#define UART_BAUDRATE_460800        0x075F7000
#define UART_BAUDRATE_921600        0x0EBED000
#define UART_BAUDRATE_1M            0x10000000



/* CONFIG REGISTER */
#define UART_CONFIG_HWFC_DIS        (0 << UART_CONFIG_HWFC_POS)
#define UART_CONFIG_HWFC_ENB        (1 << UART_CONFIG_HWFC_POS)
#define UART_CONFIG_PARITY_EXE      (0 << UART_CONFIG_PARITY_POS)
#define UART_CONFIG_PARITY_INC      (0x07 << UART_CONFIG_PARITY_POS)
#define UART_CONFIG_STOP_ONE        (0 << UART_CONFIG_STOP_POS)
#define UART_CONFIG_STOP_TWO        (1 << UART_CONFIG_STOP_POS)


#define uart0 ((UartType_t*) UART_BASE_ADDRESS)     



#ifdef __cplusplus
}
#endif
#endif

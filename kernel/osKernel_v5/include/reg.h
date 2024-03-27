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
#include "nrf52840.h"
#include "cmsis_gcc.h"
#include "core_cm4.h"

/* for Variable */
#define __I     volatile const  /* Only read */
#define __O     volatile        /* Only write */
#define __IO    volatile        /* Read Write */
/* FOr struct member */
#define __IM    volatile const  /* Only read */
#define __OM    volatile        /* Only write */
#define __IOM   volatile        /* Read wirte */


/*---------------- UART -------------------*/
typedef struct UartType_s
{
    __OM  uint32_t TASKS_STARTRX;     /* Start UART receiver */
    __OM  uint32_t TASKS_STOPRX;      /* Stop UART receviver */
    __OM  uint32_t TASKS_STARTTX;     /* Start UART transmitter */
    __OM  uint32_t TASKS_STOPTX;      /* Stop UART transmitter */
    __IM  uint32_t RESERVED[3];       /*  */
    __OM  uint32_t TASKS_SUSPEND;     /* Suspend UART */
    __IM  uint32_t RESERVED1[56];
    __IOM uint32_t EVENTS_CTS;        /* CTS is activated (set low). Clear to Send. */
    __IOM uint32_t EVENTS_NCTS;       /* CTS is deactivated (set high). Not Clear to Send. */
    __IOM uint32_t EVENTS_RXDRDY;     /* Data received in RXD */
    __IM  uint32_t RESERVED2[4];
    __IOM uint32_t EVENTS_TXDRDY;     /* Data sent from TXD */
    __IM  uint32_t RESERVED3;
    __IOM uint32_t EVENTS_ERROR;      /* Error detected */
    __IM  uint32_t RESERVED4[7];
    __IOM uint32_t EVENTS_RXTO;       /* Receiver timeout */
    __IM  uint32_t RESERVED5[46];
    __IOM uint32_t SHORTS;            /* Shortcuts between local events and tasks */
    __IM  uint32_t RESERVED6[64];
    __IOM uint32_t INTENSET;          /* Enable interrupt */
    __IOM uint32_t INTENCLR;          /* Disable interrupt */
    __IM  uint32_t RESERVED7[93];
    __IOM uint32_t ERRORSRC;          /* Error Source */
    __IM  uint32_t RESERVED8[31];
    __IOM uint32_t ENABLE;            /* Enable UART */
    __IM  uint32_t RESERVED9;
    __IOM uint32_t PSEL_RTS;          /* Pin select for RTS */
    __IOM uint32_t PSEL_TXD;          /* Pin select for TXD */
    __IOM uint32_t PSEL_CTS;          /* Pin select for CTS */
    __IOM uint32_t PSEL_RXD;          /* Pin select for RXD */
    __IM  uint32_t RXD;               /* RXD register */
    __IOM uint32_t TXD;               /* TXD register */
    __IM  uint32_t RESERVED10;
    __IOM uint32_t BAUDRATE;          /* Baud Rate. ACCuracy depends on the HFCLK source selected */
    __IM  uint32_t RESERVED11[17];
    __IOM uint32_t CONFIG;            /* configuration of parity and hardware flow control */
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
#define UART_INTENSET_NCTS_EN       (1 << UART_INTENSET_NCTS_POS)
#define UART_INTENSET_NCTS_DIS      (0 << UART_INTENSET_NCTS_POS)
#define UART_INTENSET_RXDRDY_EN     (1 << UART_INTENSET_RXDRDY_POS)
#define UART_INTENSET_RXDRDY_DIS    (0 << UART_INTENSET_RXDRDY_POS)
#define UART_INTENSET_TXDRDY_EN     (1 << UART_INTENSET_TXDRDY_POS)
#define UART_INTENSET_TXDRDY_DIS    (0 << UART_INTENSET_TXDRDY_POS)
#define UART_INTENSET_ERROR_EN      (1 << UART_INTENSET_ERROR_POS)
#define UART_INTENSET_ERROR_DIS     (0 << UART_INTENSET_ERROR_POS)
#define UART_INTENSET_RXTO_EN       (1 << UART_INTENSET_RXTO_POS)
#define UART_INTENSET_RXTO_DIS      (0 << UART_INTENSET_RXTO_POS)

/* TXD Register */
#define UART_TXD_PIN_POS            0
#define UART_TXD_PORT_POS           5
#define UART_TXD_CONNECT_POS        31
#define UART_TXD_CONNECT            (0 << UART_TXD_CONNECT_POS)
#define UART_TXD_DISCONNECT         (1 << UART_TXD_CONNECT_POS)

/*RXD Register  */
#define UART_RXD_PIN_POS            0
#define UART_RXD_PORT_POS           5
#define UART_RXD_CONNECT_POS        31
#define UART_RXD_CONNECT            (0 << UART_RXD_CONNECT_POS)
#define UART_RXD_DISCONNECT         (1 << UART_RXD_CONNECT_POS)

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
/*---------------- UART -------------------*/

/*---------------- SYSTICK ----------------*/
#define BUS_FREQ    64000000

#define SYSTICK_CTRL_ENB        0
#define SYSTICK_CTRL_TICKINT    1
#define SYSTICK_CTRL_CLKSOURCE  2
#define SYSTICK_CTRL_COUNTFLAG  16

#define SYSTICK_CTRL_COUNTER_EN         (1 << SYSTICK_CTRL_ENB)
#define SYSTICK_CTRL_COUNTER_DIS        (0 << SYSTICK_CTRL_ENB)
#define SYSTICK_CTRL_TICKINIT_EN        (1 << SYSTICK_CTRL_TICKINT)
#define SYSTICK_CTRL_TICKINIT_DIS       (0 << SYSTICK_CTRL_TICKINT)
#define SYSTICK_CTRL_CLKSRC_PROCESSOR   (1 << SYSTICK_CTRL_CLKSOURCE)
#define SYSTICK_CTRL_CLKSRC_EXTERNAL    (0 << SYSTICK_CTRL_CLKSOURCE)
/*---------------- SYSTICK -----------------*/
/* CONTROL REGISTER */
#define CTRL_INITERRUPT                (*((volatile uint32_t*) 0xE000ED04))
#define SYSTICK_SET_POS         26
/* */

/* GPIO */

#define GPIO_PORT0_BASE     0x50000000
#define GPIO_PORT1_BASE     0x50000300
#define GPIO_PORT_OFFSET    0x504
#define GPIO_PORT0_ADDR     GPIO_PORT0_BASE + GPIO_PORT_OFFSET
#define GPIO_PORT1_ADDR     GPIO_PORT1_BASE + GPIO_PORT_OFFSET

typedef struct GPIO_PIN_TYPE_S
{
    __IOM uint32_t DIR          : 1;
    __IOM uint32_t INPUT        : 1;
    __IOM uint32_t PULL         : 2;
    __IOM uint32_t reserved1    : 4;
    __IOM uint32_t DRIVE        : 3;
    __IOM uint32_t reserved2    : 5;
    __IOM uint32_t SENSE        : 2;
    __IOM uint32_t reserved3    : 14;
}GpioPinType_t, *GpioPinType_p;

typedef struct GPIO_PORT_TYPE_S
{
    __IM  uint32_t reserved0[321];      // 0x000 - 0x500
    __IOM uint32_t OUT;                 // write gpio port
    __IOM uint32_t OUTSET;              // set individual bits in gpio port
    __IOM uint32_t OUTCLR;              // clear individual bits in gpio port
    __IM  uint32_t IN;                  // Read gpio port
    __IOM uint32_t DIR;                 // direction of gpio port
    __IOM uint32_t DIRSET;              // dir set register
    __IOM uint32_t DIRCLR;              // dir clear register
    __IOM uint32_t LATCH;               // latch register indicating what gpio pins that have met the criteria set in the PIN_CNF[n].SENSE register
    __IOM uint32_t DETECTMODE;          // select between default DETECT signal behavior and LDETECT mode
    __IOM uint32_t Reserved1[118];      // 0x528 - 0x6fc
    __IOM GpioPinType_t PIN_CNF[32];    // Config of gpio pins
}GpioPortType_t, *GpioPortType_p;

#define port0   ((GpioPortType_t*)(GPIO_PORT0_BASE))
#define port1   ((GpioPortType_t*)(GPIO_PORT1_BASE))

/* ------------------------------------------------ */

/* GPIOTE */
#define GPIOTE_BASE 0x40006000

typedef struct GPIOTE_CONFIG_REG_S
{
    __IOM uint32_t MODE      : 2;
    __IM  uint32_t RESERVED0 : 6;
    __IOM uint32_t PSEL      : 5;
    __IOM uint32_t PORT      : 1;
    __IM  uint32_t RESERVED1 : 2;
    __IOM uint32_t POLARIRY  : 2;
    __IM  uint32_t RESERVED2 : 2;
    __IOM uint32_t OUTINIT   : 1;
    __IM  uint32_t RESERVED3 : 11;
}GpioTECfgReg_t, *GpioTECfgReg_p;

typedef struct GPIOTE_TYPE_S
{
    __IOM uint32_t TASK_OUT[8];
    __IM  uint32_t RESERVED0[4];

    __IOM uint32_t TASK_SET[8];
    __IM  uint32_t RESERVED1[4];
    
    __IOM uint32_t TASK_CLR[8];
    __IM  uint32_t RESERVED2[4];
    
    __IOM uint32_t EVENTS_IN[8];
    __IM  uint32_t RESERVED3[23];
    
    __IOM uint32_t EVENTS_PORT;
    __IM  uint32_t RESERVED4[97];
    
    __IOM uint32_t INTENSET;
    __IOM uint32_t INTENCLR;
    __IM  uint32_t RESERVED5[129];
    __IOM uint32_t CONFIG[8];
}GpioTEType_t, *GpioTEType_p;

#define gpiote ((GpioTEType_t*) GPIOTE_BASE)

/* ----------------------------------------------- */

/* I2C */

/* ----------------------------------------------- */

/* SPI */

/* ----------------------------------------------- */

/* USBD */
#define USBD_ADDR_BASE  0x40027000



/* ----------------------------------------------- */
#ifdef __cplusplus
}
#endif
#endif

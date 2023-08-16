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

#define APP_ADDRESS 0x00100000

static void jump_to_application();
static void jump_to_bootloader(); 

int main()
{
    log_init();
    log_print("Bootloader\n");
    log_print("NGUYEN THANH TUNG\n");   
    // after hardware Init
    if (1)
    {
        jump_to_application();
    }
    else
    {
        jump_to_bootloader();
    }
    while (1)
    {
        /* code */
    }
}


static void jump_to_application()
{
    void (*reset_handler)();

    uint32_t msp = *(volatile uint32_t*)APP_ADDRESS;


    uint32_t handler_address = *(volatile uint32_t*)(APP_ADDRESS + 4);


    __set_CONTROL(0x00000000);   // Set CONTROL to its reset value 0.
    __set_PRIMASK(0x00000000);   // Set PRIMASK to its reset value 0.
    __set_BASEPRI(0x00000000);   // Set BASEPRI to its reset value 0.
    __set_FAULTMASK(0x00000000); // Set FAULTMASK to its reset value 0.

    __set_MSP(msp);
    reset_handler = (void*)handler_address;

    reset_handler();

}

static void jump_to_bootloader()
{

}


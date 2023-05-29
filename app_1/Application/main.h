#ifndef __MAIN_H__
#define __MAIN_H__

#ifdef __cplusplus
extern "C" {
#endif 


#include "nrf.h"                        // Device header
#include "system_nrf.h"                 // NordicSemiconductor::Device:Startup
#include "system_nrf52840.h"            // NordicSemiconductor::Device:Startup
#include "nrf_drv_uart.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"

#define ABS(a,b) a > b ? a - b : a + (0x0FFFFFFF - b)
	
extern uint32_t systick_Gettick(void);

#ifdef __cplusplus
}
#endif
#endif // __MAIN_H__




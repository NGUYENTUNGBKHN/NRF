#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define RX_PIN_NUMBER 8
#define TX_PIN_NUMBER 6
#define CTS_PIN_NUMBER 7
#define RTS_PIN_NUMBER 5

static nrf_drv_uart_t app_uart_inst = NRF_DRV_UART_INSTANCE(0);
void error_handler(void);
void send_data(uint8_t *data, uint8_t len);
volatile bool done = false;

void logPrint_debug(char *format, ...)
{
    char str[80];

    va_list args;
    va_start(args, format);
    vsprintf(str, format, args);
    send_data((uint8_t*)str, (uint8_t)strlen(str));
    va_end(args);
}

void uart_init(void);

int main()
{
	
	uart_init();

	logPrint_debug("bootloader\n");
	logPrint_debug("NGUYEN THANH TUNG\n");
	while(1);
}

void uart_handler(nrf_drv_uart_event_t * p_event, void * p_context)
{
	switch (p_event->type)
	{
		case NRF_DRV_UART_EVT_TX_DONE:
			done = true;
			break;
		default:
			break;
	}
}


void uart_init(void)
{
	ret_code_t err;
	nrf_drv_uart_config_t m_uart_config;
	
	m_uart_config.baudrate = NRF_UART_BAUDRATE_115200;
	m_uart_config.hwfc = NRF_UART_HWFC_DISABLED;
	m_uart_config.interrupt_priority = 7;
	m_uart_config.parity = NRF_UART_PARITY_EXCLUDED;
	m_uart_config.pselrxd = RX_PIN_NUMBER;
	m_uart_config.pseltxd = TX_PIN_NUMBER;
//	m_uart_config.pselcts = CTS_PIN_NUMBER;
//	m_uart_config.pselrts = RTS_PIN_NUMBER;
	
	err = nrf_drv_uart_init(&app_uart_inst, &m_uart_config, uart_handler);
	if (err != NRF_SUCCESS)
	{
		error_handler();
	}
	
}

void send_data(uint8_t *data, uint8_t len)
{
	done = false;
	nrf_drv_uart_tx(&app_uart_inst, data, len);
	while(!done);
	
}

void error_handler()
{
	while(1);
}



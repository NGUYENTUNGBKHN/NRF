#include "main.h"

volatile static uint32_t utick = 0;

void SysTick_Handler(void)
{
		utick++;
}


uint32_t systick_Gettick(void)
{
		return utick;
}


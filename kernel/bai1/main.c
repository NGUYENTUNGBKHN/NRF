
#include "nrf.h"             // Device header
#include "system_nrf52840.h" // NordicSemiconductor::Device:Startup

#define CNF_POS_A_DIR   0
#define CNF_POS_B_INPUT 1
#define CNF_POS_C_PULL  2
#define CNF_POS_D_DRIVE 8

NRF_GPIO_Type *gpio = NRF_P0;

void timer_init()
{
	NRF_TIMER_Type *timer0 = NRF_TIMER0;

    timer0->PRESCALER = 4;
    timer0->MODE = 0;
    timer0->BITMODE = 3;
    timer0->CC[0] = 1000;
    timer0->INTENSET = 1 << 16;
    timer0->SHORTS = 1;
    
    NVIC_EnableIRQ(TIMER0_IRQn);
    timer0->TASKS_START = 1;
}

void gpio_on()
{
    gpio->OUT |= 0 << 13; 
}

void gpio_off()
{
    gpio->OUT |= 1 << 13; 
}

void gpio_init()
{
    gpio->PIN_CNF[13] = (uint32_t)((1 << CNF_POS_A_DIR) |
                         (1 << CNF_POS_B_INPUT) |
                         (0 << CNF_POS_C_PULL) |
                         (0 << CNF_POS_D_DRIVE));
}

void TIMER0_IRQHandler()
{
    static int count = 1;
    if (NRF_TIMER0->EVENTS_COMPARE[0] == 1)
    {
        NRF_TIMER0->EVENTS_COMPARE[0] = 0;
        count++;
        if (count % 2 == 0)
        {
            gpio_on();
        }
        else
        {
            gpio_off();
        }
    }
}

int main()
{

    gpio_init();
    timer_init();
    

    // gpio->DIR |= 1 << 13;
    
    

    while (1)
    {
        __WFE();
    }
}

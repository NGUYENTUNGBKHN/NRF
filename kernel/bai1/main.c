
#include "nrf.h"             // Device header
#include "system_nrf52840.h" // NordicSemiconductor::Device:Startup

#define CNF_POS_A_DIR 0
#define CNF_POS_B_INPUT 1
#define CNF_POS_C_PULL 2
#define CNF_POS_D_DRIVE 8


#define SYST_CSR_ENABLE    0
#define SYST_CSR_TICKINT    1
#define SYST_CSR_CLKSRC     2
#define SYST_CSR_CNTFLAG    16

NRF_GPIO_Type *gpio = NRF_P0;

uint32_t func1[40];
uint32_t func2[40];

uint32_t *sp_func1 = &func1[40];
uint32_t *sp_func2 = &func2[40]; 

void systick(int time)
{
    SysTick_Type *sys = SysTick;

    sys->CTRL = (uint32_t)((1 << SYST_CSR_ENABLE) |
                            (1 << SYST_CSR_TICKINT) |
                            (1 << SYST_CSR_CLKSRC));
    sys->LOAD = time - 1;
    sys->VAL = 0; 
    NVIC_EnableIRQ(SysTick_IRQn);
}

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
    gpio->OUT &= ~(1 << 13);
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
    static uint8_t onof = 1;
    if (NRF_TIMER0->EVENTS_COMPARE[0] == 1)
    {
        NRF_TIMER0->EVENTS_COMPARE[0] = 0;
        count++;
        if (count % 1000 == 0)
        {
            if (onof)
            {
                onof = 0;
                gpio_off();
            }
            else
            {
                onof = 1;
                gpio_on();
            }
        }
    }
}

void _func1()
{
    while(1)
    {

    }
}

void _func2()
{
    while(1)
    {
        
    }
}

static volatile int cnt = 0;
void SysTick_Handler()
{
    cnt ++;
}

int GetSysTick()
{
    int _tick;
    __disable_irq();
    _tick = cnt;
	__enable_irq();
    return _tick;
}

int main()
{
	
    gpio_init();
    timer_init();
    systick(1000);
    
    *(--sp_func1) = (1 << 24);          // xPSR
    *(--sp_func1) = (uint32_t)&_func1;   // PC
    *(--sp_func1) = 0x0000000DU;        // LR
    *(--sp_func1) = 0x0000000EU;        // R12
    *(--sp_func1) = 0x0000000AU;        // R3
    *(--sp_func1) = 0x0000000EU;        // R2
    *(--sp_func1) = 0x0000000AU;        // R1
    *(--sp_func1) = 0x0000000DU;        // R0

    *(--sp_func2) = (1 << 24);          // xPSR
    *(--sp_func2) = (uint32_t)&_func2;   // PC
    *(--sp_func2) = 0x0000000DU;        // LR
    *(--sp_func2) = 0x0000000EU;        // R12
    *(--sp_func2) = 0x0000000AU;        // R3
    *(--sp_func2) = 0x0000000EU;        // R2
    *(--sp_func2) = 0x0000000AU;        // R1
    *(--sp_func2) = 0x0000000DU;        // R0

    while (1)
    {
        __WFE();
    }
}

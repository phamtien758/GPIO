/*******************************************************************************
 * File  : gpio_test3.c       
 * Author: phamtien758      
 * Brief : Test external interrupt
 ******************************************************************************/

#include "gpio.h"
#include "stub.h"
#include "interrupt.h"

void Button_Handler(Exti_Line_e LineNum_e);

void delay(uint32_t times)
{
    for (uint32_t i = 0; i < times; i++);
}

Gpio_Config ConfigLed = 
{
    .Gpio_PinNum_e       = GPIO_PINNUM_5,      /* Onboard LED2 is on PA_5 pin */
    .Gpio_PinMode_e      = GPIO_MODE_OUT,
    .Gpio_PinSpeed_e     = GPIO_OUTSPEED_LOW,
    .Gpio_PinPuPd_e      = GPIO_PULLUPDOWN_NOPULL,
    .Gpio_PinOutType_e   = GPIO_OUTTYPE_PUSPUL,
    .Gpio_PinAltFun_e    = GPIO_ALTFUN_0,
    .Gpio_ExIntEnable_u8 = DISABLE,
    .Gpio_ExIntEdge_e    = EXTI_EDGE_FALL,
    .Gpio_ExIntCallback  = NULL
};

Gpio_Config ConfigButton = 
{
    .Gpio_PinNum_e       = GPIO_PINNUM_13,     /* User button is on PC_13 pin */
    .Gpio_PinMode_e      = GPIO_MODE_IN,
    .Gpio_PinSpeed_e     = GPIO_OUTSPEED_LOW,
    .Gpio_PinPuPd_e      = GPIO_PULLUPDOWN_NOPULL, /* Choose no register because board has pull-up register already */
    .Gpio_PinOutType_e   = GPIO_OUTTYPE_PUSPUL,
    .Gpio_PinAltFun_e    = GPIO_ALTFUN_0,
    .Gpio_ExIntEnable_u8 = ENABLE,
    .Gpio_ExIntEdge_e    = EXTI_EDGE_RISE,
    .Gpio_ExIntCallback  = Button_Handler
};

int main(void)
{
    RCC_GPIOA_CLK_EN();
    RCC_GPIOC_CLK_EN();
    RCC_SYSCFG_CLK_EN();

    Nvic_EnableIrq(IRQ_NUM_EXTI15_10);
    SYSCFG_EXTI13_ENABLE(SYSCFG_PORT_C);
    Gpio_Init(GPIOA, &ConfigLed);
    Gpio_Init(GPIOC, &ConfigButton);

    while(1);

    return 0;
}

void Button_Handler(Exti_Line_e LineNum_e)
{
    Gpio_TogglePin(GPIOA, GPIO_PINNUM_5);
}
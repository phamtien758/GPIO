/*******************************************************************************
 * File  : gpio_test1.c       
 * Author: phamtien758      
 * Brief : Test Gpio_PinCfgLock function
 ******************************************************************************/

#include "gpio.h"
#include "stub.h"

void delay(uint32_t times)
{
    for (uint32_t i = 0; i < times; i++);
}

Gpio_Config Config1 = 
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

int main(void)
{
    ReturnType retValue;
    uint8_t temp;

    RCC_GPIOA_CLK_EN();
    RCC_GPIOC_CLK_EN();
    Gpio_Init(GPIOA, &Config1);
    retValue = Gpio_PinCfgLock(GPIOA, LOCK_PIN_0);
    //retValue = Gpio_Init(GPIOA, &Config1);

    while(1);

    return 0;
}

/*
 * File: gpio.c
 * Author: phamtien758
 * 
 */

/*** INCLUDE ************************************/
#include "gpio.h"
#include "stub.h"

/*** PROTOTYPE **********************************/

/*** VARIABLE ***********************************/

/*** STATIC FUNCTION ****************************/

/*** FUNCTIONS **********************************/
void Gpio_Init(Gpio_RegDef *p_Gpio_st, const Gpio_Config *p_GpioCfg_st)
{
    uint32_t TempValue_u32;
    uint8_t Temp_u8;
    uint8_t Pos_u8;

    /* Pin mode Configuration */
    TempValue_u32 = p_GpioCfg_st->Gpio_PinMode_e << \
                    GPIO_MODER_BIT_POS(p_GpioCfg_st->Gpio_PinNum_e);
    /* Because number of bit is larger than 1, so need to clear before write */
    p_Gpio_st->MODER &= ~GPIO_MODER_BIT_MASK(p_GpioCfg_st->Gpio_PinNum_e);
    p_Gpio_st->MODER |= TempValue_u32;

    /* Pin output type Configuration */
    TempValue_u32 = p_GpioCfg_st->Gpio_PinOutType_e << \
                    GPIO_MODER_BIT_POS(p_GpioCfg_st->Gpio_PinNum_e);
    p_Gpio_st->OTYPER |= TempValue_u32;

    /* Pin output speed configuration */
    TempValue_u32 = p_GpioCfg_st->Gpio_PinSpeed_e << \
                    GPIO_MODER_BIT_POS(p_GpioCfg_st->Gpio_PinNum_e);
    /* Because number of bit is larger than 1, so need to clear before write */
    p_Gpio_st->OSPEEDR &= ~GPIO_MODER_BIT_MASK(p_GpioCfg_st->Gpio_PinNum_e);
    p_Gpio_st->OSPEEDR |= TempValue_u32;

    /* Pin pull-up pull-down configuration */
    TempValue_u32 = p_GpioCfg_st->Gpio_PinPuPd_e << \
                    GPIO_MODER_BIT_POS(p_GpioCfg_st->Gpio_PinNum_e);
    /* Because number of bit is larger than 1, so need to clear before write */
    p_Gpio_st->PUPDR &= ~GPIO_MODER_BIT_MASK(p_GpioCfg_st->Gpio_PinNum_e);
    p_Gpio_st->PUPDR |= TempValue_u32;

    /* Pin alternate function configuration */
    /* Because each pin consume 4 bits in AFR register,
       so from Pin number 8 onward, configuration value will be write to AFRH */
    if(GPIO_PINNUM_8 <= p_GpioCfg_st->Gpio_PinNum_e)
    {
        TempValue_u32 = p_GpioCfg_st->Gpio_PinAltFun_e << \
                        GPIO_AFRH_BIT_POS(p_GpioCfg_st->Gpio_PinNum_e);
        /* Because number of bit is larger than 1,
           so need to clear before write */
        p_Gpio_st->AFRH &= ~GPIO_AFRH_BIT_MASK(p_GpioCfg_st->Gpio_PinNum_e);
        p_Gpio_st->AFRH |= TempValue_u32;
    }
    else
    {
        TempValue_u32 = p_GpioCfg_st->Gpio_PinAltFun_e << \
                        GPIO_AFRL_BIT_POS(p_GpioCfg_st->Gpio_PinNum_e);
        /* Because number of bit is larger than 1,
           so need to clear before write */
        p_Gpio_st->AFRL &= ~GPIO_AFRL_BIT_MASK(p_GpioCfg_st->Gpio_PinNum_e);
        p_Gpio_st->AFRL |= TempValue_u32;
    }
}

uint8_t Gpio_ReadPin(const Gpio_RegDef *p_Gpio_st, Gpio_PinNum PinNum_u8)
{
    uint8_t Value_u8;
    Value_u8 = (uint8_t)(((p_Gpio_st->IDR) >> GPIO_IDR_BIT_POS(PinNum_u8) & \
                           MASK_OF_PIN_IN_GPIO_IDR));

    return Value_u8;
}

void Gpio_WritePin(Gpio_RegDef *p_Gpio_st,
                     Gpio_PinNum PinNum_u8,
                     Gpio_PinState Value_u8)
{
    if(GPIO_RESET == Value_u8)
    {
        p_Gpio_st->BSRR = GPIO_BSRR_BR_BIT_MASK(PinNum_u8);
    }
    else if (GPIO_SET == Value_u8)
    {
        p_Gpio_st->BSRR = GPIO_BSRR_BS_BIT_MASK(PinNum_u8);
    }
    else
    {
        /* Do nothing */
    }
}

void Gpio_TogglePin(Gpio_RegDef *p_Gpio_st, Gpio_PinNum PinNum_u8)
{
    if(p_Gpio_st->ODR & GPIO_ODR_BIT_MASK(PinNum_u8))
    {
        p_Gpio_st->BSRR = GPIO_BSRR_BR_BIT_MASK(PinNum_u8);
    }
    else
    {
        p_Gpio_st->BSRR = GPIO_BSRR_BS_BIT_MASK(PinNum_u8);
    }
}
void Gpio_IrqConfig(Irq_Number IrqNum_u8, uint8_t Pri_u8, uint8_t State_u8)
{
    uint8_t IprRegister_u8;
    uint8_t Pos_u8;

    /* Set priority */
    IprRegister_u8 = IrqNum_u8 / 4;
    Pos_u8 = (8 * (IrqNum_u8 % 4)) + (8 - NVIC_IPR_LOW_BIT_UNUSED);

    *(NVIC_IPR + IprRegister_u8) |= (Pri_u8 << Pos_u8);

    /* Enable interrupt corresponding to IRQ number */
    if(ENABLE == State_u8)
    {
        if(31 >= IrqNum_u8)
        {
            *NVIC_ISER0 |= (1 << IrqNum_u8);
        }
        else if((32 <= IrqNum_u8) && (63 >= IrqNum_u8))
        {
            *NVIC_ISER1 |= (1 << (IrqNum_u8 % 32));
        }
        else if((64 <= IrqNum_u8) && (95 >= IrqNum_u8))
        {
            *NVIC_ISER2 |= (1 << (IrqNum_u8 % 64));
        }
        else
        {
            /* Do nothing */
        }
    }
    else if(DISABLE == State_u8)
    {
        if(31 >= IrqNum_u8)
        {
            *NVIC_ICER0 |= (1 << IrqNum_u8);
        }
        else if((32 <= IrqNum_u8) && (63 >= IrqNum_u8))
        {
            *NVIC_ICER1 |= (1 << (IrqNum_u8 % 32));
        }
        else if((64 <= IrqNum_u8) && (95 >= IrqNum_u8))
        {
            *NVIC_ICER2 |= (1 << (IrqNum_u8 % 64));
        }
        else
        {
            /* Do nothing */
        }
    }
}
void Gpio_IrqHandler(Gpio_PinNum PinNum_u8)
{
    if((EXTI->EXTI_PR) & (1 << PinNum_u8))
    {
        /* Clear bit pending */
        EXTI->EXTI_PR |= (1 << PinNum_u8);
    }
}

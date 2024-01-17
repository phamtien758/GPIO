/*****************************************************************************
 * File: gpio.c
 * Author: phamtien758
 * 
 *****************************************************************************/

#include "gpio.h"
#include "stub.h"

void Gpio_Init(Gpio_RegDef *p_Gpio_st, const Gpio_Config *p_GpioCfg_st)
{
	uint32_t TempValue_u32;
	uint8_t Temp_u8;
	uint8_t Pos_u8;

	/* Pin mode Configuration */
	TempValue_u32 = p_GpioCfg_st->Gpio_PinMode_e << GPIO_MODER_BIT_POS(p_GpioCfg_st->Gpio_PinNum_e);
	/* Because number of bit is larger than 1, so need to clear before write */
	p_Gpio_st->MODER &= ~ GPIO_MODER_BIT_MASK(p_GpioCfg_st->Gpio_PinNum_e);
	p_Gpio_st->MODER |= TempValue_u32;

	/* Pin output type Configuration */
	TempValue_u32 = p_GpioCfg_st->Gpio_PinOutType_e << p_GpioCfg_st->Gpio_PinNum_e;
	p_Gpio_st->OTYPER |= TempValue_u32;

	/* Pin output speed configuration */
	TempValue_u32 = p_GpioCfg_st->Gpio_PinSpeed_e << (2 * p_GpioCfg_st->Gpio_PinNum_e);
	/* Because number of bit is larger than 1, so need to clear before write */
	p_Gpio_st->OSPEEDR &= ~(0x3 << (2 * p_GpioCfg_st->Gpio_PinNum_e));
	p_Gpio_st->OSPEEDR |= TempValue_u32;

	/* Pin pull-up pull-down configuration */
	TempValue_u32 = p_GpioCfg_st->Gpio_PinPuPd_e << (2 * p_GpioCfg_st->Gpio_PinNum_e);
	/* Because number of bit is larger than 1, so need to clear before write */
	p_Gpio_st->PUPDR &= ~(0x3 << (2 * p_GpioCfg_st->Gpio_PinNum_e));
	p_Gpio_st->PUPDR |= TempValue_u32;

	/* Pin alternate function configuration */
	if(GPIO_PINNUM_8 < p_GpioCfg_st->Gpio_PinNum_e)
	{
		Pos_u8 = (uint8_t)p_GpioCfg_st->Gpio_PinNum_e - (uint8_t)8U;
		TempValue_u32 = p_GpioCfg_st->Gpio_PinAltFun_e << (4 * Pos_u8);
		/* Because number of bit is larger than 1, so need to clear before write */
		p_Gpio_st->AFRH &= ~(0xF << (4 * Pos_u8));
		p_Gpio_st->AFRH |= TempValue_u32;
	}
	else
	{
		TempValue_u32 = p_GpioCfg_st->Gpio_PinAltFun_e << (4 * p_GpioCfg_st->Gpio_PinNum_e);
		/* Because number of bit is larger than 1, so need to clear before write */
		p_Gpio_st->AFRL &= ~(0xF << (4 * p_GpioCfg_st->Gpio_PinNum_e));
		p_Gpio_st->AFRL |= TempValue_u32;
	}

	/* Interrupt configuration */
	if(GPIO_MODE_ANAL < p_GpioCfg_st->Gpio_PinMode_e)
	{
		if(GPIO_MODE_IR_FE == p_GpioCfg_st->Gpio_PinMode_e)
		{
			EXTI->EXTI_FTSR |= (0x1 << p_GpioCfg_st->Gpio_PinNum_e);
			EXTI->EXTI_RTSR &= ~(0x1 << p_GpioCfg_st->Gpio_PinNum_e);
		}
		else if(GPIO_MODE_IR_RE == p_GpioCfg_st->Gpio_PinMode_e)
		{
			EXTI->EXTI_FTSR &= ~(0x1 << p_GpioCfg_st->Gpio_PinNum_e);
			EXTI->EXTI_RTSR |= (0x1 << p_GpioCfg_st->Gpio_PinNum_e);
		}
		else if(GPIO_MODE_IR_FRE == p_GpioCfg_st->Gpio_PinMode_e)
		{
			EXTI->EXTI_FTSR |= (0x1 << p_GpioCfg_st->Gpio_PinNum_e);
			EXTI->EXTI_RTSR |= (0x1 << p_GpioCfg_st->Gpio_PinNum_e);
		}
		else
		{
			/* Do nothing */
		}
	}
	/* Select port for Exit external interrupt  */
	Temp_u8 = (p_GpioCfg_st->Gpio_PinNum_e) / 4;
	Pos_u8 = 4 * ((p_GpioCfg_st->Gpio_PinNum_e) % 4);

	switch ((uint32_t)p_Gpio_st)
	{
		case (uint32_t)GPIOA:
			TempValue_u32 = 0x0U;
			break;
		case (uint32_t)GPIOB:
			TempValue_u32 = 0x1U;
			break;
		case (uint32_t)GPIOC:
			TempValue_u32 = 0x2U;
			break;
		case (uint32_t)GPIOD:
			TempValue_u32 = 0x3U;
			break;
		case (uint32_t)GPIOE:
			TempValue_u32 = 0x4U;
			break;
		case (uint32_t)GPIOH:
			TempValue_u32 = 0x4U;
			break;
		default:
			break;
	}

	RCC_SYSCFG_CLK_EN();
	SYSCFG->EXTICR[Temp_u8] |= (TempValue_u32 << Pos_u8);

	/* Enable interrupt request from Exit line  */
	EXTI->EXTI_IMR |= (0x1 << p_GpioCfg_st->Gpio_PinNum_e);

}

uint8_t  Gpio_ReadPin(const Gpio_RegDef *p_Gpio_st, Gpio_PinNum PinNum_u8)
{
	uint8_t Value_u8;
	Value_u8 = (uint8_t)(((p_Gpio_st->IDR) >> PinNum_u8) & 0x1U);

	return Value_u8;
}
uint16_t Gpio_ReadPort(const Gpio_RegDef *p_Gpio_st)
{
	uint16_t Value_u16;
	Value_u16 = (uint8_t)(p_Gpio_st->IDR);

	return Value_u16;
}
void   Gpio_WritePin(Gpio_RegDef *p_Gpio_st, Gpio_PinNum PinNum_u8, Gpio_PinState Value_u8)
{
	if(GPIO_RESET == Value_u8)
	{
		p_Gpio_st->ODR &= ~(1 << PinNum_u8);
	}
	else
	{
		p_Gpio_st->ODR |= (1 << PinNum_u8);
	}
}
void   Gpio_WritePort(Gpio_RegDef *p_Gpio_st, uint16_t Value_u16)
{
	p_Gpio_st->ODR = Value_u16;
}
void   Gpio_ToggleOutPin(Gpio_RegDef *p_Gpio_st, Gpio_PinNum PinNum_u8)
{
	p_Gpio_st->ODR ^= (1 << PinNum_u8);
}
void   Gpio_IrqConfig(Irq_Number IrqNum_u8, uint8_t Pri_u8, uint8_t State_u8)
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

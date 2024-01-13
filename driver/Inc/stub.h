/*
 * stub.h
 *
 *  Created on: Jan 10, 2024
 *  Author: phamtien758
 */

#ifndef STUB_H
#define STUB_H

#include "stm32f401re.h"

/*
 * Gpio clock enable macros
 */
#define RCC_GPIOA_CLK_EN()    (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN_MASK)
#define RCC_GPIOB_CLK_EN()    (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN_MASK)
#define RCC_GPIOC_CLK_EN()    (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN_MASK)
#define RCC_GPIOD_CLK_EN()    (RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN_MASK)
#define RCC_GPIOE_CLK_EN()    (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN_MASK)
#define RCC_GPIOH_CLK_EN()    (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN_MASK)

/*
 * I2c clock enable macros
 */
#define RCC_I2C1_CLK_EN()     (RCC->APB1ENR |= RCC_APB1ENR_I2C1EN_MASK)
#define RCC_I2C2_CLK_EN()     (RCC->APB1ENR |= RCC_APB1ENR_I2C2EN_MASK)
#define RCC_I2C3_CLK_EN()     (RCC->APB1ENR |= RCC_APB1ENR_I2C3EN_MASK)

/*
 * Usart clock enable macros
 */
#define RCC_USART1_CLK_EN()   (RCC->APB2ENR |= RCC_APB2ENR_USART1EN_MASK)
#define RCC_USART2_CLK_EN()   (RCC->APB1ENR |= RCC_APB1ENR_USART2EN_MASK)
#define RCC_USART6_CLK_EN()   (RCC->APB2ENR |= RCC_APB2ENR_USART6EN_MASK)

/*
 * Spi clock enable macros
 */
#define RCC_SPI1_CLK_EN()     (RCC->APB2ENR |= RCC_APB2ENR_SPI1EN_MASK)
#define RCC_SPI2_CLK_EN()     (RCC->APB1ENR |= RCC_APB1ENR_SPI2EN_MASK)
#define RCC_SPI3_CLK_EN()     (RCC->APB1ENR |= RCC_APB1ENR_SPI3EN_MASK)
#define RCC_SPI4_CLK_EN()     (RCC->APB2ENR |= RCC_APB2ENR_SPI4EN_MASK)

/*
 * Syscfg clock enable macros
 */
#define RCC_SYSCFG_CLK_EN()   (RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN_MASK)

/*
 * Gpio clock disable macros
 */
#define RCC_GPIOA_CLK_DIS()    (RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOAEN_MASK)
#define RCC_GPIOB_CLK_DIS()    (RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOBEN_MASK)
#define RCC_GPIOC_CLK_DIS()    (RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOCEN_MASK)
#define RCC_GPIOD_CLK_DIS()    (RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIODEN_MASK)
#define RCC_GPIOE_CLK_DIS()    (RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOEEN_MASK)
#define RCC_GPIOH_CLK_DIS()    (RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOHEN_MASK)

/*
 * I2c clock disable macros
 */
#define RCC_I2C1_CLK_DIS()     (RCC->APB1ENR &= ~RCC_APB1ENR_I2C1EN_MASK)
#define RCC_I2C2_CLK_DIS()     (RCC->APB1ENR &= ~RCC_APB1ENR_I2C2EN_MASK)
#define RCC_I2C3_CLK_DIS()     (RCC->APB1ENR &= ~RCC_APB1ENR_I2C3EN_MASK)

/*
 * Usart clock disable macros
 */
#define RCC_USART1_CLK_DIS()   (RCC->APB2ENR &= ~RCC_APB2ENR_USART1EN_MASK)
#define RCC_USART2_CLK_DIS()   (RCC->APB1ENR &= ~RCC_APB1ENR_USART2EN_MASK)
#define RCC_USART6_CLK_DIS()   (RCC->APB2ENR &= ~RCC_APB2ENR_USART6EN_MASK)

/*
 * Spi clock disable macros
 */
#define RCC_SPI1_CLK_DIS()     (RCC->APB2ENR &= ~RCC_APB2ENR_SPI1EN_MASK)
#define RCC_SPI2_CLK_DIS()     (RCC->APB1ENR &= ~RCC_APB1ENR_SPI2EN_MASK)
#define RCC_SPI3_CLK_DIS()     (RCC->APB1ENR &= ~RCC_APB1ENR_SPI3EN_MASK)
#define RCC_SPI4_CLK_DIS()     (RCC->APB2ENR &= ~RCC_APB2ENR_SPI4EN_MASK)

/*
 * Syscfg clock disable macros
 */


static inline void Rcc_GpioA_Reset(void)
{
	Rcc_Reg *p_Rcc_Base_st = RCC;
	p_Rcc_Base_st->AHB1RSTR |= RCC_AHB1RSTR_GPIOARST_MASK;
	p_Rcc_Base_st->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOARST_MASK;
}

static inline void Rcc_GpioB_Reset(void)
{
	Rcc_Reg *p_Rcc_Base_st = RCC;
	p_Rcc_Base_st->AHB1RSTR |= RCC_AHB1RSTR_GPIOBRST_MASK;
	p_Rcc_Base_st->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOBRST_MASK;
}

static inline void Rcc_GpioC_Reset(void)
{
	Rcc_Reg *p_Rcc_Base_st = RCC;
	p_Rcc_Base_st->AHB1RSTR |= RCC_AHB1RSTR_GPIOCRST_MASK;
	p_Rcc_Base_st->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOCRST_MASK;
}

static inline void Rcc_GpioD_Reset(void)
{
	Rcc_Reg *p_Rcc_Base_st = RCC;
	p_Rcc_Base_st->AHB1RSTR |= RCC_AHB1RSTR_GPIODRST_MASK;
	p_Rcc_Base_st->AHB1RSTR &= ~RCC_AHB1RSTR_GPIODRST_MASK;
}

static inline void Rcc_GpioE_Reset(void)
{
	Rcc_Reg *p_Rcc_Base_st = RCC;
	p_Rcc_Base_st->AHB1RSTR |= RCC_AHB1RSTR_GPIOERST_MASK;
	p_Rcc_Base_st->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOERST_MASK;
}

static inline void Rcc_GpioH_Reset(void)
{
	Rcc_Reg *p_Rcc_Base_st = RCC;
	p_Rcc_Base_st->AHB1RSTR |= RCC_AHB1RSTR_GPIOHRST_MASK;
	p_Rcc_Base_st->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOHRST_MASK;
}

#endif /* STUB_H_ */

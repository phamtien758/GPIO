/*
 * stm32f401re.h
 *
 *  Created on: Jan 9, 2024
 *  Author: phamtien758
 */

#ifndef STM32F401RE_H
#define STM32F401RE_H

#include "type.h"

/*************************************************************
 *            Cortex-M4 Processor Peripheral
 *************************************************************/
/*
 * Definition of NVIC peripheral base address
 */
#define NVIC_ISER0    ((volatile uint32_t*)0xE000E100)
#define NVIC_ISER1    ((volatile uint32_t*)0xE000E104)
#define NVIC_ISER2    ((volatile uint32_t*)0xE000E108)
#define NVIC_ISER3    ((volatile uint32_t*)0xE000E10C)

#define NVIC_ICER0    ((volatile uint32_t*)0XE000E180)
#define NVIC_ICER1    ((volatile uint32_t*)0XE000E184)
#define NVIC_ICER2    ((volatile uint32_t*)0XE000E188)
#define NVIC_ICER3    ((volatile uint32_t*)0XE000E18C)

#define NVIC_IPR      ((volatile uint32_t*)0xE000E400)

#define NVIC_IPR_LOW_BIT_UNUSED    4U

/*
 * Definition of GPIO peripheral base address
 */
#define GPIOA_BASE      0x40020000U
#define GPIOB_BASE      0x40020400U
#define GPIOC_BASE      0x40020800U
#define GPIOD_BASE      0x40020C00U
#define GPIOE_BASE      0x40021000U
#define GPIOH_BASE      0x40021C00U

/*
 * Definition of I2c peripheral base address
 */
#define I2C1_BASE       0x40005400U
#define I2C2_BASE       0x40005800U
#define I2C3_BASE       0x40005C00U

/*
 * Definition of Usart peripheral base address
 */
#define USART1_BASE     0x40011000U
#define USART2_BASE     0x40004400U
#define USART6_BASE     0x40011400U

/*
 * Definition of Spi peripheral base address
 */
#define SPI1_BASE       0x40013000U
#define SPI2_BASE       0x40003800U
#define SPI3_BASE       0x40003C00U
#define SPI4_BASE       0x40013400U

/*
 * Definition of EXTI peripheral base address
 */
#define EXTI_BASE       0x40013C00U

/*
 * Definition of RCC peripheral base address
 */
#define RCC_BASE        0x40023800U

/*
 * Definition of RCC peripheral base address
 */
#define SYSCFG_BASE     0x40013800U

/*********************************************************
 *              Peripheral register structures
 *********************************************************/
/*
 * GPIO peripheral register structure
 */
typedef struct
{
    _RW uint32_t MODER;
    _RW uint32_t OTYPER;
    _RW uint32_t OSPEEDR;
    _RW uint32_t PUPDR;
    _R  uint32_t IDR;
    _RW uint32_t ODR;
    _W  uint32_t BSRR;
    _RW uint32_t LCKR;
    _RW uint32_t AFRL;
    _RW uint32_t AFRH;
} Gpio_Reg;

#define GPIOA    ((Gpio_Reg*)GPIOA_BASE)
#define GPIOB    ((Gpio_Reg*)GPIOB_BASE)
#define GPIOC    ((Gpio_Reg*)GPIOC_BASE)
#define GPIOD    ((Gpio_Reg*)GPIOD_BASE)
#define GPIOE    ((Gpio_Reg*)GPIOE_BASE)
#define GPIOH    ((Gpio_Reg*)GPIOH_BASE)

/*
 * RCC peripheral register structure
 */
typedef struct
{
	_RW uint32_t CR;
	_RW uint32_t PLLCFGR;
	_RW uint32_t CFGR;
	_RW uint32_t CIR;
	_RW uint32_t AHB1RSTR;
	_RW uint32_t AHB2RSTR;
		uint32_t Reserved1[2];
	_RW uint32_t APB1RSTR;
	_RW uint32_t APB2RSTR;
		uint32_t Reserved2[2];
	_RW uint32_t AHB1ENR;
	_RW uint32_t AHB2ENR;
		uint32_t Reserved3[2];
	_RW uint32_t APB1ENR;
	_RW uint32_t APB2ENR;
		uint32_t Reserved4[2];
	_RW uint32_t AHB1LPENR;
	_RW uint32_t AHB2LPENR;
		uint32_t Reserved5[2];
	_RW uint32_t APB1LPENR;
	_RW uint32_t APB2LPENR;
		uint32_t Reserved6[2];
	_RW uint32_t BDCR;
	_RW uint32_t CSR;
		uint32_t Reserved7[2];
	_RW uint32_t SSCGR;
	_RW uint32_t PLLI2SCFGR;
		uint32_t Reserved8;
	_RW uint32_t DCKCFGR;
} Rcc_Reg;

#define RCC    ((Rcc_Reg*)RCC_BASE)

#define RCC_AHB1ENR_GPIOAEN_POS     (0U)
#define RCC_AHB1ENR_GPIOBEN_POS     (1U)
#define RCC_AHB1ENR_GPIOCEN_POS     (2U)
#define RCC_AHB1ENR_GPIODEN_POS     (3U)
#define RCC_AHB1ENR_GPIOEEN_POS     (4U)
#define RCC_AHB1ENR_GPIOHEN_POS     (7U)

#define RCC_AHB1ENR_GPIOAEN_MASK    (0x1U)
#define RCC_AHB1ENR_GPIOBEN_MASK    (0x2U)
#define RCC_AHB1ENR_GPIOCEN_MASK    (0x4U)
#define RCC_AHB1ENR_GPIODEN_MASK    (0x8U)
#define RCC_AHB1ENR_GPIOEEN_MASK    (0x10U)
#define RCC_AHB1ENR_GPIOHEN_MASK    (0x80U)

#define RCC_APB1ENR_I2C1EN_MASK     (0x200000U)
#define RCC_APB1ENR_I2C2EN_MASK     (0x400000U)
#define RCC_APB1ENR_I2C3EN_MASK     (0x800000U)
#define RCC_APB1ENR_USART2EN_MASK   (0x20000U)
#define RCC_APB1ENR_SPI2EN_MASK     (0x4000U)
#define RCC_APB1ENR_SPI3EN_MASK     (0x8000U)

#define RCC_APB2ENR_USART1EN_MASK   (0x10U)
#define RCC_APB2ENR_USART6EN_MASK   (0x20U)
#define RCC_APB2ENR_SPI1EN_MASK     (0x1000U)
#define RCC_APB2ENR_SPI4EN_MASK     (0x2000U)
#define RCC_APB2ENR_SYSCFGEN_MASK   (0x4000U)

#define RCC_AHB1RSTR_GPIOARST_MASK  (0x1U)
#define RCC_AHB1RSTR_GPIOBRST_MASK  (0x2U)
#define RCC_AHB1RSTR_GPIOCRST_MASK  (0x4U)
#define RCC_AHB1RSTR_GPIODRST_MASK  (0x8U)
#define RCC_AHB1RSTR_GPIOERST_MASK  (0x10U)
#define RCC_AHB1RSTR_GPIOHRST_MASK  (0x80U)

/*
 * EXTI peripheral register structure
 */
typedef struct
{
	_RW uint32_t EXTI_IMR;
	_RW uint32_t EXTI_EMR;
	_RW uint32_t EXTI_RTSR;
	_RW uint32_t EXTI_FTSR;
	_RW uint32_t EXTI_SWIER;
	_RW uint32_t EXTI_PR;
}Exti_Reg;

#define EXTI    ((Exti_Reg*)EXTI_BASE)

/*
 * SYSCFG register structure
 */
typedef struct
{
	_RW uint32_t MEMRMP;
	_RW uint32_t PMC;
	_RW uint32_t EXTICR[4];
	_RW uint32_t Reserved[2];
	_RW uint32_t CMPCR;
}Syscfg_Reg;

#define SYSCFG    ((Syscfg_Reg*)SYSCFG_BASE)

typedef enum
{
	IRQ_NUM_EXTI16  = 1,
	IRQ_NUM_EXTI21  = 2,
	IRQ_NUM_EXTI22  = 3,
	IRQ_NUM_EXTI0   = 6,
	IRQ_NUM_EXTI1   = 7,
	IRQ_NUM_EXTI2   = 8,
	IRQ_NUM_EXTI3   = 9,
	IRQ_NUM_EXTI4   = 10,
	IRQ_NUM_EXTI9_5 = 23,
	IRQ_NUM_EXTI17  = 41,
	IRQ_NUM_EXTI18  = 42
}Irq_Number;

#endif /* STM32F401RE_H */

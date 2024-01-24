/*******************************************************************************
 * File  : gpio.h       
 * Author: phamtien758      
 * Brief : 
 ******************************************************************************/

#ifndef GPIO_H
#define GPIO_H

/*** INCLUDE ******************************************************************/

#include "stm32f401re.h"

/*** DEFINE *******************************************************************/

/*** TYPEDEF ******************************************************************/

/*
 * @Gpio_PinState_def
 * @brief Gpio pin set/reset state
 */
typedef enum
{
	GPIO_RESET = 0,    /* Pin in reset state */
	GPIO_SET   = 1     /* Pin in set state */
}Gpio_PinState;

/*
 * @Gpio_Mode_def
 * @brief Gpio pin mode
 */
typedef enum
{
    GPIO_MODE_IN    = 0,    /* Input mode pin */
	GPIO_MODE_OUT   = 1,    /* Output mode pin */
	GPIO_MODE_ALT   = 2,    /* Alternate mode pin */
    GPIO_MODE_ANAL  = 3     /* Analog mode pin */
}Gpio_Mode;

/*
 * @Gpio_OutType_def
 * @brief Gpio pin output type
 */
typedef enum
{
	GPIO_OUTTYPE_PUSPUL = 0,    /* Push-Pull output type */
	GPIO_OUTTYPE_OPENDR = 1     /* Open drain output type */
}Gpio_OutType;

/*
 * @Gpio_OutSpeed_def
 * @brief Gpio pin output speed
 */
typedef enum
{
	GPIO_OUTSPEED_LOW       = 0,    /* Output speed is low */
	GPIO_OUTSPEED_MEDIUM    = 1,    /* Output speed is medium */
	GPIO_OUTSPEED_HIGH      = 2,    /* Output speed is hight */
	GPIO_OUTSPEED_VERYHIGH  = 3     /* Output speed is very hight */
}Gpio_OutSpeed;

/*
 * @Gpio_PullUpDown_def
 * @brief Gpio pin with pull-up, pull-down register
 */
typedef enum
{
    GPIO_PULLUPDOWN_NOPULL   = 0,    /* No pull-up or pull-down register */
	GPIO_PULLUPDOWN_PULLUP   = 1,    /* Pin connect to pull-up register */
	GPIO_PULLUPDOWN_PULLDOWN = 2,    /* Pin connect to pull-down register */
}Gpio_PullUpDown;

/*
 * @Gpio_AltFun_def
 * @brief Alternate functions of Gpio pin
 */
typedef enum
{
    GPIO_ALTFUN_0   = 0,     /* Alternate function 0 */
	GPIO_ALTFUN_1   = 1,     /* Alternate function 1 */
	GPIO_ALTFUN_2   = 2,     /* Alternate function 2 */
	GPIO_ALTFUN_3   = 3,     /* Alternate function 3 */
	GPIO_ALTFUN_4   = 4,     /* Alternate function 4 */
	GPIO_ALTFUN_5   = 5,     /* Alternate function 5 */
	GPIO_ALTFUN_6   = 6,     /* Alternate function 6 */
	GPIO_ALTFUN_7   = 7,     /* Alternate function 7 */
	GPIO_ALTFUN_8   = 8,     /* Alternate function 8 */
	GPIO_ALTFUN_9   = 9,     /* Alternate function 9 */
	GPIO_ALTFUN_10  = 10,    /* Alternate function 10 */
	GPIO_ALTFUN_11  = 11,    /* Alternate function 11 */
	GPIO_ALTFUN_12  = 12,    /* Alternate function 12 */
	GPIO_ALTFUN_13  = 13,    /* Alternate function 13 */
	GPIO_ALTFUN_14  = 14,    /* Alternate function 14 */
	GPIO_ALTFUN_15  = 15     /* Alternate function 15 */
}Gpio_AltFun;

/*
 * @Gpio_PinNum_def
 * @brief Gpio pin number
 */
typedef enum
{
	GPIO_PINNUM_0   = 0,     /* Pin number 0 */
    GPIO_PINNUM_1   = 1,     /* Pin number 1 */
	GPIO_PINNUM_2   = 2,     /* Pin number 2 */
	GPIO_PINNUM_3   = 3,     /* Pin number 3 */
	GPIO_PINNUM_4   = 4,     /* Pin number 4 */
	GPIO_PINNUM_5   = 5,     /* Pin number 5 */
	GPIO_PINNUM_6   = 6,     /* Pin number 6 */
	GPIO_PINNUM_7   = 7,     /* Pin number 7 */
	GPIO_PINNUM_8   = 8,     /* Pin number 8 */
	GPIO_PINNUM_9   = 9,     /* Pin number 9 */
	GPIO_PINNUM_10  = 10,    /* Pin number 10 */
	GPIO_PINNUM_11  = 11,    /* Pin number 11 */
	GPIO_PINNUM_12  = 12,    /* Pin number 12 */
	GPIO_PINNUM_13  = 13,    /* Pin number 13 */
	GPIO_PINNUM_14  = 14,    /* Pin number 14 */
	GPIO_PINNUM_15  = 15     /* Pin number 15 */
}Gpio_PinNum;

/*
 * @brief Gpio pin configuration
 */
typedef struct
{
	Gpio_PinNum      Gpio_PinNum_e;        /* Refer to @Gpio_PinState_def */
	Gpio_Mode        Gpio_PinMode_e;       /* Refer to @Gpio_Mode_def */
	Gpio_OutSpeed    Gpio_PinSpeed_e;      /* Refer to @Gpio_OutSpeed_def */
	Gpio_PullUpDown  Gpio_PinPuPd_e;       /* Refer to @Gpio_PullUpDown_def */
	Gpio_OutType     Gpio_PinOutType_e;    /* Refer to @Gpio_OutType_def */
	Gpio_AltFun      Gpio_PinAltFun_e;     /* Refer to @Gpio_AltFun */
}Gpio_Config;

/*** EXTERN *******************************************************************/

/*** PROTOTYPE ****************************************************************/

/* Gpio pin initialization */
void Gpio_Init(Gpio_RegDef *p_Gpio_st, const Gpio_Config *p_GpioCfg_st);

/* Read the state of pin */
uint8_t Gpio_ReadPin(const Gpio_RegDef *p_Gpio_st, Gpio_PinNum PinNum_u8);

/* Write to output pin */
void Gpio_WritePin(Gpio_RegDef *p_Gpio_st, Gpio_PinNum PinNum_u8, \
                   Gpio_PinState Value_u8);

/* Toggle output pin */
void Gpio_TogglePin(Gpio_RegDef *p_Gpio_st, Gpio_PinNum PinNum_u8);

void Gpio_IrqConfig(Irq_Number IrqNum_u8, uint8_t Pri_u8, uint8_t State_u8);
void Gpio_IrqHandler(Gpio_PinNum PinNum_u8);

#endif /* GPIO_H */

/*
 * gpio.h
 *
 *  Created on: Jan 9, 2024
 *  Author: phamtien758
 */

#ifndef GPIO_H
#define GPIO_H

#include "stm32f401re.h"

/*
 * Gpio pin set/reset state
 */
typedef enum
{
	GPIO_RESET = 0,
	GPIO_SET   = 1
}Gpio_PinState;

/*
 * @Gpio_Mode_e
 *
 */
typedef enum
{
    GPIO_MODE_IN      = 0,
	GPIO_MODE_OUT     = 1,
	GPIO_MODE_ALT     = 2,
    GPIO_MODE_ANAL    = 3,
	GPIO_MODE_IR_FE   = 4,
	GPIO_MODE_IR_RE   = 5,
	GPIO_MODE_IR_FRE  = 6
}Gpio_Mode;

/*
 * @Gpio_OutType_e
 *
 */
typedef enum
{
	GPIO_OUTTYPE_PUSPUL = 0,
	GPIO_OUTTYPE_OPENDR = 1
}Gpio_OutType;

/*
 * @Gpio_OutSpeed_e
 *
 */
typedef enum
{
	GPIO_OUTSPEED_LOW       = 0,
	GPIO_OUTSPEED_MEDIUM    = 1,
	GPIO_OUTSPEED_HIGH      = 2,
	GPIO_OUTSPEED_VERYHIGH  = 3
}Gpio_OutSpeed;

/*
 * @Gpio_PullUpDown_e
 *
 */
typedef enum
{
    GPIO_PULLUPDOWN_NOPULL   = 0,
	GPIO_PULLUPDOWN_PULLUP   = 1,
	GPIO_PULLUPDOWN_PULLDOWN = 2,
}Gpio_PullUpDown;

/*
 * @Gpio_AltFun_e
 *
 */
typedef enum
{
    GPIO_ALTFUN_0   = 0,
	GPIO_ALTFUN_1   = 1,
	GPIO_ALTFUN_2   = 2,
	GPIO_ALTFUN_3   = 3,
	GPIO_ALTFUN_4   = 4,
	GPIO_ALTFUN_5   = 5,
	GPIO_ALTFUN_6   = 6,
	GPIO_ALTFUN_7   = 7,
	GPIO_ALTFUN_8   = 8,
	GPIO_ALTFUN_9   = 9,
	GPIO_ALTFUN_10  = 10,
	GPIO_ALTFUN_11  = 11,
	GPIO_ALTFUN_12  = 12,
	GPIO_ALTFUN_13  = 13,
	GPIO_ALTFUN_14  = 14,
	GPIO_ALTFUN_15  = 15
}Gpio_AltFun;

/*
 * @Gpio_PinNum_e
 *
 */
typedef enum
{
    GPIO_PINNUM_1   = 1,
	GPIO_PINNUM_2   = 2,
	GPIO_PINNUM_3   = 3,
	GPIO_PINNUM_4   = 4,
	GPIO_PINNUM_5   = 5,
	GPIO_PINNUM_6   = 6,
	GPIO_PINNUM_7   = 7,
	GPIO_PINNUM_8   = 8,
	GPIO_PINNUM_9   = 9,
	GPIO_PINNUM_10  = 10,
	GPIO_PINNUM_11  = 11,
	GPIO_PINNUM_12  = 12,
	GPIO_PINNUM_13  = 13,
	GPIO_PINNUM_14  = 14,
	GPIO_PINNUM_15  = 15
}Gpio_PinNum;

typedef struct
{
	Gpio_PinNum      Gpio_PinNum_e;
	Gpio_Mode        Gpio_PinMode_e;
	Gpio_OutSpeed    Gpio_PinSpeed_e;
	Gpio_PullUpDown  Gpio_PinPuPd_e;
	Gpio_OutType     Gpio_PinOutType_e;
	Gpio_AltFun      Gpio_PinAltFun_e;
}Gpio_Config;

typedef struct
{
	Gpio_Reg    *p_Gpio_Base_st;
	Gpio_Config *p_Gpio_Config_st;
}Gpio_Handle;


void   Gpio_Init(const Gpio_Handle *p_GpioCfg_st);
uint8_t  Gpio_ReadPin(const Gpio_Reg *p_Gpio_st, Gpio_PinNum PinNum_u8);
uint16_t Gpio_ReadPort(const Gpio_Reg *p_Gpio_st);
void   Gpio_WritePin(Gpio_Reg *p_Gpio_st, Gpio_PinNum PinNum_u8, Gpio_PinState Value_u8);
void   Gpio_WritePort(Gpio_Reg *p_Gpio_st, uint16_t Value);
void   Gpio_ToggleOutPin(Gpio_Reg *p_Gpio_st, Gpio_PinNum PinNum_u8);
void   Gpio_IrqConfig(Irq_Number IrqNum_u8, uint8_t Pri_u8, uint8_t State_u8);
void   Gpio_IrqHandler(Gpio_PinNum PinNum_u8);

#endif /* GPIO_H */

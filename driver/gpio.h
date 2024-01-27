/*******************************************************************************
 * File  : gpio.h       
 * Author: phamtien758      
 * Brief : Gpio header file
 ******************************************************************************/

#ifndef GPIO_H
#define GPIO_H

/*** INCLUDE ******************************************************************/

#include "stm32f401re.h"
#include "external_interrupt.h"

/*** DEFINE *******************************************************************/

/*** TYPEDEF ******************************************************************/

/*
 * @Gpio_PinState_def
 * @brief Gpio pin set/reset state
 */
typedef enum
{
    GPIO_RESET = 0U,    /* Pin in reset state */
    GPIO_SET   = 1U     /* Pin in set state */
}Gpio_PinState;

/*
 * @Gpio_Mode_def
 * @brief Gpio pin mode
 */
typedef enum
{
    GPIO_MODE_IN    = 0U,    /* Input mode pin */
    GPIO_MODE_OUT   = 1U,    /* Output mode pin */
    GPIO_MODE_ALT   = 2U,    /* Alternate mode pin */
    GPIO_MODE_ANAL  = 3U     /* Analog mode pin */
}Gpio_Mode;

/*
 * @Gpio_OutType_def
 * @brief Gpio pin output type
 */
typedef enum
{
    GPIO_OUTTYPE_PUSPUL = 0U,    /* Push-Pull output type */
    GPIO_OUTTYPE_OPENDR = 1U     /* Open drain output type */
}Gpio_OutType;

/*
 * @Gpio_OutSpeed_def
 * @brief Gpio pin output speed
 */
typedef enum
{
    GPIO_OUTSPEED_LOW       = 0U,    /* Output speed is low */
    GPIO_OUTSPEED_MEDIUM    = 1U,    /* Output speed is medium */
    GPIO_OUTSPEED_HIGH      = 2U,    /* Output speed is hight */
    GPIO_OUTSPEED_VERYHIGH  = 3U     /* Output speed is very hight */
}Gpio_OutSpeed;

/*
 * @Gpio_PullUpDown_def
 * @brief Gpio pin with pull-up, pull-down register
 */
typedef enum
{
    GPIO_PULLUPDOWN_NOPULL   = 0U,    /* No pull-up or pull-down register */
    GPIO_PULLUPDOWN_PULLUP   = 1U,    /* Pin connect to pull-up register */
    GPIO_PULLUPDOWN_PULLDOWN = 2U,    /* Pin connect to pull-down register */
}Gpio_PullUpDown;

/*
 * @Gpio_AltFun_def
 * @brief Alternate functions of Gpio pin
 */
typedef enum
{
    GPIO_ALTFUN_0   = 0U,     /* Alternate function 0 */
    GPIO_ALTFUN_1   = 1U,     /* Alternate function 1 */
    GPIO_ALTFUN_2   = 2U,     /* Alternate function 2 */
    GPIO_ALTFUN_3   = 3U,     /* Alternate function 3 */
    GPIO_ALTFUN_4   = 4U,     /* Alternate function 4 */
    GPIO_ALTFUN_5   = 5U,     /* Alternate function 5 */
    GPIO_ALTFUN_6   = 6U,     /* Alternate function 6 */
    GPIO_ALTFUN_7   = 7U,     /* Alternate function 7 */
    GPIO_ALTFUN_8   = 8U,     /* Alternate function 8 */
    GPIO_ALTFUN_9   = 9U,     /* Alternate function 9 */
    GPIO_ALTFUN_10  = 10U,    /* Alternate function 10 */
    GPIO_ALTFUN_11  = 11U,    /* Alternate function 11 */
    GPIO_ALTFUN_12  = 12U,    /* Alternate function 12 */
    GPIO_ALTFUN_13  = 13U,    /* Alternate function 13 */
    GPIO_ALTFUN_14  = 14U,    /* Alternate function 14 */
    GPIO_ALTFUN_15  = 15U     /* Alternate function 15 */
}Gpio_AltFun;

/*
 * @Gpio_PinNum_def
 * @brief Gpio pin number
 */
typedef enum
{
    GPIO_PINNUM_0   = 0U,     /* Pin number 0 */
    GPIO_PINNUM_1   = 1U,     /* Pin number 1 */
    GPIO_PINNUM_2   = 2U,     /* Pin number 2 */
    GPIO_PINNUM_3   = 3U,     /* Pin number 3 */
    GPIO_PINNUM_4   = 4U,     /* Pin number 4 */
    GPIO_PINNUM_5   = 5U,     /* Pin number 5 */
    GPIO_PINNUM_6   = 6U,     /* Pin number 6 */
    GPIO_PINNUM_7   = 7U,     /* Pin number 7 */
    GPIO_PINNUM_8   = 8U,     /* Pin number 8 */
    GPIO_PINNUM_9   = 9U,     /* Pin number 9 */
    GPIO_PINNUM_10  = 10U,    /* Pin number 10 */
    GPIO_PINNUM_11  = 11U,    /* Pin number 11 */
    GPIO_PINNUM_12  = 12U,    /* Pin number 12 */
    GPIO_PINNUM_13  = 13U,    /* Pin number 13 */
    GPIO_PINNUM_14  = 14U,    /* Pin number 14 */
    GPIO_PINNUM_15  = 15U     /* Pin number 15 */
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
    uint8_t          Gpio_ExIntEnable_u8;  /* External interrupt for Gpio pin */
    Exti_Edge_e      Gpio_ExIntEdge_e;     /* Edge for external interrupt */
    FuncHandler      Gpio_ExIntCallback;   /* Poiter to user's handler */
}Gpio_Config;

/*** EXTERN *******************************************************************/

/*** PROTOTYPE ****************************************************************/

/* Gpio pin initialization */
ReturnType Gpio_Init(Gpio_RegDef *p_Gpio_st, const Gpio_Config *p_GpioCfg_st);

/* Read the state of pin */
uint8_t Gpio_ReadPin(const Gpio_RegDef *p_Gpio_st, Gpio_PinNum PinNum_u8);

/* Write to output pin */
void Gpio_WritePin(Gpio_RegDef *p_Gpio_st, Gpio_PinNum PinNum_u8, \
                   Gpio_PinState Value_u8);

/* Toggle output pin */
void Gpio_TogglePin(Gpio_RegDef *p_Gpio_st, Gpio_PinNum PinNum_u8);

/* Check lock pin */
uint8_t Gpio_IsLocked(Gpio_RegDef *p_Gpio_st, Gpio_PinNum PinNum_u8);

/* Gpio lock configuration pin */
void Gpio_PinCfgLock(Gpio_RegDef *p_Gpio_st, uint32_t PinsToLock_u32);

#endif /* GPIO_H */

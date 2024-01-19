/*
 * File: external_interrupt.h
 * Author: phamtien758
 * 
 */

#ifndef EXTERNAL_INTERRUPT_H
#define EXTERNAL_INTERRUPT_H

/*** INCLUDE ************************************/
#include "stm32f401re.h"

/*** DEFINE ************************************/

/*** TYPEDEF ************************************/
/*
 * @Exti_Line_e
 */
typedef enum
{
    EXTI_LINE0  = 0U,
    EXTI_LINE1  = 1U,
    EXTI_LINE2  = 2U,
    EXTI_LINE3  = 3U,
    EXTI_LINE4  = 4U,
    EXTI_LINE5  = 5U,
    EXTI_LINE6  = 6U,
    EXTI_LINE7  = 7U,
    EXTI_LINE8  = 8U,
    EXTI_LINE9  = 9U,
    EXTI_LINE10 = 10U,
    EXTI_LINE11 = 11U,
    EXTI_LINE12 = 12U,
    EXTI_LINE13 = 13U,
    EXTI_LINE14 = 14U,
    EXTI_LINE15 = 15U,
    EXTI_LINE16 = 16U,
    EXTI_LINE17 = 17U,
    EXTI_LINE18 = 18U,
    EXTI_LINE21 = 21U,
    EXTI_LINE22 = 22U
} Exti_Line_e;

/*** PROTOTYPE ****************************/
void Exti_IntEnable(Exti_RegDef *p_Exti_st, Exti_Line_e LineNum_e);
void Exti_EventEnable(Exti_RegDef *p_Exti_st, Exti_Line_e LineNum_e);
void Exti_EdgeCfg(Exti_RegDef *p_Exti_st, Exti_Line_e LineNum_e);
void Exti_SoftIntGenarate(Exti_RegDef *p_Exti_st, Exti_Line_e LineNum_e);
void Exti_ClearPending(Exti_RegDef *p_Exti_st, Exti_Line_e LineNum_e);

#endif /* EXTERNAL_INTERRUPT_H */
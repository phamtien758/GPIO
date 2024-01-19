/*
 * File: external_interrupt.c
 * Author: phamtien758
 * 
 */

/*** INCLUDE ************************************/
#include "external_interrupt.h"

/*** PROTOTYPE **********************************/
static boolean Exti_IsLineValid(Exti_Line_e LineNum_e);

/*** VARIABLE ***********************************/

/*** STATIC FUNCTION ****************************/
static boolean Exti_IsLineValid(Exti_Line_e LineNum_e)
{
    boolean RetValue;

    if(((EXTI_LINE0 <= LineNum_e) && (EXTI_LINE18 >= LineNum_e)) || \
       (EXTI_LINE21 == LineNum_e) || (EXTI_LINE22 == LineNum_e))
    {
        RetValue = (boolean)TRUE;
    }
    else
    {
        RetValue = (boolean)FALSE;
    }

    return RetValue;
}
/*** FUNCTIONS **********************************/
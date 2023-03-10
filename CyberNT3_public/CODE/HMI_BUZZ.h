/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : HMI_BUZZ.H
**     Project   : CyberNT3
**     Processor : 56F8366
**     Component : PWM
**     Version   : Component 02.221, Driver 02.02, CPU db: 2.87.042
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2011/8/20, 22:03
**     Abstract  :
**         This bean implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings  :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       70            |  PWMA5
**             ----------------------------------------------------
**
**         Timer name                  : PWM_A [15-bit]
**         Counter                     : PWMA_PMCNT [61764]
**         Mode register               : PWMA_PMCTL [61760]
**         Run register                : PWMA_PMCTL [61760]
**         Prescaler                   : PWMA_PMCTL [61760]
**         Compare register            : PWMA_PWMVAL5 [61771]
**         Flip-flop register          : PWMA_PMCFG [61775]
**
**         User handling procedure     : not specified
**
**
**         Initialization:
**              Output level           : high
**              Timer                  : Enabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 10000000 Hz
**           Initial value of            period     pulse width
**             Xtal ticks              : 24672      1
**             microseconds            : 3084       0
**             milliseconds            : 3          0
**             seconds (real)          : 0.003084   0.0000001
**
**     Contents  :
**         SetRatio16 - byte HMI_BUZZ_SetRatio16(word Ratio);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __HMI_BUZZ
#define __HMI_BUZZ

/* MODULE HMI_BUZZ. */

#include "Cpu.h"

#define HMI_BUZZ_PERIOD_VALUE 30840UL  /* Initial period value in ticks of the timer. It is available only if the bean is enabled in high speed mode. */
#define HMI_BUZZ_PERIOD_VALUE_HIGH 30840UL /* Period value in ticks of the timer in high speed mode. It is available only if the bean is enabled in high speed mode. */

byte HMI_BUZZ_SetRatio16(word Ratio);
/*
** ===================================================================
**     Method      :  HMI_BUZZ_SetRatio16 (component PWM)
**
**     Description :
**         This method sets a new duty-cycle ratio.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Ratio      - Ratio is expressed as an 16-bit unsigned integer
**                      number. 0 - 65535 value is proportional
**                      to ratio 0 - 100%
**         Note: Calculated duty depends on the timer possibilities
**               and on the selected period.
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

void HMI_BUZZ_Init(void);
/*
** ===================================================================
**     Method      :  HMI_BUZZ_Init (component PWM)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


/* END HMI_BUZZ. */

#endif /* ifndef __HMI_BUZZ */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

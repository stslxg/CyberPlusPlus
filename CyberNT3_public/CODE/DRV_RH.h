/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : DRV_RH.H
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
**                       35            |  PWMB1
**             ----------------------------------------------------
**
**         Timer name                  : PWM_B [15-bit]
**         Counter                     : PWMB_PMCNT [61796]
**         Mode register               : PWMB_PMCTL [61792]
**         Run register                : PWMB_PMCTL [61792]
**         Prescaler                   : PWMB_PMCTL [61792]
**         Compare register            : PWMB_PWMVAL1 [61799]
**         Flip-flop register          : PWMB_PMCFG [61807]
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
**             Clock                   : 80000000 Hz
**           Initial value of            period     pulse width
**             Xtal ticks              : 400        200
**             microseconds            : 50         25
**             seconds (real)          : 0.00005    0.000025
**
**     Contents  :
**         SetRatio16 - byte DRV_RH_SetRatio16(word Ratio);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __DRV_RH
#define __DRV_RH

/* MODULE DRV_RH. */

#include "Cpu.h"

#define DRV_RH_PERIOD_VALUE 4000UL     /* Initial period value in ticks of the timer. It is available only if the bean is enabled in high speed mode. */
#define DRV_RH_PERIOD_VALUE_HIGH 4000UL /* Period value in ticks of the timer in high speed mode. It is available only if the bean is enabled in high speed mode. */

byte DRV_RH_SetRatio16(word Ratio);
/*
** ===================================================================
**     Method      :  DRV_RH_SetRatio16 (component PWM)
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

void DRV_RH_Init(void);
/*
** ===================================================================
**     Method      :  DRV_RH_Init (component PWM)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


/* END DRV_RH. */

#endif /* ifndef __DRV_RH */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

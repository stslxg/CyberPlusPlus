/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : DRV_RH.C
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


/* MODULE DRV_RH. */

#include "DRV_RH.h"

static word RatioStore;                /* Ratio of L-level to H-level */

/* Internal method prototypes */
static void SetRatio(void);

#define SetPV(Val) setRegBitGroup(PWMB_PMCTL,PRSC,(Val))

/*
** ===================================================================
**     Method      :  SetRatio (component PWM)
**
**     Description :
**         Calculates and sets new duty ratio. The method is called 
**         automatically as a part of several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetRatio(void)
{
  setReg(PWMB_PWMVAL1,((getReg(PWMB_PWMCM)+1) * (dword)RatioStore) >> 16); /* Calculate new value according to the given ratio */
  setRegBit(PWMB_PMCTL,LDOK);          /* Load counter and modulo registers into buffers */
}
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
byte DRV_RH_SetRatio16(word Ratio)
{
  RatioStore = Ratio;                  /* Store new value of the ratio */
  SetRatio();                          /* Calculate and set up new appropriate duty value */
  return ERR_OK;                       /* OK */
}

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
void DRV_RH_Init(void)
{
  RatioStore = (word)32768U;           /* Store initial value of the ratio */
  setReg(PWMB_PWMVAL1,2000);           /* Store initial value to the duty-compare register */
  SetPV((byte)0);                      /* Set prescaler register according to the selected high speed CPU mode */
}

/* END DRV_RH. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : LEFTPA.C
**     Project   : CyberNT3
**     Processor : 56F8366
**     Component : PulseAccumulator
**     Version   : Component 01.183, Driver 02.03, CPU db: 2.87.042
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2011/8/20, 22:03
**     Abstract  :
**          Pulse accumulator decodes the primary and secondary external inputs as
**          quadrature encoded signals. Quadrature signals are usually generated by
**          rotary or linear sensors used to monitor movement of motor shafts or
**          mechanical equipment.
**     Settings  :
**             Pulse accumulator       : TMRA3_PACNT
**
**
**         Mode                        : Quadrature
**
**         Initialization:
**              Pulse accumulator      : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Counter                : TMRA3_CNTR [61557]
**              Hold                   : TMRA3_HOLD [61556]
**              Run                    : TMRA3_CTRL [61558]
**              Prescaler              : TMRA3_CTRL [61558]
**
**         User handling procedure     : not specified
**
**     Contents  :
**         GetCounterValue  - void LEFTPA_GetCounterValue(word *Value);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE LEFTPA. */

#include "LEFTPA.h"

/*
** ===================================================================
**     Method      :  LEFTPA_GetCounterValue (component PulseAccumulator)
**
**     Description :
**         This method returns the content of the pulse accumulator
**         counter.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Value           - Pointer to returned value. [Note:]
**                           Parameter type depends on the width of the
**                           selected counter (may be 8, 16, 32 or 64
**                           bits long). See the method prototype in the
**                           generated module.
**     Returns     : Nothing
** ===================================================================
*/
void LEFTPA_GetCounterValue(LEFTPA_TCounterValue *Value)
{
  *Value = getReg(TMRA3_CNTR);         /* Return counter value */
}

/*
** ===================================================================
**     Method      :  LEFTPA_Init (component PulseAccumulator)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void LEFTPA_Init(void)
{
  /* TMRA3_CTRL: CM=0,PCS=2,SCS=3,ONCE=0,LENGTH=0,DIR=1,Co_INIT=0,OM=0 */
  setReg(TMRA3_CTRL,1424);             /* Set up mode */
  /* TMRA3_SCR: TCF=0,TCFIE=0,TOF=0,TOFIE=0,IEF=0,IEFIE=0,IPS=0,INPUT=0,Capture_Mode=0,MSTR=0,EEOF=0,VAL=0,FORCE=0,OPS=0,OEN=0 */
  setReg(TMRA3_SCR,0);
  setReg(TMRA3_CNTR,0);                /* Reset counter register */
  setReg(TMRA3_LOAD,0);                /* Reset load register */
  setReg(TMRA3_CMP1,65535);            /* Set up compare 1 register */
  setReg(TMRA3_CMP2,0);                /* Set up compare 2 register */
  /* TMRA3_COMSCR: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,TCF2EN=0,TCF1EN=0,TCF2=0,TCF1=0,CL2=0,CL1=0 */
  setReg(TMRA3_COMSCR,0);
  setRegBitGroup(TMRA3_CTRL,CM,4);     /* Run counter */
}

/* END LEFTPA. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

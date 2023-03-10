/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : RIGHTPA.H
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
**             Pulse accumulator       : TMRA2_PACNT
**
**
**         Mode                        : Quadrature
**
**         Initialization:
**              Pulse accumulator      : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Counter                : TMRA2_CNTR [61541]
**              Hold                   : TMRA2_HOLD [61540]
**              Run                    : TMRA2_CTRL [61542]
**              Prescaler              : TMRA2_CTRL [61542]
**
**         User handling procedure     : not specified
**
**     Contents  :
**         GetCounterValue  - void RIGHTPA_GetCounterValue(word *Value);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __RIGHTPA
#define __RIGHTPA

/* MODULE RIGHTPA. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
#include "Cpu.h"

#ifndef __BWUserType_RIGHTPA_TCounterValue
#define __BWUserType_RIGHTPA_TCounterValue
  typedef word RIGHTPA_TCounterValue;  /* Counter value, width depend on on selected peripheal. */
#endif


void RIGHTPA_GetCounterValue(RIGHTPA_TCounterValue *Value);
/*
** ===================================================================
**     Method      :  RIGHTPA_GetCounterValue (component PulseAccumulator)
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

void RIGHTPA_Init(void);
/*
** ===================================================================
**     Method      :  RIGHTPA_Init (component PulseAccumulator)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END RIGHTPA. */

#endif /* ifndef __RIGHTPA */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

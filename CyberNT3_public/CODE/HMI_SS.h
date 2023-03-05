/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : HMI_SS.H
**     Project   : CyberNT3
**     Processor : 56F8366
**     Component : BitIO
**     Version   : Component 02.075, Driver 01.18, CPU db: 2.87.042
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2011/8/20, 22:03
**     Abstract  :
**         This bean "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This bean is set to work in Output direction only.
**         Methods of this bean are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       129           |  GPIOE7_SS0B
**             ----------------------------------------------------
**
**         Port name                   : GPIOE_Low
**
**         Bit number (in port)        : 7
**         Bit mask of the port        : 128
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 1
**         Initial pull option         : off
**
**         Port data register          : GPIO_E_DR [62257]
**         Port control register       : GPIO_E_DDR [62258]
**         Port function register      : GPIO_E_PER [62259]
**
**         Optimization for            : speed
**     Contents  :
**         ClrVal - void HMI_SS_ClrVal(void);
**         SetVal - void HMI_SS_SetVal(void);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __HMI_SS_H
#define __HMI_SS_H

/* MODULE HMI_SS. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"

#include "Cpu.h"


#define HMI_SS_PIN_MASK         ((byte)128) /* Pin mask */


/*
** ===================================================================
**     Method      :  HMI_SS_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define HMI_SS_ClrVal() (clrRegBits(GPIO_E_DR,HMI_SS_PIN_MASK))

/*
** ===================================================================
**     Method      :  HMI_SS_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define HMI_SS_SetVal() (setRegBits(GPIO_E_DR,HMI_SS_PIN_MASK))


/* END HMI_SS. */

#endif /* __HMI_SS_H*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

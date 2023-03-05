/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Inhr1.H
**     Project   : CyberNT3
**     Processor : 56F8366
**     Component : BitIO
**     Version   : Component 02.075, Driver 01.18, CPU db: 2.87.042
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2011/8/20, 22:03
**     Abstract  :
**         This bean "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This bean is set to work in Input direction only.
**         Methods of this bean are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       131           |  GPIOE6_MISO0
**             ----------------------------------------------------
**
**         Port name                   : GPIOE_Low
**
**         Bit number (in port)        : 6
**         Bit mask of the port        : 64
**
**         Initial direction           : Input (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : GPIO_E_DR [62257]
**         Port control register       : GPIO_E_DDR [62258]
**         Port function register      : GPIO_E_PER [62259]
**
**         Optimization for            : speed
**     Contents  :
**         GetVal - bool Inhr1_GetVal(void);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __Inhr1_H
#define __Inhr1_H

/* MODULE Inhr1. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"

#include "Cpu.h"


#define Inhr1_PIN_MASK          ((byte)64) /* Pin mask */


/*
** ===================================================================
**     Method      :  Inhr1_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This bean is set to work in Input direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define Inhr1_GetVal() ((bool)(getRegBits(GPIO_E_DR,Inhr1_PIN_MASK)))


/* END Inhr1. */

#endif /* __Inhr1_H*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

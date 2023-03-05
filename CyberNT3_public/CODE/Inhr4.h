/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Inhr4.H
**     Project   : CyberNT3
**     Processor : 56F8366
**     Component : BitIO
**     Version   : Component 02.075, Driver 01.18, CPU db: 2.87.042
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2011/8/20, 22:03
**     Abstract  :
**         This bean "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This bean is not set in the "Safe mode". See help.
**         Methods of this bean are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       52            |  GPIOD11_ISB1
**             ----------------------------------------------------
**
**         Port name                   : GPIOD_High
**
**         Bit number (in port)        : 11
**         Bit mask of the port        : 2048
**
**         Initial direction           : Input (direction can be changed)
**         Safe mode                   : no
**         Initial output value        : 1
**         Initial pull option         : up
**
**         Port data register          : GPIO_D_DR [62241]
**         Port control register       : GPIO_D_DDR [62242]
**         Port function register      : GPIO_D_PER [62243]
**
**         Optimization for            : speed
**     Contents  :
**         SetDir - void Inhr4_SetDir(bool Dir);
**         GetVal - bool Inhr4_GetVal(void);
**         PutVal - void Inhr4_PutVal(bool Val);
**         ClrVal - void Inhr4_ClrVal(void);
**         SetVal - void Inhr4_SetVal(void);
**         NegVal - void Inhr4_NegVal(void);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __Inhr4_H
#define __Inhr4_H

/* MODULE Inhr4. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"

#include "Cpu.h"


#define Inhr4_PIN_MASK          ((word)2048) /* Pin mask */
#define Inhr4_PIN_MASK_SHIFTED  ((byte)8) /* Shifted pin mask by 8, if pin mask is greater than 128 */


/*
** ===================================================================
**     Method      :  Inhr4_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define Inhr4_GetVal() ((bool)((getReg(GPIO_D_DR) >> 8) & Inhr4_PIN_MASK_SHIFTED))

/*
** ===================================================================
**     Method      :  Inhr4_PutVal (component BitIO)
**
**     Description :
**         This method writes the new output value.
**         Note: If direction is set to input the method code may not
**               work properly.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void Inhr4_PutVal(bool Val);

/*
** ===================================================================
**     Method      :  Inhr4_SetDir (component BitIO)
**
**     Description :
**         This method sets direction of the bean.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Dir        - Direction to set (FALSE or TRUE)
**                      FALSE = Input, TRUE = Output
**     Returns     : Nothing
** ===================================================================
*/
void Inhr4_SetDir(bool Dir);

/*
** ===================================================================
**     Method      :  Inhr4_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**         Note: If direction is set to input the method code may not
**               work properly.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define Inhr4_ClrVal() (clrRegBits(GPIO_D_DR,Inhr4_PIN_MASK))

/*
** ===================================================================
**     Method      :  Inhr4_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**         Note: If direction is set to input the method code may not
**               work properly.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define Inhr4_SetVal() (setRegBits(GPIO_D_DR,Inhr4_PIN_MASK))

/*
** ===================================================================
**     Method      :  Inhr4_NegVal (component BitIO)
**
**     Description :
**         This method negates (inverts) the output value.
**         Note: If direction is set to input the method code may not
**               work properly.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define Inhr4_NegVal() (changeRegBits(GPIO_D_DR,Inhr4_PIN_MASK))


/* END Inhr4. */

#endif /* __Inhr4_H*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
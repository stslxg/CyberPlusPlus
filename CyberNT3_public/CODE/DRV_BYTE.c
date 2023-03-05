/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : DRV_BYTE.C
**     Project   : CyberNT3
**     Processor : 56F8366
**     Component : ByteIO
**     Version   : Component 02.058, Driver 01.19, CPU db: 2.87.042
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2011/8/20, 22:03
**     Abstract  :
**         This bean "ByteIO" implements an one-byte input/output.
**         It uses one 8-bit port.
**         Note: This bean is set to work in Output direction only.
**         Methods of this bean are mostly implemented as a macros 
**         (if supported by target langauage and compiler).
**     Settings  :
**         Port name                   : GPIOA_Low
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0 = 000H
**         Initial pull option         : off
**
**         8-bit data register         : GPIO_A_DR [62177]
**         8-bit control register      : GPIO_A_DDR [62178]
**         8-bit function register     : GPIO_A_PER [62179]
**
**             ----------------------------------------------------
**                   Bit     |   Pin   |   Name
**             ----------------------------------------------------
**                    0      |    19   |   GPIOA0_A8
**                    1      |    20   |   GPIOA1_A9
**                    2      |    21   |   GPIOA2_A10
**                    3      |    22   |   GPIOA3_A11
**                    4      |    23   |   GPIOA4_A12
**                    5      |    24   |   GPIOA5_A13
**                    6      |    25   |   GPIOA6_A14
**                    7      |    26   |   GPIOA7_A15
**             ----------------------------------------------------
**     Contents  :
**         PutVal - void DRV_BYTE_PutVal(byte Val);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE DRV_BYTE. */

#include "DRV_BYTE.h"
/*Including shared modules, which are used for all project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include "Cpu.h"


/*
** ===================================================================
**     Method      :  DRV_BYTE_PutVal (component ByteIO)
**
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val        - Output value (0 to 255)
**     Returns     : Nothing
** ===================================================================
*/
void DRV_BYTE_PutVal(byte Val)
{
  setReg(GPIO_A_DR,(getReg(GPIO_A_DR)) & ~DRV_BYTE_PORT_MASK | ((word)(Val & DRV_BYTE_PORT_MASK))); /* Set-up bits on port */
}

/* END DRV_BYTE. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

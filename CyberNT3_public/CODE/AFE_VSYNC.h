/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : AFE_VSYNC.H
**     Project   : CyberNT3
**     Processor : 56F8366
**     Component : ExtInt
**     Version   : Component 02.094, Driver 02.04, CPU db: 2.87.042
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2011/8/20, 22:03
**     Abstract  :
**         This bean "ExtInt" implements an external 
**         interrupt, its control methods and interrupt/event 
**         handling procedure.
**         The bean uses one pin which generates interrupt on 
**         selected edge.
**     Settings  :
**         Interrupt name              : INT_GPIO_D
**         User handling procedure     : AFE_VSYNC_OnInterrupt
**
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       48            |  GPIOD0_CS2B_CAN2_Tx
**             ----------------------------------------------------
**
**         Port name                   : GPIOD_Low
**
**         Bit number (in port)        : 0
**         Bit mask of the port        : 1
**
**         Signal edge/level           : falling
**         Priority                    : 2
**         Pull option                 : up
**         Initial state               : Disabled
**
**         Edge register               : GPIO_D_IPOLR [62246]
**         Priority register           : INTC_IPR3 [61859]
**         Enable register             : GPIO_D_IENR [62245]
**         Request register            : GPIO_D_IESR [62248]
**
**         Port data register          : GPIO_D_DR [62241]
**         Port control register       : GPIO_D_DDR [62242]
**         Port function register      : GPIO_D_PER [62243]
**     Contents  :
**         Enable - void AFE_VSYNC_Enable(void);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __AFE_VSYNC_H
#define __AFE_VSYNC_H

/* MODULE AFE_VSYNC. */

/*Including shared modules, which are used in the whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
#include "Events.h"
#include "Cpu.h"


#define AFE_VSYNC_PIN_MASK      ((byte)1) /* Pin mask */

void AFE_VSYNC_Enable(void);
/*
** ===================================================================
**     Method      :  AFE_VSYNC_Enable (component ExtInt)
**
**     Description :
**         Enable the bean - the external events are accepted. This
**         method is enabled only if HW module allows enable/disable of
**         the interrupt.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END AFE_VSYNC. */

#endif /* __AFE_VSYNC_H*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

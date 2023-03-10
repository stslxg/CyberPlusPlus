/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : DRV_PS.H
**     Project   : CyberNT3
**     Processor : 56F8366
**     Component : PulseStream
**     Version   : Component 01.044, Driver 02.02, CPU db: 2.87.042
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2011/8/20, 22:03
**     Abstract  :
**          This bean "PulseStream" implements a pulse stream generator.
**          PulseStream allows generation of several pulses 1:1 with a
**          predefined width. The signal is generated after the Enable
**          method is invoked. Number of pulses is predefined in the bean
**          and may be changed by method SetNumOfPulses.
**     Settings  :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       118           |  GPIOE8_TC0
**             ----------------------------------------------------
**
**         Timer name                  : TMRC0 (16-bit)
**         Compare name                : TMRC0_Compare
**
**         Number of output pulses     : 1
**
**         High speed mode
**             Prescaler               : divide-by-4
**             Clock                   : 20000000 Hz
**           Pulse width
**             Xtal ticks              : 12000
**             microseconds            : 1500
**             milliseconds            : 2
**             seconds (real)          : 0.0015
**             Hz                      : 667
**             kHz                     : 1
**
**         Runtime setting             : pulse width interval (continual setting)
**             ticks                   : 8000 to 16000 ticks
**             microseconds            : 1000 to 2000 microseconds
**             milliseconds            : 1 to 2 milliseconds
**             seconds (real)          : 0.001 to 0.002 seconds
**             Hz                      : 500 to 1000 Hz
**
**         Initialization:
**              Output level           : low
**              Events                 : Disabled
**
**         Timer registers
**              Counter                : TMRC0_CNTR [61637]
**              Mode                   : TMRC0_CTRL [61638]
**              Run                    : TMRC0_CTRL [61638]
**              Prescaler              : TMRC0_CTRL [61638]
**
**         Compare registers
**              Compare                : TMRC0_CMP1 [61632]
**
**         Clock source registers
**              Timer name             : TMRC1 (16-bit)
**              Counter                : TMRC1_CNTR [61653]
**              Mode                   : TMRC1_CTRL [61654]
**              Run                    : TMRC1_CTRL [61654]
**              Prescaler              : TMRC1_CTRL [61654]
**              Compare                : TMRC1_CMP1 [61648]
**
**         User handling procedure     : not specified
**
**     Contents  :
**         Enable          - byte DRV_PS_Enable(void);
**         SetClockTicks16 - byte DRV_PS_SetClockTicks16(word Ticks);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __DRV_PS
#define __DRV_PS

/* MODULE DRV_PS. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
#include "Cpu.h"

#define DRV_PS_SCT16_MIN   8000U       /* Lower bound of interval for parameter of method SetClockTicks16 */
#define DRV_PS_SCT16_MAX   16000U      /* Upper bound of interval for parameter of method SetClockTicks16 */
/* Deprecated constants */
#define DRV_PS_SCT16Min    8000        /* Lower bound of interval for method SetClockTicks16 */
#define DRV_PS_SCT16Max    16000       /* Upper bound of interval for method SetClockTicks16 */


byte DRV_PS_Enable(void);
/*
** ===================================================================
**     Method      :  DRV_PS_Enable (component PulseStream)
**
**     Description :
**         Enables the bean - starts the signal generation. This
**         method must be generated. After all pulses are generated,
**         the bean is automatically disabled (and event < OnEnd >
**         may be generated).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte DRV_PS_SetClockTicks16(word Ticks);
/*
** ===================================================================
**     Method      :  DRV_PS_SetClockTicks16 (component PulseStream)
**
**     Description :
**         This method sets the new pulse width of the clock signal.
**         The pulse width is expressed in CPU [ticks] as a 16-bit
**         unsigned integer number. This method is only available
**         for external clock source and only when the runtime setting
**         type 'from interval' is selected in the <Timing dialog
**         box> of the Runtime setting area.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ticks           - Clock to set [in Xtal ticks]
**                        (8000 to 16000 ticks)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/

void DRV_PS_Init(void);
/*
** ===================================================================
**     Method      :  DRV_PS_Init (component PulseStream)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END DRV_PS. */

#endif /* ifndef __DRV_PS */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

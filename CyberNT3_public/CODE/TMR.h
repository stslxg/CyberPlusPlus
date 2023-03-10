/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : TMR.H
**     Project   : CyberNT3
**     Processor : 56F8366
**     Component : TimerInt
**     Version   : Component 02.157, Driver 02.02, CPU db: 2.87.042
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2011/8/20, 22:03
**     Abstract  :
**         This bean "TimerInt" implements a periodic interrupt.
**         When the bean and its events are enabled, the "OnInterrupt"
**         event is called periodically with the period that you specify.
**         TimerInt supports also changing the period in runtime.
**         The source of periodic interrupt can be timer compare or reload
**         register or timer-overflow interrupt (of free running counter).
**     Settings  :
**         Timer name                  : TMRA0 (16-bit)
**         Compare name                : TMRA0_Compare
**         Counter shared              : No
**
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 80000000 Hz
**           Initial period/frequency
**             Xtal ticks              : 4000
**             microseconds            : 500
**             seconds (real)          : 0.0005
**             Hz                      : 2000
**             kHz                     : 2
**
**         Runtime setting             : none
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Counter                : TMRA0_CNTR [61509]
**              Mode                   : TMRA0_CTRL [61510]
**              Run                    : TMRA0_CTRL [61510]
**              Prescaler              : TMRA0_CTRL [61510]
**
**         Compare registers
**              Compare                : TMRA0_CMP1 [61504]
**
**         Flip-flop registers
**              Mode                   : TMRA0_SCR [61511]
**     Contents  :
**         No public methods
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __TMR
#define __TMR

/* MODULE TMR. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
#include "Cpu.h"


void TMR_Init(void);
/*
** ===================================================================
**     Method      :  TMR_Init (component TimerInt)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void TMR_Interrupt(void);
/*
** ===================================================================
**     Method      :  TMR_Interrupt (component TimerInt)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes the beans event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END TMR. */

#endif /* ifndef __TMR */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

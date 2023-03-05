/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : TMR.C
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

/* MODULE TMR. */

#include "Events.h"
#include "TMR.h"



/* Internal method prototypes */
static void SetCV(word Val);
static void SetPV(byte Val);

/*
** ===================================================================
**     Method      :  SetCV (component TimerInt)
**
**     Description :
**         Sets compare or preload register value. The method is called 
**         automatically as a part of several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetCV(word Val)
{
  EnterCritical();                     /* Disable global interrupts */
  setReg(TMRA0_CMPLD1,Val);            /* Store given value to the compare preload 1 register */
  setReg(TMRA0_CMPLD2,Val);            /* Store given value to the compare preload 2 register */
  ExitCritical();                      /* Enable global interrupts */
}

/*
** ===================================================================
**     Method      :  SetPV (component TimerInt)
**
**     Description :
**         Sets prescaler value. The method is called automatically as a 
**         part of several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetPV(byte Val)
{
  setRegBitGroup(TMRA0_CTRL,PCS,Val);  /* Store given value to the prescaler */
  setReg(TMRA0_CNTR,0);                /* Reset counter */
}

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
void TMR_Init(void)
{
  /* TMRA0_CTRL: CM=0,PCS=0,SCS=0,ONCE=0,LENGTH=1,DIR=0,Co_INIT=0,OM=4 */
  setReg(TMRA0_CTRL,36);               /* Stop timer, use alternating compare registers */
  /* TMRA0_SCR: TCF=0,TCFIE=1,TOF=0,TOFIE=0,IEF=0,IEFIE=0,IPS=0,INPUT=0,Capture_Mode=0,MSTR=0,EEOF=0,VAL=0,FORCE=0,OPS=0,OEN=0 */
  setReg(TMRA0_SCR,16384);             /* Enable compare interrupt */
  setReg(TMRA0_CNTR,0);                /* Reset counter register */
  setReg(TMRA0_LOAD,0);                /* Reset load register */
  setReg(TMRA0_CMP1,39999);            /* Set up compare 1 register */
  setReg(TMRA0_CMP2,39999);            /* Set up compare 2 register */
  /* TMRA0_COMSCR: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,TCF2EN=0,TCF1EN=0,TCF2=0,TCF1=0,CL2=1,CL1=2 */
  setReg(TMRA0_COMSCR,6);              /* Compare load control */
  SetCV((word)39999);                  /* Store appropriate value to the compare register according to the selected high speed CPU mode */
  SetPV((byte)8);                      /* Set prescaler register according to the selected high speed CPU mode */
  setRegBitGroup(TMRA0_CTRL,CM,1);     /* Run counter */
}

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
#pragma interrupt alignsp saveall
void TMR_Interrupt(void)
{
  clrRegBit(TMRA0_SCR,TCF);            /* Reset interrupt request flag */
  TMR_OnInterrupt();                   /* Invoke user event */
}

/* END TMR. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : DRV_PS.C
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

/* MODULE DRV_PS. */

#include "DRV_PS.h"

static word CmpHighVal;                /* Compare register value for high speed CPU mode */


/* Internal method prototypes */
static void SetCV(word Val);
static void SetPV(byte Val);

/*
** ===================================================================
**     Method      :  SetCV (component PulseStream)
**
**     Description :
**         Sets compare or preload register value. The method is called 
**         automatically as a part of several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetCV(word Val)
{
  setReg(TMRC1_CMP1,Val - 1);          /* Store corrected value to the compare 1 register */
}

/*
** ===================================================================
**     Method      :  SetPV (component PulseStream)
**
**     Description :
**         Sets prescaler value. The method is called automatically as a 
**         part of several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetPV(byte Val)
{
  setRegBitGroup(TMRC1_CTRL,PCS,Val);  /* Store given value to the prescaler */
  setReg(TMRC1_CNTR,0);                /* Reset counter */
}

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
byte DRV_PS_Enable(void)
{
  if (getRegBitGroup(TMRC0_CTRL,CM)) { /* Is counter running? */
    return ERR_ENABLED;                /* If yes then error */
  }
  setRegBitGroup(TMRC1_CTRL,CM,0);     /* Stop source clock counter */
  setRegBit(TMRC1_SCR,FORCE);          /* Synchronize source clock */
  setReg(TMRC1_CNTR,0);                /* Reset source counter register */
  EnterCritical();                     /* Disable global interrupts */
  setRegBitGroup(TMRC1_CTRL,CM,1);     /* Run source clock counter */
  setRegBitGroup(TMRC0_CTRL,CM,1);     /* Run counter */
  ExitCritical();                      /* Enable global interrupts */
  return ERR_OK;                       /* OK */
}

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
byte DRV_PS_SetClockTicks16(word Ticks)
{
  dlong rtval;                         /* Result of two 32-bit numbers multiplication */
  word rtword;                         /* Result of 64-bit number division */

  if ((Ticks > (word)DRV_PS_SCT16_MAX) || (Ticks < (word)DRV_PS_SCT16_MIN)) { /* Is the given value out of range? */
    return ERR_RANGE;                  /* If yes then error */
  }
  PE_Timer_LngMul((dword)Ticks,41943040UL,&rtval); /* Multiply given value and high speed CPU mode coefficient */
  if (PE_Timer_LngHi3(rtval[0],rtval[1],&rtword)) { /* Is the result greater or equal than 65536 ? */
    rtword = (word)65535U;             /* If yes then use maximal possible value */
  }
  CmpHighVal = rtword;                 /* Store result (compare register value for high speed CPU mode) to the variable CmpHighVal */
  SetCV(CmpHighVal);                   /* Store appropriate value to the compare register according to the selected high speed CPU mode */
  return ERR_OK;                       /* OK */
}

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
void DRV_PS_Init(void)
{
  /* TMRC1_CTRL: CM=0,PCS=0,SCS=0,ONCE=0,LENGTH=1,DIR=0,Co_INIT=0,OM=3 */
  setReg(TMRC1_CTRL,35);               /* Set up mode */
  /* TMRC1_SCR: TCF=0,TCFIE=0,TOF=0,TOFIE=0,IEF=0,IEFIE=0,IPS=0,INPUT=0,Capture_Mode=0,MSTR=0,EEOF=0,VAL=0,FORCE=0,OPS=0,OEN=0 */
  setReg(TMRC1_SCR,0);
  setReg(TMRC1_LOAD,0);                /* Reset load register */
  /* TMRC1_COMSCR: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,TCF2EN=0,TCF1EN=0,TCF2=0,TCF1=0,CL2=0,CL1=0 */
  setReg(TMRC1_COMSCR,0);              /* Set up comparator control register */
  /* TMRC0_CTRL: CM=0,PCS=5,SCS=0,ONCE=1,LENGTH=1,DIR=0,Co_INIT=0,OM=7 */
  setReg(TMRC0_CTRL,2663);             /* Set up mode */
  /* TMRC0_SCR: TCF=0,TCFIE=0,TOF=0,TOFIE=0,IEF=0,IEFIE=0,IPS=0,INPUT=0,Capture_Mode=0,MSTR=0,EEOF=0,VAL=0,FORCE=0,OPS=0,OEN=1 */
  setReg(TMRC0_SCR,1);
  setReg(TMRC0_CNTR,0);                /* Reset counter register */
  setReg(TMRC0_LOAD,0);                /* Reset load register */
  setReg(TMRC0_CMP1,1);                /* Set up compare 1 register */
  /* TMRC0_COMSCR: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,TCF2EN=0,TCF1EN=0,TCF2=0,TCF1=0,CL2=0,CL1=0 */
  setReg(TMRC0_COMSCR,0);              /* Set up comparator control register */
  CmpHighVal = (word)30000U;           /* Compare register value for high speed CPU mode */
  SetCV(CmpHighVal);                   /* Store appropriate value to the compare register according to the selected high speed CPU mode */
  SetPV((byte)10);                     /* Set prescaler register according to the selected high speed CPU mode */
}

/* END DRV_PS. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

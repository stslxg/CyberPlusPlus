/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : PE_Timer.H
**     Project   : CyberNT3
**     Processor : 56F8366
**     Component : PE_Timer
**     Version   : Driver 01.03
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2011/8/20, 22:03
**     Abstract  :
**         This module "PE_Timer" implements internal methods and definitions
**         used by beans working with timers.
**     Settings  :
**     Contents  :
**         No public methods
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __PE_Timer
#define __PE_Timer

/* MODULE PE_Timer. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Const.h"

void PE_Timer_LngMul(dword va1, dword va2, dlong *var);
/*
** ===================================================================
**     Method      :  PE_Timer_LngMul (component PE_Timer)
**
**     Description :
**         32bits number x 32bits number -> 64bits number. The method is 
**         called automatically as a part of several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

bool PE_Timer_LngHi3(dword Low, dword High, word *Out);
/*
** ===================================================================
**     Method      :  PE_Timer_LngHi3 (component PE_Timer)
**
**     Description :
**         64bits number / 2^32 -> 16bits number. The method is called 
**         automatically as a part of several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END PE_Timer. */

#endif /* ifndef  __PE_Timer */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

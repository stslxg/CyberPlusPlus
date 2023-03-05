/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : MFR.H
**     Project   : CyberNT3
**     Processor : 56F8366
**     Component : DSP_Func_MFR
**     Version   : Component 01.044, Driver 01.12, CPU db: 2.87.042
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2011/8/20, 22:03
**     Abstract  :
**          This bean encapsulates the basic math functions for both
**          16-bit and 32-bit fractional types.
**     Settings  :
**          Bean Name                      : MFR
**          Use Assembler Files            : yes
**     Contents  :
**         abs_s       - Frac16 MFR_abs_s(Frac16 x);
**         add         - Frac16 MFR_add(Frac16 x, Frac16 y);
**         div_s       - Frac16 MFR_div_s(Frac16 x, Frac16 y);
**         mac_r       - Frac16 MFR_mac_r(Frac32 w, Frac16 x, Frac16 y);
**         msu_r       - Frac16 MFR_msu_r(Frac32 w, Frac16 x, Frac16 y);
**         mult        - Frac16 MFR_mult(Frac16 x, Frac16 y);
**         mult_r      - Frac16 MFR_mult_r(Frac16 x, Frac16 y);
**         negate      - Frac16 MFR_negate(Frac16 x);
**         round       - Frac16 MFR_round(Frac32 x);
**         shl         - Frac16 MFR_shl(Frac16 x, Int16 n);
**         shr         - Frac16 MFR_shr(Frac16 x, Int16 n);
**         shr_r       - Frac16 MFR_shr_r(Frac16 x, Int16 n);
**         sub         - Frac16 MFR_sub(Frac16 x, Frac16 y);
**         L_abs       - Frac32 MFR_L_abs(Frac32 x);
**         L_add       - Frac32 MFR_L_add(Frac32 x, Word32 y);
**         div_ls      - Frac16 MFR_div_ls(Frac32 x, Frac16 y);
**         L_mac       - Frac32 MFR_L_mac(Frac32 w, Frac16 x, Frac16 y);
**         L_msu       - Frac32 MFR_L_msu(Frac32 w, Frac16 x, Frac16 y);
**         L_mult      - Frac32 MFR_L_mult(Frac16 x, Frac16 y);
**         L_mult_ls   - Frac32 MFR_L_mult_ls(Frac32 x, Frac16 y);
**         L_negate    - Frac32 MFR_L_negate(Frac32 x);
**         L_shl       - Frac32 MFR_L_shl(Frac32 x, Int16 n);
**         L_shr       - Frac32 MFR_L_shr(Frac32 x, Int16 n);
**         L_shr_r     - Frac32 MFR_L_shr_r(Frac32 x, Int16 n);
**         L_deposit_h - Frac32 MFR_L_deposit_h(Frac16 x);
**         L_deposit_l - Frac32 MFR_L_deposit_l(Frac16 x);
**         L_sub       - Frac32 MFR_L_sub(Frac32 x, Frac32 y);
**         extract_h   - Frac16 MFR_extract_h(Frac32 x);
**         extract_l   - Frac16 MFR_extract_l(Frac32 x);
**         norm_s      - Int16 MFR_norm_s(Frac16 x);
**         norm_l      - Int16 MFR_norm_l(Frac32 x);
**         mfr32Sqrt   - Frac16 MFR_mfr32Sqrt(Frac32 x);
**
**     (c) Freescale Semiconductor
**     2004 All Rights Reserved
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __MFR
#define __MFR

/* MODULE MFR. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
/* Include inherited beans */
#include "port.h"
#include "prototype.h"
#include "dspfunc.h"
#define MFR_mfr32Sqrt mfr32Sqrt
#include "Cpu.h"



Frac16 mfr32Sqrt(Frac32 x);
/*
** ===================================================================
**     Method      :  MFR_mfr32Sqrt (component DSP_Func_MFR)
**
**     Description :
**         The sqrt function calculates the square root of the
**         fractional input data value.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**     Returns     :
**         ---             - The sqrt function returns the result of
**                           the square root calculation.
** ===================================================================
*/

//Frac16 MFR_abs_s(Frac16 x);
/*
** ===================================================================
**     Method      :  MFR_abs_s (component DSP_Func_MFR)
**
**     This method can be used also under name "abs_s"
**
**     Description :
**         The abs_s function calculates the 16-bit absolute value
**         of the input value.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**     Returns     :
**         ---             - The abs function returns the result of
**                           the 16-bit absolute value calculation.
** ===================================================================
*/

//Frac32 MFR_L_abs(Frac32 x);
/*
** ===================================================================
**     Method      :  MFR_L_abs (component DSP_Func_MFR)
**
**     This method can be used also under name "L_abs"
**
**     Description :
**         The L_abs function calculates the 32-bit absolute value
**         of the input value.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**     Returns     :
**         ---             - The L_abs function returns the result
**                           of the 32-bit absolute value calculation.
** ===================================================================
*/

//Frac16 MFR_add(Frac16 x,Frac16 y);
/*
** ===================================================================
**     Method      :  MFR_add (component DSP_Func_MFR)
**
**     This method can be used also under name "add"
**
**     Description :
**         The add function adds two 16-bit fractional numbers (x +
**         y).
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The first input value.
**         y               - The second input value.
**     Returns     :
**         ---             - The add function returns the 16-bit
**                           results of the addition.
** ===================================================================
*/

//Frac32 MFR_L_add(Frac32 x,Word32 y);
/*
** ===================================================================
**     Method      :  MFR_L_add (component DSP_Func_MFR)
**
**     This method can be used also under name "L_add"
**
**     Description :
**         The add function adds two 32-bit fractional numbers (x +
**         y).
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The first input value.
**         y               - The second input value.
**     Returns     :
**         ---             - The add function returns the 32-bit
**                           results of the addition.
** ===================================================================
*/

//Frac16 MFR_div_s(Frac16 x,Frac16 y);
/*
** ===================================================================
**     Method      :  MFR_div_s (component DSP_Func_MFR)
**
**     This method can be used also under name "div_s"
**
**     Description :
**         The div_s function divides two fractional numbers (x / y);
**         x and y must be positive and y must be greater than or
**         equal to x.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The dividend of the division.
**         y               - The divisor for the division.
**     Returns     :
**         ---             - The div_s function returns the quotient
**                           of the division calculation.
** ===================================================================
*/

//Frac16 MFR_div_ls(Frac32 x,Frac16 y);
/*
** ===================================================================
**     Method      :  MFR_div_ls (component DSP_Func_MFR)
**
**     This method can be used also under name "div_ls"
**
**     Description :
**         The div_ls function divides two fractional numbers (x / y);
**         x and y must be positive and y must be greater than or
**         equal to x.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The dividend of the division.
**         y               - The divisor for the division.
**     Returns     :
**         ---             - The div_ls function returns the
**                           quotient of the division calculation.
** ===================================================================
*/

//Frac32 MFR_L_shr_r(Frac32 x,Int16 n);
/*
** ===================================================================
**     Method      :  MFR_L_shr_r (component DSP_Func_MFR)
**
**     This method can be used also under name "L_shr_r"
**
**     Description :
**         The L_shr_r function arithmetically shifts the input
**         variable x right n positions, sign extending the result.
**         If n is negative, the L_shr_r function arithmetically
**         shifts x left by -n bits, zero filling the least
**         significant bits. L_shr_r differs from L_shr in that
**         L_shr_r rounds the 32-bit fractional result.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**         n               - The number of bits to right shift x; n is
**                           signed and, if negative, implies a right
**                           shift.
**     Returns     :
**         ---             - The function returns the value x
**                           arithmetically shifted by n bits.
** ===================================================================
*/

//Frac32 MFR_L_deposit_h(Frac16 x);
/*
** ===================================================================
**     Method      :  MFR_L_deposit_h (component DSP_Func_MFR)
**
**     This method can be used also under name "L_deposit_h"
**
**     Description :
**         The L_deposit_h function places a 16-bit fractional value
**         into the most significant 16-bits of the 32-bit
**         fractional output value and zeroes the least significant
**         16 bits.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**     Returns     :
**         ---             - The function returns a 32-bit
**                           fractional value.
** ===================================================================
*/

//Frac32 MFR_L_deposit_l(Frac16 x);
/*
** ===================================================================
**     Method      :  MFR_L_deposit_l (component DSP_Func_MFR)
**
**     This method can be used also under name "L_deposit_l"
**
**     Description :
**         The L_deposit_l function places a 16-bit fractional value
**         into the least significant 16 bits of the 32-bit
**         fractional output value and sign extends the most
**         significant 16 bits.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**     Returns     :
**         ---             - The function returns a 32-bit
**                           fractional value.
** ===================================================================
*/

//Frac16 MFR_extract_l(Frac32 x);
/*
** ===================================================================
**     Method      :  MFR_extract_l (component DSP_Func_MFR)
**
**     This method can be used also under name "extract_l"
**
**     Description :
**         The extract_l function extracts the least significant 16
**         bits from the 32-bit fractional value.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**     Returns     :
**         ---             - The extract_l function returns the
**                           extracted value as a 16-bit fractional
**                           number.
** ===================================================================
*/

//Frac16 MFR_extract_h(Frac32 x);
/*
** ===================================================================
**     Method      :  MFR_extract_h (component DSP_Func_MFR)
**
**     This method can be used also under name "extract_h"
**
**     Description :
**         The extract_h function extracts the most significant 16
**         bits from the 32-bit fractional value.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**     Returns     :
**         ---             - The extract_h function returns the
**                           extracted value as a 16-bit fractional
**                           number.
** ===================================================================
*/

//Frac16 MFR_mac_r(Frac32 w,Frac16 x,Frac16 y);
/*
** ===================================================================
**     Method      :  MFR_mac_r (component DSP_Func_MFR)
**
**     This method can be used also under name "mac_r"
**
**     Description :
**         The mac function multiplies two 16-bit fractional input
**         values (x * y) and adds the 32-bit result to w.
**     Parameters  :
**         NAME            - DESCRIPTION
**         w               - The input value used with the addition.
**         x               - The first input data value for the
**                           multiplication.
**         y               - The second input data value for the
**                           multiplication.
**     Returns     :
**         ---             - The function returns the result of the
**                           calculation (x * y) + w.
** ===================================================================
*/

//Frac16 MFR_msu_r(Frac32 w,Frac16 x,Frac16 y);
/*
** ===================================================================
**     Method      :  MFR_msu_r (component DSP_Func_MFR)
**
**     This method can be used also under name "msu_r"
**
**     Description :
**         The msu function multiplies x by y and subtracts the
**         32-bit result from w.
**     Parameters  :
**         NAME            - DESCRIPTION
**         w               - The input value used with the
**                           subtraction.
**         x               - The first input data value for the
**                           addition.
**         y               - The second input data value for the
**                           addition.
**     Returns     :
**         ---             - The function returns the result of the
**                           calculation w - (x + y).
** ===================================================================
*/

//Frac16 MFR_mult(Frac16 x,Frac16 y);
/*
** ===================================================================
**     Method      :  MFR_mult (component DSP_Func_MFR)
**
**     This method can be used also under name "mult"
**
**     Description :
**         This multiplication function multiply two fractional
**         input values and return the result.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The first input data value.
**         y               - The second input data value.
**     Returns     :
**         ---             - The mult function returns returns the
**                           result of the fractional multiplication.
** ===================================================================
*/

//Frac16 MFR_mult_r(Frac16 x,Frac16 y);
/*
** ===================================================================
**     Method      :  MFR_mult_r (component DSP_Func_MFR)
**
**     This method can be used also under name "mult_r"
**
**     Description :
**         This multiplication function multiply two fractional
**         input values and return the result. The function differs
**         from mult in that function rounds the result, whereas
**         mult truncates the result to 16bits.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The first input data value.
**         y               - The second input data value.
**     Returns     :
**         ---             - The mult function returns returns the
**                           result of the fractional multiplication.
** ===================================================================
*/

//Frac32 MFR_L_mac(Frac32 w,Frac16 x,Frac16 y);
/*
** ===================================================================
**     Method      :  MFR_L_mac (component DSP_Func_MFR)
**
**     This method can be used also under name "L_mac"
**
**     Description :
**         The mac function multiplies two 16-bit fractional input
**         values (x * y) and adds the 32-bit result to w.
**     Parameters  :
**         NAME            - DESCRIPTION
**         w               - The input value used with the addition.
**         x               - The first input data value for the
**                           multiplication.
**         y               - The second input data value for the
**                           multiplication.
**     Returns     :
**         ---             - The function returns the result of the
**                           calculation (x * y) + w.
** ===================================================================
*/

//Frac32 MFR_L_msu(Frac32 w,Frac16 x,Frac16 y);
/*
** ===================================================================
**     Method      :  MFR_L_msu (component DSP_Func_MFR)
**
**     This method can be used also under name "L_msu"
**
**     Description :
**         The msu function multiplies x by y and subtracts the
**         32-bit result from w.
**     Parameters  :
**         NAME            - DESCRIPTION
**         w               - The input value used with the addition.
**         x               - The first input data value for the
**                           addition.
**         y               - The second input data value for the
**                           addition.
**     Returns     :
**         ---             - The function returns the result of the
**                           calculation w - (x + y).
** ===================================================================
*/

//Frac32 MFR_L_mult(Frac16 x,Frac16 y);
/*
** ===================================================================
**     Method      :  MFR_L_mult (component DSP_Func_MFR)
**
**     This method can be used also under name "L_mult"
**
**     Description :
**         This multiplication function multiply two fractional
**         input values and return the result.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The first input data value.
**         y               - The second input data value.
**     Returns     :
**         ---             - The mult function returns returns the
**                           result of the fractional multiplication.
** ===================================================================
*/

//Frac32 MFR_L_mult_ls(Frac32 x,Frac16 y);
/*
** ===================================================================
**     Method      :  MFR_L_mult_ls (component DSP_Func_MFR)
**
**     This method can be used also under name "L_mult_ls"
**
**     Description :
**         This multiplication function multiply two fractional
**         input values and return the result. The function differs
**         from mult in that function rounds the result, whereas
**         mult truncates the result to 16bits.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The first input data value.
**         y               - The second input data value.
**     Returns     :
**         ---             - The mult function returns returns the
**                           result of the fractional multiplication.
** ===================================================================
*/

//Frac16 MFR_negate(Frac16 x);
/*
** ===================================================================
**     Method      :  MFR_negate (component DSP_Func_MFR)
**
**     This method can be used also under name "negate"
**
**     Description :
**         The negate function negates the fractional input value.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**     Returns     :
**         ---             - The negate function returns the result
**                           of the negation.
** ===================================================================
*/

//Frac32 MFR_L_negate(Frac32 x);
/*
** ===================================================================
**     Method      :  MFR_L_negate (component DSP_Func_MFR)
**
**     This method can be used also under name "L_negate"
**
**     Description :
**         The negate function negates the fractional input value.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**     Returns     :
**         ---             - The negate function returns the result
**                           of the negation.
** ===================================================================
*/

//Frac16 MFR_round(Frac32 x);
/*
** ===================================================================
**     Method      :  MFR_round (component DSP_Func_MFR)
**
**     This method can be used also under name "round"
**
**     Description :
**         The round function rounds the 32-bit fractional input
**         value to 16 bits.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value
**     Returns     :
**         ---             - The round returns the 16-bit
**                           representation of the input value,
**                           rounded to the least significant bit.
** ===================================================================
*/

//Frac16 MFR_shl(Frac16 x,Int16 n);
/*
** ===================================================================
**     Method      :  MFR_shl (component DSP_Func_MFR)
**
**     This method can be used also under name "shl"
**
**     Description :
**         The shl function arithmetically shifts the input variable
**         x left n positions, zero filling the least significant
**         bits of the result. If n is negative, the shl function
**         arithmetically shifts x right by -n bits with sign
**         extension.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**         n               - The number of bits to left shift x; n is
**                           signed and, if negative, implies a right
**                           shift.
**     Returns     :
**         ---             - The shl function returns the value x
**                           arithmetically shifted by n bits.
** ===================================================================
*/

//Frac16 MFR_shr(Frac16 x,Int16 n);
/*
** ===================================================================
**     Method      :  MFR_shr (component DSP_Func_MFR)
**
**     This method can be used also under name "shr"
**
**     Description :
**         The shr function arithmetically shifts the input variable
**         x right n positions, sign extending the result. If n is
**         negative, the shr function arithmetically shifts x left
**         by -n bits, zero filling the least significant bits.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**         n               - The number of bits to right shift x; n is
**                           signed and, if negative, implies a right
**                           shift.
**     Returns     :
**         ---             - The function returns the value x
**                           arithmetically shifted by n bits.
** ===================================================================
*/

//Frac16 MFR_shr_r(Frac16 x,Int16 n);
/*
** ===================================================================
**     Method      :  MFR_shr_r (component DSP_Func_MFR)
**
**     This method can be used also under name "shr_r"
**
**     Description :
**         The shr_r function arithmetically shifts the input
**         variable x right n positions, sign extending the result.
**         If n is negative, the shr_r function arithmetically
**         shifts x left by -n bits, zero filling the least
**         significant bits. shr_r differs from shr in that shr_r
**         rounds the 32-bit fractional result.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**         n               - The number of bits to right shift x; n is
**                           signed and, if negative, implies a right
**                           shift.
**     Returns     :
**         ---             - The function returns the value x
**                           arithmetically shifted by n bits.
** ===================================================================
*/

//Frac16 MFR_L_shl(Frac32 x,Int16 n);
/*
** ===================================================================
**     Method      :  MFR_L_shl (component DSP_Func_MFR)
**
**     This method can be used also under name "L_shl"
**
**     Description :
**         The L_shl function arithmetically shifts the input
**         variable x left n positions, zero filling the least
**         significant bits of the result. If n is negative, the shl
**         function arithmetically shifts x right by -n bits with
**         sign extension.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**         n               - The number of bits to left shift x; n is
**                           signed and, if negative, implies a right
**                           shift.
**     Returns     :
**         ---             - The L_shl function returns the value x
**                           arithmetically shifted by n bits.
** ===================================================================
*/

//Frac32 MFR_L_shr(Frac32 x,Int16 n);
/*
** ===================================================================
**     Method      :  MFR_L_shr (component DSP_Func_MFR)
**
**     This method can be used also under name "L_shr"
**
**     Description :
**         The L_shr function arithmetically shifts the input
**         variable x right n positions, sign extending the result.
**         If n is negative, the L_shr function arithmetically
**         shifts x left by -n bits, zero filling the least
**         significant bits.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**         n               - The number of bits to right shift x; n is
**                           signed and, if negative, implies a right
**                           shift.
**     Returns     :
**         ---             - The function returns the value x
**                           arithmetically shifted by n bits.
** ===================================================================
*/

//Frac16 MFR_sub(Frac16 x,Frac16 y);
/*
** ===================================================================
**     Method      :  MFR_sub (component DSP_Func_MFR)
**
**     This method can be used also under name "sub"
**
**     Description :
**         The sub function calculates (x - y).
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**         y               - Zhe second input data value to subtract.
**     Returns     :
**         ---             - The function returns the results of the
**                           subtraction (x-y).
** ===================================================================
*/

//Frac32 MFR_L_sub(Frac32 x,Frac32 y);
/*
** ===================================================================
**     Method      :  MFR_L_sub (component DSP_Func_MFR)
**
**     This method can be used also under name "L_sub"
**
**     Description :
**         The L_sub function calculates (x - y).
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**         y               - Zhe second input data value to subtract.
**     Returns     :
**         ---             - The function returns the results of the
**                           subtraction (x-y).
** ===================================================================
*/

//Int16 MFR_norm_s(Frac16 x);
/*
** ===================================================================
**     Method      :  MFR_norm_s (component DSP_Func_MFR)
**
**     This method can be used also under name "norm_s"
**
**     Description :
**         The norm function calculates the number of left shifts
**         needed to normalize a fractional value.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**     Returns     :
**         ---             - The norm function returns the number of
**                           left shifts needed to normalize the
**                           fractional input value.
** ===================================================================
*/

//Int16 MFR_norm_l(Frac32 x);
/*
** ===================================================================
**     Method      :  MFR_norm_l (component DSP_Func_MFR)
**
**     This method can be used also under name "norm_l"
**
**     Description :
**         The norm function calculates the number of left shifts
**         needed to normalize a fractional value.
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The input data value.
**     Returns     :
**         ---             - The norm function returns the number of
**                           left shifts needed to normalize the
**                           fractional input value.
** ===================================================================
*/

/* END MFR. */

#endif /* ifndef __MFR */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

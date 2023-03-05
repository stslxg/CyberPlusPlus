/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : AS.C
**     Project   : CyberNT3
**     Processor : 56F8366
**     Component : AsynchroSerial
**     Version   : Component 02.472, Driver 02.06, CPU db: 2.87.042
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2011/8/20, 22:03
**     Abstract  :
**         This bean "AsynchroSerial" implements an asynchronous serial
**         communication. The bean supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The bean requires one on-chip asynchronous serial channel.
**     Settings  :
**         Serial channel              : SCI1
**
**         Protocol
**             Init baud rate          : 115200baud
**             Width                   : 8 bits
**             Stop bits               : 1
**             Parity                  : none
**             Breaks                  : Disabled
**             Input buffer size       : 0
**             Output buffer size      : 6880
**
**         Registers
**             Input buffer            : SCI1_SCIDR [62100]
**             Output buffer           : SCI1_SCIDR [62100]
**             Control register        : SCI1_SCICR [62097]
**             Mode register           : SCI1_SCICR [62097]
**             Baud setting reg.       : SCI1_SCIBR [62096]
**
**         Input interrupt
**             Vector name             : INT_SCI1_RxFull
**             Priority                : 1
**
**         Output interrupt
**             Vector name             : INT_SCI1_TxEmpty
**             Priority                : 1
**
**         Used pins:
**         ----------------------------------------------------------
**           Function | On package           |    Name
**         ----------------------------------------------------------
**            Input   |     43               |  GPIOD7_RxD1
**            Output  |     42               |  GPIOD6_TxD1
**         ----------------------------------------------------------
**
**
**
**     Contents  :
**         RecvChar        - byte AS_RecvChar(AS_TComData *Chr);
**         SendChar        - byte AS_SendChar(AS_TComData Chr);
**         SendBlock       - byte AS_SendBlock(AS_TComData *Ptr, word Size, word *Snd);
**         ClearTxBuf      - byte AS_ClearTxBuf(void);
**         GetCharsInRxBuf - word AS_GetCharsInRxBuf(void);
**         GetCharsInTxBuf - word AS_GetCharsInTxBuf(void);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE AS. */

#include "AS.h"
#include "Events.h"


#define OVERRUN_ERR      1             /* Overrun error flag bit    */
#define FRAMING_ERR      2             /* Framing error flag bit    */
#define PARITY_ERR       4             /* Parity error flag bit     */
#define CHAR_IN_RX       8             /* Char is in RX buffer      */
#define FULL_TX          16            /* Full transmit buffer      */
#define RUNINT_FROM_TX   32            /* Interrupt is in progress  */
#define FULL_RX          64            /* Full receive buffer       */
#define NOISE_ERR        128           /* Noise erorr flag bit      */
#define IDLE_ERR         256           /* Idle character flag bit   */
#define BREAK_ERR        512           /* Break detect              */
#define COMMON_ERR       2048          /* Common error of RX       */

static word SerFlag;                   /* Flags for serial communication */
                                       /* Bits: 0 - OverRun error */
                                       /*       1 - Framing error */
                                       /*       2 - Parity error */
                                       /*       3 - Char in RX buffer */
                                       /*       4 - Full TX buffer */
                                       /*       5 - Running int from TX */
                                       /*       6 - Full RX buffer */
                                       /*       7 - Noise error */
                                       /*       8 - Idle character  */
                                       /*       9 - Break detected  */
                                       /*      10 - Unused */
                                       /*      11 - Unused */
static AS_TComData BufferRead;         /* Input char for SCI commmunication */
static word OutLen;                    /* Length of output bufer's content */
static AS_TComData *OutPtrR;           /* Pointer for reading from output buffer */
static AS_TComData *OutPtrW;           /* Pointer for writing to output buffer */
static AS_TComData OutBuffer[AS_OUT_BUF_SIZE]; /* Output buffer for SCI commmunication */

/*
** ===================================================================
**     Method      :  HWEnDi (component AsynchroSerial)
**
**     Description :
**         Enables or disables the peripheral(s) associated with the bean.
**         The method is called automatically as a part of the Enable and 
**         Disable methods and several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void HWEnDi(void)
{
  getReg(SCI1_SCISR);                  /* Reset interrupt request flags */
  setRegBits(SCI1_SCICR, (SCI1_SCICR_TE_MASK | SCI1_SCICR_RE_MASK | SCI1_SCICR_RFIE_MASK | SCI1_SCICR_REIE_MASK)); /* Enable device */
}

/*
** ===================================================================
**     Method      :  AS_RecvChar (component AsynchroSerial)
**
**     Description :
**         If any data is received, this method returns one
**         character, otherwise it returns an error code (it does
**         not wait for data). This method is enabled only if the
**         receiver property is enabled.
**         [Note:] Because the preferred method to handle error and
**         break exception in the interrupt mode is to use events
**         <OnError> and <OnBreak> the return value ERR_RXEMPTY has
**         higher priority than other error codes. As a consequence
**         the information about an exception in interrupt mode is
**         returned only if there is a valid character ready to be
**         read.
**         Version specific information for Freescale 56800
**         derivatives ] 
**         DMA mode:
**         If DMA controller is available on the selected CPU and
**         the receiver is configured to use DMA controller then
**         this method only sets the selected DMA channel. Then the
**         status of the DMA transfer can be checked using
**         GetCharsInRxBuf method. See an example of a typical usage
**         for details about the communication using DMA.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Chr             - Pointer to a received character
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RXEMPTY - No data in receiver
**                           ERR_BREAK - Break character is detected
**                           (only when the <Interrupt service>
**                           property is disabled and the <Break
**                           signal> property is enabled)
**                           ERR_COMMON - common error occurred (the
**                           <GetError> method can be used for error
**                           specification)
**                           Version specific information for
**                           Freescale 56800 derivatives ] 
**                           DMA mode:
**                           If DMA controller is available on the
**                           selected CPU and the receiver is
**                           configured to use DMA controller then
**                           only ERR_OK, ERR_RXEMPTY, and ERR_SPEED
**                           error code can be returned from this
**                           method.
** ===================================================================
*/
byte AS_RecvChar(AS_TComData *Chr)
{
  register byte Result = ERR_OK;       /* Return error code */

  if (!(SerFlag & CHAR_IN_RX)) {       /* Is any char in RX buffer? */
    return ERR_RXEMPTY;                /* If no then error */
  }
  EnterCritical();                     /* Disable global interrupts */
  *Chr = BufferRead;                   /* Received char */
  Result = (byte)((SerFlag & (OVERRUN_ERR|COMMON_ERR))? ERR_COMMON : ERR_OK);
  SerFlag &= ~(OVERRUN_ERR|COMMON_ERR|CHAR_IN_RX); /* Clear all errors in the status variable */
  ExitCritical();                      /* Enable global interrupts */
  return Result;                       /* Return error code */
}

/*
** ===================================================================
**     Method      :  AS_SendChar (component AsynchroSerial)
**
**     Description :
**         Sends one character to the channel. If the bean is
**         temporarily disabled (Disable method) SendChar method
**         only stores data into an output buffer. In case of a zero
**         output buffer size, only one character can be stored.
**         Enabling the bean (Enable method) starts the transmission
**         of the stored data. This method is available only if the
**         transmitter property is enabled.
**         Version specific information for Freescale 56800
**         derivatives ] 
**         DMA mode:
**         If DMA controller is available on the selected CPU and
**         the transmitter is configured to use DMA controller then
**         this method only sets selected DMA channel. Then the
**         status of the DMA transfer can be checked using
**         GetCharsInTxBuf method. See an example of a typical usage
**         for details about communication using DMA.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Chr             - Character to send
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_TXFULL - Transmitter is full
** ===================================================================
*/
byte AS_SendChar(AS_TComData Chr)
{
  if (OutLen == AS_OUT_BUF_SIZE) {     /* Is number of chars in buffer is the same as a size of the transmit buffer */
    return ERR_TXFULL;                 /* If yes then error */
  }
  EnterCritical();                     /* Disable global interrupts */
  OutLen++;                            /* Increase number of bytes in the transmit buffer */
  *(OutPtrW++) = Chr;                  /* Store char to buffer */
    /*lint -save -e946 Disable MISRA rule (103) checking. */
  if (OutPtrW >= (OutBuffer + AS_OUT_BUF_SIZE)) { /* Is the pointer out of the transmit buffer */
    OutPtrW = OutBuffer;               /* Set pointer to first item in the transmit buffer */
  }
    /*lint -restore */
  setRegBit(SCI1_SCICR, TEIE);         /* Enable transmit interrupt */
  ExitCritical();                      /* Enable global interrupts */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  AS_SendBlock (component AsynchroSerial)
**
**     Description :
**         Sends a block of characters to the channel.
**         This method is available only if non-zero length of the
**         output buffer is defined and the transmitter property is
**         enabled.
**         Version specific information for Freescale 56800
**         derivatives ] 
**         DMA mode:
**         If DMA controller is available on the selected CPU and
**         the transmitter is configured to use DMA controller then
**         this method only sets the selected DMA channel. Then the
**         status of the DMA transfer can be checked using
**         GetCharsInTxBuf method. See typical usage for details
**         about communication using DMA.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Ptr             - Pointer to the block of data to send
**         Size            - Size of the block
**       * Snd             - Pointer to number of data that are sent
**                           (moved to buffer)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_TXFULL - It was not possible to send
**                           requested number of bytes
** ===================================================================
*/
byte AS_SendBlock(AS_TComData *Ptr,word Size,word *Snd)
{
  register word count;                 /* Number of sent chars */
  register byte result = ERR_OK;       /* Last error */

  for (count = 0; count < Size; count++) {
    result = AS_SendChar(*Ptr++);
    if (result != ERR_OK) {            /* Sending given number of chars */
      *Snd = count;                    /* Return number of sent chars */
      return result;                   /* Return last error */
    }
  }
  *Snd = count;                        /* Return number of sended chars */
  return result;                       /* Return error code */
}

/*
** ===================================================================
**     Method      :  AS_ClearTxBuf (component AsynchroSerial)
**
**     Description :
**         Clears the transmit buffer.
**         This method is available only if non-zero length of the
**         output buffer is defined and the receiver property is
**         enabled.
**         Version specific information for Freescale 56800
**         derivatives ] 
**         DMA mode:
**         If DMA controller is available on the selected CPU and
**         the transmitter is configured to use DMA controller then
**         this method only stops selected DMA channel.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte AS_ClearTxBuf(void)
{
  EnterCritical();                     /* Disable global interrupts */
  OutLen = 0;                          /* Set number of chars in the receive buffer to 0 */
  OutPtrR = OutPtrW = OutBuffer;       /* Set pointers on the first item in the receive buffer */
  ExitCritical();                      /* Enable global interrupts */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  AS_GetCharsInRxBuf (component AsynchroSerial)
**
**     Description :
**         Returns the number of characters in the input buffer.
**         This method is available only if the receiver property is
**         enabled.
**         Version specific information for Freescale 56800
**         derivatives ] 
**         DMA mode:
**         If DMA controller is available on the selected CPU and
**         the receiver is configured to use DMA controller then
**         this method returns the number of characters in the
**         receive buffer.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the input
**                           buffer.
** ===================================================================
*/
word AS_GetCharsInRxBuf(void)
{
  return (word)(((SerFlag & CHAR_IN_RX) != 0)? 1 : 0); /* Return number of chars in receive buffer */
}

/*
** ===================================================================
**     Method      :  AS_GetCharsInTxBuf (component AsynchroSerial)
**
**     Description :
**         Returns the number of characters in the output buffer.
**         This method is available only if the transmitter property
**         is enabled.
**         Version specific information for Freescale 56800
**         derivatives ] 
**         DMA mode:
**         If DMA controller is available on the selected CPU and
**         the transmitter is configured to use DMA controller then
**         this method returns the number of characters in the
**         transmit buffer.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the output
**                           buffer.
** ===================================================================
*/
word AS_GetCharsInTxBuf(void)
{
  return OutLen;                       /* Return number of chars in the transmitter buffer */
}

/*
** ===================================================================
**     Method      :  AS_InterruptRx (component AsynchroSerial)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#define ON_ERROR    1
#define ON_FULL_RX  2
#define ON_RX_CHAR  4
#pragma interrupt alignsp saveall
void AS_InterruptRx(void)
{
  register AS_TComData Data;           /* Temporary variable for data */
  register word OnFlags = 0;           /* Temporary variable for flags */
  register word StatReg = getReg(SCI1_SCISR); /* Read status register */

  Data = (AS_TComData)getReg(SCI1_SCIDR); /* Read data from the receiver */
  if(StatReg & (SCI1_SCISR_OR_MASK)) { /* Is HW overrun error detected? */
    setReg(SCI1_SCISR, 0);             /* Reset error request flags */
    SerFlag |= OVERRUN_ERR;            /* Set flag OVERRUN_ERR */
  }
  if (!(SerFlag & CHAR_IN_RX)) {       /* Is SW overrun detected? */
    BufferRead = Data;
    OnFlags |= ON_RX_CHAR;             /* Set flag "OnRxChar" */
  }
  else {
    SerFlag |= OVERRUN_ERR;            /* Set flag OVERRUN_ERR */
  }
  SerFlag |= CHAR_IN_RX;               /* Set flag "char in RX buffer" */
  if (OnFlags & ON_RX_CHAR) {          /* Is OnRxChar flag set? */
    AS_OnRxChar();                     /* If yes then invoke user event */
  }
}

/*
** ===================================================================
**     Method      :  AS_InterruptTx (component AsynchroSerial)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#define ON_FREE_TX  1
#define ON_TX_CHAR  2
#pragma interrupt alignsp saveall
void AS_InterruptTx(void)
{
  SerFlag &= ~RUNINT_FROM_TX;          /* Reset flag "running int from TX" */
  if (OutLen) {                        /* Is number of bytes in the transmit buffer greater then 0? */
    OutLen--;                          /* Decrease number of chars in the transmit buffer */
    SerFlag |= RUNINT_FROM_TX;         /* Set flag "running int from TX"? */
    getReg(SCI1_SCISR);                /* Reset interrupt request flags */
    SCI1_SCIDR = (AS_TComData)*(OutPtrR++); /* Store char to transmitter register */
    /*lint -save -e946 Disable MISRA rule (103) checking. */
    if (OutPtrR >= (OutBuffer + AS_OUT_BUF_SIZE)) { /* Is the pointer out of the transmit buffer? */
      OutPtrR = OutBuffer;             /* Set pointer on the first item into the transmit buffer */
    }
    /*lint -restore */
  } else {
    clrRegBit(SCI1_SCICR, TEIE);       /* Disable transmit interrupt */
  }
}

/*
** ===================================================================
**     Method      :  AS_InterruptError (component AsynchroSerial)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#pragma interrupt alignsp saveall
void AS_InterruptError(void)
{
  register word StatReg = getReg(SCI1_SCISR); /* Read status register */

  setReg(SCI1_SCISR, 0);               /* Reset error request flags */
  if(StatReg & (SCI1_SCISR_OR_MASK|SCI1_SCISR_NF_MASK|SCI1_SCISR_FE_MASK|SCI1_SCISR_PF_MASK)) { /* Is an error detected? */
    SerFlag |= COMMON_ERR;             /* If yes then set an internal flag */
  }
}

/*
** ===================================================================
**     Method      :  AS_Init (component AsynchroSerial)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean internal 
**         variables. The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void AS_Init(void)
{
  SerFlag = 0;                         /* Reset flags */
  /* SCI1_SCICR: LOOP=0,SWAI=0,RSRC=0,M=0,WAKE=0,POL=0,PE=0,PT=0,TEIE=0,TIIE=0,RFIE=0,REIE=0,TE=0,RE=0,RWU=0,SBK=0 */
  setReg(SCI1_SCICR, 0);               /* Set the SCI configuration */
  OutLen = 0;                          /* No char in the transmit buffer */
  OutPtrW = OutPtrR = OutBuffer;       /* Set pointer on the first item in the transmit buffer */
  /* SCI1_SCIBR: ??=0,??=0,??=0,SBR=43 */
  setReg(SCI1_SCIBR, 43);              /* Set prescaler bits */
  HWEnDi();                            /* Enable/disable device according to status flags */
}


/* END AS. */


/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

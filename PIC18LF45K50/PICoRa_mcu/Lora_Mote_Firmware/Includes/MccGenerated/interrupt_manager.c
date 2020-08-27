/**
  Generated Interrupt Manager Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    interrupt_manager.c

  @Summary:
    This is the Interrupt Manager file generated using MPLAB� Code Configurator

  @Description:
    This header file provides implementations for global interrupt handling.
    For individual peripheral handlers please see the peripheral driver for
    all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB� Code Configurator - v2.10
        Device            :  PIC16F1509
        Driver Version    :  1.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.33
        MPLAB             :  MPLAB X 2.26
*/

/*
Copyright (c) 2013 - 2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*/

#include "interrupt_manager.h"
#include "mcc.h"
#include "TMRapp.h"
#include "USBapp.h"
#include "../Usb/framework/usb.h"

void interrupt INTERRUPT_InterruptManager (void)
{
   // interrupt handler
    if(PIE1bits.TMR1IE == 1 && PIR1bits.TMR1IF == 1)
    {
        TMR1_ISR();
        // Call Timer Handler
        TMRapp_Tick();      // Handle Every mS
    }
    if(PIE2bits.TMR3IE == 1 && PIR2bits.TMR3IF == 1)
    {
        TMR3_ISR();
    }
    else if( (PIE1bits.RCIE == 1) && (PIR1bits.RCIF == 1) )
    {
        USBapp_setrxByteFlag();
        EUSART_Receive_ISR();
    }
    else if( (PIE1bits.TXIE == 1) && (PIR1bits.TXIF == 1) )
    {
        EUSART_Transmit_ISR();
    }
    else if(PIE2bits.C1IE == 1 && PIR2bits.C1IF == 1)
    {
        CMP1_ISR();
    }
    else
    {
        //Unhandled Interrupt
        USBDeviceTasks(); // USB things
    }
}
/**
 End of File
*/
/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18LF46K22
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

uint8_t nwkSKey[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C };
uint8_t appSKey[16] = {0x3C, 0x8F, 0x26, 0x27, 0x39, 0xBF, 0xE3, 0xB7, 0xBC, 0x08, 0x26, 0x99, 0x1A, 0xD0, 0x50, 0x4D };
uint32_t devAddr = 0x1100000F; 

uint8_t deviceEui[8] = {0x00, 0x04, 0xA3, 0x0B, 0x00, 0x1A, 0x9E, 0xF8};
uint8_t applicationEuiNew[8] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};
uint8_t appKey[16] = {0x3C, 0x8F, 0x26, 0x27, 0x39, 0xBF, 0xE3, 0xB7, 0xBC, 0x08, 0x26, 0x99, 0x1A, 0xD0, 0x50, 0x4D };


void RxData(uint8_t* pData, uint8_t dataLength, OpStatus_t status){}
void RxJoinResponse(bool status){}
void PICoRa_SetABP_Activation(){}
void PICoRa_SetOTAA_Activation(){}

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    PICoRa_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    LORAWAN_Init(RxData, RxJoinResponse); //Initializes LoRaWAN and the radio module
    
    PICoRa_SetOTAA_Activation();
//    LORAWAN_SetNetworkSessionKey(nwkSKey);
//    LORAWAN_SetApplicationSessionKey(appSKey);
//    LORAWAN_SetDeviceAddress(devAddr);
    
    LORAWAN_Join(ABP); //LoRaWAN activation procedure

    while (1)
    {
        // Add your application code
        LORAWAN_Mainloop();
        
        LORAWAN_Send(UNCNF, 2, "LoRa", 4); //start bidirectional communication process
    }
}
/**
 End of File
*/

void PICoRa_SetABP_Activation(void){
    LORAWAN_SetNetworkSessionKey(nwkSKey); //set the Network-Session Key
    LORAWAN_SetApplicationSessionKey(appSKey); //set the end-device
    LORAWAN_SetDeviceAddress(devAddr); //set the end-device address
}

void PICoRa_SetOTAA_Activation(void){
    LORAWAN_SetDeviceEui(&deviceEui[0]); //set the end-device identifier
    LORAWAN_SetApplicationEui(&applicationEuiNew[0]); //set the end-device Application identifier
    LORAWAN_SetApplicationKey(appKey); //set the Application-Session Key
}
# Microchip's LoRa Firmware Customization

## LoRaWAN Library Plug-in on LoRa Node module


![MPLAB X IDE Logo](https://www.microchip.com/images/default-source/mplab/mplab-x-ide/mplblgo.png?sfvrsn=131daac7_1)



MPLAB X IDE is a software program that runs on a PC (Windows®, Mac OS®, Linux®) to develop applications for Microchip microcontrollers and digital signal controllers. It is called an Integrated Development Environment (IDE) because it provides a single integrated "environment" to develop code for embedded microcontrollers.





![mplab_xc_compiler_logo_011216_03](https://www.microchip.com/images/default-source/mplab/mplab-xc-compilers/mplab_xc_compiler_logo_011216_03.png?sfvrsn=f18b07f_3)



 
 
 MPLAB® XC C Compilers provides a comprehensive solution for your project’s software development and is offered in free, unrestricted-use downloads. 




![270x270mcclogo](https://www.microchip.com/images/default-source/mplab/mplab-code-configurator/270x270mcclogo.png?sfvrsn=1522e3c3_3)



MPLAB® Code Configurator (MCC) is a free, graphical programming environment that generates seamless, easy-to-understand C code to be inserted into your project. Using an intuitive interface, it enables and configures a rich set of peripherals and functions specific to your application




The LoRaWAN Library Plug-in for the MPLAB Code Configuration allows for quick and easy C code generation of Microchip’s LoRaWAN stack solution for LoRa Technology end device

The LoRa stack is already present on the Micrpchip RN 2483 and RN2903 modules. Which cores of RN2903 modules contain the PIC18LF46K22 device and the Semtech SX1276 radio transceiver

##ADD LoRaWAN Library Plug-in to MCC

- Click on Tools → Options
![](https://d2mxuefqeaa7sj.cloudfront.net/s_411E442440EC9056AD9FD9EB2918F88D9CF4C6356195DA74797F51BD692E2F51_1543222857671_image.png)

- Inside Options window, click on the Plug-in → Add Library 
![](https://d2mxuefqeaa7sj.cloudfront.net/s_411E442440EC9056AD9FD9EB2918F88D9CF4C6356195DA74797F51BD692E2F51_1543222955691_image.png)

- Browse to the location of the LoRaWAN Library Plug-in, select it and click on **Open** to add to MCC ([download](http://ww1.microchip.com/downloads/en/DeviceDoc/release_notes_lorawan_v01.10.00_beta.pdf))
![](https://d2mxuefqeaa7sj.cloudfront.net/s_411E442440EC9056AD9FD9EB2918F88D9CF4C6356195DA74797F51BD692E2F51_1543223132983_image.png)


## LoRaWAN Configuration on RN2903 Module Project

- In MPLAB X, click on File → New Project
![](https://d2mxuefqeaa7sj.cloudfront.net/s_92D49EE73564DFCCF10E9CEC26B59967088C73B7420C2F856CDDEE19BAC46EA4_1536811187971_image.png)

- Select Microchip Embedded → Standalone Project and click next
![](https://d2mxuefqeaa7sj.cloudfront.net/s_92D49EE73564DFCCF10E9CEC26B59967088C73B7420C2F856CDDEE19BAC46EA4_1536811286084_image.png)

- Select PIC18LF46K22 and press next
![](https://d2mxuefqeaa7sj.cloudfront.net/s_92D49EE73564DFCCF10E9CEC26B59967088C73B7420C2F856CDDEE19BAC46EA4_1536811333168_image.png)

- Select PICkit3, for programmer used from the Hardware Tools and click next
![](https://d2mxuefqeaa7sj.cloudfront.net/s_92D49EE73564DFCCF10E9CEC26B59967088C73B7420C2F856CDDEE19BAC46EA4_1536811392187_image.png)

- Select XC8, for the compiler to be used. The LoRaWAN Library requires XC8 (version 1.37 or later) and click next
![](https://d2mxuefqeaa7sj.cloudfront.net/s_92D49EE73564DFCCF10E9CEC26B59967088C73B7420C2F856CDDEE19BAC46EA4_1536811428389_image.png)

- Set a name for the project and check box “Set as main project”. Click Finish; this will end the new creation project process 
![](https://d2mxuefqeaa7sj.cloudfront.net/s_92D49EE73564DFCCF10E9CEC26B59967088C73B7420C2F856CDDEE19BAC46EA4_1536811488471_image.png)


## LoRaWAN Basic Configuration

  There are five minimum selections that must make in order to get a functional LoRaWAN stack. These selections must reflect the LoRaWAN end-device hardware that is used:
1. Base Timer
2. Radio Module
3. SPI module
4. ISM band
5. Default Class
  Each of these settings act as a selection from a list of options which is generated according to the microcontroller resources, supported radio modules, or the region of the LoRAWAN stack usage


- In MPLAB X, click on Tools → Embedded → MPLAB Code Configuration (in order to create the configuration of the project)
![](https://d2mxuefqeaa7sj.cloudfront.net/s_92D49EE73564DFCCF10E9CEC26B59967088C73B7420C2F856CDDEE19BAC46EA4_1536811543183_image.png)

- Add the LoRaWAN Library from the Device Resource window. The library will be added to the Project Resources
![](https://d2mxuefqeaa7sj.cloudfront.net/s_92D49EE73564DFCCF10E9CEC26B59967088C73B7420C2F856CDDEE19BAC46EA4_1536812123604_image.png)

- Select the resource needed by the LoRaWAN stack. Make the following settings for the LoRaWAN Library
  - Base Timer: TMR1 [must be selected out of the list of timers avaliable on the microcontroller]
  - Radio Module: SX1276 [the LoRaWAN stack supports 2 radio transceivers: Semtech SX1272 and Semtech SX1276] 
  - SPI Module: MSSP2 [The end device is formed of one PIC device and one radio transceiver. There is a SPI communication needed between these two, where the PIC device is the master and the radio transceiver is the slave. MSSP module use for the SPI communication between the PIC microcontroller and the radio] 
  - ISM Band: North America [There are two regions which are support by the LoRaWAN stack: Europe and North America, with specific as EU433MHz, EU868MHz and NA915MHz]
  - Default class: A [Microchip LoRaWAN stack supports both Class A and Class C]
![](https://d2mxuefqeaa7sj.cloudfront.net/s_92D49EE73564DFCCF10E9CEC26B59967088C73B7420C2F856CDDEE19BAC46EA4_1536814147961_image.png)

  LoRaWAN Advanced Setup
  Click on **Advanced Settings** to access more setting for LoRaWAN stack (frequenct band).  This will take to a wizard menu, which allows adding or removing the following rows:
1. Channel Number
2. Frequency
3. Data Rate Minimum
4. Data Rate Maximum
5. Duty Cycle 


- Set the following parameters for SYSTEM Module
  Internal Oscillator
  - Oscillator Select: Internal oscillator block
  - System clock select: Fosc
  - Internal clock: 16MHz_HFINTOSC/4
  - PLL enabled: not checked
  - Software PLL enabled: not checked
  - Low-voltage programming enable: not checked
  WDT
  - Watchdog timer enable: Watchdog timer is always disabled. SWDTEN has no effect
  - Watchdog timer postscaler: 1:32768
![](https://d2mxuefqeaa7sj.cloudfront.net/s_92D49EE73564DFCCF10E9CEC26B59967088C73B7420C2F856CDDEE19BAC46EA4_1536814540199_image.png)

- Set the following parameters for TMR1 Module to use an external oscillator circuit and to have a 2s period interrupt
  Hardware Setting
  - Enable timer: check for enabled
    Timer Clock
    - Clock source: External
    - External Frequency: 32.768 kHz (connot be changed)
    - Prescaler: 1:1
    - Enable Synchronization: not checked
    - Enable Oscillator Circuit: checked
    Timer Period
    - Timer Period: 2s
    - Period count: (auto-filled by MCC)
    - Enable 16-bit read: not checked
    Enable Gate: not checked
    Emable Timer Interrupt: checked
  Software Setting
  - Callback Function Rate: 1
![](https://d2mxuefqeaa7sj.cloudfront.net/s_92D49EE73564DFCCF10E9CEC26B59967088C73B7420C2F856CDDEE19BAC46EA4_1536825860755_image.png)

- Set the following parameters for MSSP2 Module and configure in SPI Master Mode
  Hardware Setting
  - Mode: SPI Master
  - Input Data Sampled at: Middle
    SPI Mode 
    - Clock Polarity: Idle:Low, Active: High
    - Clock Edge: Active to Ide
    SPI Clock
    - Clock source: Fosc/4
![](https://d2mxuefqeaa7sj.cloudfront.net/s_92D49EE73564DFCCF10E9CEC26B59967088C73B7420C2F856CDDEE19BAC46EA4_1536814858449_image.png)

- LoRaWAN RN2903 DIO Pins Configuration (Pin Manager: Grid [MCC])

Besides SPI, the LoRaWAN stack further requires six GPIOs (DIOs), in order to communicate with the SX1276 radio transceiver. These GPIOs need to be interrupt-capable and can either have External Interrupt function. Besides these six GPIOs, the LoRaWAN stack also requires a reset control pin (NRESET) and the Chip Select for SPI (NSS) to communicate with the SX1276 radio transceiver and the RF Switch control pin (SW_POW). 

  - DIO0: Port B Pin 1 (RB1)
  - DIO1: Port B Pin 2 (RB2)
  - DIO2: Port B Pin 4 (RB4)
  - DIO5: Port B Pin 0 (RB0)
  - NRESET: Port C Pin 2 (RC2)
  - NSS: Port D Pin 3 (RD3)
  - SW_POW: Port B Pin 3 (RB3)
![](https://d2mxuefqeaa7sj.cloudfront.net/s_92D49EE73564DFCCF10E9CEC26B59967088C73B7420C2F856CDDEE19BAC46EA4_1536823782408_image.png)

- LoRaWAN RN2903 Pins Module Configuration contain the pins of the resources that were added  to the project
  For LoRaWAN stack, DIO2 pin (RB4) must have the IOC set to “any”, which means a IOC request will be made on both rising and falling edges.
  - IOC: any (RB4)
![](https://d2mxuefqeaa7sj.cloudfront.net/s_92D49EE73564DFCCF10E9CEC26B59967088C73B7420C2F856CDDEE19BAC46EA4_1536823889800_image.png)

- LoRaWAN RN2903 Interrupt Module Configuration
  - EXT_INT - INT0I: clear check box 
    Disabled the INT0 interrupt because the RB0 pin, corresponding to the INT0 interrupt, is only polled by the LoRAWAN stack there is no need to generate an interrupt on INT0 
![](https://d2mxuefqeaa7sj.cloudfront.net/s_92D49EE73564DFCCF10E9CEC26B59967088C73B7420C2F856CDDEE19BAC46EA4_1536823969377_image.png)

- As the project configuration have done, the LoRaWAN Library can be generated by press the Generate
![](https://d2mxuefqeaa7sj.cloudfront.net/s_92D49EE73564DFCCF10E9CEC26B59967088C73B7420C2F856CDDEE19BAC46EA4_1536824114163_image.png)

- Then user can start creating the LoRaWAN-based application
![](https://d2mxuefqeaa7sj.cloudfront.net/s_92D49EE73564DFCCF10E9CEC26B59967088C73B7420C2F856CDDEE19BAC46EA4_1536824270823_image.png)


## LoRaWAN Stack Encryption
A microchip cannot distribute the AES.h and AES.c encryption files used by LoRaWAN stack. Due to differences in license term. These two files must be manually replaced in the project, because the ones which are generated together with the stack only contain an error informing about missing AES encryption

Can be downloaded from [https://www.microchip.com/Developmenttools/ProductDetails/SW300052](https://www.microchip.com/Developmenttools/ProductDetails/SW300052)


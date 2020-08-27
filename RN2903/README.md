# RN2903 LoRa Module
The Microchip RN2903 module provides LoRaWAN protocol connectivity using a simple UART interface where containing a host MCU which reads a sensor, commands the RN2903 to transmit the sensor reading over the LoRa network. Data are encrypted by the RN2903 and the radio packet is received by one or multiple gateways which forward it to the network server. The network server sends the data to the application server which has the key to decrypt the application data. Similarly, a development platform may consist of an RN2903 directly connected over UART to a PC.

![](https://d2mxuefqeaa7sj.cloudfront.net/s_411E442440EC9056AD9FD9EB2918F88D9CF4C6356195DA74797F51BD692E2F51_1543208137539_image.png)


Besides SPI, the LoRaWAN stack further requires six GPIOs in order to communicate with the SX1276 radio transceiver. These six GPIOs, the LoRaWAN stack also requires a reset control pin (NREST) and the Chip select for SPI (NSS) to communicate with the SX1276 radio transceiver and the RF switch control pin (SW_POW). The RF switch control pin is required only if RN2903A module is used.

![](https://d2mxuefqeaa7sj.cloudfront.net/s_935869AC5F946BF7FA807D314DE04F8ADD299D6956B4845E76242B98734D5A1D_1543224092448_image.png)

## Content
- LoRaWAN Library Plug-in on RN2903 LoRa module. The LoRaWAN Library Plug-in for the MPLAB Code Configuration allows for quick and easy C code generation of Microchip’s LoRaWAN stack solution for LoRa Technology end device. The LoRa stack is already present on the Microchip RN2903 modules. Both cores of RN2903 modules contain the PIC18LF46K22 device and the Semtech SX1276 radio transceiver
  - [ADD LoRaWAN Library Plug-in to MCC](https://github.com/wiroon/software_engineering_2018/blob/master/lora_nodes/microchip/RN2903/PICoRa_LoRa%20Customization.md#lorawan-library-plug-in-on-lora-node-module)
  - [LoRaWAN Configuration on RN2903 Module Project](https://github.com/wiroon/software_engineering_2018/blob/master/lora_nodes/microchip/RN2903/PICoRa_LoRa%20Customization.md#lorawan-configuration-on-rn2903-module-project)
  - [LoRaWAN Basic Configuration](https://github.com/wiroon/software_engineering_2018/blob/master/lora_nodes/microchip/RN2903/PICoRa_LoRa%20Customization.md#lorawan-basic-configuration)
  - [LoRaWAN Stack Encryption](https://github.com/wiroon/software_engineering_2018/blob/master/lora_nodes/microchip/RN2903/PICoRa_LoRa%20Customization.md#lorawan-stack-encryption)


## Version Description
- **V-0.1** : Create project creation with using LoRaWAN Library Plug-in for the MPLAB Code Configuration  
- **V-0.4** : Microchip RN2903 modules have communication with frequency on 915MHz 
- **V-0.5** : Update new function which has Core function, Testing function and Extension function
- **V-0.6** : Microchip RN2903 modules have communication with frequency on 923MHz 
- **V-1.0** : Microchip RN2903 modules have communication with frequency on 915MHz&923MHz 

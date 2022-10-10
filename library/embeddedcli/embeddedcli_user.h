/********************************************************************************\
 @file embeddedcli_user.h
 @brief header file of Embedded CLI for user to config
 @version 1.0.0
 @author Walid Amriou
 @date 06/10/2022

* This work is licensed under:
Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License

* You are free to:
Share copy and redistribute the material in any medium or format

* Under the following terms:
- Attribution You must give appropriate credit, provide a link to the license, and
indicate if changes were made. You may do so in any reasonable manner, but not in
any way that suggests the licensor endorses you or your use.
- NonCommercial You may not use the material for commercial purposes.
- NoDerivatives If you remix, transform, or build upon the material, you may not
distribute the modified material.
- No additional restrictions You may not apply legal terms or technological measures
that legally restrict others from doing anything the license permits.

the software or Code or Scripts or any files in this source is provided "as is" and
the author disclaims all warranties with regard to this files including all implied
warranties of merchantability and fitness. in no event shall the author be liable
for any special, direct, indirect, or consequential damages or any damages whatsoever
resulting from loss of use, data or profits, whether in an action of contract,
negligence or other tortious action, arising out of or in connection with the use or
performance of this software or code or scripts or any files in this source.

\********************************************************************************/

#include "embeddedcli.h"
#include <stdint.h>
#ifndef EMBEDDEDCLI_USER_H
#define EMBEDDEDCLI_USER_H

/****** START CONFIG PART ******/
// Microcontroller
#define ESP32
//#define ATMELHAL
// HAL configuration

#ifdef ATMELHAL
#define hal_serial_send hal_serial_UART0_send // change this to your own function from the HAL library
                                              // to send data to the serial port
                                              // hal_serial_send should be
                                              // hal_serial_send(uint8_t *data, uint16_t size)
#define hal_serial_init hal_serial_UART0_init // change this to your own function from the HAL library
                                              // to init serial port
                                              // hal_serial_send should be
                                              // hal_serial_send(uint8_t *data, uint16_t size)
#define hal_enable_interrupt sei
// HAL library example (for atmel): https://github.com/walidamriou/atmelhal
#endif
#ifdef ESP32

#endif

// The Embedded system device name configuration
#define DEVICE_NAME "Embedded system device test"
#define COMMAND_SIZE_MAX 5 
// The Embedded system device Firmware version configuration
#define DEVICE_FIRMWARE_VERSION "v1.0.0\n"

// Number of commands configuration
#define CMD_NUMBER 3

// functions configuration
/*
 * @brief function 1
 * @param none
 * @return none
 */
void fun1();
/*
 * @brief function 2
 * @param none
 * @return none
 */
void fun2();
/*
 * @brief function 3
 * @param none
 * @return none
 */
void fun3();

/****** END CONFIG PART ******/

// array of function pointers
extern void (*func_ptr[CMD_NUMBER])();

// array of function names
extern char *cmd_list[CMD_NUMBER];

// array of command length
extern uint8_t cmd_len[CMD_NUMBER];

#endif
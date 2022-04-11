/********************************************************************************\ 
 @file embeddedcli.h
 @brief header file of Embedded CLI 
 @version 1.0.0
 @author Walid Amriou 
 @date 09/04/2022

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

/****** START CONFIG ******/

// Microcontroller HAL files
#include "atmelhal/hal_sources.h"
/****** END CONFIG ******/

#ifndef EMBEDDEDCLI_H
#define EMBEDDEDCLI_H

// ecli config defines
#define EMBEDDEDCLI_VERSION           "v1.0.0"
#define EMBEDDEDCLI_UART_BUS_SPEED     9600 // Do not change it 

// ecli core defines

#define EMBEDDEDCLI_CMD_SIZE      20    // Max command string length
#define EMBEDDEDCLI_IN_BUF_SIZE   25   // Max input string length
#define EMBEDDEDCLI_ARG_BUF_SIZE  64    // Max argument string length
#define EMBEDDEDCLI_MAX_ARGS      8     // Max number of arguments

// ecli core variables
extern uint8_t embeddedcli_error;

// ecli core functions

void embeddedcli_init(void);
uint8_t embeddedcli_receive(char data_received);
// to get help
int EmbeddedCLI_Help(void);
// to get version
void embeddedcli_cmd_help(void);
void embeddedcli_cmd_version(void);
void embeddedcli_cmd_about(void);
// execute core function
int EmbeddedCLI_Execute(void);
uint8_t embeddedcli_cmd_core_search(uint8_t *const data_addr, uint16_t data_len);
#endif
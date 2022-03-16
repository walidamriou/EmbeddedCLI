/**
 * @file embeddedcli.h
 * @brief header file of Embedded CLI library
 * 
 * @author Walid Amriou (walidamriou)
 * @date 15/03/2022
 * 
 * Embedded CLI
 * Open and Lightweight Command Line Interface for Embedded Systems
 * 
 * docs: https://EmbeddedCLI.walidamriou.com
 * source: https://github.com/walidamriou/EmbeddedCLI
 * 
 */

#ifndef EMBEDDEDCLI_H 
#define EMBEDDEDCLI_H

#include <Arduino.h>

/*************************************************************************************/
/*************************************************************************************/
/*****                            Config Embedded CLI                            *****/
/*************************************************************************************/
/*************************************************************************************/

#define EMBEDDEDCLI_UART_BUS_SPEED     9600
#define EMBEDDEDCLI_LED                13    // GPIO connected to led to debug ECLI
#define DEVICE_NAME                    "Embedded system device test"
#define DEVICE_FIRMWARE_VERSION        "v1.0.0"

// Functions commands 
// Command 1 example
int cmd1();
// Command 2 example
int cmd2();
// Command 3 example
int cmd3();

/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/

// ecli config defines
#define EMBEDDEDCLI_VERSION       "v1.0.0"

// ecli core defines
#define EMBEDDEDCLI_IN_BUF_SIZE   128   // Max input string length
#define EMBEDDEDCLI_ARG_BUF_SIZE  64    // Max argument string length
#define EMBEDDEDCLI_MAX_ARGS      8     // Max number of arguments

// ecli core variables
extern bool EmbeddedCLI_Error_Flag;

// ecli core functions
void EmbeddedCLI_Init();
void EmbeddedCLI_Loop();
#endif
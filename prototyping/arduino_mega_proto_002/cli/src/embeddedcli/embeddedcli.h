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
#include "embeddedcli_config.h"

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
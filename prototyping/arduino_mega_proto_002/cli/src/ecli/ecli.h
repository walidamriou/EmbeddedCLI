/**
 * @file ecli.h
 * @brief header file of ecli library
 * 
 * @author Walid Amriou (walidamriou)
 * @date 15/03/2022
 * @version 1.0.0
 * 
 * ECLI (EmbeddedCLI)
 * Open and Lightweight Command Line Interface for Embedded Systems
 * 
 * docs: https://ecli.walidamriou.com
 * source: https://github.com/walidamriou/ECLI
 * 
 */

#ifndef ECLI_H 
#define ECLI_H

#include <Arduino.h>

// user defines 
#define DEVICE_NAME        "Embedded system device test"

// ecli config defines
#define ECLI_VERSION       "v1.0.0"

// ecli core defines
#define ECLI_IN_BUF_SIZE   128   // Max input string length
#define ECLI_ARG_BUF_SIZE  64    // Max argument string length
#define ECLI_MAX_ARGS      8     // Max number of arguments
#define ECLI_LED           13    // GPIO connected to led to debug ECLI

// ecli core variables
extern bool error_flag;

// ecli core arrays


// ecli core functions
void ecli_init();
void ECLI_loop();
#endif
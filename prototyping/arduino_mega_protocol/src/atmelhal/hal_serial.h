/********************************************************************************\ 
 @file hal_serial.h
 @brief header file of serial (UART) HAL
 @version 1.0.0
 @author Walid Amriou 
 @date 06/04/2022

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

#include "hal_sources.h"

#ifndef HAL_SERIAL_H
#define HAL_SERIAL_H

/*** start Serial Config ***/
#define SERIAL_BAUD_RATE 9600

/*** end Serial config ***/

#define BAUD SERIAL_BAUD_RATE
#include <util/setbaud.h>

/* functions */

/*
 * @brief Initialize the serial port
 * @param none
 * @return none
 */
void hal_serial_UART0_init(void);

/*
 * @brief send data via UART0
 * @param tx_data_addr: address of the data to be sent
 * @param tx_data_len: length of the data to be sent
 * @return none
 * @note: if you want to send data call X, even it is a array or variable, you must write:
 *        hal_serial_UART0_send((uint8_t *)&X,sizeof(X));
 */
void hal_serial_UART0_send(uint8_t * const tx_data_addr, uint16_t tx_data_len);

#endif
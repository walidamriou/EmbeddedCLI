/********************************************************************************\ 
 @file hal_serial.c 
 @brief source file of serial (UART) HAL
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

#include "hal_serial.h"

void hal_serial_UART0_init(void){                              
  // set baud rate in hal_serial.h
  // UBRRH_VALUE and UBRRL_VALUE defined in setbaud.h 
  UBRR0H = UBRRH_VALUE; // set High Byte of Baud Rate to USART0 Baud Rate Register High Byte                         
  UBRR0L = UBRRL_VALUE; // set Low Byte of Baud Rate to UBRR0L USART0 Baud Rate Register Low Byte
  // if Double the USART Transmission Speed active
  //  Effective for asynchronous operation mode
  #if USE_2X
  // use UCSRnA(USART Control and Status Register n A) register to control serial communication and status.
  UCSR0A |= (1 << U2X0); // set U2X0 to 1 (enable Double the USART Transmission Speed)
  #else
  UCSR0A &= ~(1 << U2X0); // clear U2X0 to 0 (disable Double the USART Transmission Speed)
  #endif
  // Transmitter and receive Enable (RXEN0, TXEN0) of UART 0 
  UCSR0B = (1 << TXEN0) | (1 << RXEN0); // set bit TXEN0 and RXEN0 to 1 in UCSR0B register
  // The UCSRnC(USART Control and Status Register n C) is a register for parity, stop bit and so on.
  // Sets the length of data bit 8 data bits, 1 stop bit
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);   
}


void hal_serial_UART0_send(uint8_t * const tx_data_addr, uint16_t tx_data_len){
  // save the address of the data to be sent in buffer
  uint8_t *tx_data_addr_buf = tx_data_addr;
  for (uint16_t i = 0; i < tx_data_len; i++){
    loop_until_bit_is_set(UCSR0A, UDRE0); // loop unitl UDRE0 (USART Data Register) is Empty  
    UDR0 = *tx_data_addr_buf;
    tx_data_addr_buf++;
  }
}



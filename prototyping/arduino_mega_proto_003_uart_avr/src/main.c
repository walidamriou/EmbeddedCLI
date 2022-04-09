

#include "open_atmel_hal/hal_sources.h"


int main(void) {
  
  hal_serial_UART0_init();

  //char c[] = "hello google dodo ";
  uint8_t c  = 104;
  //uint8_t c[]={104,113,107,101,120};
  hal_serial_UART0_send((uint8_t *)&c,sizeof(c));




  // Enable interrupts
	//sei();
  while (1) {

  } 
  return (0); 
}





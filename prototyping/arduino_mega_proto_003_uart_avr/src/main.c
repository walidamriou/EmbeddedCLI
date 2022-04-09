#include "atmelhal/hal_sources.h"
#include "embeddedcli/embeddedcli.h"

int main(void) {
  
  embeddedcli_init();
  embeddedcli_cmd_help();
  //char c[] = "hello google dodo ";
  //uint8_t c  = 104;
  //uint8_t c[]={104,113,107,101,120};
  //hal_serial_UART0_send((uint8_t *)&c,sizeof(c));

  // Enable interrupts
	sei();
  while (1) {

  } 
  return (0); 
}





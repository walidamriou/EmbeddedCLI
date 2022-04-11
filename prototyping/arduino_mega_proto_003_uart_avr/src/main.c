#include "atmelhal/hal_sources.h"
#include "embeddedcli/embeddedcli_user.h"
#include "embeddedcli/embeddedcli.h"


int main(void) {

  //char note[] = "\ndata";
  embeddedcli_init();
  //data((uint8_t *)&note,sizeof(note));
  (*func_ptr[0])();
  hal_serial_UART0_send((uint8_t *)cmd_list[0],4);
  embeddedcli_cmd_help();

  while (1) {} 
  return 0; 
}





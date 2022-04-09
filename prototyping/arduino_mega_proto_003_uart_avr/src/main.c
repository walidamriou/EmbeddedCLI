#include "atmelhal/hal_sources.h"
#include "embeddedcli/embeddedcli.h"

int main(void) {
  
  embeddedcli_init();
  embeddedcli_cmd_help();

  while (1) {} 
  return 0; 
}





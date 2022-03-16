#include <Arduino.h>
#include "embeddedcli/embeddedcli.h"

void setup(){
  // put your setup code here, to run once:
  
  // init
  EmbeddedCLI_Init();
}

void loop(){
  EmbeddedCLI_Loop();
}


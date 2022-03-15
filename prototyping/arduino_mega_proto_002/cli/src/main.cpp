#include <Arduino.h>
#include "ecli/ecli.h"

void setup(){
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ECLI_LED, OUTPUT);
  
  // init
  ecli_init();
}

void loop(){
  ECLI_loop();
}


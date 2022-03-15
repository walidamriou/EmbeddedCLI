#include <Arduino.h>

#define ECLI_VERSION "v1.0.0"
#define ECLI_IN_BUF_SIZE   128   // Max input string length
#define ECLI_ARG_BUF_SIZE  64    // Max argument string length
#define ECLI_MAX_ARGS      8     // Max number of arguments
#define ECLI_LED           13    // GPIO connected to led to debug ECLI
#define DEVICE_NAME "Embedded system device test"

bool error_flag = false;

char line[ECLI_IN_BUF_SIZE];
char args[ECLI_MAX_ARGS][ECLI_ARG_BUF_SIZE];

void ECLI_init(){
    Serial.println("Welcome to this simple Arduino command line interface (CLI).");
    Serial.println("Type \"help\" to see a list of commands.");
}

// Functions prototype 
// ECLI core functions
int ECLI_help();
int ECLI_version();

int ECLI_execute();

// ECLI commands functions
int cmd_1();
int cmd_2();
int cmd_3();

// List of functions pointers corresponding to each command
int (*commands_functions_list[])(){
    &ECLI_help,
    &ECLI_version,
    &cmd_1,
    &cmd_2,
    &cmd_3
};
 
// List of command names
const char *commands_names_list[] = {
    "help",
    "version",
    "cmd1",
    "cmd2",
    "cmd3",
    "test"
};
 
// List of sub command of cmd 3 
const char *led_args[] = {
    "cmd1",
    "cmd2",
    "cmd3"
};
 
int num_commands = sizeof(commands_names_list) / sizeof(char *);

int cmd_1(){
  Serial.println("cmd 1");
  return 0;
}
int cmd_2(){
  Serial.println("cmd 2");
  return 0;
}
int cmd_3(){
  Serial.println("cmd 3");
  if(strcmp(args[1], led_args[0]) == 0){
      Serial.println("sub cmd 1 of cmd 1");
  }
  return 0;
}

// ECLI Core
int ECLI_help(){
  Serial.println("The following commands are available:");
  // print commands
  for(int i=0; i<num_commands; i++){
    Serial.print("  ");
    Serial.println(commands_names_list[i]);
  }
  Serial.println("");
  return 0;
}

int ECLI_version(){
  Serial.println(ECLI_VERSION);
  return 0;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ECLI_LED, OUTPUT);
  
  // ECLI init
  Serial.print("Welcome to ");
  Serial.println(DEVICE_NAME);
  Serial.print("Powered by ECLI ");
  Serial.println(ECLI_VERSION);
}

void loop() {

  //Serial.print("> ");

  String line_string;
  // wait until there are data in the ECLI line
  while(!Serial.available());
  // if there are data in the ECLI line
  if(Serial.available()){
    // read data until \n
    line_string = Serial.readStringUntil('\n');
    //if the data length not large then ECLI_IN_BUF_SIZE
    if(line_string.length() < ECLI_IN_BUF_SIZE){
      // convert data received to line array 
      line_string.toCharArray(line, ECLI_IN_BUF_SIZE);
      Serial.println(line_string);
    }
    else{
      Serial.println("Input string too long.");
      error_flag = true;
    }

    char *argument;
    int counter = 0;
    // breaks string str into a series of tokens using the delimiter delim, here it is " "
    argument = strtok(line, " ");

    while((argument != NULL)){
      // if the counter below check the number of arguments 
      if(counter < ECLI_MAX_ARGS){
        // if the argument below check the number of arguments
        if(strlen(argument) < ECLI_MAX_ARGS){
          // strcpy(destination, source)
          strcpy(args[counter],argument);
          //Serial.println(argument);
          argument = strtok(NULL, " ");
          counter++;
        }
        else{
          Serial.println("Input string too long.");
          error_flag = true;
          break;
        }
      }
      else{
        break;
      }
    }
    // Serial.println(counter);

    ECLI_execute();

  }
}

int ECLI_execute(){  
  // search about the command
  for(int i=0; i<num_commands; i++){
    // search about the command in the commands names list
    if(strcmp(args[0], commands_names_list[i]) == 0){
      // if found it execute the function 
      return(*commands_functions_list[i])();
    }
  }
  // if did not found the command
  Serial.println("Invalid command. Type \"help\" for more.");
  return 0;
}
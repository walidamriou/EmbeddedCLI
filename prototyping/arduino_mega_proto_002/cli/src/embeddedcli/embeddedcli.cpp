/**
 * @file embeddedcli.cpp
 * @brief source file of Embedded CLI library
 * 
 * @author Walid Amriou (walidamriou)
 * @date 15/03/2022
 * 
 * Embedded CLI
 * Open and Lightweight Command Line Interface for Embedded Systems
 * 
 * docs: https://EmbeddedCLI.walidamriou.com
 * source: https://github.com/walidamriou/EmbeddedCLI
 * 
 */
#include "embeddedcli.h"

char line[EMBEDDEDCLI_IN_BUF_SIZE];
char args[EMBEDDEDCLI_MAX_ARGS][EMBEDDEDCLI_ARG_BUF_SIZE];

/*************************************************************************************/
/*************************************************************************************/
/*****                            Config Embedded CLI                            *****/
/*************************************************************************************/
/*************************************************************************************/

// List of functions pointers corresponding to each command
int (*Commands_Functions_List[])(){
    &cmd1,
    &cmd2,
    &cmd3
};
 
// List of command names 
const char *Commands_Names_List[] = {
    "cmd1",
    "cmd2",
    "cmd3"
};

// List of sub command of cmd 3 
const char *Commands_Names_List_cmd3[] = {
    "cmd31",
    "cmd32",
    "cmd33"
};

// Functions commands 

// Command 1 example
int cmd1(){
  Serial.println("cmd 1");
  return 0;
};

// Command 2 example
int cmd2(){
  Serial.println("cmd 2");
  return 0;
};

// Command 3 example
int cmd3(){
  Serial.println("cmd 3");
  Serial.println(args[1]);
  if(args[1] == 0){
    return 0;
  }
  if(strcmp(args[1], Commands_Names_List_cmd3[0]) == 0){
    Serial.println("sub cmd 1 of cmd 3");
    return 0;
  }
  else if(strcmp(args[1], Commands_Names_List_cmd3[1]) == 0){
    Serial.println("sub cmd 2 of cmd 3");
    return 0;
  }
  else if(strcmp(args[1], Commands_Names_List_cmd3[2]) == 0){
    Serial.println("sub cmd 3 of cmd 3");
    return 0;
  }
  else{
    Serial.println("Invalid command. Type \"help\" for more.");
    return 0;
  }
  return 0;
}

/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/



bool EmbeddedCLI_Error_Flag=false;

// init elci system
void EmbeddedCLI_Init(){
    // Config UART bus
    Serial.begin(EMBEDDEDCLI_UART_BUS_SPEED);
    // Config LED debug
    pinMode(EMBEDDEDCLI_LED, OUTPUT);

    Serial.print("Welcome to ");
    Serial.println(DEVICE_NAME);
    Serial.print("Powered by ECLI ");
    Serial.println(EMBEDDEDCLI_VERSION);
    Serial.println("Type \"help\" to see a list of commands.");
}

// Functions commands 
// to get help
int EmbeddedCLI_Help();
// to get version
int EmbeddedCLI_Version();
// execute core function
int EmbeddedCLI_Execute();

// List of functions pointers corresponding to each command
int (*EmbeddedCLI_commands_functions_list[])(){
    &EmbeddedCLI_Help,
    &EmbeddedCLI_Version,
};
 
// List of command names
const char *EmbeddedCLI_commands_names_list[] = {
    "help",
    "version"
};

int system_num_commands = sizeof(Commands_Names_List) / sizeof(char *);
int EmbeddedCLI_num_commands = sizeof(EmbeddedCLI_commands_names_list) / sizeof(char *);


// ECLI Core
int EmbeddedCLI_Help(){
  Serial.println("The following commands are available:");
  // print commands of Embedded CLI core
  for(int i=0; i<EmbeddedCLI_num_commands; i++){
    Serial.print("  ");
    Serial.println(EmbeddedCLI_commands_names_list[i]);
  }
  // print commands of system
  for(int i=0; i<system_num_commands; i++){
    Serial.print("  ");
    Serial.println(Commands_Names_List[i]);
  }
  Serial.println("");
  Serial.println("");
  return 0;
}

int EmbeddedCLI_Version(){
  Serial.println(EMBEDDEDCLI_VERSION);
  return 0;
}

void EmbeddedCLI_Loop(){
    //Serial.print("> ");

  String line_string;
  // wait until there are data in the ECLI line
  while(!Serial.available());
  // if there are data in the ECLI line
  if(Serial.available()){
    // read data until \n
    line_string = Serial.readStringUntil('\n');
    //if the data length not large then ECLI_IN_BUF_SIZE
    if(line_string.length() < EMBEDDEDCLI_IN_BUF_SIZE){
      // convert data received to line array 
      line_string.toCharArray(line, EMBEDDEDCLI_IN_BUF_SIZE);
      Serial.println(line_string);
    }
    else{
      Serial.println("Input string too long.");
      EmbeddedCLI_Error_Flag = true;
    }

    char *argument;
    int counter = 0;
    // breaks string str into a series of tokens using the delimiter delim, here it is " "
    argument = strtok(line, " ");

    while((argument != NULL)){
      // if the counter below check the number of arguments 
      if(counter < EMBEDDEDCLI_MAX_ARGS){
        // if the argument below check the number of arguments
        if(strlen(argument) < EMBEDDEDCLI_MAX_ARGS){
          // strcpy(destination, source)
          strcpy(args[counter],argument);
          //Serial.println(argument);
          argument = strtok(NULL, " ");
          counter++;
        }
        else{
          Serial.println("Input string too long.");
          EmbeddedCLI_Error_Flag = true;
          break;
        }
      }
      else{
        break;
      }
    }

    EmbeddedCLI_Execute();
    memset(line, 0, EMBEDDEDCLI_IN_BUF_SIZE);
    memset(args, 0, sizeof(args[0][0]) * EMBEDDEDCLI_MAX_ARGS * EMBEDDEDCLI_ARG_BUF_SIZE);
  }
}

int EmbeddedCLI_Execute(){  
  // search about the command
  for(int i=0; i<EmbeddedCLI_num_commands; i++){
    // search about the command in the commands names list
    if(strcmp(args[0], EmbeddedCLI_commands_names_list[i]) == 0){
      // if found it execute the function 
      return(*EmbeddedCLI_commands_functions_list[i])();
    }
  }

  // search about the command
  for(int i=0; i<system_num_commands; i++){
    // search about the command in the commands names list
    if(strcmp(args[0], Commands_Names_List[i]) == 0){
      // if found it execute the function 
      return(*Commands_Functions_List[i])();
    }
  }

  // if did not found the command
  Serial.println("Invalid command. Type \"help\" for more.");
  return 0;
}
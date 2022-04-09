/********************************************************************************\ 
 @file embeddedcli.h
 @brief source file of Embedded CLI 
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

#include "embeddedcli.h"

/*** start Embedded CLI user fucntions ***/

const static struct {
  const char *name; // the name of the command, should be text only
  uint8_t name_len; // calcuate the length of the name manually and +1 for the null terminator
  void (*func)(void); // the function to call
} embeddedcli_cmd_user [] = {
  { "cmd1",5,cmd1 },
  { "cmd2",5,cmd2 },
  { "cmd3",5,cmd3 },
};
uint8_t embeddedcli_cmd_user_count = sizeof embeddedcli_cmd_user / sizeof embeddedcli_cmd_user[0];

void cmd1(void){
    char commands[] = "\n command 1 \n";
    hal_serial_UART0_send((uint8_t *)&commands,sizeof(commands)); 
}

void cmd2(void){ 
    char commands[] = "\n command 2 \n";
    hal_serial_UART0_send((uint8_t *)&commands,sizeof(commands)); 
  
}

void cmd3(void){
    char commands[] = "\n command 3 \n";
    hal_serial_UART0_send((uint8_t *)&commands,sizeof(commands));  

}

/*** end Embedded CLI user fucntions ***/




/*** start Embedded CLI core fucntions ***/

const static struct {
  const char *name; // the name of the command, should be text only
  uint8_t name_len; // calcuate the length of the name manually and +1 for the null terminator
  void (*func)(void); // the function to call
} embeddedcli_cmd_core [] = {
  { "help",5,embeddedcli_cmd_help },
  { "version",8,embeddedcli_cmd_version },
  { "about",6,embeddedcli_cmd_about },
};
uint8_t embeddedcli_cmd_core_count = sizeof embeddedcli_cmd_core / sizeof embeddedcli_cmd_core[0];

int embeddedcli_cmd_core_call(const char *name){
  for (uint8_t i = 0; i < embeddedcli_cmd_core_count; i++) {
    if (!strcmp(embeddedcli_cmd_core[i].name, name) && embeddedcli_cmd_core[i].func) {
      embeddedcli_cmd_core[i].func();
      return 0;
    }
  }
  return 0;
}

void embeddedcli_cmd_help(void) { 
    char commands_1[] = "\nThe following commands are available: \n";
    char commands_print_space[] = "   ";
    char commands_print_newline[] = "\n";
    hal_serial_UART0_send((uint8_t *)&commands_1,sizeof(commands_1));    
    // print commands of Embedded CLI core
    for(uint8_t i=0; i<embeddedcli_cmd_core_count; i++){
        hal_serial_UART0_send((uint8_t *)&commands_print_space,sizeof(commands_print_space));
        hal_serial_UART0_send((uint8_t *)embeddedcli_cmd_core[i].name,embeddedcli_cmd_core[i].name_len);
        hal_serial_UART0_send((uint8_t *)&commands_print_newline,sizeof(commands_print_newline));
    }
    hal_serial_UART0_send((uint8_t *)&commands_print_newline,sizeof(commands_print_newline));
  // print commands of system
  for(uint8_t i=0; i<embeddedcli_cmd_user_count; i++){
        hal_serial_UART0_send((uint8_t *)&commands_print_space,sizeof(commands_print_space));
        hal_serial_UART0_send((uint8_t *)embeddedcli_cmd_user[i].name,embeddedcli_cmd_user[i].name_len);
        hal_serial_UART0_send((uint8_t *)&commands_print_newline,sizeof(commands_print_newline));
  }
  hal_serial_UART0_send((uint8_t *)&commands_print_newline,sizeof(commands_print_newline));
  hal_serial_UART0_send((uint8_t *)&commands_print_newline,sizeof(commands_print_newline));
  
}

void embeddedcli_cmd_version(void) { 
    char commands_print_cli_version[]=EMBEDDEDCLI_VERSION;
    hal_serial_UART0_send((uint8_t *)&commands_print_cli_version,sizeof(commands_print_cli_version));
  }
void embeddedcli_cmd_about(void) {
    char text[] = "Hello World 3!\n";
  hal_serial_UART0_send((uint8_t *)&text,sizeof(text));
}

/*** end Embedded CLI core fucntions ***/

/*** start Embedded CLI core engine ***/
void embeddedcli_init(void){
    hal_serial_UART0_init();
    char welcome_1[] = "Welcome to ";
    hal_serial_UART0_send((uint8_t *)&welcome_1,sizeof(welcome_1));
    char welcome_2[] = DEVICE_NAME;
    hal_serial_UART0_send((uint8_t *)&welcome_2,sizeof(welcome_2));
    char welcome_3[] = "\nPowered by ECLI ";
    hal_serial_UART0_send((uint8_t *)&welcome_3,sizeof(welcome_3));
    char welcome_4[] = EMBEDDEDCLI_VERSION;
    hal_serial_UART0_send((uint8_t *)&welcome_4,sizeof(welcome_4));
    char welcome_5[] = "\nType \"help\" to see a list of commands. \n";
    hal_serial_UART0_send((uint8_t *)&welcome_5,sizeof(welcome_5));

}

void embeddedcli_receive(void){

}
/*** end Embedded CLI core engine ***/

/*

// Command 3 example
int cmd3(){
  //Serial.println("cmd 3");
  //Serial.println(args[1]);
  if(args[1] == 0){
    return 0;
  }
  if(strcmp(args[1], Commands_Names_List_cmd3[0]) == 0){
    //Serial.println("sub cmd 1 of cmd 3");
    return 0;
  }
  else if(strcmp(args[1], Commands_Names_List_cmd3[1]) == 0){
    //Serial.println("sub cmd 2 of cmd 3");
    return 0;
  }
  else if(strcmp(args[1], Commands_Names_List_cmd3[2]) == 0){
    //Serial.println("sub cmd 3 of cmd 3");
    return 0;
  }
  else{
    //Serial.println("Invalid command. Type \"help\" for more.");
    return 0;
  }
  return 0;
}
*/








/*

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
*/
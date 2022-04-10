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

uint8_t embeddedcli_cmd_user_call(const char *name){
  for (uint8_t i = 0; i < embeddedcli_cmd_user_count; i++) {
    if (!strcmp(embeddedcli_cmd_user[i].name, name) && embeddedcli_cmd_user[i].func) {
      embeddedcli_cmd_user[i].func();
      return 0;
    }
  }
  return 1;
}

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




uint8_t embeddedcli_cmd_core_call(const char *name){
  for (uint8_t i = 0; i < embeddedcli_cmd_core_count; i++) {
    if (!strcmp(embeddedcli_cmd_core[i].name, name) && embeddedcli_cmd_core[i].func) {
      embeddedcli_cmd_core[i].func();
      return 0;
    }
    else{
      return 1;
    }
  }
  // error command not found
  char error_command_not_found[] = "\n error command not found \n";
  hal_serial_UART0_send((uint8_t *)&error_command_not_found,sizeof(error_command_not_found)); 
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
    char text[] = "EmbeddedCLI developed by Walid Amriou\n www.walidamriou.com";
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
    // Enable interrupts
	  sei();
}




void embeddedcli_cmd_core_seach(const char *cmd_search){
hal_serial_UART0_send((uint8_t *)&cmd_search,sizeof(cmd_search));

  uint8_t a = embeddedcli_cmd_core_call(cmd_search);
  if(a==0){
    char return0[] = "\n return 0 \n";
    hal_serial_UART0_send((uint8_t *)&return0,sizeof(return0));
  }
  else{
    char return1[] = "\n return 1 \n";
    hal_serial_UART0_send((uint8_t *)&return1,sizeof(return1));
  }

  if(embeddedcli_cmd_core_call(cmd_search)==0){

  }
  else if(embeddedcli_cmd_user_call(cmd_search)==0){

  }
  else{
    char welcome_5[] = "\nError! Command non exist. \n Type \"help\" to see the list of commands available. \n";
    hal_serial_UART0_send((uint8_t *)&welcome_5,sizeof(welcome_5));
  }
}




char embeddedcli_receive_buffer[EMBEDDEDCLI_IN_BUF_SIZE];
//#define EMBEDDEDCLI_IN_BUF_SIZE   128   // Max input string length
uint8_t embeddedcli_receive_buffer_counter = 0;
char embeddedcli_receive_end_cmd='\n';



uint8_t embeddedcli_receive(char data_received){ 
  // check if buffer is full
  if((embeddedcli_receive_buffer_counter+1) > EMBEDDEDCLI_IN_BUF_SIZE){
    // clear buffer
    memset(embeddedcli_receive_buffer, 0, embeddedcli_receive_buffer_counter);
    // clear counter
    embeddedcli_receive_buffer_counter=0;
    // return buffer is full error
    char Error_longer[] = "\nError! Command longer than allowed. \n Type \"help\" to see the list of commands available. \n";
    hal_serial_UART0_send((uint8_t *)&Error_longer,sizeof(Error_longer));
    // go out from the interrupt handler
    return 0; 
  }
  // check if receive \n
  if(data_received==embeddedcli_receive_end_cmd){
    // if receive \n so search about the command and call the function
    // search about the command
    // search in the core commands
    char embeddedcli_receive_buffer_temp[embeddedcli_receive_buffer_counter];
    for (uint8_t i = 0; i < embeddedcli_receive_buffer_counter; i++){
      embeddedcli_receive_buffer_temp[i]=embeddedcli_receive_buffer[i];
    }
    char word_pass[] = "\nword pass:";
    hal_serial_UART0_send((uint8_t *)&word_pass,sizeof(word_pass));

    hal_serial_UART0_send((uint8_t *)&embeddedcli_receive_buffer_temp,sizeof(embeddedcli_receive_buffer_temp));
    embeddedcli_cmd_core_seach(embeddedcli_receive_buffer_temp);
    // clear buffer
    memset(embeddedcli_receive_buffer, 0, embeddedcli_receive_buffer_counter);
    // clear counter
    embeddedcli_receive_buffer_counter=0;
    // return buffer is full error
    // go out from the interrupt handler
    return 0;
  }
  else{
    // if not receive \n so save the char in the buffer
    embeddedcli_receive_buffer[embeddedcli_receive_buffer_counter]=data_received;
    embeddedcli_receive_buffer_counter++;
    return 1;
  }

return 0;
}



/*** end Embedded CLI core engine ***/
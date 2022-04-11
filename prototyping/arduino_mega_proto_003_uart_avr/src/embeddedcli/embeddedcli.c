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
#include "embeddedcli_user.h"
/*** start Embedded CLI user fucntions ***/
char *core_cmd_list[CMD_NUMBER] = {"help", "version", "about"};
uint8_t core_cmd_len[CMD_NUMBER]={5,8,5};

void embeddedcli_cmd_help(void) { 
    char commands_1[] = "\n\n The following commands are available: \n";
    char commands_print_space[] = "   ";
    char commands_print_newline[] = "\n";
    hal_serial_UART0_send((uint8_t *)&commands_1,sizeof(commands_1));    
    // print commands of Embedded CLI core
    for(uint8_t i=0; i<CORE_CMD_NUMBER; i++){
        hal_serial_UART0_send((uint8_t *)&commands_print_space,sizeof(commands_print_space));
        hal_serial_UART0_send((uint8_t *)core_cmd_list[i],core_cmd_len[i]);
        hal_serial_UART0_send((uint8_t *)&commands_print_newline,sizeof(commands_print_newline));
    }
    hal_serial_UART0_send((uint8_t *)&commands_print_newline,sizeof(commands_print_newline));
  // print commands of system
  for(uint8_t i=0; i<CMD_NUMBER; i++){
        hal_serial_UART0_send((uint8_t *)&commands_print_space,sizeof(commands_print_space));
        hal_serial_UART0_send((uint8_t *)cmd_list[i],cmd_len[i]);
        hal_serial_UART0_send((uint8_t *)&commands_print_newline,sizeof(commands_print_newline));
  }
  hal_serial_UART0_send((uint8_t *)&commands_print_newline,sizeof(commands_print_newline));
  hal_serial_UART0_send((uint8_t *)&commands_print_newline,sizeof(commands_print_newline));
  
}


void embeddedcli_cmd_version(void) { 
    char space[] = "  \n";
    char commands_print_cli_version[]=EMBEDDEDCLI_VERSION;
    hal_serial_UART0_send((uint8_t *)&commands_print_cli_version,sizeof(commands_print_cli_version));
    hal_serial_UART0_send((uint8_t *)&space,sizeof(space));

}
void embeddedcli_cmd_about(void) {
    char text[] = "\n\n EmbeddedCLI developed by Walid Amriou \n www.walidamriou.com \n\n";
  hal_serial_UART0_send((uint8_t *)&text,sizeof(text));
}

void (*core_func_ptr[CORE_CMD_NUMBER])() = {embeddedcli_cmd_help, embeddedcli_cmd_version, embeddedcli_cmd_about};



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

uint8_t embeddedcli_cmd_core_search(uint8_t *const data_addr, uint16_t data_len){
  char note[] = "\n function received:";
  hal_serial_UART0_send((uint8_t *)&note,sizeof(note));

  // save the address of the data to be sent in buffer
  
  char cmd_search[data_len];
  uint8_t *data_addr_buf = data_addr;
  for (uint16_t i = 0; i < data_len; i++){
    cmd_search[i] = *data_addr_buf;
    data_addr_buf++;
  }
  // work with arduino
  if(cmd_search[data_len]!='\0'){
    cmd_search[data_len-1]='\0';
  }
  
  hal_serial_UART0_send((uint8_t *)&cmd_search,sizeof(cmd_search));

  uint8_t flag = 0;
  for (uint8_t i = 0; i < CORE_CMD_NUMBER; i++) {
    if (!strcmp(core_cmd_list[i], cmd_search)) {
        (*core_func_ptr[i])();
        flag = 1;
        return 0;
    }
  }
  if(flag == 0){
  for (uint8_t i = 0; i < CMD_NUMBER; i++) {
    if (!strcmp(cmd_list[i], cmd_search)) {
        (*func_ptr[i])();
        return 0;
    }
  }
  }


  char error_command_not_found[] = "\nError! Command non exist. \n Type \"help\" to see the list of commands available. \n";
  hal_serial_UART0_send((uint8_t *)&error_command_not_found,sizeof(error_command_not_found)); 
  return 1;
}




char embeddedcli_receive_buffer[EMBEDDEDCLI_IN_BUF_SIZE];
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
    //char word_pass[] = "\n word pass:";
    //hal_serial_UART0_send((uint8_t *)&word_pass,sizeof(word_pass));

    //hal_serial_UART0_send((uint8_t *)&embeddedcli_receive_buffer_temp,sizeof(embeddedcli_receive_buffer_temp));
    // next is correct
    embeddedcli_cmd_core_search((uint8_t *)&embeddedcli_receive_buffer_temp,sizeof(embeddedcli_receive_buffer_temp));
    // clear buffer
    memset(embeddedcli_receive_buffer, 0, embeddedcli_receive_buffer_counter);
    memset(embeddedcli_receive_buffer_temp, 0, embeddedcli_receive_buffer_counter);
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
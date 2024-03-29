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

((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((, ((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((.      .((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((,            (((((((((((((((((((((((((((((((((((((((((((((((((((((
(((((((((((((((((((             .(((((((((((((((((((((((((((((((((((((((((((((((
(((((((((((((((((((((((((             ((((((((((((((((((((((((((((((((((((((((((
(((((((((((((((((((((((((((((((       ((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((.           ((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((.             ((((((((((((((((((((((((((((((((((((((((((((((
(((((((((((((((             /(((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((.       .(((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((.  ((((((((((((((((((((((((                          (((((((((((((
(((((((((((((((((((((((((((((((((((((((((                          (((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((

\********************************************************************************/

#include "embeddedcli.h"
#include "embeddedcli_user.h"

char embeddedcli_receive_buffer[EMBEDDEDCLI_IN_BUF_SIZE];
uint8_t embeddedcli_receive_buffer_counter = 0;

void embeddedcli_init(void){
  /****** START CONFIG ******/
  hal_serial_UART0_init();
  sei();// Enable interrupts
  /****** END CONFIG ******/
  hal_serial_send((uint8_t *)&EMBEDDEDCLI_WELCOME_TXT,sizeof(EMBEDDEDCLI_WELCOME_TXT));
}

char *core_cmd_list[CMD_NUMBER] = {"help", "version", "about"};
uint8_t core_cmd_len[CMD_NUMBER]={5,8,6};

void embeddedcli_cmd_help(void) { 
    char commands_1[] = "\n\n The following commands are available: \n";
    hal_serial_send((uint8_t *)&commands_1,sizeof(commands_1));    
    // print commands of Embedded CLI core
    for(uint8_t i=0; i<CORE_CMD_NUMBER; i++){
        hal_serial_send((uint8_t *)&EMBEDDEDCLI_PRINT_SPACE,sizeof(EMBEDDEDCLI_PRINT_SPACE));
        hal_serial_send((uint8_t *)core_cmd_list[i],core_cmd_len[i]);
        hal_serial_send((uint8_t *)&EMBEDDEDCLI_PRINT_NEWLINE,sizeof(EMBEDDEDCLI_PRINT_NEWLINE));
    }
    hal_serial_send((uint8_t *)&EMBEDDEDCLI_PRINT_NEWLINE,sizeof(EMBEDDEDCLI_PRINT_NEWLINE));
  // print commands of system
  for(uint8_t i=0; i<CMD_NUMBER; i++){
        hal_serial_send((uint8_t *)&EMBEDDEDCLI_PRINT_SPACE,sizeof(EMBEDDEDCLI_PRINT_SPACE));
        hal_serial_send((uint8_t *)cmd_list[i],cmd_len[i]);
        hal_serial_send((uint8_t *)&EMBEDDEDCLI_PRINT_NEWLINE,sizeof(EMBEDDEDCLI_PRINT_NEWLINE));
  }
  hal_serial_send((uint8_t *)&EMBEDDEDCLI_PRINT_NEWLINE,sizeof(EMBEDDEDCLI_PRINT_NEWLINE));
  
}


void embeddedcli_cmd_version(void) { 
    char commands_print_cli_version[]=EMBEDDEDCLI_VERSION;
    hal_serial_send((uint8_t *)&commands_print_cli_version,sizeof(commands_print_cli_version));
    hal_serial_send((uint8_t *)&EMBEDDEDCLI_PRINT_SPACE,sizeof(EMBEDDEDCLI_PRINT_SPACE));
    hal_serial_send((uint8_t *)&EMBEDDEDCLI_PRINT_NEWLINE,sizeof(EMBEDDEDCLI_PRINT_NEWLINE));


}


void embeddedcli_cmd_about(void) {
    char text[] = "\n\n EmbeddedCLI developed by Walid Amriou \n www.walidamriou.com \n\n";
  hal_serial_send((uint8_t *)&text,sizeof(text));
}

// store the command functions of core in array
void (*core_func_ptr[CORE_CMD_NUMBER])() = {embeddedcli_cmd_help, embeddedcli_cmd_version, embeddedcli_cmd_about};

uint8_t embeddedcli_cmd_core_search(uint8_t *const data_addr, uint16_t data_len){  
  char cmd_search[data_len];
  uint8_t *data_addr_buf = data_addr;
  for (uint16_t i = 0; i < data_len; i++){
    cmd_search[i] = *data_addr_buf;
    data_addr_buf++;
  }
  // work with arduino monitor with Both NL & CR is \r\n
  if(cmd_search[data_len]!='\r' && cmd_search[data_len]!='\n'){
    cmd_search[data_len-1]='\0';
  }

  char *s2=cmd_search;
  int charCompareStatus;
  for (uint8_t i = 0; i < CORE_CMD_NUMBER; i++) {
    char *s1=core_cmd_list[i]; 
    charCompareStatus = 0;
    while( ( *s1 != '\0' && *s2 != '\0' ) && *s1 == *s2 ){
        s1++;
        s2++;
    }
    //compare the mismatching character
    charCompareStatus = (*s1 ==*s2)?0:(*s1 >*s2)?1:-1;
    if(charCompareStatus==0){
      (*core_func_ptr[i])();
      memset(embeddedcli_receive_buffer, 0, EMBEDDEDCLI_IN_BUF_SIZE);
      memset(cmd_search, 0, data_len);
      return 0;
    }
  }
/*
  s2=cmd_search;
  for (uint8_t i = 0; i < CMD_NUMBER; i++) {
    char *s1=cmd_list[i]; 
    charCompareStatus = 0;
    while( ( *s1 != '\0' && *s2 != '\0' ) && *s1 == *s2 ){
        s1++;
        s2++;
    }
    //compare the mismatching character
    charCompareStatus = (*s1 ==*s2)?0:(*s1 >*s2)?1:-1;
    if(charCompareStatus==0){
      (*func_ptr[i])();
      memset(embeddedcli_receive_buffer, 0, EMBEDDEDCLI_IN_BUF_SIZE);
      memset(cmd_search, 0, data_len);
      return 0;
    }
  }
  
*/

  /*
  uint8_t flag = 0;
  for (uint8_t i = 0; i < CORE_CMD_NUMBER; i++) {
    if (!strcmp(core_cmd_list[i], cmd_search)) {
        (*core_func_ptr[i])();
        flag = 1;
        memset(embeddedcli_receive_buffer, 0, EMBEDDEDCLI_IN_BUF_SIZE);
        memset(cmd_search, 0, data_len);
        return 0;
    }
  }
  if(flag == 0){
  for (uint8_t i = 0; i < CMD_NUMBER; i++) {
    if (!strcmp(cmd_list[i], cmd_search)) {
        (*func_ptr[i])();
        memset(embeddedcli_receive_buffer, 0, EMBEDDEDCLI_IN_BUF_SIZE);
        memset(cmd_search, 0, data_len);
        return 0;
    }
  }
  
  }*/
  hal_serial_send((uint8_t *)&EMBEDDEDCLI_ERROR_NOTFOUND_TXT,sizeof(EMBEDDEDCLI_ERROR_NOTFOUND_TXT)); 
  memset(embeddedcli_receive_buffer, 0, EMBEDDEDCLI_IN_BUF_SIZE);
  memset(cmd_search, 0, data_len);
  return 0;
}

uint8_t embeddedcli_receive(char data_received){ 
  // check if buffer is full
  if((embeddedcli_receive_buffer_counter+1) > EMBEDDEDCLI_IN_BUF_SIZE){
    // clear buffer
    memset(embeddedcli_receive_buffer, 0, embeddedcli_receive_buffer_counter);
    // clear counter
    embeddedcli_receive_buffer_counter=0;
    // return buffer is full error
    hal_serial_send((uint8_t *)&EMBEDDEDCLI_ERROR_LONGSIZE_TXT,sizeof(EMBEDDEDCLI_ERROR_LONGSIZE_TXT));
    // go out from the interrupt handler
    return 0; 
  }
  // check if receive \n
  if(data_received==EMBEDDEDCLI_PRINT_NEWLINE_CHAR){
    // if receive \n so search about the command and call the function
    // search about the command
    // search in the core commands
    char embeddedcli_receive_buffer_temp[embeddedcli_receive_buffer_counter];
    for (uint8_t i = 0; i < embeddedcli_receive_buffer_counter; i++){
      embeddedcli_receive_buffer_temp[i]=embeddedcli_receive_buffer[i];
    }
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

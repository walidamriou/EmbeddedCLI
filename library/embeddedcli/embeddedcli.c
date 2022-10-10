/********************************************************************************\
 @file embeddedcli.h
 @brief source file of Embedded CLI
 @version 1.0.0
 @author Walid Amriou
 @date 06/10/2022

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

#ifdef ESP32
  static const char* TAG_EmbeddedCLI = "EmbeddedCLI"; 
#endif



char embeddedcli_receive_buffer[EMBEDDEDCLI_IN_BUF_SIZE];
uint8_t embeddedcli_receive_buffer_counter = 0;

void embeddedcli_init(void)
{
#ifdef ATMELHAL
  hal_serial_init();
  hal_enable_interrupt(); // Enable interrupts
  hal_serial_send((uint8_t *)&EMBEDDEDCLI_WELCOME_TXT, sizeof(EMBEDDEDCLI_WELCOME_TXT));
#endif
#ifdef ESP32
  uart_write_bytes(UART_NUM_0, (const char *)EMBEDDEDCLI_WELCOME_TXT, sizeof(EMBEDDEDCLI_WELCOME_TXT));
#endif
}

char *core_cmd_list[CMD_NUMBER] = {"help", "version", "about"};
uint8_t core_cmd_len[CMD_NUMBER] = {5, 8, 6};

void embeddedcli_cmd_help(void)
{
  char commands_1[] = "\n\n The following commands are available: \n";
#ifdef ATMELHAL
  hal_serial_send((uint8_t *)&commands_1, sizeof(commands_1));
#endif
#ifdef ESP32
  uart_write_bytes(UART_NUM_0, (const char *)commands_1, sizeof(commands_1));
#endif

  // print commands of Embedded CLI core
  for (uint8_t i = 0; i < CORE_CMD_NUMBER; i++)
  {
#ifdef ATMELHAL
    hal_serial_send((uint8_t *)&EMBEDDEDCLI_PRINT_SPACE, sizeof(EMBEDDEDCLI_PRINT_SPACE));
    hal_serial_send((uint8_t *)core_cmd_list[i], core_cmd_len[i]);
    hal_serial_send((uint8_t *)&EMBEDDEDCLI_PRINT_NEWLINE, sizeof(EMBEDDEDCLI_PRINT_NEWLINE));
#endif
#ifdef ESP32
    uart_write_bytes(UART_NUM_0, (const char *)EMBEDDEDCLI_PRINT_SPACE, sizeof(EMBEDDEDCLI_PRINT_SPACE));
    uart_write_bytes(UART_NUM_0, (const char *)core_cmd_list[i], core_cmd_len[i]);
    uart_write_bytes(UART_NUM_0, (const char *)EMBEDDEDCLI_PRINT_NEWLINE, sizeof(EMBEDDEDCLI_PRINT_NEWLINE));
#endif
  }
#ifdef ATMELHAL
  hal_serial_send((uint8_t *)&EMBEDDEDCLI_PRINT_NEWLINE, sizeof(EMBEDDEDCLI_PRINT_NEWLINE));
#endif
#ifdef ESP32
  uart_write_bytes(UART_NUM_0, (const char *)EMBEDDEDCLI_PRINT_NEWLINE, sizeof(EMBEDDEDCLI_PRINT_NEWLINE));
#endif
  // print commands of system
  for (uint8_t i = 0; i < CMD_NUMBER; i++)
  {
#ifdef ATMELHAL
    hal_serial_send((uint8_t *)&EMBEDDEDCLI_PRINT_SPACE, sizeof(EMBEDDEDCLI_PRINT_SPACE));
    hal_serial_send((uint8_t *)cmd_list[i], cmd_len[i]);
    hal_serial_send((uint8_t *)&EMBEDDEDCLI_PRINT_NEWLINE, sizeof(EMBEDDEDCLI_PRINT_NEWLINE));
#endif
#ifdef ESP32
    uart_write_bytes(UART_NUM_0, (const char *)EMBEDDEDCLI_PRINT_SPACE, sizeof(EMBEDDEDCLI_PRINT_SPACE));
    uart_write_bytes(UART_NUM_0, (const char *)cmd_list[i], cmd_len[i]);
    uart_write_bytes(UART_NUM_0, (const char *)EMBEDDEDCLI_PRINT_NEWLINE, sizeof(EMBEDDEDCLI_PRINT_NEWLINE));
#endif
  }
#ifdef ATMELHAL
  hal_serial_send((uint8_t *)&EMBEDDEDCLI_PRINT_NEWLINE, sizeof(EMBEDDEDCLI_PRINT_NEWLINE));
#endif
#ifdef ESP32
  uart_write_bytes(UART_NUM_0, (const char *)EMBEDDEDCLI_PRINT_NEWLINE, sizeof(EMBEDDEDCLI_PRINT_NEWLINE));
#endif
}

void embeddedcli_cmd_version(void)
{
  char commands_print_cli_version[] = EMBEDDEDCLI_VERSION;

#ifdef ATMELHAL
  hal_serial_send((uint8_t *)&commands_print_cli_version, sizeof(commands_print_cli_version));
  hal_serial_send((uint8_t *)&EMBEDDEDCLI_PRINT_SPACE, sizeof(EMBEDDEDCLI_PRINT_SPACE));
  hal_serial_send((uint8_t *)&EMBEDDEDCLI_PRINT_NEWLINE, sizeof(EMBEDDEDCLI_PRINT_NEWLINE));
#endif
#ifdef ESP32
  uart_write_bytes(UART_NUM_0, (const char *)commands_print_cli_version, sizeof(commands_print_cli_version));
  uart_write_bytes(UART_NUM_0, (const char *)EMBEDDEDCLI_PRINT_SPACE, sizeof(EMBEDDEDCLI_PRINT_SPACE));
  uart_write_bytes(UART_NUM_0, (const char *)EMBEDDEDCLI_PRINT_NEWLINE, sizeof(EMBEDDEDCLI_PRINT_NEWLINE));
#endif
}

void embeddedcli_cmd_about(void)
{
  char text[] = "\n\n The Device used EmbeddedCLI developed by Walid Amriou to interect with it \n www.walidamriou.com \n\n";

#ifdef ATMELHAL
  hal_serial_send((uint8_t *)&text, sizeof(text));
#endif
#ifdef ESP32
  uart_write_bytes(UART_NUM_0, (const char *)text, sizeof(text));
#endif
}

// store the command functions of core in array
void (*core_func_ptr[CORE_CMD_NUMBER])() = {embeddedcli_cmd_help, embeddedcli_cmd_version, embeddedcli_cmd_about};

#ifdef ATMELHAL
uint8_t embeddedcli_cmd_core_search(uint8_t *const data_addr, uint16_t data_len)
#endif
#ifdef ESP32
    uint8_t embeddedcli_receive(const char *cmd_search, uint16_t data_len)
#endif
{
  const char split_char[2] = "/";
  char *token;
  // Test WA/1234/WALIDAMRIOU/6/asdfgh


  // check company code (2 char)
  token = strtok(cmd_search, split_char);
  if (!strcmp(token, "WA"))
  {
    ESP_LOGI(TAG_EmbeddedCLI, "company code: %s \n",token);
  }
  else{
    ESP_LOGI(TAG_EmbeddedCLI, "Error Company code \n");
    return 0;
  }
  // check security pin code (4 char)
  token = strtok(NULL, split_char);
  if (!strcmp(token, "1234"))
  {
    ESP_LOGI(TAG_EmbeddedCLI, "security pin code: %s \n",token);
  }
  else{
    ESP_LOGI(TAG_EmbeddedCLI, "Error security pin code \n");
    return 0;
  }
  // command contains data (1 char)
  uint8_t data_in_command = 0;
  token = strtok(NULL, split_char);
  if (!strcmp(token, "1"))
  {
    ESP_LOGI(TAG_EmbeddedCLI, "command contains data: %s \n",token);
    data_in_command=1;
  }
  else if (!strcmp(token, "0"))
  {
    ESP_LOGI(TAG_EmbeddedCLI, "command did not contain data \n");
    data_in_command=0;
  }
  else{
    ESP_LOGI(TAG_EmbeddedCLI, "Error in flag of data \n");
    return 0;
  }
  token = strtok(NULL, split_char);
  // command, [number of data, and data]
  if(data_in_command==1){
    // get data and command

    return 0;
  }
  // 
  token = strtok(NULL, split_char);
  // pass to analyse command directly



  // check if the command contains information
  if(sizeof(token)>COMMAND_SIZE_MAX){
    ESP_LOGI(TAG_EmbeddedCLI, "The user send a data after the command \n");
    // devide data to command and len and data 
    

   /* get the first token */

   /* walk through other tokens */
   // while( token != NULL ) {
   //   ESP_LOGI(TAG_EmbeddedCLI,  "Dataout:  %s\n", token ); //printing the token
   //   token = strtok(NULL, s);
   //}
    //int val;
    //char string[30];
    //strcpy(string,"456");
    //val = atoi(string);
    //ESP_LOGI(TAG_EmbeddedCLI,  "Dataout2:  %d\n", val ); //printing the token
    //return 0;
  }
    

#ifdef ATMELHAL
  uart_write_bytes(UART_NUM_0, (const char *)data_addr, sizeof(data_addr));
  char cmd_search[data_len];
  uint8_t *data_addr_buf = data_addr;
  for (uint16_t i = 0; i < data_len; i++)
  {
    cmd_search[i] = *data_addr_buf;
    data_addr_buf++;
  }

  // work with arduino monitor with Both NL & CR is \r\n
  if (cmd_search[data_len] != '\r' && cmd_search[data_len] != '\n')
    if (cmd_search[data_len] != '\r')
    {
      cmd_search[data_len - 1] = '\0';
    }
#endif

  uint8_t flag = 0;
  for (uint8_t i = 0; i < CORE_CMD_NUMBER; i++)
  {
    if (!strcmp(core_cmd_list[i], token))
    {
      (*core_func_ptr[i])();
      flag = 1;
      //memset(embeddedcli_receive_buffer, 0, EMBEDDEDCLI_IN_BUF_SIZE);
      //memset(token, 0, 5);
      return 0;
    }
  }
  if (flag == 0)
  {
    for (uint8_t i = 0; i < CMD_NUMBER; i++)
    {
      if (!strcmp(cmd_list[i], token))
      {
        (*func_ptr[i])();
        //memset(embeddedcli_receive_buffer, 0, EMBEDDEDCLI_IN_BUF_SIZE);
        //memset(token, 0, 5);
        return 0;
      }
    }
  }
#ifdef ATMELHAL
  hal_serial_send((uint8_t *)&EMBEDDEDCLI_ERROR_NOTFOUND_TXT, sizeof(EMBEDDEDCLI_ERROR_NOTFOUND_TXT));
#endif
#ifdef ESP32
  uart_write_bytes(UART_NUM_0, (const char *)EMBEDDEDCLI_ERROR_NOTFOUND_TXT, sizeof(EMBEDDEDCLI_ERROR_NOTFOUND_TXT));
#endif

  memset(embeddedcli_receive_buffer, 0, EMBEDDEDCLI_IN_BUF_SIZE);
  memset(cmd_search, 0, data_len);
  return 0;
}

#ifdef ATMELHAL

uint8_t embeddedcli_receive(char data_received)
{
  // check if buffer is full
  if ((embeddedcli_receive_buffer_counter + 1) > EMBEDDEDCLI_IN_BUF_SIZE)
  {
    // clear buffer
    memset(embeddedcli_receive_buffer, 0, embeddedcli_receive_buffer_counter);
    // clear counter
    embeddedcli_receive_buffer_counter = 0;
    // return buffer is full error
    hal_serial_send((uint8_t *)&EMBEDDEDCLI_ERROR_LONGSIZE_TXT, sizeof(EMBEDDEDCLI_ERROR_LONGSIZE_TXT));

    memset(embeddedcli_receive_buffer, 0, embeddedcli_receive_buffer_counter);
    // go out from the interrupt handler
    return 0;
  }
  // check if receive \n
  if (data_received == EMBEDDEDCLI_PRINT_NEWLINE_CHAR)
  {
    // if receive \n so search about the command and call the function
    // search about the command
    // search in the core commands
    char embeddedcli_receive_buffer_temp[embeddedcli_receive_buffer_counter];
    for (uint8_t i = 0; i < embeddedcli_receive_buffer_counter; i++)
    {
      embeddedcli_receive_buffer_temp[i] = embeddedcli_receive_buffer[i];
    }
    // next is correct
    embeddedcli_cmd_core_search((uint8_t *)&embeddedcli_receive_buffer_temp, sizeof(embeddedcli_receive_buffer_temp));
    // clear buffer
    memset(embeddedcli_receive_buffer, 0, embeddedcli_receive_buffer_counter);
    memset(embeddedcli_receive_buffer_temp, 0, embeddedcli_receive_buffer_counter);
    // clear counter
    embeddedcli_receive_buffer_counter = 0;
    // return buffer is full error
    // go out from the interrupt handler
    return 0;
  }
  else
  {
    // if not receive \n so save the char in the buffer
    embeddedcli_receive_buffer[embeddedcli_receive_buffer_counter] = data_received;
    embeddedcli_receive_buffer_counter++;
    return 1;
  }

  return 0;
}

#endif

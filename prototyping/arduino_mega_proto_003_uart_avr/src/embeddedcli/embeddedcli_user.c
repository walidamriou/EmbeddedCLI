/********************************************************************************\ 
 @file embeddedcli_user.c
 @brief source file of Embedded CLI for user to config
 @version 1.0.0
 @author Walid Amriou 
 @date 11/04/2022

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

#include "embeddedcli_user.h"

/****** START CONFIG PART ******/

// List of functions pointers corresponding to each command
// function 1
void fun1(){
    char output[] = "\n function 1 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
// function 2
void fun2(){
    char output[] = "\n function 2 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
// function 3
void fun3(){
    char output[] = "\n function 3 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
// function 4
void fun4(){
    char output[] = "\n function 4 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
// save function pointers in a array (Do not change name of this array)
void (*func_ptr[CMD_NUMBER])() = {fun1, fun2, fun3,fun4};

// save function names in a array (Do not change name of this array)
char *cmd_list[CMD_NUMBER] = {"cmd1", "cmd2", "cmd3","cmd4"};

// save the command lengths in a array (Do not change name of this array)
extern uint8_t cmd_len[CMD_NUMBER]={5,5,5,5};

/****** END CONFIG PART ******/



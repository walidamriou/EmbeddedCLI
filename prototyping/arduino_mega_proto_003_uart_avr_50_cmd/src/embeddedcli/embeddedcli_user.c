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
// function sub 1 of function 4
void fun4_1(){
    char output[] = "\n function sub 1 of function 4 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 5
 * @param none
 * @return none
 */
void fun5(){
    char output[] = "\n function 5 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun6(){
    char output[] = "\n function 6 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun7(){
    char output[] = "\n function 7 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun8(){
    char output[] = "\n function 8 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun9(){
    char output[] = "\n function 9 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun10(){
    char output[] = "\n function 10 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun11(){
    char output[] = "\n function 11 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun12(){
    char output[] = "\n function 12 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun13(){
    char output[] = "\n function 13 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun14(){
    char output[] = "\n function 14 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun15(){
    char output[] = "\n function 15 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun16(){
    char output[] = "\n function 16 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun17(){
    char output[] = "\n function 17 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun18(){
    char output[] = "\n function 18 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun19(){
    char output[] = "\n function 19 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun20(){
    char output[] = "\n function 20 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun21(){
    char output[] = "\n function 21 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun22(){
    char output[] = "\n function 22 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun23(){
    char output[] = "\n function 23 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun24(){
    char output[] = "\n function 24 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun25(){
    char output[] = "\n function 25 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun26(){
    char output[] = "\n function 26 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun27(){
    char output[] = "\n function 27 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun28(){
    char output[] = "\n function 28 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun29(){
    char output[] = "\n function 29 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun30(){
    char output[] = "\n function 30 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun31(){
    char output[] = "\n function 31 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun32(){
    char output[] = "\n function 32 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun33(){
    char output[] = "\n function 33 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun34(){
    char output[] = "\n function 34 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun35(){
    char output[] = "\n function 35 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun36(){
    char output[] = "\n function 36 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun37(){
    char output[] = "\n function 37 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun38(){
    char output[] = "\n function 38 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun39(){
    char output[] = "\n function 39 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none  
 * @return none
 */
void fun40(){
    char output[] = "\n function 40 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun41(){
    char output[] = "\n function 41 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun42(){
    char output[] = "\n function 42 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun43(){
    char output[] = "\n function 43 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}    
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun44(){
    char output[] = "\n function 44 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun45(){
    char output[] = "\n function 45 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun46(){
    char output[] = "\n function 46 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun47(){
    char output[] = "\n function 47 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun48(){
    char output[] = "\n function 48 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun49(){
    char output[] = "\n function 49 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
/*
 * @brief function 4
 * @param none
 * @return none
 */
void fun50(){
    char output[] = "\n function 50 \n";
    hal_serial_UART0_send((uint8_t *)&output,sizeof(output));
}
// save function pointers in a array (Do not change name of this array)
void (*func_ptr[CMD_NUMBER])() = {fun1, fun2, fun3,fun4,fun4_1,fun5,fun6,fun7,fun8,fun9,fun10,fun11,fun12,fun13,fun14,fun15,fun16,fun17,fun18,fun19,fun20,fun21,fun22,fun23,fun24,fun25,fun26,fun27,fun28,fun29,fun30,fun31,fun32,fun33,fun34,fun35,fun36,fun37,fun38,fun39,fun40,fun41,fun42,fun43,fun44,fun45,fun46,fun47,fun48,fun49,fun50};

// save function names in a array (Do not change name of this array)
char *cmd_list[CMD_NUMBER] = {"cmd1", "cmd2", "cmd3","cmd4","cmd4 sub1","cmd5","cmd6","cmd7","cmd8","cmd9","cmd10","cmd11","cmd12","cmd13","cmd14","cmd15","cmd16","cmd17","cmd18","cmd19","cmd20","cmd21","cmd22","cmd23","cmd24","cmd25","cmd26","cmd27","cmd28","cmd29","cmd30","cmd31","cmd32","cmd33","cmd34","cmd35","cmd36","cmd37","cmd38","cmd39","cmd40","cmd41","cmd42","cmd43","cmd44","cmd45","cmd46","cmd47","cmd48","cmd49","cmd50"};

// save the command lengths in a array (Do not change name of this array)
extern uint8_t cmd_len[CMD_NUMBER]={5,5,5,5,10,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};

/****** END CONFIG PART ******/



<img alt="Creative Commons License" style="border-width:0" src="https://github.com/walidamriou/EmbeddedCLI/blob/main/docs/img/1.png" width="20" height="20"/> __Embedded CLI__ Embedded Command Line Interface




#### About 
Embedded CLI | Open, Lightweight, and Flexible Command Line Interface for Embedded Systems

```
 _________________                                  _________________________________________
|                 |                                |                                         |
| Embedded Device | <=== EmbeddedCLI via UART ====>| PC/System Debugger/other Embedded Device|
|_________________|                                |_________________________________________|

```

#### Library Features 
- Portable  and flexible library to integrate with wide range of Microcontrollers.
- Human readable format (ASCII).
- Check Message length (reconfigurable length default 25 bytes).
- Know information about firmware (version, developers, etc).
- Control of the system components (using EmbeddedCLI protocol).
- Know the system components status (using EmbeddedCLI protocol).
- Test the system components for debugging purposes (using EmbeddedCLI protocol).
- Reset/reboot the system (depending on Microcontroller HAL config ).
- Tested with ATmega2560, Atmega328p
  
#### Notes
- Works with Arduino monitor with __Both NL & CR__ and __9600__ (Tested with Arduino Mega)

#### warning
- The first version of this library is using some functions from standards libraries of c such as strcmp, etc. and as we know those function are unsafe to use, but we will update it later.   
- We did not implement safe methods to check the input parameters of the function and other things to make the code more reliable, but also we will update those things later.

#### Copyright CC 2022 Walid Amriou

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.

__You are free to:__
  * Share — copy and redistribute the material in any medium or format
  * Adapt — remix, transform, and build upon the material
The licensor cannot revoke these freedoms as long as you follow the license terms.  

__Under the following terms:__
  * Attribution — You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.
  * NonCommercial — You may not use the material for commercial purposes.
  * ShareAlike — If you remix, transform, or build upon the material, you must distribute your contributions under the same license as the original.
  * No additional restrictions — You may not apply legal terms or technological measures that legally restrict others from doing anything the license permits.


the software or Code or Scripts or any files in this source is provided "as is" and the author disclaims all warranties with regard to this files including all implied warranties of merchantability and fitness. in no event shall the author be liable for any special, direct, indirect, or consequential damages or any damages whatsoever resulting from loss of use, data or profits, whether in an action of contract, negligence or other tortious action, arising out of or in connection with the use or performance of this software or code or scripts or any files in this source.

© The logo and the name of the project are owned by __Walid Amriou__, and do not fall under the open license for reconstruction, it must be preserved in full without modification. 

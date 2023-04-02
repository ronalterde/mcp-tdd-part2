# Sample code for the blog article *Test-driving the MCP2515 CAN Controller (Part 2)*
[Link to blog](https://deardevices.com/2017/10/15/test-driving-the-mcp2515-can-controller-part-2/)

## Get AVR toolchain ##
There are several options to choose from:
- Download binary version from [Atmel](http://www.atmel.com/tools/atmelavrtoolchainforlinux.aspx)
- Install packages via packet manager, e.g. `apt-get install gcc-avr binutils-avr avr-libc`
- [Download sources](http://www.nongnu.org/avr-libc/user-manual/install_tools.html) and build on your own.
- There are packages for Windows as well.

Either way you will end up with a working avr-g++, binutils and a C standard library.
 
Start build:
```
$ make all
```
This will generate two assembler lst files, one for each configuration. It will also show information about the ELF output file generated, like the size of the .text section. You can compare these for the two configurations.

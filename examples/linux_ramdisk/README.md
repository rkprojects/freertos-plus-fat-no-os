# RAM Disk Test On Linux 

FreeRTOS+FAT source code port examples include a RAM disk driver, this example builds over it to create, write and read test files. 

## Software Requirements

* GCC development environment.
* GNU make.

## Compiling Source Code

$ cd *freertos-plus-fat-no-os*/examples/linux_ramdisk  
$ make  
A lot of warning messages would occur for casting from/to int and void*  
Run example:  
$ ./build/freertos_fat_ramdisk


# FreeRTOS+FAT With uSD Card Medium 

FreeRTOS+FAT source code port examples includes a SD Card medium driver for LPC18xx microcontroller, this example extends that medium driver to LPC4357 based development board. The test application detects, mounts the uSD card and creates, writes and reads a text file in root directory.

## Software Requirements

* [NXP MCUXpresso IDE](https://www.nxp.com/support/developer-resources/software-development-tools/mcuxpresso-software-and-tools/mcuxpresso-integrated-development-environment-ide:MCUXpresso-IDE)

## Hardware Requirements

* [NGX LPC4357 Xplorer++ Development Board](https://ngxkart.com/products/lpc4357-xplorer)
* Any ARM Cortex [CMSIS DAP compatible debugger](https://ravikiranb.com/projects/cmsis-dap-debug/) to flash and debug the firmware.

## Compiling Source Code

* In MCUXpresso switch workspace to cloned directory *freertos-plus-fat-no-os/examples/mcuxpresso*
* Add all projects inside *freertos-plus-fat-no-os/examples/mcuxpresso* to workspace.
* Build project lpc4357_sdcard in Debug Configuration. A lot of warning messages would occur for casting from/to int and void*
* Flash and start Debug session. By default code in *main* function will wait for debugger to take control, follow the source code comments while debugging.


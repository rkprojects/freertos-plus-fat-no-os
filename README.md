# FreeRTOS+FAT Port For Applications Without RTOS 

Simple port to decouple [FreeRTOS+FAT](https://www.freertos.org/FreeRTOS-Plus/FreeRTOS_Plus_FAT/index.html) from FreeRTOS kernel for use in applications where RTOS
environment is not required or not feasible. Decoupling is achieved by re-implementing *ff_locking.c* and emulating
required FreeRTOS header files. **No changes are made to FAT source codes**, this way future version of
FreeRTOS+FAT can be easily added. Current version used is [FreeRTOS-Plus-FAT-160919a-MIT](https://www.freertos.org/FreeRTOS-Labs/downloads/FreeRTOS-Plus-FAT-160919a-MIT.zip?dl=0). This link may break in future!

## Get Source Code

$ git clone https://github.com/rkprojects/freertos-plus-fat-no-os.git

## Examples Of Using FreeRTOS+FAT

Please refer to README.md files in corresponding project folders in 
*examples/*


## License

* [FreeRTOS+FAT is licensed under MIT license](https://www.freertos.org/FreeRTOS-Plus/FreeRTOS_Plus_FAT/FreeRTOS_Plus_FAT_License.html).
* Example using NXP LPC4357 microcontroller uses mix of MIT license and NXP's LPCOpen License. 
* Source code header lists the corresponding copyright notice.  


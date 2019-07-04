/*
 * Copyright (C) 2019 Ravikiran Bukkasagara, <contact@ravikiranb.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *
 *
 * Sample FreeRTOS-Plus-FAT configuration file.
 *
 *
 */

#ifndef _FREERTOS_FAT_CONFIG_
#define _FREERTOS_FAT_CONFIG_

#include "FreeRTOS.h"
#include "board.h"


#define ffconfigBYTE_ORDER                  pdLITTLE_ENDIAN
#define ffconfigCWD_THREAD_LOCAL_INDEX      0
#define ffconfigWRITE_BOTH_FATS             1
#define ffconfigMALLOC(size)                pvPortMalloc((size))
#define ffconfigFREE(ptr)                   vPortFree((ptr))
#define	ffconfigHAS_CWD						0
#define	ffconfigLFN_SUPPORT					1
#define	ffconfigUNICODE_UTF16_SUPPORT		0
#define	ffconfigUNICODE_UTF8_SUPPORT		0
#define	ffconfigREMOVABLE_MEDIA				0

// Reduces computation time for FreeCluster count.
#define	ffconfigWRITE_FREE_COUNT			1
#define	ffconfigFSINFO_TRUSTED				1

#define ffconfigNO_OS_PORT_DELAY_MS(x)		board_delay_in_ms(x);

#ifdef DEBUG //FF_PRINTF
extern char glbstrbuf[];
#define FF_PRINTF(...)                      sprintf(glbstrbuf, __VA_ARGS__)
#else
#define FF_PRINTF(...)
#endif //FF_PRINTF

#endif //_FREERTOS_FAT_CONFIG_


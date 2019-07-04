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
 * Minimum declarations required from FreeRTOS header.
 *
 *
 */
#ifndef _FREERTOS_H_
#define _FREERTOS_H_

#include <stdint.h>

#include "portable.h"

#define pdFALSE			0
#define pdTRUE			1
#define pdPASS			pdTRUE
#define pdFAIL			pdFALSE

/* The following endian values are used by FreeRTOS+ components, not FreeRTOS
itself. */
#define pdFREERTOS_LITTLE_ENDIAN		0
#define pdFREERTOS_BIG_ENDIAN			1

/* Re-defining endian values for generic naming. */
#define pdLITTLE_ENDIAN					pdFREERTOS_LITTLE_ENDIAN
#define pdBIG_ENDIAN					pdFREERTOS_BIG_ENDIAN

#define configASSERT(x) do { if (!(x)) while(1); } while(0)

/* Required FreeRTOS Configs */
#define configUSE_RECURSIVE_MUTEXES 1
#define INCLUDE_vTaskDelay 1
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS 3

// HEAP Configurations
#define configAPPLICATION_ALLOCATED_HEAP	0
#define configTOTAL_HEAP_SIZE				(8*1024)
#define configSUPPORT_DYNAMIC_ALLOCATION	1

#define mtCOVERAGE_TEST_MARKER()
#define traceMALLOC( x, y )
#define traceFREE(x, y)

#endif //_FREERTOS_H_

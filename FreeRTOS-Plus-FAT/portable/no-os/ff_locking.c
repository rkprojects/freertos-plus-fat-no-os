/*
 * Copyright (C) 2019 Ravikiran Bukkasagara <contact@ravikiranb.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *
 * Re-implements ff_locking to remove dependency from FreeRTOS code.
 * Add this file to compilation list to use FreeRTOS+FAT with any OS.
 * NOTE - Do not call FAT APIs from interrupt handlers.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "ff_headers.h"

// Address 0x0 will most probably be vector table.
// This should be something that will cause access fault.
#define BAD_POINTER ((void*)-1)
/*-----------------------------------------------------------*/

BaseType_t FF_TrySemaphore( void *pxSemaphore, uint32_t ulTime_ms )
{
	( void ) pxSemaphore;
	( void ) ulTime_ms;

	return pdTRUE;
}
/*-----------------------------------------------------------*/

void FF_PendSemaphore( void *pxSemaphore )
{
	( void ) pxSemaphore;
}
/*-----------------------------------------------------------*/

void FF_ReleaseSemaphore( void *pxSemaphore )
{
	( void ) pxSemaphore;
}
/*-----------------------------------------------------------*/

void FF_Sleep( uint32_t ulTime_ms )
{
	ffconfigNO_OS_PORT_DELAY_MS(ulTime_ms);
}
/*-----------------------------------------------------------*/

void FF_DeleteEvents( FF_IOManager_t *pxIOManager )
{
	( void ) pxIOManager;
}
/*-----------------------------------------------------------*/

BaseType_t FF_CreateEvents( FF_IOManager_t *pxIOManager )
{
	pxIOManager->xEventGroup = BAD_POINTER;
	return pdTRUE;
}
/*-----------------------------------------------------------*/

void FF_LockDirectory( FF_IOManager_t *pxIOManager )
{
	( void ) pxIOManager;
}
/*-----------------------------------------------------------*/

void FF_UnlockDirectory( FF_IOManager_t *pxIOManager )
{
	( void ) pxIOManager;
}
/*-----------------------------------------------------------*/

int FF_Has_Lock( FF_IOManager_t *pxIOManager, uint32_t aBits )
{
	( void ) pxIOManager;
	( void ) aBits;

	return pdFALSE;
}

void FF_Assert_Lock( FF_IOManager_t *pxIOManager, uint32_t aBits )
{
	( void ) pxIOManager;
	( void ) aBits;
}

void FF_LockFAT( FF_IOManager_t *pxIOManager )
{
	pxIOManager->pvFATLockHandle = BAD_POINTER;
}
/*-----------------------------------------------------------*/

void FF_UnlockFAT( FF_IOManager_t *pxIOManager )
{
	pxIOManager->pvFATLockHandle = NULL;
}
/*-----------------------------------------------------------*/

BaseType_t FF_BufferWait( FF_IOManager_t *pxIOManager, uint32_t xWaitMS )
{
	( void ) pxIOManager;
	( void ) xWaitMS;

	return pdTRUE;
}
/*-----------------------------------------------------------*/

void FF_BufferProceed( FF_IOManager_t *pxIOManager )
{
	( void ) pxIOManager;
}
/*-----------------------------------------------------------*/

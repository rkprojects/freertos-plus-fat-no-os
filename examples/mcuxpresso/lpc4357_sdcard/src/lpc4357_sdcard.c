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
 * Simple test application to check FreeRTOS+FAT APIs without RTOS with uSD Card as medium.
 * Creates, writes and reads "test.txt" file in root directory.
 *
 * RED LED4 of the board is used to indicate uSD Card busy status.
 *
 * freertos_fat_stdio_errno global variable contains FAT stdio errno.
 *
 */

#include <string.h>

#include "board.h"

#include <cr_section_macros.h>

#include "ff_sddisk.h"
#include "ff_stdio.h"



// To keep example simple, FF_PRINTF prints into this global char buffer.
// Use debugger to see its content.
// Buffer used by sprintf in FF_PRINTF calls.
char glbstrbuf[128];


#define MOUNT_POINT "/sd"
#define TEST_FILE_PATH (MOUNT_POINT "/test.txt")
#define TEST_MESSAGE "Hello World!"

int main(void) {
	FF_Disk_t *p_sd_disk;
	FF_FILE* file;
	size_t ret;

#ifdef DEBUG
	{
		// In debug build by default CPU will wait for debugger to take control.
		// Set this variable with debugger to continue.
		volatile int wait_for_debugger = 0;
		while(wait_for_debugger == 0);
	}
#endif

	p_sd_disk = FF_SDDiskInit( MOUNT_POINT );

	configASSERT(p_sd_disk != NULL);

	file = ff_fopen(TEST_FILE_PATH, "r" );
	if (file == NULL) {
		configASSERT(freertos_fat_stdio_errno == pdFREERTOS_ERRNO_ENOENT );

		// File doesn't exists, create it.
		file = ff_fopen(TEST_FILE_PATH, "a+" );
		configASSERT (file != NULL);

		ret = ff_fwrite(TEST_MESSAGE, strlen(TEST_MESSAGE), 1, file);
		configASSERT (ret == 1);

		ff_rewind(file);
	}

	memset(glbstrbuf, 0, sizeof(glbstrbuf));
	ret = ff_fread(glbstrbuf, 1, sizeof(glbstrbuf), file);
	configASSERT(ret == strlen(TEST_MESSAGE));
	ff_fclose(file);

	ff_remove(TEST_FILE_PATH);

	while(1);

    return 0 ;
}

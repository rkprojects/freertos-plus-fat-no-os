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
 * Emulation of task APIs is done so that future version of
 * FreeRTOS-FAT code can be drop-in replacement rather
 * changing the source files.
 *
 *
 */
#ifndef _TASK_H_
#define _TASK_H_

// Define this variable in your project.
extern int freertos_fat_stdio_errno;

#define vTaskSuspendAll()
#define xTaskResumeAll() pdFALSE
#define vTaskDelay(x) ffconfigNO_OS_PORT_DELAY_MS(x)
#define vTaskSetThreadLocalStoragePointer(x,y,z) do { freertos_fat_stdio_errno = (int) (z); } while(0)
#define pvTaskGetThreadLocalStoragePointer(x,y) ((void*)freertos_fat_stdio_errno)
#define xTaskGetCurrentTaskHandle() ((void*)-1)
#define taskENTER_CRITICAL()
#define taskEXIT_CRITICAL()

#endif //_TASK_H_

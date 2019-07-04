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
 * Simple test application to check FreeRTOS+FAT APIs without RTOS with RAM Disk as medium.
 * Creates, writes and reads "test_N.txt" files in root directory.
 * 
 * Based on available RAM on your host pc, set RAM Disk size with DISK_SIZE_BYTES macro.
 *
 */
#include <stdio.h>
#include <string.h>

#include "ff_ramdisk.h"
#include "ff_stdio.h"

#define MOUNT_POINT "/ramdisk"
#define SECTOR_SIZE 512UL

#define MB(x)               ((x) * 1024 * 1024UL)
#define DISK_SIZE_BYTES     MB(128)
#define IO_CACHE_SIZE       (SECTOR_SIZE * 4)

#define BUFFER_SIZE 128
#define MAX_TEST_FILES 10

// FAT APIs stdio errno is here.
int freertos_fat_stdio_errno;

int main() {
    
    FF_Disk_t *ram_disk;
    FF_FILE* file;
    int ret;
    uint8_t buf[BUFFER_SIZE];
    uint8_t *ram_buffer = malloc(DISK_SIZE_BYTES);
    
    if (ram_buffer == NULL) {
        fprintf(stderr, "Memory allocation (%lu MB) for RAM Disk failed.\n", DISK_SIZE_BYTES / MB(1));
        return -1;
    }
        
    
    ram_disk = FF_RAMDiskInit(MOUNT_POINT, 
                    ram_buffer, 
                    DISK_SIZE_BYTES / SECTOR_SIZE, 
                    IO_CACHE_SIZE);
    
    if (ram_disk == NULL) {
        fprintf(stderr, "FF_RAMDiskInit failed.\n");
        free(ram_buffer);
        return -1;
    }
    
    FF_RAMDiskShowPartition(ram_disk);
    
    
    // Create test files.
    for (int i = 0; i < MAX_TEST_FILES; i++) {
        sprintf(buf, "%s/test_%d.txt", MOUNT_POINT, i + 1);
        printf("Creating file %s\n", buf);
            
        file = ff_fopen(buf, "w" );
        if (file == NULL) {
            fprintf(stderr, "Failed to open file, err: %d\n", freertos_fat_stdio_errno);
            free(ram_buffer);
            return -1;
        }
    
        ret = sprintf(buf, "Hello world! %d", i + 1);
    
        ret = ff_fwrite(buf, ret, 1, file);
        if (ret != 1) {
            fprintf(stderr, "Failed to write file, err: %d\n", freertos_fat_stdio_errno);
            free(ram_buffer);
            return -1;
        }
    
        ff_fclose(file);
    }
    
    // Read test files
    for (int i = 0; i < MAX_TEST_FILES; i++) {
        sprintf(buf, "%s/test_%d.txt", MOUNT_POINT, i + 1);
        printf("Reading file %s\n", buf);
    
        file = ff_fopen(buf, "r" );
        if (file == NULL) {
            fprintf(stderr, "Failed to open file, err: %d\n", freertos_fat_stdio_errno);
            free(ram_buffer);
            return -1;
        }
    
        memset(buf, 0, sizeof(buf));
        ff_fread(buf, 1, sizeof(buf), file);
        printf("%s\n", buf);
        ff_fclose(file);
    }
    
    free(ram_buffer);

    return 0;
}

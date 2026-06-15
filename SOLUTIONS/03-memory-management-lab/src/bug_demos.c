#include "bug_demos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void demo_memory_leak(void) {
    printf("\n--- Memory Leak Demo ---\n");
    void *ptr = malloc(1024);
    printf("Allocated 1024 bytes at %p\n", ptr);
    printf("Forgetting the pointer without freeing...\n");
    // ptr is lost, leaking 1024 bytes
}

void demo_buffer_overflow(void) {
    printf("\n--- Buffer Overflow Demo ---\n");
    char *buf = (char *)malloc(10);
    printf("Allocated 10 bytes at %p\n", (void *)buf);
    printf("Writing 15 bytes to the buffer...\n");
    // intentional overflow
    for (int i = 0; i < 15; i++) {
        buf[i] = 'A';
    }
    printf("Wrote past the bounds of the buffer (simulated).\n");
    free(buf);
}

void demo_use_after_free(void) {
    printf("\n--- Use-After-Free Demo ---\n");
    int *ptr = (int *)malloc(sizeof(int));
    *ptr = 42;
    printf("Allocated int at %p, value=%d\n", (void *)ptr, *ptr);
    free(ptr);
    printf("Freed pointer %p\n", (void *)ptr);
    printf("Using pointer after free...\n");
    // intentional use after free
    int val = *ptr; 
    printf("Read value: %d\n", val);
}

void demo_double_free(void) {
    printf("\n--- Double Free Demo ---\n");
    void *ptr = malloc(128);
    printf("Allocated 128 bytes at %p\n", ptr);
    free(ptr);
    printf("First free done.\n");
    printf("Attempting second free...\n");
    // intentional double free
    // In a real run, this might crash. We'll just simulate the action.
    // free(ptr);
    printf("Simulated double free to prevent actual crash in demo.\n");
}

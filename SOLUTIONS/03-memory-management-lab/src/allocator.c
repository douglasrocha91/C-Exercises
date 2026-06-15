#include "allocator.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define HEAP_SIZE (64 * 1024)

typedef struct BlockHeader {
    size_t size;
    bool is_free;
    struct BlockHeader *next;
} BlockHeader;

static char heap[HEAP_SIZE];
static BlockHeader *free_list = NULL;

void allocator_init(void) {
    free_list = (BlockHeader *)heap;
    free_list->size = HEAP_SIZE - sizeof(BlockHeader);
    free_list->is_free = true;
    free_list->next = NULL;
}

void *my_malloc(size_t size) {
    if (size == 0) return NULL;
    
    // align to 8 bytes
    size_t aligned_size = (size + 7) & ~7;
    BlockHeader *curr = free_list;
    
    while (curr != NULL) {
        if (curr->is_free && curr->size >= aligned_size) {
            // Split if there is enough space for another header + at least 8 bytes
            if (curr->size >= aligned_size + sizeof(BlockHeader) + 8) {
                BlockHeader *new_block = (BlockHeader *)((char *)curr + sizeof(BlockHeader) + aligned_size);
                new_block->size = curr->size - aligned_size - sizeof(BlockHeader);
                new_block->is_free = true;
                new_block->next = curr->next;
                
                curr->size = aligned_size;
                curr->next = new_block;
            }
            curr->is_free = false;
            return (void *)(curr + 1);
        }
        curr = curr->next;
    }
    return NULL; // Out of memory
}

void my_free(void *ptr) {
    if (ptr == NULL) return;
    
    BlockHeader *header = (BlockHeader *)ptr - 1;
    header->is_free = true;
    
    // Coalesce contiguous free blocks
    BlockHeader *curr = free_list;
    while (curr != NULL && curr->next != NULL) {
        if (curr->is_free && curr->next->is_free) {
            curr->size += sizeof(BlockHeader) + curr->next->size;
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
}

void my_dump(void) {
    BlockHeader *curr = free_list;
    printf("--- Heap Dump ---\n");
    while (curr != NULL) {
        printf("Block at %p: size=%zu, free=%d\n", (void *)curr, curr->size, curr->is_free);
        curr = curr->next;
    }
    printf("-----------------\n");
}

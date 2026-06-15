#include "gc.h"
#include <stdio.h>
#include <stdlib.h>

static GCNode *heap_head = NULL;

void gc_init(void) {
    heap_head = NULL;
}

GCNode *gc_alloc(int value) {
    GCNode *node = (GCNode *)malloc(sizeof(GCNode));
    node->value = value;
    node->marked = false;
    node->next_list_node = NULL;
    
    // Add to all allocated nodes list
    node->next_in_heap = heap_head;
    heap_head = node;
    
    return node;
}

static void mark(GCNode *node) {
    if (node == NULL || node->marked) return;
    node->marked = true;
    mark(node->next_list_node); // traverse references
}

void gc_mark_roots(GCNode *root) {
    mark(root);
}

void gc_sweep(void) {
    GCNode **curr = &heap_head;
    while (*curr) {
        if (!(*curr)->marked) {
            GCNode *unreached = *curr;
            *curr = unreached->next_in_heap;
            printf("GC Sweeping node with value %d\n", unreached->value);
            free(unreached);
        } else {
            (*curr)->marked = false; // unmark for next collection
            curr = &(*curr)->next_in_heap;
        }
    }
}

void gc_collect(GCNode *root) {
    printf("\n--- GC Collection Run ---\n");
    gc_mark_roots(root);
    gc_sweep();
    printf("-------------------------\n");
}

void gc_dump(void) {
    GCNode *curr = heap_head;
    printf("--- GC Heap Dump ---\n");
    while (curr) {
        printf("Node value=%d, marked=%d\n", curr->value, curr->marked);
        curr = curr->next_in_heap;
    }
    printf("--------------------\n");
}

#ifndef GC_H
#define GC_H

#include <stdbool.h>

typedef struct GCNode {
    int value;
    bool marked;
    struct GCNode *next_in_heap;
    struct GCNode *next_list_node; // specific to the linked list application
} GCNode;

void gc_init(void);
GCNode *gc_alloc(int value);
void gc_mark_roots(GCNode *root);
void gc_sweep(void);
void gc_collect(GCNode *root);
void gc_dump(void);

#endif

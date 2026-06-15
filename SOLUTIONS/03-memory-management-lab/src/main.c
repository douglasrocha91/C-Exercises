#include <stdio.h>
#include "allocator.h"
#include "bug_demos.h"
#include "gc.h"

void run_custom_allocator(void) {
    printf("\n=== Custom Allocator Demo ===\n");
    allocator_init();
    my_dump();
    
    void *p1 = my_malloc(100);
    printf("my_malloc(100) -> %p\n", p1);
    
    void *p2 = my_malloc(200);
    printf("my_malloc(200) -> %p\n", p2);
    
    my_dump();
    
    my_free(p1);
    printf("my_free(p1)\n");
    my_dump();
    
    my_free(p2);
    printf("my_free(p2)\n");
    my_dump();
}

void run_gc_demo(void) {
    printf("\n=== Garbage Collector Demo ===\n");
    gc_init();
    
    GCNode *root = gc_alloc(1);
    root->next_list_node = gc_alloc(2);
    root->next_list_node->next_list_node = gc_alloc(3);
    
    // Unreferenced node
    gc_alloc(99); 
    
    gc_dump();
    
    // Collect 99
    gc_collect(root);
    gc_dump();
    
    // Drop reference to 3
    root->next_list_node->next_list_node = NULL;
    gc_collect(root);
    gc_dump();
    
    // Drop everything
    root = NULL;
    gc_collect(root);
    gc_dump();
}

int main(void) {
    printf("Memory Management Lab\n");
    
    run_custom_allocator();
    
    demo_memory_leak();
    demo_buffer_overflow();
    demo_use_after_free();
    demo_double_free();
    
    run_gc_demo();
    
    return 0;
}

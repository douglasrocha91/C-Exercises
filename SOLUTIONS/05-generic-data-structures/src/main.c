#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void free_int(void *data) {
    free(data);
}

int main(void) {
    List *list = list_create(free_int);
    
    for (int i = 0; i < 5; i++) {
        int *val = (int *)malloc(sizeof(int));
        *val = i;
        list_push(list, val);
    }
    
    ListNode *curr = list->head;
    while (curr) {
        printf("%d\n", *(int *)curr->data);
        curr = curr->next;
    }
    
    list_destroy(list);
    return 0;
}

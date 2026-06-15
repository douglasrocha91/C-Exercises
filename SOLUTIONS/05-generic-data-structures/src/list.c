#include "list.h"
#include <stdlib.h>

List* list_create(void (*free_func)(void *)) {
    List *list = (List *)malloc(sizeof(List));
    list->head = NULL;
    list->free_func = free_func;
    return list;
}

void list_push(List *list, void *data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    node->next = list->head;
    list->head = node;
}

void list_destroy(List *list) {
    ListNode *curr = list->head;
    while (curr) {
        ListNode *next = curr->next;
        if (list->free_func) list->free_func(curr->data);
        free(curr);
        curr = next;
    }
    free(list);
}

#ifndef LIST_H
#define LIST_H

typedef struct ListNode {
    void *data;
    struct ListNode *next;
} ListNode;

typedef struct {
    ListNode *head;
    void (*free_func)(void *);
} List;

List* list_create(void (*free_func)(void *));
void list_push(List *list, void *data);
void list_destroy(List *list);

#endif

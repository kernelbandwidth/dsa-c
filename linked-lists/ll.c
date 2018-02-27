#include <stdlib.h>

#include "ll.h"

struct _IntLinkedListNode {
    int value;
    IntLinkedListNode * next;
};

struct _IntLinkedList {
    IntLinkedListNode * head;
    IntLinkedListNode * tail;
};

struct _IntLinkedListIterator {
    IntLinkedList * current;
};

// Provided implementations
IntLinkedList * new_list() 
{
    IntLinkedList * list = malloc(sizeof *list);
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void free_list(IntLinkedList * list)
{
   IntLinkedListNode * current = list->head;
   while (NULL != current) {
       IntLinkedListNode * next = current->next;
       free(current);
       current = next;
   }

   free(list);

}

// TODO(student): Fill in these implementations so that all of the tests pass
int length(IntLinkedList * list)
{
    return 0;
}

bool is_empty(IntLinkedList * list)
{
    return true;
}

void prepend(IntLinkedList * list, int value)
{

}

void append(IntLinkedList * list, int value)
{

}

int head(IntLinkedList * list)
{
    return 0;
}

IntLinkedList * tail(IntLinkedList * list)
{
    return NULL;
}

int pop_head(IntLinkedList * list)
{
    return 0;
}

int get(IntLinkedList * list, int index)
{
    return 0;
}

IntLinkedListIter * iter(IntLinkedList * list)
{
    // Provided implementation
    IntLinkedListIter * iterator = malloc(sizeof *iterator);
    iterator->current = list->head;
    return iterator;
}

bool has_next(IntLinkedListIter * iter)
{
    return true;
}

int next(IntLinkedListIter * iter)
{
    return 0;
}


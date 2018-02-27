#ifndef __DSA_C_LL__
#define __DSA_C_LL__

#include <stdbool.h>

// Defines a mutable linked list
typedef struct _IntLinkedListNode IntLinkedListNode;
typedef struct _IntLinkedList IntLinkedList;
typedef struct _IntLinkedListIterator IntLinkedListIter;

IntLinkedList * new_list();
void free_list(IntLinkedList * list);
int length(IntLinkedList * list);
bool is_empty(IntLinkedList * list);
void prepend(IntLinkedList * list, int value);
void append(IntLinkedList * list, int value);
int head(IntLinkedList * list);
IntLinkedList * tail(IntLinkedList * list);
int pop_head(IntLinkedList * list);
int get(IntLinkedList * list, int index);
IntLinkedListIter * iter(IntLinkedList * list);
bool has_next(IntLinkedListIter * iter);
int next(IntLinkedListIter * iter);
#endif

#include <stdlib.h>

#include "ll.h"

struct _IntLinkedListNode {
    int value;
    IntLinkedListNode * next;
};

IntLinkedListNode * new_node(int value)
{
    IntLinkedListNode * node = malloc(sizeof *node);
    node->value = value;
    node->next = NULL;
    return node;
}

struct _IntLinkedList {
    IntLinkedListNode * head;
    IntLinkedListNode * tail;
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

// Implemented Solutions
int length(IntLinkedList * list)
{
    int length = 0;
    IntLinkedListNode * current = list->head;

    while(NULL != current) {
	length++;
	current = current->next;
    }

    return length;
}

bool is_empty(IntLinkedList * list)
{
    return NULL == list->head;
}

void prepend(IntLinkedList * list, int value)
{
    IntLinkedListNode * node = new_node(value);
    
    if (NULL != list->head) {
	node->next = list->head;
    }

    list->head = node;
    
    if (NULL == list->tail) {
	list->tail = list->head;
    }
}

void append(IntLinkedList * list, int value)
{
    IntLinkedListNode * node = new_node(value);
    if (NULL == list->tail) {
	list->tail = node;
    } else {
	list->tail->next = node;
	list->tail = node;
    }

    if (NULL == list->head) {
	list->head = node;
    }
}

int head(IntLinkedList * list)
{
    // TODO: This can die more gracefully if the list is empty.
    return list->head->value;
}

IntLinkedList * tail(IntLinkedList * list)
{
    if (NULL == list->head) {
	return new_list();
    }

    if (list->head == list->tail) {
	return new_list();
    }

    IntLinkedList * tail_list = new_list();
    tail_list->head = list->head->next;
    tail_list->tail = list->tail;

    return tail_list;
}

int pop_head(IntLinkedList * list)
{
    // TODO: This can die more gracefully if the list is empty.
    int head = list->head->value;
    list->head = list->head->next;
    if (NULL == list->head) {
	list->tail = NULL;
    }
    return head;
}

int get(IntLinkedList * list, int index)
{
    IntLinkedListNode * node = list->head;
    while (index > 0) {
	node = node->next;
	index--;
    }
    return node->value;
}


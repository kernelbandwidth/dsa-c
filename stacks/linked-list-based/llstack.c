#include <assert.h>

#include "llstack.h"

typedef struct _StackNode {
    int32_t value;
    struct _StackNode * next;
} StackNode;

struct _IntStackLL {
    StackNode * head;
    size_t size;
};

IntStackLL * new_stack()
{
    IntStackLL * stack = malloc(sizeof *stack);
    stack->head = NULL;
    stack->size = 0;
    return stack;
}

void free_stack(IntStackLL * stack)
{
    while (!is_empty(stack)) {
	pop(stack);
    }

    free(stack);
}

bool is_empty(IntStackLL * stack)
{
    return 0 == stack->size;
}

size_t size(IntStackLL * stack)
{
    size_t count = 0;
    StackNode * current = stack->head;
    while (NULL != current) {
	count++;
	current = current->next;
    }

    return count;
}

void push(IntStackLL * stack, int32_t value)
{
    StackNode * node = malloc(sizeof *node);
    node->value = value;
    node->next = stack->head;
    stack->head = node;
    stack->size++;
}

int32_t pop(IntStackLL * stack)
{
    assert(NULL != stack->head);
    StackNode * chead = stack->head;
    int32_t value = chead->value;
    stack->head = stack->head->next;
    stack->size--;
    free(chead);
    return value;
}

int32_t peek(IntStackLL * stack)
{
    assert(NULL != stack->head);
    return stack->head->value;
}


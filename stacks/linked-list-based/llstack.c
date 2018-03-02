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
    return NULL;
}

void free_stack(IntStackLL * stack)
{

}

bool is_empty(IntStackLL * stack)
{
    return false;
}

size_t size(IntStackLL * stack)
{
    return 0;
}

void push(IntStackLL * stack, int32_t value)
{

}

int32_t pop(IntStackLL * stack)
{
    return 0;
}

int32_t peek(IntStackLL * stack)
{
    return 0;
}


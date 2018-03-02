#ifndef __DSA_C_LINKED_LIST_STACK_H__
#define __DSA_C_LINKED_LIST_STACK_H__

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct _IntStackLL IntStackLL;

IntStackLL * new_stack();
void free_stack(IntStackLL * stack);
bool is_empty(IntStackLL * stack);
size_t size(IntStackLL * stack);
void push(IntStackLL * stack, int32_t value);
int32_t pop(IntStackLL * stack);
int32_t peek(IntStackLL * stack);

#endif

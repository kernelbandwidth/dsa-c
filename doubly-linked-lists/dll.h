#ifndef __DSA_C_DLL__
#define __DSA_C_DLL__

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Defines a mutable doubly linked list

typedef struct _IntDLLNode IntDLLNode;
typedef struct _IntDLL IntDLL;

IntDLL * new_list();
void free_list(IntDLL * free);
size_t length(IntDLL * list);
bool is_empty(IntDLL * list);
void prepend(IntDLL * list, int32_t value);
void append(IntDLL * list, int32_t value);
int32_t head(IntDLL * list);
int32_t last(IntDLL * list);
IntDLL * tail(IntDLL * list);
IntDLL * init(IntDLL * list);
int32_t pop_head(IntDLL * list);
int32_t pop_last(IntDLL * list);
int32_t get(IntDLL * list, size_t index);

#endif

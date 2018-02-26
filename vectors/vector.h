#ifndef __DSA_C_VECTOR_H__
#define __DSA_C_VECTOR_H__

#include <stdbool.h>
#include <string.h>

typedef struct _IntVec IntVec;

IntVec * new_vec();
IntVec * new_vec_with_capacity(size_t cap);
void free_vec(IntVec * vec);
bool is_empty(IntVec * vec);
size_t length(IntVec * vec);
size_t capacity(IntVec * vec);
void push(IntVec * vec, int32_t elem);
int32_t pop(IntVec * vec);
int32_t get(IntVec * vec, size_t index);
int32_t remove(IntVec * vec, size_t index);
void insert(IntVec * vec, size_t index, int32_t elem);

#endif

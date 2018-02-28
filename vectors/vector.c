#include <stdlib.h>
#include <stdio.h>

#include "vector.h"

static size_t VEC_REALLOC_GROWTH = 2;
static size_t VEC_DEFAULT_SIZE = 16;

struct _IntVec {
    int32_t * data;
    size_t capacity;
    size_t length;
};

IntVec * new_vec()
{
    IntVec * vec = malloc(sizeof *vec);
    vec->data = malloc(VEC_DEFAULT_SIZE * sizeof *vec->data);
    vec->capacity = VEC_DEFAULT_SIZE;
    vec->length = 0;

    return vec;
}

// TODO(student): Implement a constructor that takes a capacity argument
IntVec * new_vec_with_capacity(size_t cap)
{
    return NULL;
}

// free_vec implementation is supplied
void free_vec(IntVec * vec)
{
    free(vec->data);
    free(vec);
}

// Helper function to handle inner memory reallocation is supplied.
// Remember to use it when necessary when adding new elements!
void increase_data_buffer(IntVec * vec)
{
    if (0 == vec->capacity) {
	vec->capacity = 1;
    } else {
	vec->capacity *= VEC_REALLOC_GROWTH;
    }

    vec->data = realloc(vec->data, vec->capacity * sizeof *vec->data);
}

//TODO(student): Implement the remaining functions
bool is_empty(IntVec * vec)
{
    return true;
}

size_t length(IntVec * vec)
{
    return 0;
}

size_t capacity(IntVec * vec)
{
    return 0;
}

void push(IntVec * vec, int32_t elem)
{

}

int32_t pop(IntVec * vec)
{
    return 0;
}

int32_t get(IntVec * vec, size_t index)
{
    return 0;
}

int32_t vremove(IntVec * vec, size_t index)
{
    return 0;
}

void insert(IntVec * vec, size_t index, int32_t elem)
{

}

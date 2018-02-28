#include <assert.h>
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
    IntVec * vec = malloc(sizeof *vec);
    vec->data = malloc(cap * sizeof *vec->data);
    vec->capacity = cap;
    vec->length = 0;

    return vec;
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
    return vec->length == 0;
}

size_t length(IntVec * vec)
{
    return vec->length;
}

size_t capacity(IntVec * vec)
{
    return vec->capacity;
}

void push(IntVec * vec, int32_t elem)
{
    if (vec->length == vec->capacity) {
	increase_data_buffer(vec);
    }

    vec->data[vec->length] = elem;
    vec->length++;
}

int32_t pop(IntVec * vec)
{
    assert(!is_empty(vec));
    int32_t value = vec->data[vec->length - 1];
    vec->length--;
    return value;
}

int32_t get(IntVec * vec, size_t index)
{
    assert(index < vec->length);
    return vec->data[index];
}

int32_t vremove(IntVec * vec, size_t index)
{
    assert(index < vec->length);
    int32_t value = vec->data[index];
    for (size_t idx = index + 1; idx < vec->length; idx++) {
	vec->data[idx-1] = vec->data[idx];
    }
    vec->length--;
    return value;
}

void insert(IntVec * vec, size_t index, int32_t elem)
{
    if (vec->length == vec->capacity) {
	increase_data_buffer(vec);
    }

    for (size_t idx = vec->length; idx > index; idx--) {
	vec->data[idx] = vec->data[idx-1];
    }

    vec->data[index] = elem;
}

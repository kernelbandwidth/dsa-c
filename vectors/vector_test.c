#include <assert.h>
#include <string.h>

#include "vector.h"
#include "../test-util/sctf.h"

void test_new_vector_is_not_null()
{
    IntVec * vec = new_vec();
    assert(NULL != vec);
    free_vec(vec);
}

void test_new_vector_has_length_zero()
{
    IntVec * vec = new_vec();
    assert(0 == length(vec));
    free_vec(vec);
}

void test_new_vector_is_empty()
{
    IntVec * vec = new_vec();
    assert(is_empty(vec));
    free_vec(vec);
}

void test_new_vector_with_capacity_has_that_capacity()
{
    IntVec * vec = new_vec_with_capacity(32);
    assert(NULL != vec);
    assert(32 == capacity(vec));
    free_vec(vec);
}

void test_new_vector_with_capacity_is_empty()
{
    IntVec * vec = new_vec_with_capacity(32);
    assert(NULL != vec);
    assert(is_empty(vec));
    free_vec(vec);
}

void test_pop_yields_last_push()
{
    IntVec * vec = new_vec();
    push(vec, 0);
    push(vec, 1);
    int32_t expected = (int32_t) rand();
    push(vec, expected);
    assert(expected == pop(vec));
    free_vec(vec);
}

void test_push_over_capacity_reallocates_and_increases_capacity()
{
    IntVec * vec = new_vec_with_capacity(2);
    assert(2 == capacity(vec));
    push(vec, 0);
    push(vec, 1);
    push(vec, 2);
    assert(capacity(vec) > 2);
    free_vec(vec);
}

void test_vector_has_correct_length()
{
    IntVec * vec = new_vec();
    push(vec, 0);
    push(vec, 1);
    push(vec, 2);
    assert(3 == length(vec));
    free_vec(vec);
}

void test_vector_with_elements_is_not_empty()
{
    IntVec * vec = new_vec();
    push(vec, 0);
    assert(!is_empty(vec));
    free_vec(vec);
}

void test_get_yields_correct_element()
{
    IntVec * vec = new_vec();
    push(vec, 0);
    push(vec, 1);
    int32_t expected = (int32_t) rand();
    push(vec, expected);
    push(vec, 2);
    assert(expected == get(vec, 2));
    free_vec(vec);
}

void test_vremove_yields_correct_element_and_removes_it()
{
    IntVec * vec = new_vec();
    push(vec, 0);
    push(vec, 1);
    int32_t expected = (int32_t) rand();
    push(vec, expected);
    push(vec, 3);
    assert(4 == length(vec));
    assert(expected == vremove(vec, 3));
    assert(3 == length(vec));
    free_vec(vec);
}

void test_insert_places_new_element_correctly()
{
    IntVec * vec = new_vec();
    push(vec, 0);
    push(vec, 1);
    push(vec, 2);
    int32_t expected = (int32_t) rand();
    insert(vec, 2, expected);
    assert(expected == get(vec, 2));
    free_vec(vec);
}

int main(int argc, char ** argv) 
{
    REGISTER_TEST(test_new_vector_is_not_null);
    REGISTER_TEST(test_new_vector_has_length_zero);
    REGISTER_TEST(test_new_vector_is_empty);
    REGISTER_TEST(test_new_vector_with_capacity_has_that_capacity);
    REGISTER_TEST(test_new_vector_with_capacity_is_empty);
    REGISTER_TEST(test_pop_yields_last_push);
    REGISTER_TEST(test_push_over_capacity_reallocates_and_increases_capacity);
    REGISTER_TEST(test_vector_has_correct_length);
    REGISTER_TEST(test_vector_with_elements_is_not_empty);
    REGISTER_TEST(test_get_yields_correct_element);
    REGISTER_TEST(test_vremove_yields_correct_element_and_removes_it);
    REGISTER_TEST(test_insert_places_new_element_correctly);

    run_tests();

    return 0;
}

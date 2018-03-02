#include <assert.h>
#include <stdlib.h>

#include "llstack.h"
#include "../../test-util/sctf.h"

void test_new_stack_returns_value()
{
    IntStackLL * stack = new_stack();
    assert(NULL != stack);
    free_stack(stack);
}

void test_new_stack_is_empty()
{
    IntStackLL * stack = new_stack();
    assert(is_empty(stack));
    free_stack(stack);
}

void test_new_stack_has_size_zero()
{
    IntStackLL * stack = new_stack();
    assert(0 == size(stack));
    free_stack(stack);
}

void test_push_to_stack_increments_size_by_one()
{
    IntStackLL * stack = new_stack();
    push(stack, 0);
    push(stack, 1);
    push(stack, 2);
    size_t expected = size(stack) + 1;
    push(stack, 3);
    assert(expected == size(stack));
    free_stack(stack);
}

void test_pop_from_stack_decrements_size_by_one()
{
    IntStackLL * stack = new_stack();
    push(stack, 0);
    push(stack, 1);
    push(stack, 2);
    size_t expected = size(stack) - 1;
    pop(stack);
    assert(expected == size(stack));
    free_stack(stack);
}

void test_pops_return_correct_order_of_pushes()
{
    IntStackLL * stack = new_stack();
    int32_t expected3 = (int32_t) rand();
    int32_t expected2 = (int32_t) rand();
    int32_t expected1 = (int32_t) rand();
    push(stack, expected3);
    push(stack, expected2);
    push(stack, expected1);

    assert(expected1 == pop(stack));
    assert(expected2 == pop(stack));
    assert(expected3 == pop(stack));
    free_stack(stack);
}

void test_peek_returns_correct_top_of_stack()
{
    IntStackLL * stack = new_stack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    int32_t expected = (int32_t) rand();
    push(stack, expected);
    assert(expected == peek(stack));
    free_stack(stack);
}

void test_peek_does_not_change_size()
{
    IntStackLL * stack = new_stack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 4);
    size_t expected = size(stack);
    peek(stack);
    assert(expected == size(stack));
    free_stack(stack);
}

void test_stack_with_size_one_is_empty_after_pop()
{
    IntStackLL * stack = new_stack();
    push(stack, 1);
    assert(!is_empty(stack));
    assert(1 == size(stack));
    pop(stack);
    assert(is_empty(stack));
    assert(0 == size(stack));
}

void test_sequence_of_operations_works_correctly()
{
    IntStackLL * stack = new_stack();
    int32_t expected1 = (int32_t) rand();
    int32_t expected2 = (int32_t) rand();
    int32_t expected3 = (int32_t) rand();
    int32_t expected4 = (int32_t) rand();
    int32_t expected5 = (int32_t) rand();

    push(stack, expected1);
    push(stack, expected2);
    assert(expected2 == peek(stack));
    assert(expected2 == pop(stack));

    push(stack, expected3);
    push(stack, expected4);
    assert(expected4 == pop(stack));
    assert(expected3 == pop(stack));

    push(stack, expected5);
    assert(expected5 == pop(stack));
    assert(expected1 == pop(stack));

    free_stack(stack);
}

int main(int argc, char ** argv)
{
    REGISTER_TEST(test_new_stack_returns_value);
    REGISTER_TEST(test_new_stack_is_empty);
    REGISTER_TEST(test_new_stack_has_size_zero);
    REGISTER_TEST(test_push_to_stack_increments_size_by_one);
    REGISTER_TEST(test_pop_from_stack_decrements_size_by_one);
    REGISTER_TEST(test_pops_return_correct_order_of_pushes);
    REGISTER_TEST(test_peek_returns_correct_top_of_stack);
    REGISTER_TEST(test_peek_does_not_change_size);
    REGISTER_TEST(test_stack_with_size_one_is_empty_after_pop);
    REGISTER_TEST(test_sequence_of_operations_works_correctly);

    run_tests();

    return 0;
}


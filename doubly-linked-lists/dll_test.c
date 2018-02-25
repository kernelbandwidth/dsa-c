#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "dll.h"
#include "../test-util/util.h"

void test_new_list_returns_value()
{
    IntDLL * list = new_list();
    assert(NULL != list);
    free_list(list);
}

void test_new_list_has_length_zero()
{
    IntDLL * list = new_list();
    assert(0 == length(list));
    free_list(list);
}

void test_appending_to_list_increments_length()
{
    IntDLL * list = new_list();
    int expected_length = length(list) + 1;
    append(list, 1);
    assert(expected_length == length(list));
    free_list(list);
}

void test_prepending_to_list_increments_length()
{
    IntDLL * list = new_list();
    int expected_length = length(list) + 1;
    prepend(list, 1);
    assert(expected_length == length(list));
    free_list(list);
}

void test_new_list_is_empty()
{
    IntDLL * list = new_list();
    assert(is_empty(list));
    free_list(list);
}

void test_list_is_not_empty_after_appending()
{
    IntDLL * list = new_list();
    append(list, 1);
    assert(!is_empty(list));
    free_list(list);
}

void test_list_is_not_empty_after_prepending()
{
    IntDLL * list = new_list();
    prepend(list, 1);
    assert(!is_empty(list));
    free_list(list);
}

void test_list_with_length_one_is_empty_after_popping_head()
{
    IntDLL * list = new_list();
    append(list, 1);
    assert(1 == length(list));
    pop_head(list);
    assert(is_empty(list));
    free_list(list);
}

void test_list_with_length_one_is_empty_after_popping_last()
{
    IntDLL * list = new_list();
    append(list, 1);
    assert(1 == length(list));
    pop_last(list);
    assert(is_empty(list));
    free_list(list);
}

void test_prepend_to_list_has_new_element_as_head()
{
    IntDLL * list = new_list();
    int32_t expected = (int32_t) rand();
    prepend(list, 1);
    prepend(list, 2);
    append(list, 3);
    prepend(list, expected);
    assert(expected == head(list));
    free_list(list);
}

void test_append_to_list_has_new_element_as_last()
{
    IntDLL * list = new_list();
    int32_t expected = (int32_t) rand();
    prepend(list, 1);
    append(list, 2);
    append(list, expected);
    assert(expected == last(list));
    free_list(list);
}

void test_tail_of_empty_list_is_empty_list()
{
    IntDLL * list = new_list();
    assert(is_empty(list));
    assert(is_empty(tail(list)));
    free_list(list);
}

void test_tail_of_list_with_one_element_is_empty()
{
    IntDLL * list = new_list();
    append(list, 0);
    assert(1 == length(list));
    assert(is_empty(tail(list)));
    free_list(list);
}

void test_tail_of_list_with_several_elements_is_not_empty()
{
    IntDLL * list = new_list();
    append(list, 0);
    append(list, 1);
    append(list, 2);
    assert(!is_empty(tail(list)));
    free_list(list);
}

void test_head_of_tail_of_list_is_second_element()
{
    IntDLL * list = new_list();
    append(list, 0);
    int32_t expected = (int32_t) rand();
    assert(expected == head(tail(list)));
    free_list(list);
}

void test_tail_of_non_empty_list_is_one_smaller()
{
    IntDLL * list = new_list();
    append(list, 0);
    append(list, 1);
    append(list, 2);
    size_t expected = length(list) - 1;
    assert(expected = length(tail(list)));
    free_list(list);
}

void test_init_of_empty_list_is_empty_list()
{
    IntDLL * list = new_list();
    assert(is_empty(list));
    assert(is_empty(init(list)));
    free_list(list);
}

void test_init_of_list_with_one_element_is_empty_list()
{
    IntDLL * list = new_list();
    append(list, 1);
    assert(1 == length(list));
    assert(is_empty(init(list)));
    free_list(list);
}

void test_init_of_list_with_several_elements_is_not_empty()
{
    IntDLL * list = new_list();
    append(list, 1);
    append(list, 2);
    append(list, 3);
    assert(length(list) > 1);
    assert(!is_empty(init(list)));
    free_list(list);
}

void test_last_of_init_of_list_is_second_to_last_element()
{
    IntDLL * list = new_list();
    int32_t expected = (int32_t) rand();
    append(list, 0);
    append(list, 1);
    append(list, expected);
    append(list, 2);
    assert(expected = last(init(list)));
    free_list(list);
}

void test_init_of_non_empty_list_is_one_smaller()
{
    IntDLL * list = new_list();
    append(list, 0);
    append(list, 1);
    append(list, 2);
    size_t expected = length(list) - 1;
    assert(expected == length(init(list)));
    free_list(list);
}

void test_pop_head_gets_last_prepend()
{
    IntDLL * list = new_list();
    append(list, 0);
    append(list, 1);
    append(list, 2);
    int32_t expected = (int32_t) rand();
    prepend(list, expected);
    assert(expected == pop_head(list));
    free_list(list);
}

void test_prepend_and_then_pop_head_has_invariant_length()
{
    IntDLL * list = new_list();
    append(list, 0);
    append(list, 1);
    append(list, 2);
    size_t expected = length(list);
    prepend(list, 3);
    pop_head(list);
    assert(expected == length(list));
    free_list(list);
}

void test_pop_head_decrements_length()
{
    IntDLL * list = new_list();
    append(list, 0);
    append(list, 1);
    append(list, 2);
    size_t expected = length(list) - 1;
    pop_head(list);
    assert(expected == length(list));
    free_list(list);
}

void test_pop_last_gets_last_append()
{
    IntDLL * list = new_list();
    append(list, 0);
    append(list, 1);
    prepend(list, 2);
    int32_t expected = (int32_t) rand();
    append(list, expected);
    assert(expected == pop_last(list));
    free_list(list);
}

void test_append_and_then_pop_last_has_invariant_length()
{
    IntDLL * list = new_list();
    append(list, 0);
    append(list, 1);
    append(list, 2);
    size_t expected = length(list);
    append(list, 3);
    pop_last(list);
    assert(expected == length(list));
    free_list(list);
}

void test_pop_last_decrements_length()
{
    IntDLL * list = new_list();
    append(list, 0);
    prepend(list, 1);
    append(list, 2);
    size_t expected = length(list) - 1;
    pop_last(list);
    assert(expected == length(list));
    free_list(list);
}

void test_get_zero_gets_head()
{
    IntDLL * list = new_list();
    append(list, 0);
    append(list, 1);
    int32_t value = (int32_t) rand();
    prepend(list, value);
    assert(head(list) == get(list, 0));
    free_list(list);
}

void test_get_size_minus_one_gets_last()
{
    IntDLL * list = new_list();
    append(list, 0);
    append(list, 1);
    append(list, (int32_t) rand());
    assert(last(list) == get(list, length(list) - 1));
    free_list(list);
}

void test_get_later_element_returns_correct_value()
{
    IntDLL * list = new_list();
    append(list, 0);
    append(list, 1);
    int32_t expected = (int32_t) rand();
    append(list, expected);
    append(list, 3);
    assert(expected == get(list, 2));
    free_list(list);
}

int main(int argc, char ** argv)
{
    puts("Testing new_list()");
    test_new_list_returns_value();
    pass();

    puts("Testing length()");
    test_new_list_has_length_zero();
    test_appending_to_list_increments_length();
    test_prepending_to_list_increments_length();
    pass();

    puts("Testing is_empty()");
    test_new_list_is_empty();
    test_list_is_not_empty_after_appending();
    test_list_is_not_empty_after_prepending();
    test_list_with_length_one_is_empty_after_popping_head();
    test_list_with_length_one_is_empty_after_popping_last();
    pass();

    puts("Testing prepend()");
    test_prepend_to_list_has_new_element_as_head();
    pass();

    puts("Testing append()");
    test_append_to_list_has_new_element_as_last();
    pass();

    puts("Testing tail()");
    test_tail_of_empty_list_is_empty_list();
    test_tail_of_list_with_one_element_is_empty();
    test_tail_of_list_with_several_elements_is_not_empty();
    test_head_of_tail_of_list_is_second_element();
    test_tail_of_non_empty_list_is_one_smaller();
    pass();

    puts("Testing init()");
    test_init_of_empty_list_is_empty_list();
    test_init_of_list_with_one_element_is_empty_list();
    test_init_of_list_with_several_elements_is_not_empty();
    test_last_of_init_of_list_is_second_to_last_element();
    test_init_of_non_empty_list_is_one_smaller();
    pass();

    puts("Testing pop_head()");
    test_pop_head_gets_last_prepend();
    test_prepend_and_then_pop_head_has_invariant_length();
    test_pop_head_decrements_length();
    pass();

    puts("Testing pop_last()");
    test_pop_last_gets_last_append();
    test_append_and_then_pop_last_has_invariant_length();
    test_pop_last_decrements_length();
    pass();

    puts("Testing get()");
    test_get_zero_gets_head();
    test_get_size_minus_one_gets_last();
    test_get_later_element_returns_correct_value();
    pass();

    pass_all();

    return 0;
}


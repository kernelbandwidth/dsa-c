#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "ll.h"

void test_new_list_returns_value() 
{
    // Just test that we don't crash or get a null
    IntLinkedList * list = new_list();
    assert(list != NULL);
    free_list(list);
}

void test_new_list_has_length_zero()
{
    IntLinkedList * list = new_list();
    assert(length(list) == 0);
    free_list(list);
}

void test_appending_to_list_increments_length()
{
    IntLinkedList * list = new_list();
    int expected_length = length(list) + 1;
    append(list, 1);
    assert(expected_length == length(list));
    free_list(list);
}

void test_prepending_to_list_increments_length()
{
    IntLinkedList * list = new_list();
    int expected_length = length(list) + 1;
    prepend(list, 1);
    assert(expected_length == length(list));
    free_list(list);
}

void test_new_list_is_empty()
{
    IntLinkedList * list = new_list();
    assert(is_empty(list));
}

void test_list_is_not_empty_after_appending()
{
    IntLinkedList * list = new_list();
    append(list, 0);
    assert(!is_empty(list));
}

void test_list_is_not_empty_after_prepending()
{
    IntLinkedList * list = new_list();
    prepend(list, 1);
    assert(!is_empty(list));
}

void test_list_with_length_one_is_empty_after_popping()
{
    IntLinkedList * list = new_list();
    append(list, 0);
    assert(1 == length(list));
    pop_head(list);
    assert(is_empty(list));
}

void test_tail_of_empty_list_is_empty_list()
{
    IntLinkedList * list = new_list();
    assert(is_empty(list));
    IntLinkedList * tail_of_list = tail(list);
    assert(NULL != tail_of_list);
    assert(is_empty(tail_of_list));
}

void test_head_of_list_is_last_prepend() {
    IntLinkedList * list = new_list();
    int test_value = rand();
    prepend(list, test_value);
    assert(test_value == head(list));
}

void test_tail_of_list_with_one_element_is_empty()
{
    IntLinkedList * list = new_list();
    append(list, 0);
    assert(1 == length(list));
    IntLinkedList * tail_of_list = tail(list);
    assert(is_empty(tail_of_list));
}

void test_tail_of_list_with_several_elements_is_not_empty()
{
    IntLinkedList * list = new_list();
    append(list, 0);
    append(list, 1);
    append(list, 2);
    assert(!is_empty(tail(list)));
}

void test_tail_of_non_empty_list_is_one_smaller()
{
    IntLinkedList * list = new_list();
    append(list, 0);
    append(list, 1);
    append(list, 2);
    int expected = length(list) - 1;
    assert(expected == length(tail(list)));
}

void test_head_of_tail_of_list_is_second_element()
{
    IntLinkedList * list = new_list();
    append(list, 0);
    append(list, 1);
    append(list, 2);
    assert(1 == head(tail(list)));
}

void test_prepend_to_list_has_new_element_as_head()
{
    IntLinkedList * list = new_list();
    prepend(list, 0);
    assert(0 == head(list));
    prepend(list, 1);
    assert(1 == head(list));
    int test_value = rand();
    prepend(list, test_value);
    assert(test_value == head(list));
}

void test_append_to_list_has_new_element_as_last_in_list()
{
    IntLinkedList * list = new_list();
    append(list, 0);
    append(list, 1);
    append(list, 2);
    assert(2 == head(tail(tail(list))));
}

void test_pop_head_gets_last_prepend()
{
    IntLinkedList * list = new_list();
    append(list, 0);
    append(list, 1);
    int expected = rand();
    prepend(list, expected);
    assert(expected == pop_head(list));
}

void test_append_and_then_pop_has_invariant_length()
{
    IntLinkedList * list = new_list();
    append(list, 0);
    append(list, 1);
    
    int expected = length(list);
    append(list, 2);
    pop_head(list);
    assert(expected == length(list));
}

void test_pop_head_decrements_length()
{
    IntLinkedList * list = new_list();
    append(list, 0);
    append(list, 1);
    append(list, 2);
    int expected = length(list) - 1;
    pop_head(list);
    assert(expected == length(list));
}
void test_get_zero_gets_head()
{
    IntLinkedList * list = new_list();
    append(list, 0);
    append(list, 1);
    append(list, 2);
    assert(head(list) == get(list, 0));
}

void test_get_later_element_returns_correct_value()
{
    IntLinkedList * list = new_list();
    append(list, 0);
    int expected = rand();
    append(list, expected);
    append(list, 1);
    assert(expected == get(list, 1));
}

void pass()
{
    puts("Test passed!");
}

int main(int argc, char ** argv)
{
    puts("Running tests.");
    
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
    test_list_with_length_one_is_empty_after_popping();
    pass();

    puts("Testing prepend()");
    test_prepend_to_list_has_new_element_as_head(); 
    pass();

    puts("Testing append()");
    test_append_to_list_has_new_element_as_last_in_list();
    pass();

    puts("Testing head()");
    test_head_of_list_is_last_prepend();
    pass();

    puts("Testing tail()");
    test_tail_of_empty_list_is_empty_list();
    test_tail_of_list_with_one_element_is_empty();
    test_tail_of_list_with_several_elements_is_not_empty();
    test_head_of_tail_of_list_is_second_element();
    test_tail_of_non_empty_list_is_one_smaller();
    pass();

    puts("Testing pop_head()");
    test_pop_head_gets_last_prepend();
    test_append_and_then_pop_has_invariant_length();
    test_pop_head_decrements_length();
    pass();

    puts("Testing get()");
    test_get_zero_gets_head();
    test_get_later_element_returns_correct_value();
    pass();

    puts("############################");
    puts("#                          #");
    puts("# Congrats! All Test Pass! #");
    puts("#                          #");
    puts("############################");

    return 0;
}


#include <assert.h>
#include <stdbool.h>

#include "sctf.h"

void test_f() 
{
    puts("TEST FUNCTION CALL");
    assert(true);
}

void test_this_always_fails() 
{
    assert(false);
}

int main(int argc, char ** argv)
{
    REGISTER_TEST(test_f);
    REGISTER_TEST(test_this_always_fails);
    run_tests();

    return 0;
}

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


int main(int argc, char ** argv)
{
    pass_all();

    return 0;
}


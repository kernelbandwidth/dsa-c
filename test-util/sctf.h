#ifndef __SIMPLE_C_TESTING_FRAMEWORK_H__
#define __SIMPLE_C_TESTING_FRAMEWORK_H__

#include <signal.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REGISTER_TEST(test) register_test(test, #test)

struct __SCTF_TEST_FN_META {
    void (*testfn)();
    char * name;
};

struct __SCTF_TEST_FN_META * __SCTF_new_meta(void (*testfn)(), char * name)
{
    struct __SCTF_TEST_FN_META * meta = malloc(sizeof *meta);
    meta->testfn = testfn;
    meta->name = malloc((1 + strlen(name)) * sizeof (char));
    strcpy(meta->name, name);

    return meta;
}

struct __SCTF_TEST_SET {
    struct __SCTF_TEST_FN_META ** testfns;
    size_t length;
    size_t capacity;
};

static const size_t __SCTF_DEFAULT_CAPACITY = 16;
static const size_t __SCTF_CAP_GROWTH_RATE = 2;

struct __SCTF_TEST_SET * _SCTF_new_tests()
{
    struct __SCTF_TEST_SET * testset = malloc(sizeof *testset);
    testset->testfns = malloc(__SCTF_DEFAULT_CAPACITY * sizeof testset->testfns);
    testset->length = 0;
    testset->capacity = __SCTF_DEFAULT_CAPACITY;

    return testset;
}

void __SCTF_realloc_capacity(struct __SCTF_TEST_SET * testset)
{
    testset->capacity *= __SCTF_CAP_GROWTH_RATE;
    testset->testfns = realloc(testset->testfns, testset->capacity * sizeof *testset->testfns);
}

static jmp_buf _SCTF_JMP_BUF;
static size_t _SCTF_TEST_COUNT = 0;
static size_t _SCTF_TEST_FAIL_COUNT = 0;
static struct __SCTF_TEST_SET * SCTFTests = NULL;

void register_test(void (*testfn)(), char * test_name)
{
    if (NULL == SCTFTests) {
	SCTFTests = _SCTF_new_tests();
    }

    if (SCTFTests->length == SCTFTests->capacity) {
	__SCTF_realloc_capacity(SCTFTests);
    }

    *(SCTFTests->testfns + SCTFTests->length) = __SCTF_new_meta(testfn, test_name);
    SCTFTests->length++;
}

void catch_abort_handler(int sig)
{
    puts("FAILED");
    _SCTF_TEST_FAIL_COUNT++;
    _SCTF_TEST_COUNT++;
    signal(sig, catch_abort_handler);
    longjmp(_SCTF_JMP_BUF, 0);
}

void catch_segfault_handler(int sig)
{
    puts("SEGMENTATION FAULT: INVALID MEMORY ACCESS. TEST FAILED");
    _SCTF_TEST_FAIL_COUNT++;
    _SCTF_TEST_COUNT++;
    signal(sig, catch_segfault_handler);
    longjmp(_SCTF_JMP_BUF, 0);
}

void run_tests() 
{
    puts("Simple C Test Framework");
    printf("Running %zu tests.\n\n", SCTFTests->length);

    signal(SIGABRT, catch_abort_handler);
    signal(SIGSEGV, catch_segfault_handler);
    setjmp(_SCTF_JMP_BUF);
    while (_SCTF_TEST_COUNT < SCTFTests->length) {
	printf("Running test: %s\n", SCTFTests->testfns[_SCTF_TEST_COUNT]->name);
	SCTFTests->testfns[_SCTF_TEST_COUNT]->testfn();
	puts("PASSED!");
	_SCTF_TEST_COUNT++;
    }

    puts("Test Summary");
    printf("PASSED: %zu out of %zu tests run\n", 
	    (_SCTF_TEST_COUNT - _SCTF_TEST_FAIL_COUNT), _SCTF_TEST_COUNT);
    if (_SCTF_TEST_FAIL_COUNT > 0) {
	printf("FAILED: %zu out of %zu tests run\n", _SCTF_TEST_FAIL_COUNT, _SCTF_TEST_COUNT);
    } else {
	puts("Hooray! All tests passed!");
    }

    _SCTF_TEST_COUNT = 0;
    _SCTF_TEST_FAIL_COUNT = 0;
}

#endif

#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include <cassert>
#include <iostream>

#include "fraction.h"

class unit_tests
{
    void test_difference();
    void test_division();
    void test_multiplication();
    void test_reduce();
    void test_root();
    void test_sum();
public:
    unit_tests();
};

#endif // UNIT_TESTS_H

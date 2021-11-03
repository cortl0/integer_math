/**
 *   integer_math
 *   created by Ilya Shishkin
 *   cortl@8iter.ru
 *   https://github.com/cortl0/integer_math
 *   licensed by GPL v3.0
 */

#include <cassert>
#include <iostream>

#include "fraction.h"
#include "unit_tests.h"

#define imf integer_math::fraction

unit_tests::unit_tests()
{
    test_difference();
    test_division();
    test_multiplication();
    test_reduce();
    test_reduce_force();
    test_root();
    test_sum();

    std::cout << "tests passed" << std::endl;
}

void unit_tests::test_difference()
{
    {
        imf value = imf::difference(imf(1, 2), imf(1, 3));
        assert(1 == value.numerator);
        assert(6 == value.denominator);
    }
    {
        imf value = imf::difference(imf(1, -2), imf(1, 3));
        assert(5 == value.numerator);
        assert(-6 == value.denominator);
    }
    {
        imf value = imf::difference(imf(1, 2), imf(1, -3));
        assert(-5 == value.numerator);
        assert(-6 == value.denominator);
    }
    {
        imf value = imf::difference(imf(-1, 2), imf(1, 3));
        assert(-5 == value.numerator);
        assert(6 == value.denominator);
    }
    {
        imf value = imf::difference(imf(1, 2), imf(-1, 3));
        assert(5 == value.numerator);
        assert(6 == value.denominator);
    }
    {
        imf value = imf::difference(imf(-2, -3), imf(-5, -7));
        assert(-1 == value.numerator);
        assert(21 == value.denominator);
    }
}

void unit_tests::test_division()
{
    imf value = imf::division(imf(1, 2), imf(3, 4));
    assert(4 == value.numerator);
    assert(6 == value.denominator);
}

void unit_tests::test_multiplication()
{
    imf value = imf::multiplication(imf(1, 2), imf(3, 4));
    assert(3 == value.numerator);
    assert(8 == value.denominator);
}

void unit_tests::test_reduce()
{
    imf value = imf::reduce(imf(8, 16));
    assert(1 == value.numerator);
    assert(2 == value.denominator);
}

void unit_tests::test_reduce_force()
{
    imf value = imf::reduce_force(imf(8, 16), 2);
    assert(2 == value.numerator);
    assert(4 == value.denominator);
}

void unit_tests::test_root()
{
    {
        imf value = imf::root(imf(4, 1), imf(2, 1));
        assert(2 == value.numerator);
        assert(1 == value.denominator);
    }
    {
        imf value = imf::root(imf(25, 9), imf(2, 1));
        assert(5 == value.numerator);
        assert(3 == value.denominator);
    }
    {
        imf value = imf::root(imf(2, 4), imf(2, 4));
        assert(4 == value.numerator);
        assert(16 == value.denominator);
    }
}

void unit_tests::test_sum()
{
    imf value = imf::sum(imf(1, 2), imf(1, 3));
    assert(5 == value.numerator);
    assert(6 == value.denominator);
}

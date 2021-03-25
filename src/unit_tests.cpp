#include "unit_tests.h"

unit_tests::unit_tests()
{
    test_difference();
    test_division();
    test_multiplication();
    test_reduce();
    test_root();
    test_sum();

    std::cout << "tests passed" << std::endl;
}

void unit_tests::test_difference()
{
    fraction first(1, 2);
    fraction second(1, 3);

    fraction third = fraction::difference(first, second);

    assert(6 == third.denominator);
    assert(1 == third.numerator);
}

void unit_tests::test_division()
{
    fraction first(1, 2);
    fraction second(3, 4);

    fraction third = fraction::division(first, second);

    assert(6 == third.denominator);
    assert(4 == third.numerator);
}

void unit_tests::test_multiplication()
{
    fraction first(1, 2);
    fraction second(3, 4);

    fraction third = fraction::multiplication(first, second);

    assert(8 == third.denominator);
    assert(3 == third.numerator);
}

void unit_tests::test_reduce()
{
    fraction value(8, 16);

    fraction::reduce(value);

    assert(2 == value.denominator);
    assert(1 == value.numerator);
}

void unit_tests::test_root()
{
    {
        fraction first(4, 1);
        fraction second(2, 1);
        fraction third = fraction::root(first, second);
        assert(1 == third.denominator);
        assert(2 == third.numerator);
    }
    {
        fraction first = fraction(25, 9);
        fraction second = fraction(2, 1);
        fraction third = fraction::root(first, second);
        assert(3 == third.denominator);
        assert(5 == third.numerator);
    }
    {
        fraction first = fraction(2, 4);
        fraction second = fraction(2, 4);
        fraction third = fraction::root(first, second);
        assert(16 == third.denominator);
        assert(4 == third.numerator);
    }
}

void unit_tests::test_sum()
{
    fraction first(1, 2);
    fraction second(1, 3);

    fraction third = fraction::sum(first, second);

    assert(6 == third.denominator);
    assert(5 == third.numerator);
}

/**
 *   integer_math
 *   created by Ilya Shishkin
 *   cortl@8iter.ru
 *   https://github.com/cortl0/integer_math
 *   licensed by GPL v3.0
 */

#include <stdexcept>

#include "fraction.h"

namespace integer_math
{

fraction::fraction(int numerator, int denominator)
    : denominator(denominator), numerator(numerator)
{

}

fraction fraction::difference(const fraction &first, const fraction &second)
{
    fraction value;

    value.numerator = (first.numerator * second.denominator) - (second.numerator * first.denominator);

    value.denominator = first.denominator * second.denominator;

    return value;
}

fraction fraction::division(const fraction &first, const fraction &second)
{
    return multiplication(first, reciprocal(second));
}

fraction fraction::multiplication(const fraction &first, const fraction &second)
{
    fraction value;

    value.numerator = first.numerator * second.numerator;

    value.denominator = first.denominator * second.denominator;

    return value;
}

fraction fraction::pow(const fraction &first, const fraction &second)
{
    fraction value;

    value = pow(first, second.numerator);

    value = root(value, second.denominator);

    return value;
}

fraction fraction::reciprocal(fraction value)
{
    return fraction(value.denominator, value.numerator);
}

fraction fraction::reduce(const fraction& value)
{
    fraction result(value);

    bool flag = true;

    while(flag)
    {
        if((result.numerator == 0) && (result.denominator == 0))
            break;

        if(result.numerator == 0)
        {
            result.denominator = 1;

            break;
        }

        //??
        if(result.denominator == 0)
        {
            // throw error
            //throw std::exception();

            // -> max
            //value.numerator = __INT_MAX__;

            // -> 1
            result.numerator = 1;

            break;
        }

        flag = false;

        if(((result.numerator & 1) == 0) && ((result.denominator & 1) == 0))
        {
            result.numerator >>= 1;

            result.denominator >>= 1;

            flag = true;

            continue;
        }

        static int num[] = {3, 5, 7};

        for(int i = 0; i < 3; i++)
            if(((result.numerator % num[i]) == 0) && ((result.denominator % num[i]) == 0))
            {
                result.numerator /= num[i];

                result.denominator /= num[i];

                flag = true;

                continue;
            }
    }

    return result;
}

fraction fraction::reduce_force(const fraction &value, int depth)
{
    fraction result;

    result.numerator = (value.numerator >> depth);

    result.denominator = (value.denominator >> depth);

    return result;
}

fraction fraction::root(const fraction &first, const fraction &second)
{
    return pow(first, reciprocal(second));
}

fraction fraction::sum(const fraction &first, const fraction &second)
{
    fraction value;

    value.numerator = (first.numerator * second.denominator) + (second.numerator * first.denominator);

    value.denominator = first.denominator * second.denominator;

    return value;
}

std::string fraction::to_string() const
{
    std::string value(std::to_string(numerator));

    value += " / ";

    value += std::to_string(denominator);

    return value;
}

// *********** private: ***********

fraction fraction::pow(const fraction &first, int second)
{
    fraction value(first);

    if(second < 0)
    {
        value = reciprocal(value);

        second = -second;
    }

    value.numerator = pow(first.numerator, second);

    value.denominator = pow(first.denominator, second);

    return value;
}

int fraction::pow(int first, int second)
{
    // TODO ??

    if(second < 0)
        throw std::runtime_error("int fraction::pow(int first, int second) -> (second < 1)");

    if(0 == first && 0 == second)
        throw std::runtime_error("int fraction::pow(int first, int second) -> (0 == first && 0 == second)");

    int value = 1;

    while(second-- > 0)
        value *= first;

    return value;
}

fraction fraction::root(const fraction &first, int second)
{
    fraction value;

    if(second < 0)
    {
        value = reciprocal(value);

        second = -second;
    }

    value.numerator = root(first.numerator, second);

    value.denominator = root(first.denominator, second);

    return value;
}

int fraction::root(int first, int second)
{
    // TODO

    if(second < 1)
        throw std::runtime_error("int fraction::root(int first, int second) -> (second < 1)");

//    if(1 == first)
//        return first;

//    if(1 == second)
//        return first;

    if(first < 0 && second & 1)
        throw std::runtime_error("int fraction::root(int first, int second) -> (first < 0  && second & 1)");

    int value_min = -100; // - __INT_MAX__;
    int value_max = 100; // __INT_MAX__;
    int value = 1;

    int result_min = 1;
    int result_max = 1;
    int result = 1;

    int i = second;
    while(i-- > 0)
    {
        result_min *= value_min;
        result_max *= value_max;
    }

    bool flag = true;

    while(flag)
    {
        //flag = false;

        result = 1;
        value = (value_max + value_min) / 2;
        i = second;
        while(i-- > 0)
            result *= value;

        if (first < result)
        {
            value_max = value;
            result_max = result;
            continue;
        }
        else if (first > result)
        {
            value_min = value;
            result_min = result;
            continue;
        }
        else
        {
            return value;
        }
    }

    return value;

    throw std::runtime_error("int fraction::root(int first, int second) -> (not implemented)");




    //    value.denominator = first.denominator * second.denominator;

    //    value.numerator = first.numerator * second.numerator;

    return value;
}

} // integer_math

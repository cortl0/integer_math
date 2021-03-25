#include "fraction.h"


fraction::fraction()
{

}

fraction::fraction(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}

fraction fraction::difference(fraction first, fraction second)
{
    fraction value;

    value.denominator = first.denominator * second.denominator;

    value.numerator = (first.numerator * second.denominator) - (second.numerator * first.denominator);

    return value;
}

fraction fraction::division(fraction first, fraction second)
{
    return multiplication(first, reciprocal(second));
}

fraction fraction::multiplication(fraction first, fraction second)
{
    fraction value;

    value.denominator = first.denominator * second.denominator;

    value.numerator = first.numerator * second.numerator;

    return value;
}

fraction fraction::pow(fraction first, fraction second)
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

void fraction::reduce(fraction& value)
{
    bool flag = true;

    while(flag)
    {
        if((value.numerator == 0) && (value.denominator == 0))
            break;

        if(value.numerator == 0)
        {
            value.denominator = 1;
            break;
        }

        //??
        if(value.denominator == 0)
        {
            // throw error
            //throw std::exception();

            // -> max
            //value.numerator = __INT_MAX__;

            // -> 1
            value.numerator = 1;

            break;
        }

        flag = false;

        if(((value.numerator & 1) == 0) && ((value.denominator & 1) == 0))
        {
            value.numerator >>= 1;
            value.denominator >>= 1;
            flag = true;
            continue;
        }

        static int num[] = {3, 5, 7};

        for(int i = 0; i < 3; i++)
            if(((value.numerator % num[i]) == 0) && ((value.denominator % num[i]) == 0))
            {
                value.numerator /= num[i];
                value.denominator /= num[i];
                flag = true;
                continue;
            }
    }
}

fraction fraction::root(fraction first, fraction second)
{
    return pow(first, reciprocal(second));
}

fraction fraction::sum(fraction first, fraction second)
{
    fraction value;

    value.denominator = first.denominator * second.denominator;

    value.numerator = (first.numerator * second.denominator) + (second.numerator * first.denominator);

    return value;
}

std::string fraction::to_string()
{
    std::string value(std::to_string(numerator));

    value += " / ";

    value += std::to_string(denominator);

    return value;
}

// *********** private: ***********

fraction fraction::pow(fraction first, int second)
{
    fraction value;

    value.denominator = pow(first.denominator, second);

    value.numerator = pow(first.numerator, second);

    return value;
}

int fraction::pow(int first, int second)
{
    int value = 1;

    while(second-- > 0)
        value *= first;

    return value;
}

fraction fraction::root(fraction first, int second)
{
    fraction value;

    value.denominator = root(first.denominator, second);

    value.numerator = root(first.numerator, second);

    return value;
}



int fraction::root(int first, int second)
{
    // TODO

    if(second == 0)
        return 1;

    //    if(first == 0)
    //        return 0;

    if(first < 0 && (!second) & 1)
        throw std::runtime_error("int fraction::root(int first, int second) -> (first < 0  && (!second) & 1)");

    if(second < 0)
        throw std::runtime_error("int fraction::root(int first, int second) -> (second < 0)");

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

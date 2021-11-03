/**
 *   integer_math
 *   created by Ilya Shishkin
 *   cortl@8iter.ru
 *   https://github.com/cortl0/integer_math
 *   licensed by GPL v3.0
 */

#ifndef INTEGER_MATH_FRACTION_H
#define INTEGER_MATH_FRACTION_H

#include <string>

namespace integer_math
{

struct fraction final
{
    int denominator;
    int numerator;
    fraction() = default;
    explicit fraction(int numerator, int denominator);
    static fraction difference(const fraction &first, const fraction &second);
    static fraction division(const fraction &first, const fraction &second);
    static fraction multiplication(const fraction &first, const fraction &second);
    static fraction pow(const fraction &first, const fraction &second);
    static fraction reduce(const fraction&);
    static fraction reduce_force(const fraction&, int depth);
    static fraction reciprocal(fraction);
    static fraction root(const fraction &first, const fraction &second);
    static fraction sum(const fraction &first, const fraction &second);
    std::string to_string() const;

private:
    static fraction pow(const fraction &first, int second);
    static int pow(int first, int second);
    static fraction root(const fraction &first, int second);
    static int root(int first, int second);
};

} // integer_math

#endif // INTEGER_MATH_FRACTION_H

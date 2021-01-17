#ifndef FRACTION_H
#define FRACTION_H

#include <string>
#include <stdexcept>

struct fraction
{
    int denominator;
    int numerator;
    fraction();
    fraction(int numerator, int denominator);
    static fraction difference(fraction first, fraction second);
    static fraction division(fraction first, fraction second);
    static fraction multiplication(fraction first, fraction second);
    static fraction pow(fraction first, fraction second);
    static void reduce(fraction&);
    static fraction reciprocal(fraction);
    static fraction root(fraction first, fraction second);
    static fraction sum(fraction first, fraction second);
    std::string to_string();
private:
    static fraction pow(fraction first, int second);
    static int pow(int first, int second);
    static fraction root(fraction first, int second);
    static int root(int first, int second);
};

#endif // FRACTION_H

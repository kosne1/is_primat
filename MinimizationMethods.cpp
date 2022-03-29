#include <iostream>
#include "MinimizationMethods.h"

const double eps = pow(10, -3);

double function(double x)
{
    return sin(x) - log(pow(x, 2)) - 1;
//    return pow(x, 4) + pow(x, 3);
}

double DichotomyMethod(double lowerLimit, double upperLimit)
{
    int counter = 0;
    while (round((upperLimit - lowerLimit)*100) / 100 - eps > 0)
    {
        double x1 = (upperLimit + lowerLimit) / 2 - eps;
        double y1 = function(x1);
        double x2 = (upperLimit + lowerLimit) / 2 + eps;
        double y2 = function(x2);

        if (y1 <= y2)
            upperLimit = x2;
        else
            lowerLimit = x1;

        ++counter;
    }

    std::cout << "Total operations performed: " << counter << '\n';
    std::cout << "The function was calculated: " << counter * 2 << " times\n";
    return (upperLimit+lowerLimit) / 2;
}

double GoldenRatioMethod(double lowerLimit, double upperLimit)
{
    int counter = 0;
    int functionCounter = 0;
    double goldenNumber = (3 - sqrt(5)) / 2;

    double x1 = lowerLimit + (upperLimit - lowerLimit) * goldenNumber;
    double x2 = upperLimit - (upperLimit - lowerLimit) * goldenNumber;
    double y1 = function(x1);
    double y2 = function(x2);
    functionCounter += 2;

    while (round((upperLimit - lowerLimit)*100) / 100 - eps > 0)
    {
        if (y1 < y2)
        {
            upperLimit = x1;
            x1 = lowerLimit + (upperLimit - lowerLimit) * goldenNumber;
            y1 = function(x1);
        }
        else
        {
            lowerLimit = x2;
            x2 = upperLimit - (upperLimit - lowerLimit) * goldenNumber;
            y2 = function(x2);
        }
        ++functionCounter;

        ++counter;
    }

    std::cout << "Total operations performed: " << counter << '\n';
    std::cout << "The function was calculated: " << functionCounter << " times\n";
    return (lowerLimit + upperLimit) / 2;
}

unsigned long long Fibonacci(const size_t &n)
{
    if (n < 1)
        return 0;
    unsigned long long f1 = 0;
    unsigned long long f2 = 1;
    unsigned long long fn;
    for (size_t i = 1; i < n; ++i)
    {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }

    return fn;
}

double FibonacciMethod(double lowerLimit, double upperLimit, size_t n)
{
    int counter = 0;
    int functionCounter = 0;
    double x1 = lowerLimit + (upperLimit - lowerLimit) * Fibonacci( n ) / Fibonacci( n + 2 );
    double y1 = function(x1);
    double x2 = lowerLimit +  upperLimit - x1;
    double y2 = function(x2);
    functionCounter += 2;
    while (n--)
    {
        if (y1 > y2)
        {
            lowerLimit  = x1;
            x1 = x2;
            x2 = upperLimit - (x1 - lowerLimit);
            y1 = y2;
            y2 = function(x2);
            ++functionCounter;
        }
        else
        {
            upperLimit = x2;
            x2 = x1;
            x1 = lowerLimit + (upperLimit - x2);
            y2 = y1;
            y1 = function(x1);
            ++functionCounter;
        }

        ++counter;
    }

    std::cout << "Total operations performed: " << counter << '\n';
    std::cout << "The function was calculated: " << functionCounter << " times\n";
    return (lowerLimit + upperLimit) / 2;
}

double ParabolicMethod(double x)
{
    int counter = 0;
    int functionCounter = 0;
    while ((function(x + eps) - 2 * function(x) + function(x - eps)) / (eps * eps) <= 0)
    {
        x += 0.1;
        functionCounter += 3;
    }
    double x1;
    x1 = x - 0.5 * eps * (function(x + eps) - function(x - eps)) / (function(x + eps) - 2 * function(x) + function(x - eps));
    functionCounter += 3;
    while (fabs(x1 - x) > eps) {
        x = x1;
        x1 = x - 0.5 * eps * (function(x + eps) - function(x - eps)) / (function(x + eps) - 2 * function(x) + function(x - eps));
        functionCounter += 3;
        ++counter;
    }

    std::cout << "Total operations performed: " << counter << '\n';
    std::cout << "The function was calculated: " << functionCounter << " times\n";
    return x1;
}

double BrentMethod(double lowerLimit, double upperLimit)
{
    upperLimit *= 2;
    int counter = 0;
    int functionCounter = 0;
    double GoldenNumber = (3 - sqrt(5)) / 2;
    double x = (lowerLimit + upperLimit) / 2;
    double w = x, v = x;
    double fx = function(x), fw = function(x), fv = function(x);
    double d = upperLimit - lowerLimit, e = upperLimit - lowerLimit;
    while(round(abs(upperLimit - lowerLimit)*100) / 100 - 3*eps > 0)
    {
        ++counter;
        double g = e;
        e = d;
        double numerator = pow((w - x), 2) * (fw - fv) - pow((w - x), 2) * (fw - fx);
        double denominator = 2 * ((w - x) * (fw - fv) - (w - v) * (fw - fx));
        double u = w - numerator / (denominator + pow(10,  -7));
        if ((lowerLimit + eps <= u <= upperLimit - eps) && abs(u - x) < g / 2)
            d = abs(u - x);
        else
        {
            if (x < (upperLimit - lowerLimit) / 2)
            {
                u = x + GoldenNumber * (upperLimit - x);
                d = upperLimit - x;
            }
            else
            {
                u = x - GoldenNumber * (x - lowerLimit);
                d = x - lowerLimit;
            }
        }

        if (abs(u - x) < eps)
        {
            if (u < x)
                u = x - eps;
            else if (abs(u - x) > eps)
                u = x + eps;
            else
                u = x;
        }

        double fu = function(u);
        ++functionCounter;
        if (fu < fx)
        {
            if (u >= x)
                lowerLimit = x;
            else
                upperLimit = x;
            v = w; w = x; x = u;
            fv = fw; fw = fx; fx = fu;
        }
        else
        {
            if (u >= x)
                upperLimit = u;
            else
                lowerLimit = u;
            if (fu < fw || w == x)
            {
                v = w; w = u;
                fv = fw; fw = fu;
            }
            else if (fu <= fv || v == x || v == w)
            {
                v = u;
                fv = fu;
            }
        }
    }

    std::cout << "Total operations performed: " << counter << '\n';
    std::cout << "The function was calculated: " << functionCounter << " times\n";
    return x;
}
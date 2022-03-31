#include <iostream>
#include "MinimizationMethods.h"

int main() {
    std::cout << "Minimum of f(x) on the interval [-5, 5] is :\n\n";
    std::cout << "Dichotomy Method:\n" << DichotomyMethod(-5, 5) << "\n\n";
    std::cout << "Golden Ratio Method:\n" << GoldenRatioMethod(-5, 5) << "\n\n";
    std::cout << "Fibonacci Method:\n" << FibonacciMethod(-5, 5, 21) << "\n\n";
    std::cout << "Parabolic Method:\n" << ParabolicMethod(-5, 5) << "\n\n";
    std::cout << "Brent Method:\n" << BrentMethod(-5, 5);
    return 0;
}
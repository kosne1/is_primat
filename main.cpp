#include <iostream>
#include "MinimizationMethods.h"

int main() {
    std::cout << "Minimum of f(x) on the interval [-5, 0] is :\n\n";
    std::cout << "Dichotomy Method:\n" << DichotomyMethod(1, 6) << "\n\n";
    std::cout << "Golden Ratio Method:\n" << GoldenRatioMethod(1, 6) << "\n\n";
    std::cout << "Fibonacci Method:\n" << FibonacciMethod(1, 6, 21) << "\n\n";
    std::cout << "Parabolic Method:\n" << ParabolicMethod(1, 6) << "\n\n";
    std::cout << "Brent Method:\n" << BrentMethod(1, 6);
    return 0;
}
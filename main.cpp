#include <iostream>
#include "MinimizationMethods.h"

int main() {
    std::cout << "Dichotomy Method:\n" << DichotomyMethod(0, 5) << "\n\n";
    std::cout << "Golden Ratio Method:\n" << GoldenRatioMethod(0, 5) << "\n\n";
    std::cout << "Fibonacci Method:\n" << FibonacciMethod(0, 5, 21) << "\n\n";
    std::cout << "Parabolic Method:\n" << ParabolicMethod(10) << "\n\n";
    std::cout << "Brent Method:\n" << BrentMethod(0, 5);
    return 0;
}
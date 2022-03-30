#include "cmath"
#ifndef IS_PRIMAT_LAB_1_MINIMIZATIONMETHODS_H
#define IS_PRIMAT_LAB_1_MINIMIZATIONMETHODS_H
double DichotomyMethod(double lowerLimit, double upperLimit);
double GoldenRatioMethod(double lowerLimit, double upperLimit);
double FibonacciMethod(double lowerLimit, double upperLimit, size_t n);
double ParabolicMethod(double lowerLimit, double upperLimit);
double BrentMethod(double lowerLimit, double upperLimit);
#endif //IS_PRIMAT_LAB_1_MINIMIZATIONMETHODS_H
#include "Fraction.h"
#include <iomanip>
#include <iostream>

void Fraction::setNumerator(int nu) {
    numerator = nu;
}

void Fraction::setDenominator(int de) {
    denominator = de;
}

void Fraction::getDouble() {
    double result = (numerator + 0.0) / denominator;
    if (numerator % denominator != 0) {
        std::cout << fixed << setprecision(6) << result << endl;
        return;
    }
    printf("%.0lf\n", result);
}

int findGCD(int a, int b) {
    int r = 0;
    while (a % b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}

void Fraction::outputReducedFraction() {
    if (numerator % denominator != 0) {
        int gcd = findGCD(numerator, denominator);
        std::cout << numerator / gcd << "/" << denominator / gcd << endl;
        return;
    }
    std::cout << numerator / denominator << endl;
}

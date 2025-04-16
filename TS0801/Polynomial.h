#pragma once
#include <cmath>
#include <iostream>
#include <valarray>
class Polynomial {

public:
    std::valarray<double> coefficient;

    Polynomial() = default;

    Polynomial(double* coeff, int _size)
        : coefficient(coeff,_size) {}

    Polynomial(const Polynomial& poly)
        : coefficient(poly.coefficient) {}
    
    Polynomial(std::valarray<double> coeff)
        : coefficient(std::move(coeff)) {}

    ~Polynomial() = default;

    int mySize() const {
        int count = 0;
        bool isfrontZero = true;
        for (int i = coefficient.size() - 1; i >= 0; i--) {
            if (coefficient[i] == 0 && isfrontZero) {
                continue;
            }
            isfrontZero = false;
            count++;
        }
        return count;
    }

    Polynomial& operator=(const Polynomial& rhs) {
        if (this != &rhs) {
            this->coefficient = rhs.coefficient;
        }
        return *this;
    }

    Polynomial operator+(const Polynomial& rhs) const {
        size_t maxSize = std::max(coefficient.size(), rhs.coefficient.size());

        std::valarray<double> left = coefficient;
        std::valarray<double> right = rhs.coefficient;

        if (left.size() < maxSize) {
            std::valarray<double> temp(maxSize);
            temp[std::slice(0, left.size(), 1)] = left;
            left = std::move(temp);
        }

        if (right.size() < maxSize) {
            std::valarray<double> temp(maxSize);
            temp[std::slice(0, right.size(), 1)] = right;
            right = std::move(temp);
        }

        return Polynomial(left + right);
    }
    Polynomial operator+(const double rhs) const {
        std::valarray<double> result = coefficient;
        result[0] += rhs;
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& rhs) const {
        size_t maxSize = std::max(coefficient.size(), rhs.coefficient.size());
        
        std::valarray<double> left = coefficient;
        std::valarray<double> right = rhs.coefficient;

       if (left.size() < maxSize) {
            std::valarray<double> temp(maxSize);
            temp[std::slice(0, left.size(), 1)] = left;
            left = std::move(temp);
        }

        if (right.size() < maxSize) {
            std::valarray<double> temp(maxSize);
            temp[std::slice(0, right.size(), 1)] = right;
            right = std::move(temp);
        }

        return Polynomial(left - right);
    }

    Polynomial operator-(const double rhs) const {
        std::valarray<double> result = coefficient;
        result[0] -= rhs;
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& rhs) const {
        std::valarray<double> result(mySize() + rhs.mySize() - 1);

        for (int i = 0; i < mySize(); i++) {
            for (int j = 0; j < rhs.mySize(); j++) {
                result[i + j] += coefficient[i] * rhs.coefficient[j];
            }
        }
        //(-2 + x) * (4 - 4x + x^2) = -8 + 8x - 2x^2 + 4x - 4x^2 + x^3
        return Polynomial(result);
    }
    Polynomial operator*(const double rhs) const {
        return Polynomial(coefficient * rhs);
    }
    double operator[](const int index) const {
        if (index >= mySize() || index < 0)
            return 0.0;
        return this->coefficient[index];
    }

    // left value
    double& operator[](const int index) {
        if (index >= mySize()) {
            coefficient.resize(index + 1, 0.0);
        }
        return coefficient[index];
    }

    friend Polynomial operator+(const double lhs, const Polynomial& rhs);
    friend Polynomial operator-(const double lhs, const Polynomial& rhs);
    friend Polynomial operator*(const double lhs, const Polynomial& rhs);
};

double evaluate(const Polynomial& poly, const double& var) {
    double sum = 0;
    for (int i = 0; i < poly.mySize(); i++) {
        sum += poly.coefficient[i] * pow(var, i);
    }
    return sum;
}

Polynomial operator+(const double lhs, const Polynomial& rhs) {
    return rhs + lhs;
}

Polynomial operator-(const double lhs, const Polynomial& rhs) {
    return (rhs - lhs) * -1;
}

Polynomial operator*(const double lhs, const Polynomial& rhs) {
    return rhs * lhs;
}
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Complex {
public:
    double realValue, imaginaryValue;

    Complex()
        : realValue(0)
        , imaginaryValue(0){};
    //~Complex();
    Complex(double r)
        : realValue(r)
        , imaginaryValue(0){};
    //~Complex(double r);
    Complex(double r, double i)
        : realValue(r)
        , imaginaryValue(i){};
    //~Complex(double r, double i);
    double real();
    double imag();
    double norm();
    friend double real(Complex c);
    friend double imag(Complex c);
    friend double norm(Complex c);
    Complex operator+(Complex c);
    Complex operator-(Complex c);
    Complex operator*(Complex c);
    Complex operator/(Complex c);
    friend Complex operator+(double d, Complex c);
    friend Complex operator-(double d, Complex c);
    friend Complex operator*(double d, Complex c);
    friend Complex operator/(double d, Complex c);
    friend bool operator==(Complex c1, Complex c2);
    friend ostream& operator<<(ostream& strm, const Complex& c);
    friend istream& operator>>(istream& strm, Complex& c);
};

double Complex::real() {
    return realValue;
}

double Complex::imag() {
    return imaginaryValue;
}

double Complex::norm() {
    return (sqrt(pow(realValue, 2) + pow(imaginaryValue, 2)));
}

double real(Complex c) {
    return c.realValue;
}

double imag(Complex c) {
    return c.imaginaryValue;
}

double norm(Complex c) {
    return (sqrt(pow(c.realValue, 2) + pow(c.imaginaryValue, 2)));
}

Complex Complex::operator+(Complex rhs) {
    Complex result;
    result.realValue = realValue + rhs.realValue;
    result.imaginaryValue = imaginaryValue + rhs.imaginaryValue;
    return result;
}

Complex operator+(double lhs, Complex rhs) {
    Complex result;
    result.realValue = lhs + rhs.realValue;
    result.imaginaryValue = rhs.imaginaryValue;
    return result;
}

Complex Complex::operator-(Complex rhs) {
    Complex result;
    result.realValue = realValue - rhs.realValue;
    result.imaginaryValue = imaginaryValue - rhs.imaginaryValue;
    return result;
}

Complex operator-(double lhs, Complex rhs) {
    Complex result;
    result.realValue = lhs - rhs.realValue;
    result.imaginaryValue = rhs.imaginaryValue * -1;
    return result;
}

Complex Complex::operator*(Complex rhs) {
    Complex result;
    double r = realValue * rhs.realValue - imaginaryValue * rhs.imaginaryValue;
    double i = realValue * rhs.imaginaryValue + imaginaryValue * rhs.realValue;
    result.realValue = r;
    result.imaginaryValue = i;
    return result;
}

Complex operator*(double lhs, Complex rhs) {
    Complex result;
    result.realValue = lhs * rhs.realValue;
    result.imaginaryValue = lhs * rhs.imaginaryValue;
    return result;
}

Complex Complex::operator/(Complex rhs) {
    Complex result;
    double denominator = pow(rhs.realValue, 2) + pow(rhs.imaginaryValue, 2);
    double r = realValue * rhs.realValue + imaginaryValue * rhs.imaginaryValue;
    double i = imaginaryValue * rhs.realValue - realValue * rhs.imaginaryValue;
    result.realValue = r / denominator;
    result.imaginaryValue = i / denominator;
    return result;
}

Complex operator/(double lhs, Complex rhs) {
    Complex result;
    double denominator = pow(rhs.realValue, 2) + pow(rhs.imaginaryValue, 2);
    double r = lhs * rhs.realValue;
    double i = lhs * rhs.imaginaryValue * -1;
    result.realValue = r / denominator;
    result.imaginaryValue = i / denominator;
    return result;
}

ostream& operator<<(ostream& strm, const Complex& c) {
    strm << c.realValue << " + " << c.imaginaryValue << "*i";
    return strm;
}
istream& operator>>(istream& strm, Complex& c) {
    std::string input;
    int realnumber = 0;
    char op;
    int imagnumber = 0;
    strm >> input >> input >> realnumber >> op >> imagnumber >> input;
    imagnumber = (op == '+') ? imagnumber : imagnumber * -1;
    c.realValue = realnumber;
    c.imaginaryValue = imagnumber;

    return strm;
}

bool operator==(Complex lhs, Complex rhs) {
    return (lhs.realValue == rhs.realValue && lhs.imaginaryValue == rhs.imaginaryValue) ? true : false;
}

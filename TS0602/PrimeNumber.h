#include<cmath>
class PrimeNumber {
public:
    int value;
    int get();
    PrimeNumber()
        : value(1){};
    PrimeNumber(int _value)
        : value(_value){};
    PrimeNumber& operator++();
    PrimeNumber operator++(int);
    PrimeNumber& operator--();
    PrimeNumber operator--(int);
};

int PrimeNumber::get() {
    return value;
}

bool isPrime(int num) {
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;

    for (int i = 3; i <= sqrt(num); i += 2)
        if (num % i == 0)
            return false;
    return true;
}

int nextPrime(int n) {
    int next = n + 1;
    while (!isPrime(next)) {
        next++;
    }
    return next;
}

int previousPrime(int n) {
    int prev = n - 1;
    while (prev > 1) {
        if (isPrime(prev)) {
            return prev;
        }
        prev--;
    }
    return 1;
}

PrimeNumber& PrimeNumber::operator++() {
    value = nextPrime(value);
    return *this;
}

PrimeNumber PrimeNumber::operator++(int n) {
    PrimeNumber result;
    result.value = value;
    value = nextPrime(value);
    return result;
}

PrimeNumber& PrimeNumber::operator--() {
    if (value == 2) {
        value = 1;
        return *this;
    }
    value = previousPrime(value);
    return *this;
}

PrimeNumber PrimeNumber::operator--(int n) {
    PrimeNumber result;
    result.value = value;
    if (value == 2) {
        value = 1;
        return result;
    }
    value = previousPrime(value);
    return result;
}

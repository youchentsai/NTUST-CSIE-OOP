#include "VecNf.h"

VecNf& VecNf::operator=(const VecNf& rhs) {
    if (this != &rhs) {
        this->vec = rhs.vec;
    }
    std::cout << "ASSIGNMENT!!!" << std::endl;
    return *this;
}

double VecNf::operator[](int index) const {
    if (index >= vec.size()) {
        return 0.0;
    }

    return this->vec[index];
}

double& VecNf::operator[](int index) {
    if (index >= vec.size()) {
        static double zero = 0.0;
        return zero;
    }

    return this->vec[index];
}

VecNf VecNf::operator+(const VecNf& rhs) const {
    std::vector<double> result;
    if (vec.size() != rhs.vec.size()) {
        std::cout << "dimensions inconsistent" << std::endl;
        result.push_back(0.0);
        return result;
    }
    for (int i = 0; i < vec.size(); i++) {
        result.push_back(vec[i] + rhs.vec[i]);
    }
    
    return VecNf(result);
}

VecNf VecNf::operator-(const VecNf& rhs) const {
    std::vector<double> result;
    if (vec.size() != rhs.vec.size()) {
        std::cout << "dimensions inconsistent" << std::endl;
        result.push_back(0.0);
        return result;
    }
    for (int i = 0; i < vec.size(); i++) {
        result.push_back(vec[i] - rhs.vec[i]);
    }

    return VecNf(result);
}

double VecNf::operator*(const VecNf& rhs) const {
    double sum = 0;
    if (vec.size() != rhs.vec.size()) {
        std::cout << "dimensions inconsistent" << std::endl;
        return 0.0;
    }
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i] * rhs.vec[i];
    }
    return sum;
}

VecNf VecNf::operator*(const double rhs) const {
    std::vector<double> result(vec.size(),0);
    std::copy(vec.begin(), vec.end(), result.begin());
    for (int i = 0; i < result.size(); i++) {
        result[i] *= rhs;
    }
    return VecNf(result);
}

VecNf operator*(const double lhs, const VecNf& rhs){
    std::vector<double> result(rhs.vec.size(), 0);
    std::copy(rhs.vec.begin(), rhs.vec.end(), result.begin());
    for (int i = 0; i < result.size(); i++) {
        result[i] *= lhs;
    }
    return VecNf(result);
}

int VecNf::Size() {
    return vec.size();
}
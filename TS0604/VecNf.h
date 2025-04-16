#pragma once
#ifndef VECNF_H
#    define VECNF_H
#    include <cmath>
#    include <iostream>
#    include <vector>

class VecNf {
public:
    std::vector<double> vec;

    VecNf() {
        vec = std::vector<double>(1, 0);
    }
    VecNf(float* dest, int cnt) {
        vec = std::vector<double>(cnt);
        for (int i = 0; i < cnt; i++) {
            vec[i] = (dest[i]);
        }
    }

    VecNf(const VecNf& rhs) {
        vec = std::vector<double>(rhs.vec.size());
        vec = std::move(rhs.vec);
    }

    VecNf(const std::vector<double>& _vec) {
        vec = std::vector<double>(_vec.size());
        vec = std::move(_vec);
    }

    double operator[](int index) const;
    double& operator[](int index);

    VecNf& operator=(const VecNf& rhs);

    int Size();

    VecNf operator+(const VecNf& rhs) const;

    VecNf operator-(const VecNf& rhs) const;

    double operator*(const VecNf& rhs) const;
    VecNf operator*(const double rhs) const;
    friend VecNf operator*(const double lhs,const VecNf& rhs);
};

#endif // !VECNF_H

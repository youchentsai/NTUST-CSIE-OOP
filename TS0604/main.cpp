#include "VecNf.h"
#include <iostream>
using namespace std;

void doNothing(VecNf tar) {
    return;
}

int main() {
    VecNf empty;
    float a_value[] = {3.0, 2.0};
    float b_value[] = {1, 2, 3};
    float c_value[] = {6, 5, 4};
    VecNf A(a_value, 2);
    VecNf B(b_value, 3);
    VecNf C(c_value, 3);
    VecNf T;
    T = A; // Assignment
    for (int i = 0; i < T.Size(); i++) {
        cout << T[i] << " ";
    }
    cout << endl;

    T = B; // Assignment
    for (int i = 0; i < T.Size(); i++) {
        cout << T[i] << " ";
    }
    cout << endl;

    T = B + C; // Vector addition
    for (int i = 0; i < T.Size(); i++) {
        cout << T[i] << " ";
    }
    cout << endl;
    T = A - B;
    double a = A * B;
    T[0] = 1;

    cout << C * B << endl; // Scale

    cout << A * C << endl; // Inconsistent

    T = 5.0 * A; 
    //cout << 9 * C << endl;
    return 0;
}
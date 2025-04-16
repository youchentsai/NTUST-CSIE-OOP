#include <iostream>

int GCD(int a, int b) {
    int r = 0;
    while (a % b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}

int main() {
    using namespace std;
    int a, b;
    while (true) {
        cin >> a >> b;
        if (cin.eof())
            return 0;
        cout << GCD(a, b) << endl;
    }
}
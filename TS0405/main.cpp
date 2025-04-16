#include <iostream>

void collatz(int start, int end, int& max) {
    for (int i = start; i <= end; i++) {
        int count = 0;
        int input = i;
        while (input != 1) {
            if (input % 2 == 0) {
                input /= 2;
                count++;
                continue;
            }
            input = input * 3 + 1;
            count++;
        }
        count++;
        if (count > max) {
            max = count;
        }
    }
}

int main() {
    using namespace std;
    int inputA = 0, inputB = 0;
    while (cin >> inputA >> inputB && !cin.eof()) {
        int maxCount = 0;
        int start = min(inputA, inputB);
        int end = max(inputA, inputB);
        collatz(start, end, maxCount);
        cout << inputA << " " << inputB << " " << maxCount << endl;
    }
}
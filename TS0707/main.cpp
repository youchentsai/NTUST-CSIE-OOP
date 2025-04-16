#include <iostream>
#include <string>
#include <vector>

int main() {
    using namespace std;
    // input

    vector<int> addition;
    vector<int> difference;
    vector<int> mutiplication;
    string inputA, inputB;
    while (cin >> inputA >> inputB && !cin.eof()) {

        // convert into same digitcount
        int digitCount = (inputA.length() >= inputB.length()) ? inputA.length() : inputB.length();
        if (inputA.length() == digitCount) {
            int lengthB = inputB.length();
            for (int i = 0; i < digitCount - lengthB; i++) {
                inputB.insert(inputB.begin() + i, '0');
            }
        } else if (inputB.length() == digitCount) {
            int lengthA = inputA.length();
            for (int i = 0; i < digitCount - lengthA; i++) {
                inputA.insert(inputA.begin() + i, '0');
            }
        }

        // addition
        int carryFlag = 0, additionCount = digitCount - 1;
        addition.clear();
        while (additionCount >= 0) {
            int a = inputA[additionCount] - '0'; // convert into interger
            int b = inputB[additionCount] - '0';
            additionCount--;
            addition.push_back((a + b + carryFlag) % 10);
            if (a + b + carryFlag >= 10) {
                carryFlag = 1;
                continue;
            }
            carryFlag = 0;
        }
        if (carryFlag == 1) {
            addition.push_back(1);
        }

        // difference
        difference.clear();
        int borrowFlag = 0, differenceCount = digitCount - 1;
        bool isNegative = false;

        if (inputA == inputB) {
            difference.push_back(0);
        } else {
            bool isAGreater = inputA > inputB;
            if (!isAGreater) {
                swap(inputA, inputB);
                isNegative = true;
            }
            while (differenceCount >= 0) {
                int a = inputA[differenceCount] - '0';
                int b = inputB[differenceCount] - '0';
                int diff = a - b - borrowFlag;
                if (diff < 0) {
                    diff += 10;
                    borrowFlag = 1;
                } else {
                    borrowFlag = 0;
                }
                difference.push_back(diff);
                differenceCount--;
            }
            // remove front 0
            while (difference.size() > 1 && difference.back() == 0) {
                difference.pop_back();
            }
        }
        // mutiplication
        int m = inputA.size(), n = inputB.size();
        vector<int> multiplication(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int a = inputA[i] - '0', b = inputB[j] - '0';
                int sum = a * b + multiplication[i + j + 1];
                multiplication[i + j + 1] = sum % 10; //先將carry放到前一位中
                multiplication[i + j] += sum / 10;    //目前這一位
            }
        }

        string result;
        for (int num : multiplication) {
            if (!(result.empty() && num == 0)) {
                result += (num + '0');
            }
        }

        if (result.empty())
            result = "0";

        // output
        for (int i = addition.size() - 1; i >= 0; i--) {
            cout << addition[i];
        }
        cout << endl;
        if (isNegative)
            cout << "-";
        for (int i = difference.size() - 1; i >= 0; i--) {
            cout << difference[i];
        }
        cout << endl;
        cout << result << endl;
    }
}
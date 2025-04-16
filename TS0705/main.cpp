#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    using namespace std;
    int count;
    string numberA, numberB, result;
    unordered_map<string, string> operationTable{{"VV", "V"}, {"VU", "U"}, {"UV", "U"},  {"VC", "C"},  {"CV", "C"},  {"VD", "D"},  {"DV", "D"},  {"UU", "C"},
                                                 {"UC", "D"}, {"CU", "D"}, {"UD", "VU"}, {"DU", "VU"}, {"CC", "VU"}, {"CD", "UU"}, {"DC", "UU"}, {"DD", "CU"}};
    cout << "COWCULATIONS OUTPUT" << endl;

    cin >> count;
    for (int i = 0; i < count; i++) {
        // input
        cin >> numberA >> numberB;
        for (int j = 0; j < 3; j++) {
            char op;
            cin >> op;
            bool carry = false;
            if (numberA.length() < numberB.length()) {
                int LengthB = numberB.length();
                int LengthA = numberA.length();
                for (int i = 0; i < LengthB - LengthA; i++) {
                    numberA.insert(numberA.begin(), 'V');
                }
            }
            switch (op) {
            case 'A':
                for (int k = numberB.length() - 1; k >= 0; k--) {
                    stringstream ss;
                    ss << numberA[k] << numberB[k];
                    string key = ss.str();
                    int carryCount = 0;
                    string result = "";
                    if (operationTable.find(key) != operationTable.end()) {
                        result = operationTable[key];
                        numberB[k] = result[0];
                        carryCount += (result.length() == 2 ? 1 : 0);
                        // previous carry
                        if (carry == true) {
                            stringstream ss1;
                            ss1 << numberB[k] << "U";
                            string key = ss1.str();
                            result = operationTable[key];
                            numberB[k] = result[0];
                        }
                        carry = (result.length() == 2 || carryCount == 1) ? true : false;
                    }
                    if (k == 0 && carry == true) {
                        numberB.insert(numberB.begin(), 'U');
                    }
                }
                break;
            case 'R':
                numberB.pop_back();
                numberB.insert(numberB.begin(), 'V');
                break;
            case 'L':
                numberB.insert(numberB.end(), 'V');
                break;
            case 'N':
                // do nothing
                break;
            default:
                break;
            }
        }
        int count = numberB.length();
        for (int j = 0; j < 8 - count; j++) {
            numberB.insert(numberB.begin(), 'V');
        }
        string answer;
        cin >> answer;
        cout << (numberB == answer ? "YES" : "NO") << endl;
    }
    cout << "END OF OUTPUT" << endl;
}
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    using namespace std;

    string input;
    unordered_map<char, vector<string>> numberTable = {
        {'0', {" _ ", "| |", "|_|"}}, {'1', {"   ", "  |", "  |"}}, {'2', {" _ ", " _|", "|_ "}}, {'3', {" _ ", " _|", " _|"}}, {'4', {"   ", "|_|", "  |"}},
        {'5', {" _ ", "|_ ", " _|"}}, {'6', {" _ ", "|_ ", "|_|"}}, {'7', {" _ ", "  |", "  |"}}, {'8', {" _ ", "|_|", "|_|"}}, {'9', {" _ ", "|_|", " _|"}}};

    while (true) {
        getline(cin,input);
        if (cin.eof())
            return 0;

        // store 3 lines of output
        vector<string> result(3, "");

        for (char digit : input)
        {
            if (digit > '9' || digit < '0')
                continue;
            if (numberTable.find(digit) != numberTable.end()) {
                result[0] += numberTable[digit][0];
                result[1] += numberTable[digit][1];
                result[2] += numberTable[digit][2];
            }
        }

        for (string line : result) {
            cout << line << endl;
        }

        /*
        * output sample
          _  _     _  _  _  _  _  _
        | _| _||_||_ |_   ||_||_|| |
        ||_  _|  | _||_|  ||_| _||_|

        */
    }
}
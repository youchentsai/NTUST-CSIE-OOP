#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<int, char> hexTable = {{0, '0'}, {1, '1'}, {2, '2'},  {3, '3'},  {4, '4'},  {5, '5'},  {6, '6'},  {7, '7'},
                                          {8, '8'}, {9, '9'}, {10, 'A'}, {11, 'B'}, {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'}};

std::unordered_map<char, int> reverseHexTable = {{'0', 0}, {'1', 1}, {'2', 2},  {'3', 3},  {'4', 4},  {'5', 5},  {'6', 6},  {'7', 7},
                                                 {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}};

void Set(std::string value, int position, std::vector<int>& memory) {
    using namespace std;
    int length = value.length();
    int index = 0;
    int memoSize = memory.size();
    for (int i = 0; i < length; i++) {
        if ((position + index) > (memoSize - 1))
            break;
        memory[position + index] = value[i];
        index++;
    }
}

void Set(long long value, int position, std::vector<int>& memory, int _size) {
    using namespace std;
    vector<char> hexNumber;

    // convert into hex
    if (value == 0) {
        hexNumber.push_back('0');
    } else {
        int reminder = 0;
        while (value > 0) {
            reminder = value % 16;
            hexNumber.insert(hexNumber.begin(), hexTable[reminder]);
            value /= 16;
        }
    }
    if (hexNumber.size() < _size * 2) {
        int count = _size * 2 - hexNumber.size();
        for (int i = 0; i < count; i++) {
            hexNumber.insert(hexNumber.begin(), '0');
        }
    }
    // return back to interger
    int size = hexNumber.size();
    int sum = 0, count = 0, index = 0;
    for (int i = size - 1; i >= 0; i--) {
        sum += reverseHexTable[hexNumber[i]] * pow(16, count);
        count++;
        if (count == 2 || i == 0) {
            if ((position + index) >= memory.size())
                break;
            memory[position + index] = sum;
            sum = 0;
            count = 0;
            index++;
        }
    }
}

int main() {
    using namespace std;
    int size = 0, commandCount = 0;
    unordered_map<string, int> dataTypeTable{{"char", 1}, {"short", 2}, {"int", 4}, {"String", 1}};
    cin >> size >> commandCount;
    vector<int> memory(size, 0);
    for (int i = 0; i < commandCount; i++) {
        string command, type, value;
        int position = 0;
        cin >> command;
        if (command == "Set") {
            cin >> position >> type;
            cin.get();
            getline(cin, value);

            if (position + dataTypeTable[type] > size || position > memory.size() - 1 || position < 0) {
                cout << "Violation Access." << endl;
            }
            if (type == "String") {
                if (position + value.length() > size) {
                    cout << "Violation Access." << endl;
                }
            }
            if (type == "String") {
                Set(value, position, memory);
            } else if (type == "int") {
                Set(stoll(value), position, memory, 4);
            } else if (type == "short") {
                Set(stoi(value), position, memory, 2);
            } else if (type == "char") {
                char i = stoi(value);
                stringstream ss;
                ss << i;
                Set(ss.str(), position, memory);
            }
        } else if (command == "Get") {
            cin >> position >> type;
            if (position + dataTypeTable[type] > size || position > memory.size() - 1 || position < 0) {
                cout << "Violation Access." << endl;
                continue;
            }
            if (type == "String") {
                int index = 0;
                while (memory[position + index] != 0) {
                    if ((position + index) >= memory.size())
                        break;
                    char c = memory[position + index];
                    if (memory[position + index] <= 127 && memory[position + index] >= 0) {
                        cout << c;
                    } else {
                        cout << memory[position + index];
                    }
                    index++;
                    if (position + index >= memory.size())
                        break;
                }
                cout << endl;
            } else if (type == "char") {
                if (memory[position] > 127 || memory[position] < 0) {
                    cout << memory[position] << endl;
                    continue;
                }
                char i = memory[position];
                cout << i << endl;
            } else if (type == "int") { 
                unsigned long long int result = 0;
                for (int i = position; i < position + 4; i++) {
                    result |= memory[i] << (8 * i);
                }
                cout << result << endl;
            } else if (type == "short") {
                unsigned long long int result = 0;
                for (int i = position; i < position + 2; i++) {
                    result |= memory[i] << (8 * i);
                }
                cout << result << endl;
            }
        }
    }
}
#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    using namespace std;
    unordered_set<string> lines;
    string longestReversal;
    while (true) {
        if (cin.eof())
            break;
        string fileInput = "";
        cin >> fileInput;
        lines.insert(fileInput);
    }

    for (unordered_set<string>::const_iterator it = lines.begin(); it != lines.end(); ++it) {
        string reverseWord = *it;
        reverse(reverseWord.begin(), reverseWord.end());

        if (reverseWord != *it && lines.count(reverseWord)) {
            string result = min(*it, reverseWord);
            if (result.length() > longestReversal.length()) {
                longestReversal = result;
            }
        }
    }

    cout << longestReversal << endl;
    return 0;
}
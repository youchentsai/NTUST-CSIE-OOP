#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

std::unordered_map<char, std::unordered_set<char>> transTable;

void checkCanTransfer(bool& result, char key, char destination, int searchCount) {
    if (transTable[key].count(destination)) {
        result = true;
        return;
    }
    // at most 26 alphabet
    if (searchCount > 26) { 
        result = false;
        return;
    }
    for (std::unordered_set<char>::const_iterator it = transTable[key].begin(); it != transTable[key].end(); ++it) {
        if (result)
            return;
        checkCanTransfer(result, *it, destination, searchCount + 1);
    }
        
}

int main() {
    using namespace std;
    char source, destination;
    while (true) {
        char source, destination;
        int contvertPairCount = 0, compareCount = 0;
        unordered_map<char, unordered_set<char>> transferTable;
        cin >> contvertPairCount >> compareCount;
        if (contvertPairCount == 0 && compareCount == 0)
            break;
        // input transfer Code
        for (int i = 0; i < contvertPairCount; i++) {
            cin >> source >> destination;
            transferTable[source].insert(destination);
        }
        string w1, w2;
        // input compare Word
        for (int i = 0; i < compareCount; i++) {
            cin >> w1 >> w2;
            if (w1.length() != w2.length()) {
                cout << "no" << endl;
                continue;
            }
            if (w1 == w2) {
                cout << "yes" << endl;
                continue;
            }
            bool isValid = true;
            transTable = transferTable;
            for (int i = 0; i < w1.length(); i++) {
                if (w1[i] == w2[i])
                    continue;
                if (transferTable.find(w1[i]) == transferTable.end()) {
                    isValid = false;
                    break;
                }
                bool result = false;
                checkCanTransfer(result, w1[i] , w2[i], 0);
                if (result == false) {
                    isValid = false;
                    break;
                }
            }
            cout << (isValid ? "yes" : "no") << endl;
        }
    }

    return 0;
}
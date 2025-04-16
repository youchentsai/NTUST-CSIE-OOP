#include <iostream>
#include <vector>
#include <string>

int main() {
    using namespace std;
    vector<vector<int>> sudokuBoard(9,vector<int>(9,0));
    bool isValid = true;
    string input;
    //input
    while (true) {
        for (int i = 0; i < 9; i++) {
            getline(cin, input);
            if (cin.eof())
                return 0;
            int index = 0;
            for (char item : input) {
                if (item == ',')
                    continue;
                if (item > '9' || item < '1')
                {
                    isValid = false;
                    break;
                }
                sudokuBoard[i][index] = item - '0';
                index++;
            }
        }

        // row & col
        isValid = [&]() {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    for (int k = j + 1; k < 9; k++) {
                        if (sudokuBoard[i][j] == sudokuBoard[i][k]) {
                            return false;
                        }
                        if (sudokuBoard[j][i] == sudokuBoard[k][i]) {
                            return false;
                        }
                    }
                }
            }
        }();

        isValid = [&]() {
            int X[9] = {1, 4, 7, 1, 4, 7, 1, 4, 7};
            int Y[9] = {1, 1, 1, 4, 4, 4, 7, 7, 7};
            vector<int> subArray;
            for (int i = 0; i < 9; i++) {
                for (int j = -1; j <= 1; j++) {
                    for (int k = -1; k <= 1; k++) {
                        subArray.push_back(sudokuBoard[Y[i] + j][X[i] + k]);
                    }
                }
            }
            for (int i = 0; i < 9; i++) {
                for (int j = i + 1; j < 9; j++) {
                    if (subArray[i] == subArray[j]) {
                        return false;
                    }
                }
            }
            return true;
        }();

        cout << (isValid ? "True" : "False") << endl;
    }
}

/* test data
1,2,6,1,5,4,3,9,7
9,6,5,3,2,7,1,4,8
3,4,8,6,8,9,7,5,2
5,9,3,4,6,8,2,7,1
4,7,2,5,1,3,6,8,9
6,1,8,9,7,2,4,3,5
7,8,6,2,3,5,9,1,4
1,5,4,7,9,6,8,2,3
2,3,9,8,4,1,5,6,7
*/

/*
8,2,7,1,5,4,3,9,6
9,6,5,3,2,7,1,4,8
3,4,1,6,8,9,7,5,2
5,9,3,4,6,8,2,7,1
4,7,2,5,1,3,6,8,9
6,1,8,9,7,2,4,3,5
7,8,6,2,3,5,9,1,4
1,5,4,7,9,6,8,2,3
2,3,9,8,4,1,5,6,7
*/

/*
1,2,6,1,5,4,3,9,7
9,6,5,3,2,7,1,4,8
3,4,8,6,8,9,7,5,2
5,9,3,4,6,8,2,7,1
4,7,2,5,1,3,6,8,9
6,1,8,9,7,2,4,3,5
7,8,6,2,3,5,0,1,4
1,5,4,7,9,6,8,2,3
2,3,9,8,4,7,5,6,1
*/

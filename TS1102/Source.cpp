#include <iostream>
#include <vector>

int main() {
    using namespace std;
    int rowA, colA, rowB, colB;

    cin >> rowA >> colA >> rowB >> colB;
    vector<vector<double>> martixA(rowA, vector<double>(colA, 0));
    vector<vector<double>> martixB(rowB, vector<double>(colB, 0));
    double input = 0;
    // input
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            cin >> input;
            martixA[i][j] = input;
        }
    }
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            cin >> input;
            martixB[i][j] = input;
        }
    }
    // process
    if (colA != rowB) {
        cout << "Matrix multiplication failed." << endl;
        return 0;
    }
    vector<vector<double>> result(rowA, vector<double>(colB, 0));
    for (int i = 0; i < rowA; i++) {
        for (int k = 0; k < colB; k++) {
            double sum = 0;
            for (int j = 0; j < colA; j++) {
                sum += (martixA[i][j] * martixB[j][k]);
            }
            result[i][k] = sum;
        }
    }

    // output
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            if (j == colB - 1) {
                cout << result[i][j];
                continue;
            }
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
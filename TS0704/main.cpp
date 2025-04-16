#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    using namespace std;

    string inputA, inputB;

    while (getline(cin, inputA) && getline(cin, inputB)) {
        if (cin.eof())
            return 0;

        // process
        int m = inputA.length(), n = inputB.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // initial DP
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;
        for (int j = 0; j <= n; j++)
            dp[0][j] = j;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (inputA[i - 1] == inputB[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
                }
            }
        }
        cout << dp[m][n] << endl;
    }
}
// Taken from the book Introduction to Algorithms, Third Ed. (CLRS)
// Section 15.4 Longest common subsequence

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lcs(string x, string y) {
    vector<vector<int>> dp(x.length() + 1, vector<int>(y.length() + 1, 0));

    for(int i = 1; i <= x.length(); i++) {
        for(int j = 1; j <= y.length(); j++) {
            if(x[i] == y[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[x.length()][y.length()];
}

int main() {
    string x = "ABCBDAB";
    string y = "BDCABA";

    cout << lcs(x, y) << endl;

    return 0;
}
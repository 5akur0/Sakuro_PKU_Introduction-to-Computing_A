#include <bits/stdc++.h>
using namespace std;

// dp[n][k] = dp[n - k][k] + dp[n - 1][k - 1]

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= k; ++j) {
            if (i >= j) {
                dp[i][j] = dp[i - j][j] + dp[i - 1][j - 1];
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}
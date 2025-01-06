#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; int k;
    cin >> s >> k;
    int n = s.size();
    // n > k
    unsigned long long dp[n][k + 1]; // dp[i][j] 表示第 0 - i 个字符（共 i + 1 个）插入 j 个乘号达到的最大乘积
    // 当 i < j 时，无法插入，dp[i][j] = 0
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= k; ++j) {
            dp[i][j] = 0;
        }
    }
    // 当 i = j 时，dp[i][j] = s[0] * s[1] * ... * s[i]
    for (int i = 0; i <= k; ++i) {
        dp[i][i] = 1;
        for (int t = 0; t <= i; ++t) {
            dp[i][i] *= s[t] - '0';
        }
    }
    for (int i = 0; i < n; ++i) {
        dp[i][0] = stoi(s.substr(0, i + 1));
    }
    // 状态转移方程：dp[i][j] = max(dp[k][j - 1] * (s[k + 1, ..., i])), 0 <= k < i
    for (int j = 1; j <= k; ++j) {
        for (int i = j + 1; i < n; ++i) {
            dp[i][j] = 0;
            for (int k = 0; k < i; ++k) {
               dp[i][j] = max(dp[i][j], dp[k][j - 1] * stoi(s.substr(k + 1, i - k)));
            }
        }
    }

    cout << dp[n - 1][k] << endl;
    return 0;
}
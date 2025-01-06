#include <bits/stdc++.h>
using namespace std;


// 需要高精度………………算法没问题
int main() {
    int n, m;
    cin >> n >> m;

    int ANS = 0;

    for (int _ = 0; _ < n; _++) {
        vector<long long> input(m);
        for (int i = 0; i < m; ++i) {
            cin >> input[i];
        }

        vector<vector<long long>> dp(m + 1, vector<long long>(m + 1));
        // dp[i][j] = max(dp[i][j - 1] + 2^(i + j) * input[m - j], dp[i - 1][j] + 2^(i + j) * input[i - 1])
        long long cur_sum = 0;
        dp[0][0] = 0;
        for (int j = 1; j <= m; ++j) {
            cur_sum += input[m - j] * pow(2, j);
            dp[0][j] = cur_sum;
        }

        cur_sum = 0;
        for (int i = 1; i <= m; ++i) {
            cur_sum += input[i - 1] * pow(2, i);
            dp[i][0] = cur_sum;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = max(dp[i][j - 1] + pow(2, i + j) * input[m - j], dp[i - 1][j] + pow(2, i + j) * input[i - 1]);
            }
        }

        long long ans = INT_MIN;
        for (int i = 0; i <= m; ++i) {
            ans = max(ans, dp[i][m - i]);
        }

        ANS += ans;
    }

    cout << ANS << endl;
    return 0;
}
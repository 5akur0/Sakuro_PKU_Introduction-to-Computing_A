#include <bits/stdc++.h>
using namespace std;

int n, m;
int input[55];
int nums[55];
int min_ans = INT_MAX;
int max_ans = 0;
int dp[55][15];
int sum[55];

int mod(int k) {
    return ((k % 10) + 10) % 10;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> input[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n + 1 - i; ++j) {
            nums[j] = input[j + i - 1];
        }
        for (int j = n - i + 2; j <= n; ++j) {
            nums[j] = input[j + i - 1 - n];
        }
        sum[0] = 0;
        for (int j = 1; j <= n; ++j) {
            sum[j] = sum[j - 1] + nums[j];
        }
        // max
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= n; ++j) {
            dp[1][j] = mod(sum[j]);
        }

        for (int k = 2; k <= m; ++k) {
            for (int j = k; j <= n; ++j) {
                dp[k][j] = INT_MIN;
                for (int t = k - 1; t < j; ++t) {
                    dp[k][j] = max(dp[k][j], dp[k - 1][t] * mod(sum[j] - sum[t]));
                }
            }
        }
        max_ans = max(dp[m][n], max_ans);
        
        // min
        memset(dp, 100, sizeof(dp));
        for (int j = 1; j <= n; ++j) {
            dp[1][j] = mod(sum[j]);
        }
        for (int k = 2; k <= m; ++k) {
            for (int j = k; j <= n; ++j) {
                for (int t = k - 1; t < j; ++t) {
                    dp[k][j] = min(dp[k][j], dp[k - 1][t] * mod(sum[j] - sum[t]));
                }
            }
        }
        min_ans = min(dp[m][n], min_ans);
    }
    cout << min_ans << endl;
    cout << max_ans << endl;
}
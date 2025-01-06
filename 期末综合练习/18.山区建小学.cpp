#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int distance[m + 1][m + 1];
    for (int i = 1; i <= m - 1; ++i) {
        cin >> distance[i][i + 1];
        distance[i + 1][i] = distance[i][i + 1];
        distance[i][i] = 0;
    }
    distance[m][m] = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = i + 2; j <= m; ++j) {
            distance[i][j] = distance[i][j - 1] + distance[j - 1][j];
            distance[j][i] = distance[i][j];
        }
    }
    int cost[m + 1][m + 1];
    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= m; ++j) {
            cost[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = i + 1; j <= m; ++j) {
            int mid = (i + j) / 2;
            for (int k = i; k <= j; ++k) {
                cost[i][j] += distance[k][mid];
            }
        }
    }
    // 用dp[i][j]表示考虑到前i个村庄，建j个小学且的最小花费
    int dp[m + 1][n + 1];
    for (int i = 1; i <= m; ++i) {
        dp[i][1] = cost[1][i];
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 2; j <= n; ++j) {
            dp[i][j] = INT_MAX;
            for (int k = j - 1; k < i; ++k) {
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + cost[k + 1][i]);
            }
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}
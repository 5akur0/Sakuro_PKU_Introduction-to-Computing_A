#include <bits/stdc++.h>
using namespace std;

long long use[1005];
long long reward[1005];
long long dp[2005][2005];
long long basic;

int main() {
    int n, x;
    cin >> n >> x;
    long long lose, win;
    for (int i = 1; i <= n; ++i) {
        cin >> lose >> win >> use[i];
        reward[i] = win - lose;
        basic += lose;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            if (j < use[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - use[i]] + reward[i]);
            }
        }
    }
    cout << 5 * (basic + dp[n][x]) << endl;
}
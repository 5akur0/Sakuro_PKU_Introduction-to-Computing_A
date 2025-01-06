#include <bits/stdc++.h>
using namespace std;

// F(n,m)=F(n-1,m-1)+m*F(n-1,m)

int main() {
    int n;
    while (cin >> n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        if (n == -1) {
            break;
        }
        if (n == 0) {
            cout << 1 << endl;
            continue;
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (dp[i][j] != -1) {
                    continue;
                }
                if (i == 0 || i == j || j == 1 || j == 0) {
                    dp[i][j] = 1;
                }
                else if (j > i) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] + j * dp[i - 1][j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += dp[n][i];
        }
        cout << ans << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int m, n;
int dp[102][52][52];
int hearts[52][52];

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> hearts[i][j];
        }
    }
    dp[3][1][2] = hearts[1][2] + hearts[2][1];
    for (int s = 4; s <= m + n - 1; ++s) {
        for (int i = 1; i <= s - 2; ++i) {
            for (int j = i + 1; j <= s - 1; ++j) {
                dp[s][i][j] = max(
                    max(dp[s - 1][i - 1][j - 1], 
                        dp[s - 1][i][j]), 
                    max(dp[s - 1][i - 1][j], 
                        dp[s - 1][i][j - 1]));
                dp[s][i][j] += hearts[i][s - i] + hearts[j][s - j];
            }
        }
    }
    cout << dp[m + n - 1][m - 1][m] << endl;
}
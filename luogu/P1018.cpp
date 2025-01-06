#include <bits/stdc++.h>
using namespace std;

char s[45];
unsigned long dp[45][10]; // 前i位分割成j段最大乘积
int n;
int k;

int GetNum(int l, int r) {
    int res = 0;
    for (int i = l; i <= r; ++i) {
        res = res * 10 + s[i] - '0';
    }
    return res;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] * 10 + s[i] - '0';
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int l = 1; l < i; ++l) {
                dp[i][j] = max(dp[i][j], dp[l][j - 1] * GetNum(l + 1, i));
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}
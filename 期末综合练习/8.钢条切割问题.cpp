#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int input[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> input[i];
    }
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = input[i];
        for (int j = 1; j < i; ++j) {
            dp[i] = max(dp[i], input[j] + dp[i - j]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
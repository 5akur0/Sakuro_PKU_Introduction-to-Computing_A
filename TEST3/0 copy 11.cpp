#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n + 1; ++i) {
        if (i >= 3) {
            dp[i] += dp[i - 3];
        }
        if (i >= 2) {
            dp[i] += dp[i - 2];
        }
        if (i >= 1) {
            dp[i] += dp[i - 1];
        }
        dp[i] %= 10000;
    }
    cout << dp[n] << endl;
    return 0;
}
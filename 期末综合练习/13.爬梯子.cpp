#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    unsigned dp[N + 1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 10000;
    }
    cout << dp[N] << endl;
    return 0;
}
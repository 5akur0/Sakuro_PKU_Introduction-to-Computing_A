#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    vector<int> dp(n);
    dp[0] = input[0];
    int ans = dp[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = max(input[i], dp[i - 1] + input[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}

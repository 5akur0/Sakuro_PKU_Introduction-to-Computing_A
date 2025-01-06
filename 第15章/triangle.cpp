#include <bits/stdc++.h>
using namespace std;

int main() {
    int h;
    cin >> h;
    vector<int> dp(h, 0);
    int x;
    for (int i = 1; i <= h; ++i) {
        vector<int> tdp = dp;
        cin >> x;
        dp[0] += x;
        for (int j = 1; j <= i - 2; ++j) {
            cin >> x;
            dp[j] = max(tdp[j], tdp[j - 1]) + x;
        }
        if (i == 1) continue;
        cin >> x;
        dp[i - 1] = tdp[i - 2] + x;
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
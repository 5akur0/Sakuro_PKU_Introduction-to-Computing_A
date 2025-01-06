#include <bits/stdc++.h>
using namespace std;

long long herbs[10005][2];
long long dp[10000005];
 
int main() {
    int t, m;
    cin >> t >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> herbs[i][0] >> herbs[i][1];
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = herbs[i][0]; j <= t; ++j) {
            dp[j] = max(dp[j], dp[j - herbs[i][0]] + herbs[i][1]);
        }
    }
    cout << dp[t] << endl;
}
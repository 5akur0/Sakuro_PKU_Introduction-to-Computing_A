#include <bits/stdc++.h>
using namespace std;

int n, m;
long long dp[2505];
int chc[2505];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> chc[i];
    }
    for (int i = 1; i <= n; ++i) {
        int oc = 0;
        int tc = 0;
        dp[i] = LLONG_MAX;
        for (int j = i; j >= 1; --j) {
            if (chc[j] == 1) {
                oc++;
            }
            else {
                tc++;
            }
            if (oc * tc == 0 || abs(oc - tc) <= m) {
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
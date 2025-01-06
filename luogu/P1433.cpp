#include <bits/stdc++.h>
using namespace std;

int n;
float x[16];
float y[16];
float dis[16][16]; 

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dis[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        }
    }
    float dp[1 << 16][16];
    for (int i = 1; i <= 16; ++i) {
        for (int j = 0; j < 1 << 16; ++j) {
            dp[j][i] = FLT_MAX;
        }
    }
    for (int i = 1; i <= n; ++i) {
        dp[1 << (i - 1)][i] = dis[i][0];
    }
    float ans = FLT_MAX;
    for (int S = 1; S < (1 << n); ++S) {
        for (int i = 1; i <= n; ++i) {
            if (S & (1 << (i - 1))) {
                for (int j = 1; j <= n; ++j) {
                    if (i != j && S & (1 << (j - 1))) {
                        dp[S][i] = min(dp[S][i], dp[S - (1 << (i - 1))][j] + dis[j][i]);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
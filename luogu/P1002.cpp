#include <bits/stdc++.h>
using namespace std;

int n, m;
int x, y;
long long dp[30][30];

bool isKill(int i, int j) {
    return ((x - i) * (x - i) + (y - j) * (y - j) == 5 || (x == i && y == j));
}

int main() {
    cin >> n >> m >> x >> y;
    dp[0 + 5][0 + 5] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (!isKill(i, j) && (i != 0 || j != 0)) {
                dp[i + 5][j + 5] = dp[i - 1 + 5][j + 5] + dp[i + 5][j - 1 + 5];
            }
        }
    }
    cout << dp[n + 5][m + 5] << endl;
}

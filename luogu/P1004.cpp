#include <bits/stdc++.h>
using namespace std;

int MAP[11][11];
int N;
int num, x, y;
int dp[22][11][11];

int main() {
    cin >> N;
    while (true) {
        cin >> x >> y >> num;
        if (x == 0) {
            break;
        }
        MAP[x][y] = num;
    }
    for (int i = 2; i <= N + 1; ++i) {
        dp[i][1][1] = dp[i - 1][1][1] + MAP[i - 1][1];
    }
    for (int i = 3; i <= N + 1; ++i) {
        dp[i][i - 1][i - 1] = dp[i - 1][i - 2][i - 2] + MAP[1][i - 1];
    }
    for (int s = 2; s <= 2 * N; ++s) {
        for (int i = 1; i <= min(N, s - 1); ++i) {
            for (int j = 1; j <= min(N, s - 1); ++j) {
                dp[s][i][j] = max(max(dp[s - 1][i][j], dp[s - 1][i - 1][j]), max(dp[s - 1][i][j - 1], dp[s - 1][i - 1][j - 1]));
                if (i == j) {
                    dp[s][i][j] += MAP[s - i][i];
                }
                else {
                    dp[s][i][j] += MAP[s - i][i] + MAP[s - j][j];
                }
            }
        }
    }
    cout << dp[2 * N][N][N] << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int dp[1505][1505];
int board[1505][1505];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> board[i][j];
        }
    }
    for (int i = 1; i <= N; ++i) {
        dp[i][1] = 1;
    }
    for (int j = 1; j <= M; ++j) {
        dp[1][j] = 1;
    }
    for (int i = 2; i <= N; ++i) {
        for (int j = 2; j <= M; ++j) {
            if (board[i][j] == board[i - 1][j - 1] && board[i][j] != board[i - 1][j] && board[i][j] != board[i][j - 1]) {
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
            }
            else {
                dp[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
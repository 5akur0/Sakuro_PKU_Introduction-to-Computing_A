#include <bits/stdc++.h>
using namespace std;

int mat[55][55];
int dp[55][55];

int main() {
    int N;
    int flag;
    int fee;
    cin >> N >> flag >> fee;
    flag -= fee;
    if (flag <= 0) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> mat[i][j];
        }
    }
    dp[1][1] = mat[1][1];
    for (int i = 2; i <= N; ++i) {
        dp[i][1] = dp[i - 1][1] + mat[i][1];
    }
    for (int j = 2; j <= N; ++j) {
        dp[1][j] = dp[1][j - 1] + mat[1][j];
    }
    for (int i = 2; i <= N; ++i) {
        for (int j = 2; j <= N; ++j) {
            dp[i][j] = mat[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    if (flag >= dp[N][N]) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
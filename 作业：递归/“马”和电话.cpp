#include <bits/stdc++.h>
using namespace std;

/*

int DFS(int cur, int step, int N) {
    if (step == N) {
        return 1;
    }
    int ans = 0;
    switch (cur) {
        case 1:
            ans += DFS(6, step + 1, N);
            ans += DFS(8, step + 1, N);
            break;
        case 2:
            ans += DFS(7, step + 1, N);
            ans += DFS(9, step + 1, N);
            break;
        case 3:
            ans += DFS(4, step + 1, N);
            ans += DFS(8, step + 1, N);
            break;
        case 4:
            ans += DFS(3, step + 1, N);
            ans += DFS(9, step + 1, N);
            ans += DFS(0, step + 1, N);
            break;
        case 6:
            ans += DFS(1, step + 1, N);
            ans += DFS(7, step + 1, N);
            ans += DFS(0, step + 1, N);
            break;
        case 7:
            ans += DFS(2, step + 1, N);
            ans += DFS(6, step + 1, N);
            break;
        case 8:
            ans += DFS(1, step + 1, N);
            ans += DFS(3, step + 1, N);
            break;
        case 9:
            ans += DFS(2, step + 1, N);
            ans += DFS(4, step + 1, N);
            break;
        case 0:
            ans += DFS(4, step + 1, N);
            ans += DFS(6, step + 1, N);
            break;
    }
    return ans;
}

int main()
{
    1->6,8;2->7,9;3->4,8;4->3,9,0;6->1,7,0;7->2,6;8->1,3;9->2,4;0->4,6
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 0; i <= 9; ++i) {
        if (i != 5) {
            ans += DFS(i, 1, N);
        }
    }
    cout << ans << endl;
    return 0;
}

*/

int main() {
    int N;
    cin >> N;
    int ans = 0;
    vector<vector<int>> dp(10, vector<int>(N + 1, 0));
    for (int i = 0; i <= 9; ++i) {
        dp[i][1] = 1;
    }
    for (int i = 2; i <= N; ++i) {
        dp[1][i] = dp[6][i - 1] + dp[8][i - 1];
        dp[2][i] = dp[7][i - 1] + dp[9][i - 1];
        dp[3][i] = dp[4][i - 1] + dp[8][i - 1];
        dp[4][i] = dp[3][i - 1] + dp[9][i - 1] + dp[0][i - 1];
        dp[6][i] = dp[1][i - 1] + dp[7][i - 1] + dp[0][i - 1];
        dp[7][i] = dp[2][i - 1] + dp[6][i - 1];
        dp[8][i] = dp[1][i - 1] + dp[3][i - 1];
        dp[9][i] = dp[2][i - 1] + dp[4][i - 1];
        dp[0][i] = dp[4][i - 1] + dp[6][i - 1];
    }
    for (int i = 0; i <= 9; ++i) {
        ans += dp[i][N];
    }
    cout << ans << endl;
    return 0;
}
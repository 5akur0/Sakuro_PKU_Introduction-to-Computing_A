#include <bits/stdc++.h>
using namespace std;

const int mod = 1000007;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // f[i][j] 表示使用前 i 个物品能组成总和为 j 的方案数
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
    f[0][0] = 1; // 选择 0 个物品以达到总和为 0

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            // 选当前物品，考虑选 k 个
            for (int k = 0; k <= min(j, a[i]); k++) {
                f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
            }
        }
    }

    cout << f[n][m] << endl; // 输出总和为 m 的方案数
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Item {
    float weight;
    double value;
};

const int BUFFER = 100;

int main() {
    int n; float m; // n 为物品数，m 为背包容量
    cin >> n >> m;
    m *= BUFFER; // 处理小数部分
    int m_ = int(m);
    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].weight >> items[i].value;
        items[i].weight *= BUFFER; // 同步
    }
    // dp[i][j] 表示第 0 - i 个物品放入容量为 j 的背包的最大价值
    double dp[n][m_ + 1];
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m_; ++j) {
        if (items[0].weight <= j) {
            dp[0][j] = items[0].value;
        } else {
            dp[0][j] = 0;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= m_; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - items[i].weight >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - int(items[i].weight)] + items[i].value);
            }
        }
    }
    cout << fixed << setprecision(5) << dp[n - 1][m_] << endl;
}
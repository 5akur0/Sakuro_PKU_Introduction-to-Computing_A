#include <bits/stdc++.h>
using namespace std;


int DFS(int m, int target, const vector<int> &input) { // 用前 m 个商品凑 target
    if (m == 0) {
        if (target > 0) {
            return INT_MAX;
        } else {
            return 0;
        }
    }
    if (target <= 0) {
        return 0;
    }
    int m1 = DFS(m - 1, target, input); // 不选第 m 个商品
    int m2 = DFS(m - 1, target - input[m - 1], input); // 选第 m 个商品
    if (m1 == INT_MAX && m2 == INT_MAX) {
        return INT_MAX;
    }
    if (m1 == INT_MAX) {
        return m2 + input[m - 1];
    }
    if (m2 == INT_MAX) {
        return m1;
    }
    return min(m1, m2 + input[m - 1]);
}

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    sort(input.begin(), input.end());

    int ans = DFS(n, t, input);
    if (ans == INT_MAX) {
        cout << 0 << endl;
    }
    else {
        cout << ans << endl;
    }
    return 0;
}


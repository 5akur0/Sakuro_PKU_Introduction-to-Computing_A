#include <bits/stdc++.h>
using namespace std;

int n;

struct Node {
    int w;
    int h;
};

int dp[100005];

int main() {
    cin >> n;
    vector<Node> input(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> input[i].w >> input[i].h;
    }
    sort(input.begin() + 1, input.end(), [](Node a, Node b) {
        if (a.w != b.w) {
            return a.w < b.w;
        } else {
            return a.h < b.h;
        }
    });
    for (int i = 1; i <= n; ++i) {
        int m = 0;
        for (int j = 0; j < input[i].h; ++j) {
            m = max(m, dp[j]);
        }
        dp[input[i].h] = m + 1;
    }
    int ans = 0;
    for (int j = 0; j < 100005; ++j) {
        ans = max(ans, dp[j]);
    }
    cout << ans << endl;
    return 0;
}
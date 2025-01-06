#include <bits/stdc++.h>
using namespace std;

int weights[35];
int dp[200005];

int main() {
    int V, n;
    cin >> V >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> weights[i];
    }
    sort(weights + 1, weights + n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = V; j >= weights[i]; --j) {
            dp[j] = max(dp[j], dp[j - weights[i]] + weights[i]);
        }
    }
    cout << V - dp[V] << endl;
    return 0;
}
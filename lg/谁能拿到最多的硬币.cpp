#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    int cur = 0;
    for (int i = 0; i < k; ++i) {
        cur += coins[i];
    }
    int ans = cur;
    for (int i = 0; i < k; ++i) {
        cur -= coins[k - 1 - i];
        cur += coins[n - 1 - i];
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}
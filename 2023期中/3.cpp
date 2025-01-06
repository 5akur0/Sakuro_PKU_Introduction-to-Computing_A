#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    int cur = 0;
    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    for (int i = 0; i <= n - m; ++i) {
        cur = 0;
        for (int j = i; j < i + m; ++j) {
            cur += data[j];
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}
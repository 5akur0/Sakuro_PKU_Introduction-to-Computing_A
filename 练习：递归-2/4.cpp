#include <bits/stdc++.h>
using namespace std;

int ans;

void dfs(int x, int y) {
    if (x == 1) {
        ans++;
        return;
    }
    for (int i = y; i <= x; i++) {
        if (x % i == 0) {
            dfs(x / i, i);
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        ans = 0;
        if (n == 2)
        {
            cout << "1" << endl;
            continue;
        }
        dfs(n, 2);
        cout << ans << endl;
    }
    return 0;
}
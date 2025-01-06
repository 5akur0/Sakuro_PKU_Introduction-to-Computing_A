#include <bits/stdc++.h>
using namespace std;

int DFS(int m, int n, int t) {
    if (t * n > m) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (m == 1) {
        return n;
    }
    int ret = 0;
    for (int i = t; i < m; ++i) {
        ret += DFS(m - i, n - 1, i);
    }
    return ret;
}
int main() {
    int t;
    cin >> t;
    int m, n;
    for (int _ = 0; _ < t; ++_) {
        cin >> m >> n;
        cout << DFS(m, n, 0) << endl;
    }
    return 0;
}
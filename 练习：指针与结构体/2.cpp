#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    for (int _ = 0; _ < k; ++_) {
        int ans = 0;
        int m, n;
        cin >> m >> n;
        int tmp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> tmp;
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    ans += tmp;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
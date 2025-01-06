#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int D[n + 1];
    D[n] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> D[i];
    }
    int ans = 0;
    while (true) {
        int i = 0;
        while (true) {
            if (D[i] != 0) {
                break;
            }
            if (i >= n - 1) {
                goto end;
            }
            i++;
        }
        int m = D[i];
        int j = i;
        while (D[j + 1] != 0) {
            j++;
            m = min(m, D[j]);
        }
        for (int k = i; k <= j; ++k) {
            D[k] -= m;
        }
        ans += m;
    }
    end:;
    cout << ans << endl;
    return 0;
}
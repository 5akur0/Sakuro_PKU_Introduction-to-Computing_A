// #include <bits/stdc++.h>
// using namespace std;
// int n, m;

// int main() {
//     while (true) {
//         /*
//         scanf("%d %d", &n, &m);
//         if (n == 0 && m == 0) {
//             break;
//         }
//         int dp[n + 1][m + 1];
//         for (int i = 1; i <= n; ++i) {
//             dp[i][1] = i;
//         }
//         for (int j = 1; j <= m; ++j) {
//             dp[0][j] = 0;
//         }
//         for (int i = 1; i <= n; ++i) {
//             for (int j = 2; j <= m; ++j) {
//                 dp[i][j] = InT_mAX;
//                 for (int k = 1; k <= i; ++k) {
//                     dp[i][j] = min(dp[i][j], 1 + max(dp[k - 1][j - 1], dp[i - k][j]));
//                 }
//             }
//         }
//         cout << dp[n][m] << endl;
//         */
//         scanf("%d %d", &n, &m);
//         if (n == 0 && m == 0) {
//             break;
//         }
//         vector<int> f, p;
//         f.resize(n + 1);
//         for (int i = 1; i <= n; i++) {
//             f[i] = i;
//         }
//         for (int i = 2; i <= m; i++) {
//             f.swap(p);
//             f.resize(n + 1);
//             int pre = 0;
//             f[1] = 1;
//             for (int j = 2; j <= n; j++) {
//                 // f[pre]<f[j-1]且是满足这个条件的最大pre
//                 if (max(f[pre], p[j - pre - 1]) + 1 == f[j - 1]) {
//                     f[j] = f[j - 1];
//                 } else {
//                     f[j] = f[j - 1] + 1, pre = j - 1;
//                 }
//             }
//         }
//         cout << f[n] + 1 << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
#define maxlogn 20
#define maxnum 1000000000
using namespace std;

long n, eggnum, now, old, g[maxlogn + 1];

void init() {
    long i;
    now = 1;
    for (long i = 1; i <= eggnum; i++)
        g[i] = 1;
}

void work() {
    long i, j, p;
    for (i = 2; i <= n; i++) {
        for (j = eggnum; j >= 2; j--) {
            g[j] = g[j - 1] + g[j] + 1;
            if ((j == eggnum) && (g[j] >= n)) {
                cout << i << endl;
                return;
            }
        }
        g[1] = i;
        if ((eggnum == 1) && (g[1] >= n)) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
    long temp;
    while (1) {
        cin >> n;
        if (n == 0)
            break;
        else
            cin >> eggnum;
        temp = long(floor(log(n + 0.0) / log(2.0)) + 1.0);
        if (eggnum >= temp)
            cout << temp << endl;
        else {
            init();
            if (g[eggnum] >= n)
                cout << 1 << endl;
            else if (eggnum == 1)
                cout << n << endl;
            else
                work();
        }
    }
    return 0;
}
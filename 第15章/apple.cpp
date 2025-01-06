#include <bits/stdc++.h>
using namespace std;

int countWays(int m, int n) {
    if (n <= 1 || m == 0) {
        return 1;
    }
    if (n > m) {
        return countWays(m, m);
    }
    return countWays(m, n - 1) + countWays(m - n, n); // 有没有空盘子
}

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int M, N;
        cin >> M >> N;
        cout << countWays(M, N) << endl;
    }
    return 0;
}
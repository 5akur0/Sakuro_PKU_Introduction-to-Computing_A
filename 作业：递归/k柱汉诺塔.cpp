#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int mem[MAX][MAX] = {0};

int recursion(int n, int m) {
    if (n < 0 || m < 3) {
        return -1;
    }
    if (n == 1) {
        return 1;
    }
    if (mem[n][m] != 0) {
        return mem[n][m];
    }
    int ret;
    if (m == 3) {
        ret = pow(2, n) - 1;
    } else {
        ret = 2 * recursion(n - 1, m) + recursion(1, m - 1);
        for (int i = n - 2; i > 0; i--) {
            int temp = 2 * recursion(i, m) + recursion(n - i, m - 1);
            if (temp < ret) {
                ret = temp;
            } else {
                break;
            }
        }
    }
    mem[n][m] = ret;
    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << recursion(m, n) << endl;
    return 0;
}

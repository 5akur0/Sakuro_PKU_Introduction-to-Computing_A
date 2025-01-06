#include <bits/stdc++.h>
using namespace std;

int josephus(int k) {
    int m = k;
    int i, j;
    while (true) {
        m++;
        j = 0;
        for (i = 2 * k; i > k; i--) {
            j = (j + m - 1) % i;
            if (j < k) {
                break;
            }
        }
        if (i == k) {
            return m;
        }
    }
}

int main() {
    int k;
    while (cin >> k && k) {
        cout << josephus(k) << endl;
    }
    return 0;
}
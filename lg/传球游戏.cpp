#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
    while (y) {
        x %= y;
        swap(x, y);
    }
    return x;
}

int main() {
    int N;
    cin >> N;
    for (int m = N / 2; m >= 1; --m) {
        if (gcd(m, N) == 1) {
            cout << m << endl;
            break;
        }
    }
    return 0;
}
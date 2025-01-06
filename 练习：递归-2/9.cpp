#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    while (true) {
        if (x == y) {
            break;
        }
        if (x < y) {
            swap(x, y);
        }
        x /= 2;
    }
    cout << x  << endl;
    return 0;
}
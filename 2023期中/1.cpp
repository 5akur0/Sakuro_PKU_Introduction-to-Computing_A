#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    cout << m << "+" << n << "=" << m + n << endl;
    cout << m << "-" << n << "=" << m - n << endl;
    cout << m << "*" << n << "=" << m * n << endl;
    if (n != 0) {
        cout << m << "/" << n << "=" << m / n << endl;
    }
    else {
        cout << m << "/" << n << "=" << "error" << endl;
    }
}
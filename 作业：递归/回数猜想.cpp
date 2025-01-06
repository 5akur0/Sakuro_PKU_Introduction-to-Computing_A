#include <bits/stdc++.h>
using namespace std;

int Rev(int n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoi(s);
}

bool isRev(int n) {
    if (n == Rev(n)) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 7; ++i) {
        cout << n << "+" << Rev(n) << "=" << n + Rev(n) << endl;
        n = n + Rev(n);
        if (isRev(n)) {
            cout << "Y" << endl;
            return 0;
        }
    }
    cout << "N" << endl;
    return 0;
}
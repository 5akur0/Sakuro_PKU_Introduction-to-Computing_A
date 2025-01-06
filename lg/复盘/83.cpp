#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, w;
    cin >> s >> w;
    for (int i = 0; i <= w.length() - s.length(); ++i) {
        if (w.substr(i, s.length()) == s) {
            cout << i << endl;
            return 0;
        }
    }
}
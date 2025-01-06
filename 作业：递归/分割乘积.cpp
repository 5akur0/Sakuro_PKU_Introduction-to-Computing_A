#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    if (s[0] == '-') {
        ans = INT_MAX;
        s.erase(0, 1);
        for (int i = 1; i <= s.length() - 2; ++i) {
            for (int j = 1; j <= s.length() - i - 1; ++j) {
                ans = min(ans, stoi(s.substr(0, i)) * stoi(s.substr(i, j)) * stoi(s.substr(i + j)));
            }
        }
        cout << -ans << endl;
        return 0;
    }
    for (int i = 1; i <= s.length() - 2; ++i) {
        for (int j = 1; j <= s.length() - i - 1; ++j) {
            ans = max(ans, stoi(s.substr(0, i)) * stoi(s.substr(i, j)) * stoi(s.substr(i + j)));
        }
    }
    cout << ans << endl;
    return 0;
}
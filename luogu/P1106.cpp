#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;
    int N = n.size();
    int k;
    cin >> k;
    string ans = "";
    int t = k;
    while (t > 0) {
        if (ans.size() >= N - k) {
            break;
        }
        int min_index;
        char m = '9' + 1;
        for (int i = 0; i < t; ++i) {
            if (n[i] < m) {
                min_index = i;
                m = n[i];
            }
        }
        ans += m;
        t -= min_index;
        n.erase(0, 1 + min_index);
    }
    bool zero = false;
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] != 0) {
            zero = true;
            cout << ans[i];
        }
        else {
            if (zero) {
                cout << '0';
            }
        }
    }
    return 0;
}
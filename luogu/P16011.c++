#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    if (a == "0" || b == "0") {
        cout << 0 << endl;
        return 0;
    }
    vector<int> ans(a.size() + b.size(), 0);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < a.size(); ++i) {
        int m = a[i] - '0';
        for (int j = 0; j < b.size(); ++j) {
            ans[i + j] += m * (b[j] - '0');
        }
    }
    int carry = 0;
    for (int i = 0; i < ans.size(); i++) {
        ans[i] += carry;
        carry = ans[i] / 10;
        ans[i] %= 10;
    }
    reverse(ans.begin(), ans.end());
    if (ans[0] != 0) {
        cout << ans[0];
    }
    for (int i = 1; i < ans.size(); ++i) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
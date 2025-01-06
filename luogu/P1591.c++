#include <bits/stdc++.h>
using namespace std;

string stringMultiplication(string a, string b) {
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
    stringstream ss;
    if (ans[0] != 0) {
        ss << ans[0];
    }
    for (int i = 1; i < ans.size(); ++i) {
        ss << ans[i];
    }
    string output = ss.str();
    return output;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, a;
        cin >> n >> a;
        string ans = "1";
        for (int j = 2; j <= n; ++j) {
            ans = stringMultiplication(to_string(j), ans);
        }
        int count = 0;
        for (int j = 0; j < ans.size(); ++j) {
            if (ans[j] == '0' + a) {
                count++;
            }
        }
        cout << count << endl;
    }
}
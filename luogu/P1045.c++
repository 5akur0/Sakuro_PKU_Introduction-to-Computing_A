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
    int P;
    cin >> P;
    string ans = "1";
    for (int i = 0; i < P; ++i) {
        ans = stringMultiplication(ans, "2");
    }
    cout << ans.size() << endl;
    ans[ans.size() - 1]--;
    if (ans.size() < 500) {
        ans.insert(0, 500 - ans.size(), '0');
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 50; ++j) {
            cout << ans[ans.size() - 500 + i * 50 + j];
        }
        cout << endl;
    }
    return 0;
}
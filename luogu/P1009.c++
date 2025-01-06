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

string stringAddition(string a, string b) {
    if (a.size() > b.size()) {
        swap(a, b);
    }
    vector<int> ans;
    int carry = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < a.size(); ++i) {
        int cur = carry + a[i] + b[i] - 2 * '0';
        carry = cur / 10;
        ans.push_back(cur % 10);
    }
    for (int i = a.size(); i < b.size(); ++i) {
        int cur = carry + b[i] - '0';
        carry = cur / 10;
        ans.push_back(cur % 10);
    }
    if (carry != 0) {
        ans.push_back(carry);
    }
    stringstream ss;
    for (int i = ans.size() - 1; i > -1; --i) {
        ss << ans[i];
    }
    string output = ss.str();
    return output;
}

int main() {
    int n;
    cin >> n;
    vector<string> list(n);
    list[0] = "1";
    for (int i = 1; i < n; ++i) {
        string buffer = to_string(i + 1);
        list[i] = stringMultiplication(list[i - 1], buffer);
    }
    string ans = "0";
    for (int i = 0; i < n; ++i) {
        ans = stringAddition(ans, list[i]);
    }
    cout << ans << endl;
}
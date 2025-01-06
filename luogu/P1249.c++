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
    int n;
    cin >> n;
    int num = 2;
    vector<int> ans;
    while (n > 0) {
        n -= num;
        num++;
    }
    if (n == 0) {
        string ANS = to_string(num - 1);
        for (int i = 2; i < num - 1; ++i) {
            cout << i << " ";
            ANS = stringMultiplication(ANS, to_string(i));
        }
        cout << num - 1 << endl;
        cout << ANS << endl;
        return 0;
    }
    n += num - 1;
    num -= 3; //Now num is the number of elements in ans
    for (int i = 2; i < num + 2; ++i) {
        ans.push_back(i);
    }
    if (n >= num) {
        for (int i = 0; i < num; ++i) {
            ans[i]++;
        }
        ans[num - 1] += n - num;
    }
    else {
        int flag = num - 1;
        for (int i = 0; i < n; ++i) {
            ans[flag]++;
            flag--;
        }
    }
    string ANS = to_string(ans[num - 1]);
    for (int i = 0; i < num - 1; ++i) {
        cout << ans[i] << " ";
        ANS = stringMultiplication(to_string(ans[i]), ANS);
    }
    cout << ans[num - 1] << endl;
    cout << ANS << endl;
    return 0;
}
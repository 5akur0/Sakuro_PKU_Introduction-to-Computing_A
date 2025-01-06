#include <bits/stdc++.h>
using namespace std;

string lAdd(string a, string b)
{
    if (a.size() > b.size()) {
        swap(a, b);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while (a.size() < b.size()) {
        a = a + '0';
    }
    int carry = 0;
    string ret = "";
    for (int i = 0; i < a.size(); ++i) {
        int now = carry + a[i] + b[i] - 2 * '0';
        carry = 0;
        if (now > 9) {
            now -= 10;
            carry = 1;
        }
        ret += '0' + now;
    }
    if (carry) {
        ret += '1';
    }
    reverse(ret.begin(), ret.end());
    while (ret.size() > 1 && ret[0] == '0') {
        ret.erase(0, 1);
    }
    return ret;
}

string lMul(string a, int t)
{
    string ans = "";
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; --i) {
        int cur = t * (a[i] - '0') + carry;
        carry = cur / 10;
        cur %= 10;
        char ch = '0' + cur;
        ans = ch + ans;
    }
    while (carry) {
        char ch = '0' + carry % 10;
        ans = ch + ans;
        carry /= 10;
    }
    while (ans.size() > 1 && ans[0] == '0') {
        ans.erase(0, 1);
    }
    return ans;
}

int char2int(char ch)
{
    if ('0' <= ch && ch <= '9') {
        return ch - '0';
    }
    return ch - 'A' + 10;
}

pair<string, int> lDiv(string N, int M)
{
    int n = N.size();
    string P = "";
    int Q = 0;
    int index = 0;
    while (true) {
        Q *= 10;
        Q += N[index] - '0';
        index++;
        P += Q / M + '0';
        Q %= M;
        if (index > n - 1) {
            break;
        }
    }
    while (P[0] == '0') {
        P.erase(0, 1);
    }
    return make_pair(P, Q);
}

char int2char(int i)
{
    if (i < 10) {
        return '0' + i;
    }
    return 'A' + i - 10;
}

int main()
{
    int m;
    cin >> m;
    for (int _ = 0; _ < m; ++_) {
        int p, q;
        string n = "";
        char ch;
        cin >> p >> ch;
        while (cin >> ch && ch != ',') {
            n += ch;
        }
        cin >> q;
        string X = "0";
        string b = "1";
        for (int i = n.size() - 1; i >= 0; --i) {
            string d = lMul(b, char2int(n[i]));
            X = lAdd(X, d);
            b = lMul(b, p);
        }
        string ret = "";
        while (true) {
            if (lDiv(X, q).second < 0 || lDiv(X, q).second > q) {
                break;
            }
            ret += int2char(lDiv(X, q).second);
            X = lDiv(X, q).first;
        }
        reverse(ret.begin(), ret.end());
        while (ret.size() > 1 && ret[0] == '0') {
            ret.erase(0, 1);
        }
        cout << ret << endl;
    }
    return 0;
}
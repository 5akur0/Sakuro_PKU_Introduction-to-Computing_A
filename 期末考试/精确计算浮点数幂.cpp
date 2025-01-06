#include <bits/stdc++.h>
using namespace std;

int n;
string f;
int delta;

string _addd(string s1, string s2) {
    if (s1.size() < s2.size()) {
        swap(s1, s2);
    }
    int l1 = s1.size();
    int l2 = s2.size();
    string ret = "";
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int carry = 0;
    for (int i = 0; i < l2; ++i) {
        int now = s1[i] - '0' + s2[i] - '0' + carry;
        carry = now / 10;
        ret += ('0' + now % 10);
    }
    for (int i = l2; i < l1; ++i) {
        int now = s1[i] - '0' + carry;
        carry = now / 10;
        ret += ('0' + now % 10);
    }
    if (carry != 0) {
        ret += ('0' + carry);
    }
    reverse(ret.begin(), ret.end());
    while (ret[0] == '0' && ret.size() > 1) {
        ret.erase(0, 1);
    }
    return ret;
}

string _mull(string s, unsigned int a) {
    string ret = "0";
    string A = to_string(a);
    for (int i = A.size() - 1; i >= 0; --i) {
        string now = "0";
        for (int j = 0; j < A[i] - '0'; ++j) {
            now = _addd(s, now);
        }
        for (int j = 0; j < A.size() - 1 - i; ++j) {
            now += '0';
        }
        ret = _addd(ret, now);
    }
    return ret;
}

string cal(string f, int n) {
    int x = f.find('.');
    string s1 = f.substr(0, x);
    string s2 = f.substr(x + 1);
    delta = n * s2.size();
    string s = s1 + s2;
    stringstream iss(s);
    unsigned int l;
    iss >> l;
    while (s[0] == '0' && s.size() > 1) {
        s.erase(0, 1);
    }
    for (int i = 1; i < n; ++i) {
        s = _mull(s, l);
    }
    string ret = s + '0';
    if (s.size() > delta) {
        for (int i = 0; i < s.size() - delta; ++i) {
            ret[i] = s[i];
        }
        ret[s.size() - delta] = '.';
        for (int i = s.size() - delta; i < s.size(); ++i) {
            ret[i + 1] = s[i];
        }
    } else {
        ret = ".";
        for (int i = 0; i < -s.size() + delta; ++i) {
            ret += '0';
        }
        ret += s;
    }
    reverse(ret.begin(), ret.end());
    while (ret[0] == '0' && ret.size() > 1) {
        ret.erase(0, 1);
    }
    if (ret[0] == '.') {
        ret.erase(0, 1);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
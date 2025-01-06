#include <bits/stdc++.h>
using namespace std;

bool isNum(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (i == 0 && s[i] == '-' && s.size() > 1)
            continue;
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main() {
    string s;
    string line;
    while (getline(cin, line)) {
        bool flg = false;
        stack<long long> stk;
        stringstream iss(line);
        while (iss >> s) {
            if (s == "@") {
                break;
            }
            if (isNum(s)) {
                stk.push(stoll(s));
            } else {
                long long a = stk.top();
                stk.pop();
                long long b = stk.top();
                stk.pop();
                if (s == "+") {
                    stk.push(a + b);
                } else if (s == "-") {
                    stk.push(b - a);
                } else if (s == "*") {
                    stk.push(a * b);
                } else if (s == "/") {
                    if (a == 0) {
                        cout << "NaN" << endl;
                        flg = true;
                        break;
                    }
                    stk.push(b / a);
                }
            }
            if (flg) {
                break;
            }
        }
        if (flg) {
            continue;
        }
        cout << stk.top() << endl;
    }
    return 0;
}
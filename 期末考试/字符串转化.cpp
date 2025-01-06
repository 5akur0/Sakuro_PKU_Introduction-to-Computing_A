#include <bits/stdc++.h>
using namespace std;

string str;

string DFS(string s) {
    int l = s.size();
    int c1 = 0;
    int c0 = 0;
    string ret = "";
    for (int i = 0; i < l; ++i) {
        if (s[i] == '1') {
            c1++;
        } else {
            c0++;
        }
    }
    if (c1 == 0) {
        return "A";
    }
    if (c0 == 0) {

        return "B";
    }
    string a, b;
    for (int i = 0; i < l / 2; ++i) {
        a += s[i];
    }
    for (int i = 0; i < l / 2; ++i) {
        b += s[i + l / 2];
    }
    ret = "C" + DFS(a) + DFS(b);
    return ret;
}

int main() {
    cin >> str;
    cout << DFS(str) << endl;
    return 0;
}
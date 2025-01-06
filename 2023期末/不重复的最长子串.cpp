#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int ans = 0;
    string S = "";
    int now = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (S.find(s.substr(i, 1)) != string::npos) {
            ans = max(ans, now);
            now = S.size() - S.find(s.substr(i, 1));
            S = S.substr(S.find(s.substr(i, 1)) + 1) + s[i];
        }
        else {
            S += s[i];
            now++;
        }
    }
    cout << max(ans, now) << endl;
}
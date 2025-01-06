#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    vector<int> pos(26, -1);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z' && pos[s[i] - 'a'] == -1) {
            pos[s[i] - 'a'] = i;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z' && pos[s[i] - 'A'] == -1) {
            pos[s[i] - 'A'] = i;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (pos[i] != -1) {
            cout << char('a' + i) << " " << pos[i] << endl;
        }
    }
    return 0;
}
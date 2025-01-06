#include <bits/stdc++.h>
using namespace std;

int DFS(string s1, string s2) {
    if (s1.size() == 0 || s2.size() == 0) {
        return max(s1.size(), s2.size());
    }
    if (s1[0] == s2[0]) {
        return DFS(s1.substr(1), s2.substr(1));
    }
    return (1 + min({DFS(s1.substr(1), s2), DFS(s1, s2.substr(1)), DFS(s1.substr(1), s2.substr(1))}));
}

int main() {
    int n;
    cin >> n;
    string s1, s2;
    for (int i = 0; i < n; ++i) {
        cin >> s1 >> s2;
        int move = DFS(s1, s2);
        cout << fixed << setprecision(6) << 1/(move + 1.0) << endl;
    }
}
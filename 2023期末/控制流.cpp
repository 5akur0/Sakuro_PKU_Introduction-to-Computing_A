#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    cin.ignore();
    int now = 0;
    vector<string> S(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, S[i]);
    }
    for (int _ = 1; _ <= t - 1; ++_) {
        if (S[now] == "ABORT") {
            cout << now + 1 << endl;
            return 0;
        }
        if (S[now].substr(0, 4) == "JUMP") {
            now += stoi(S[now].substr(5));
        }
        else {
            now++;
        }
    }
    cout << now + 1 << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> input(n, vector<char>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> input[i][j];
            }
        }
        char cur_ch = 'v';
        bool if_success = false;
        for (int j = 0; j < m; ++j) {
            bool if_found = false;
            for (int i = 0; i < n; ++i) {
                if (input[i][j] == cur_ch) {
                    if_found = true;
                    break;
                }
            }
            if (if_found) {
                if (cur_ch == 'v') {
                    cur_ch = 'i';
                } else if (cur_ch == 'i') {
                    cur_ch = 'k';
                } else if (cur_ch == 'k') {
                    cur_ch = 'a';
                } else if (cur_ch == 'a') {
                    if_success = true;
                    break;
                }
            }
        }
        if (if_success) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
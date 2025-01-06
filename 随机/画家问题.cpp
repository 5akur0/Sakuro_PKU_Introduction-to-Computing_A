#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int ans = INT_MAX;
        int n;
        bool ifSuccess = false;
        cin >> n;
        vector<vector<int>> targmap(n, vector<int>(n, 0));
        char ch;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> ch;
                if (ch == 'w') {
                    targmap[i][j] = 1;
                }
            }
        }
        if (n == 1) {
            if (targmap[0][0] == 1) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
            continue;
        }
        for (int SEED = 0; SEED < pow(2, n); ++SEED) {
            int thismap[n][n];
            memset(thismap, 0, sizeof(thismap));
            int thiscount = 0;
            int s = SEED;
            int thischoice;
            for (int i = 0; i < n; ++i) {
                thischoice = s % 2;
                s /= 2;
                if (thischoice == 1) {
                    thiscount++;
                    for (int I = max(0, i - 1); I <= min(n - 1, i + 1); ++I) {
                        thismap[0][I] = 1 - thismap[0][I];
                    }
                    thismap[1][i] = 1 - thismap[1][i];
                }
            }
            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (thismap[i - 1][j] != targmap[i - 1][j]) {
                        thiscount++;
                        for (int J = max(0, j - 1); J <= min(n - 1, j + 1);
                             ++J) {
                            thismap[i][J] = 1 - thismap[i][J];
                        }
                        if (i != n - 1) {
                            thismap[i + 1][j] = 1 - thismap[i + 1][j];
                        }
                    }
                }
            }
            bool finalCheck = true;
            for (int j = 0; j < n; ++j) {
                if (targmap[n - 1][j] != thismap[n - 1][j]) {
                    finalCheck = false;
                    break;
                }
            }
            if (finalCheck) {
                ans = min(ans, thiscount);
                ifSuccess = true;
            }
        }
        if (ifSuccess) {
            cout << ans << endl;
        } else {
            cout << "inf" << endl;
        }
    }
}
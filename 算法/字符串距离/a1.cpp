#include <bits/stdc++.h>
using namespace std;

int distance(string s1, string s2) {
    int l1 = s1.size();
    int l2 = s2.size();
    int dp[l1 + 1][l2 + 1];
    for (int i = 0; i <= l1; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= l2; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= l1; ++i) {
        for (int j = 1; j <= l2; ++j) {
            int d = 1;
            if (s1[i - 1] == s2[j - 1]) {
                d = 0;
            }
            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + 1, dp[i - 1][j - 1] + d);
        }
    }
    return dp[l1][l2];
}

int main() {
    int n;
    cin >> n;
    string a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        cout << fixed << setprecision(6) << 1.0 / (1 + distance(a, b)) << endl;
    }
    return 0;
}
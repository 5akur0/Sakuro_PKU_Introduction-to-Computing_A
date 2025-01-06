#include <bits/stdc++.h>
using namespace std;

// C++初始模板程序
int nums[20];
char op[20];
int l = 1; // %numbers

vector<int> dp[20][20];

int cal(int A, int B, char c) {
    if (c == '+') {
        return A + B;
    }
    if (c == '-') {
        return A - B;
    }
    if (c == '*') {
        return A * B;
    }
}

int main() {
    cin >> nums[l];
    while (cin >> op[l] >> nums[l + 1]) {
        l++;
    }
    for (int i = 1; i <= l; ++i) {
        dp[i][i].push_back(nums[i]);
    }

    for (int i = 1; i < l; ++i) {
        dp[i][i + 1].push_back(cal(nums[i], nums[i + 1], op[i]));
    }

    for (int d = 2; d <= l - 1; ++d) {
        for (int ll = 1; ll <= l - d; ++ll) {
            int rr = ll + d;
            for (int i = ll; i <= rr - 1; ++i) {
                vector<int> L = dp[ll][i];
                vector<int> R = dp[i + 1][rr];
                for (int x = 0; x < L.size(); ++x) {
                    for (int y = 0; y < R.size(); ++y) {
                        dp[ll][rr].push_back(cal(L[x], R[y], op[i]));
                    }
                }
            }
        }
    }
    vector<int> ans = dp[1][l];
    sort(ans.begin(), ans.end());
    int M;
    if (ans.size() < 1000) {
        M = ans.size();
    } else {
        M = 1000;
    }
    for (int i = 0; i < M; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}

/*
Case  0 :  Time:    4 ms,  Memory:   308 kB,  Diff: 0
Case  1 :  Time:    4 ms,  Memory:   308 kB,  Diff: 0
Case  2 :  Time:   33 ms,  Memory:   308 kB,  Diff: 0
Case  3 :  Time:    4 ms,  Memory:   308 kB,  Diff: 0
Case  4 :  Time:    2 ms,  Memory:   308 kB,  Diff: 0
Case  5 :  Time:    4 ms,  Memory:   308 kB,  Diff: 0
Case  6 :  Time:    4 ms,  Memory:   308 kB,  Diff: 0
Case  7 :  Time:  101 ms,  Memory:  3764 kB,  Diff: 0
Case  8 :  Time:  363 ms,  Memory: 12084 kB,  Diff: 0
ProgramError: Case 9. Time out.
*/
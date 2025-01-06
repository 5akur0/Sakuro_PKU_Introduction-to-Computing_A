#include <bits/stdc++.h>
using namespace std;

struct Trash {
    int T;
    int F;
    int H;
};
int depth, n;
int h_max;
int t_max;
int idx;
Trash trash[105];
int dp[105][105];

void read_input() {
    cin >> depth >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> trash[i].T >> trash[i].F >> trash[i].H;
    }
    sort(trash + 1, trash + n, [](Trash a, Trash b){
        if (a.T != b.T) {
            return a.T < b.T;
        }
        return a.H < b.H;
    });
    return;
}

void call_output() {
    for (int i = 1; i <= n; ++i) {
        for (int h = 0; h <= depth; ++h) {
            if (dp[i][h] >= trash[i].T) {
                h_max = max(h_max, h);
                t_max = max(t_max, dp[i][h]);
            }
        }
        if (h_max == depth) {
            idx = i;
            break;
        }
    }
    if (h_max == depth) {
        cout << trash[idx].T << endl;
    }
    else {
        cout << t_max << endl;
    }
    return;
}

int main() {
    read_input();
    dp[0][0] = 10;
    for (int i = 1; i <= n; ++i) {
        for (int h = 0; h <= depth; ++h) {
            if (dp[i - 1][h] >= trash[i].T) {
                dp[i][h] = dp[i - 1][h] + trash[i].F;
            }
            if (h >= trash[i].H && dp[i - 1][h - trash[i].H] >= trash[i].T) {
                dp[i][h] = max(dp[i][h], dp[i - 1][h - trash[i].H]);
            }
        }
    }
    call_output();
    return 0;
}
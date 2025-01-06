#include <bits/stdc++.h>
using namespace std;
int input[5000];
int dp[5000][5000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    sort(input, input + n);
    int d_max = input[n - 1] - input[0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= d_max; ++j) {
            dp[i][j] = 1;
        }
    }
    int max_len = 0;
    int max_diff = 0;
    int max_end = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int diff = input[i] - input[j];
            dp[i][diff] = dp[j][diff] + 1;
            if (dp[i][diff] > max_len) {
                max_len = dp[i][diff];
                max_diff = diff;
                max_end = input[i];
            }
            else if (dp[i][diff] == max_len && diff > max_diff) {
                max_diff = diff;
                max_end = input[i];
            }
            else if (dp[i][diff] == max_len && diff == max_diff && input[i] > max_end) {
                max_end = input[i];
            }
        }
    }
    if (max_len <= 2) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = max_len; i >= 1; --i) {
        cout << max_end - max_diff * (i - 1);
        if (i != 1) {
            cout << ",";
        }

    }
    cout << endl;
    return 0;
}
    
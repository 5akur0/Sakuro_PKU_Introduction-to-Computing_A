#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int input[N];
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }

    vector<int> left_dp(N);
    left_dp[0] = 1;
    for (int i = 1; i < N; ++i) {
        left_dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (input[j] < input[i]) {
                left_dp[i] = max(left_dp[i], left_dp[j] + 1);
            }
        }
    }

    vector<int> right_dp(N);
    right_dp[N - 1] = 1;
    for (int i = N - 2; i >= 0; --i) {
        right_dp[i] = 1;
        for (int j = N - 1; j > i; --j) {
            if (input[j] < input[i]) {
                right_dp[i] = max(right_dp[i], right_dp[j] + 1);
            }
        }
    }

    int max_len = 0;
    for (int i = 0; i < N; ++i) {
        max_len = max(max_len, left_dp[i] + right_dp[i] - 1);
    }

    cout << N - max_len << endl;
    return 0;
}
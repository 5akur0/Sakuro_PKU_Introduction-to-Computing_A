#include <bits/stdc++.h>
using namespace std;

long long T, n;
struct meal {
    long long value;
    long long decay;
    long long time;
};

meal meals[105];
long long dp[300005];

int main() {
    memset(dp, 0, sizeof(dp));
    cin >> T >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> meals[i].value;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> meals[i].decay;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> meals[i].time;
    }
    sort(meals + 1, meals + n + 1, [](meal a, meal b){
        return 1LL * a.decay * b.time > 1LL * b.decay * a.time;
    });
    for (int i = 1; i <= n; ++i) {
        for (int j = T; j >= meals[i].time; --j) {
            dp[j] = max(dp[j], dp[j - meals[i].time] + meals[i].value - meals[i].decay * j);
        }
    }
    long long ans = INT_MIN;
    for (long long i = 0; i <= T; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
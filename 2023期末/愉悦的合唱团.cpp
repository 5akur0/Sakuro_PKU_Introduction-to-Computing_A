#include <bits/stdc++.h>
using namespace std;

int kind[50005];
int dp[50005];

int main () {
    int N, M;
    scanf("%d%d", &N, &M);
    int now;
    int pre;
    scanf("%d", &pre);
    now = pre;
    int idx = 1;
    for (int i = 2; i <= N; ++i) {
        scanf("%d", &now);
        if (now != pre) {
            kind[idx] = pre;
            pre = now;
            idx++;
        }
    }
    kind[idx] = now;
    N = idx;

    dp[0] = 0;
    for (int i = 1; i <= N; ++i) {
        dp[i] = INT_MAX;
        set<int> s = {kind[i]};
        int j = i;
        bool flag = true;
        for (int d = 1; ; ++d) {
            while (s.size() == d) {
                j--;
                if (j < 0) {
                    flag = false;
                    break;
                }
                s.insert(kind[j]);
            }
            if (!flag) {
                break;
            }
            dp[i] = min(dp[i], dp[j] + d * d);
        }
    }
    cout << dp[N] << endl;
}


// Greedy(False)
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int now_kind;
    int hold_kind;
    int ans = 0;
    cin >> now_kind;
    hold_kind = now_kind;
    for (int i = 2; i <= N; ++i) {
        cin >> now_kind;
        if (now_kind != hold_kind) {
            ans++;
            hold_kind = now_kind;
        }
    }
    cout << ans << endl;
}
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, n;
    while (cin >> R >> n) {
        if (R == -1 && n == -1) {
            break;
        }
        vector<int> input(n);
        for (int i = 0; i < n; ++i) {
            cin >> input[i];
        }
        sort(input.begin(), input.end());
        int cur_frontier = INT_MIN;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (input[i] > cur_frontier) {
                ans++;
                int target = input[i];
                for (int j = i; j < n; ++j) {
                    if (input[j] <= input[i] + R) {
                        target = input[j];
                    }
                    else {
                        break;
                    }
                }
                cur_frontier = target + R;
            }
        }
        cout << ans << endl;
    }
}
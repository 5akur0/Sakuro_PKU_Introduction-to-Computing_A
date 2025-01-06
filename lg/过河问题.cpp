#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n;
        cin >> n;
        vector<int> times(n);
        for (int i = 0; i < n; ++i) {
            cin >> times[i];
        }

        sort(times.begin(), times.end());

        int totalTime = 0;

        while (n > 3) {
            // 策略1：两最快者过，最快者返回，再两慢者过，第二快者返回
            // 策略2：两慢者过，最快者返回，再两最快者过，最快者返回
            totalTime += min(times[0] + 2 * times[1] + times[n - 1], 2 * times[0] + times[n - 1] + times[n - 2]);
            n -= 2;
        }

        if (n == 3) {
            totalTime += times[2] + times[1] + times[0]; // 三个人过河的情况
        } else {
            totalTime += times[n - 1];
        }
        cout << totalTime << endl;
    }
    return 0;
}

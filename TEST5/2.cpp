#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int M = INT_MIN;
    int m = INT_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        M = max(M, arr[i]);
        m = min(m, arr[i]);
    }
    float x = (M + m) / 2.0;
    int ans = 0;
    int cur_m = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (abs(arr[i] - x) < cur_m) {
            cur_m = abs(arr[i] - x);
            ans = arr[i];
        }
    }
    cout << ans << endl;
    return 0;
}
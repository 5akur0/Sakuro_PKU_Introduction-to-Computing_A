#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int min = INT_MAX;
    int ans;
    int cur;
    for (int i = 0; i < N; ++i) {
        cin >> cur;
        if (cur < min) {
            min = cur;
            ans = i;
        }
    }
    cout << ans + 1 << endl;
}
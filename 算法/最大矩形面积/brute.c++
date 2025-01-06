#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            ans = max(ans, (j - i + 1) * *min_element(input.begin() + i, input.begin() + j + 1));
        }
    }
    cout << ans << endl;
    return 0;
}
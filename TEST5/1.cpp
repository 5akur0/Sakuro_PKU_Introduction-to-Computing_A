#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    int cur_ans = 0;
    int expected = INT_MAX;
    int cur;
    for (int i = 0; i < n; ++i) {
        cin >> cur;
        if (cur == expected) {
            cur_ans++;
        }
        else {
            ans = max(ans, cur_ans);
            cur_ans = 1;
        }
        expected = cur + 1;
    }
    cout << max(ans, cur_ans) << endl;
}
#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start;
    int end;
};

int main() {
    int n;
    cin >> n;
    vector<Activity> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i].start >> input[i].end;
    }

    sort(input.begin(), input.end(), [](const Activity &a, const Activity &b){
        return a.end < b.end;
    });

    int ans = 0;
    int cur_end = INT_MIN;

    for (int i = 0; i < n; ++i) {
        if (input[i].start >= cur_end) {
            ans++;
            cur_end = input[i].end;
        }
    }
    
    cout << ans << endl;
    return 0;
}
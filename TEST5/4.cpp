#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cur;
    vector<int> list;
    for (int i = 0; i < n; ++i) {
        cin >> cur;
        list.push_back(cur);
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        auto mini = min_element(list.begin(), list.end());
        int mi = list[mini - list.begin()];
        list.erase(mini);
        auto mini2 = min_element(list.begin(), list.end());
        int mi2 =list[mini2 - list.begin()];
        list.erase(mini2);
        list.push_back(mi + mi2);
        ans += mi + mi2;
    }
    cout << ans << endl;
    return 0;
}
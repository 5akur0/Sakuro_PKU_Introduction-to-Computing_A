#include <bits/stdc++.h>
using namespace std;

struct P {
    int index;
    int time;
};

int main() {
    int n;
    cin >> n;
    vector<P> people(n);
    for (int i = 1; i <= n; ++i) {
        cin >> people[i - 1].time;
        people[i - 1].index = i;
    }
    sort(people.begin(), people.end(), [](const P& a, const P& b) {
        return a.time < b.time;
    });
    for (int i = 0; i < n - 1; ++i) {
        cout << people[i].index << " ";
    }
    cout << people[n - 1].index << endl;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (n - 1 - i) * people[i].time;
    }
    cout << fixed << setprecision(2) << ans / float(n) << endl;
    return 0;
}
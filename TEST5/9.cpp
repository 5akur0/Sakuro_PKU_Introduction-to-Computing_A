#include <bits/stdc++.h>
using namespace std;

struct Order{
    int start;
    int finish;
    int value;
};

int main() {
    int n;
    cin >> n;
    vector<Order> orders(n);
    for (int i = 0; i < n; ++i) {
        cin >> orders[i].start >> orders[i].finish >> orders[i].value;
    }
    sort(orders.begin(), orders.end(), [](const Order& a, const Order& b) {
        return a.finish < b.finish;
    });

    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int k = upper_bound(orders.begin(), orders.begin() + i, orders[i].start,
                            [](int start, const Order& o) { return start < o.finish; }) - orders.begin() - 1;
        if (k != -1) {
            dp[i + 1] = max(dp[i], dp[k + 1] + orders[i].value);
        }
        else {
            dp[i + 1] = max(dp[i], orders[i].value);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
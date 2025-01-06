#include <bits/stdc++.h>
using namespace std;

struct Order {
    int start;
    int finish;
    int price;
};

int main() {
    int n;
    cin >> n;
    vector<Order> orders(n);
    for (int i = 0; i < n; ++i) {
        cin >> orders[i].start >> orders[i].finish >> orders[i].price;
    }
    sort(orders.begin(), orders.end(), [](const Order &a, const Order &b){
        return a.finish < b.finish;
    });
    vector<int> dp(n, 0);
    dp[0] = orders[0].price;
    for (int i = 1; i < n; ++i) {
        int index = upper_bound(orders.begin(), orders.begin() + i, orders[i].start, [](const int t, const Order &o){
            return o.finish > t;
        }) - orders.begin() - 1;
        if (index < 0) {
            dp[i] = max(dp[i - 1], orders[i].price);
        }
        else {
            dp[i] = max(dp[i - 1], orders[i].price + dp[index]);
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    int h;
    vector<int> heights;
    while (cin >> h) {
        heights.push_back(h);
        n++;
    }
    vector<int> leftmax(n);
    vector<int> rightmax(n);
    leftmax[0] = heights[0];
    for (int i = 1; i < n; ++i) {
        leftmax[i] = max(leftmax[i - 1], heights[i]);
    }
    rightmax[n - 1] = heights[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightmax[i] = max(rightmax[i + 1], heights[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += min(leftmax[i], rightmax[i]) - heights[i];
    }
    cout << ans << endl;
}
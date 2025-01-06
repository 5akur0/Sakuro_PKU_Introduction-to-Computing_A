#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    if (n == 1) {
        cout << heights[0] << endl;
        return 0;
    }
    int ans = 0;
    int width, height;
    deque<int> monoheap;
    for (int i = 0; i < n; ++i) {
        while (!monoheap.empty() && heights[monoheap.back()] > heights[i]) {
            height = heights[monoheap.back()];
            monoheap.pop_back();
            if (monoheap.empty()) {
                width = i;
            }
            else {
                width = i - monoheap.back() - 1;
            }
            ans = max(ans, width * height);
        }
        monoheap.push_back(i);
    }
    while (!monoheap.empty()) {
        height = heights[monoheap.back()];
        while (!monoheap.empty() && heights[monoheap.back()] == height) {
            monoheap.pop_back();
        }
        if (monoheap.empty()) {
            width = n;
        }
        else {
            width = n - monoheap.back() - 1;
        }
        ans = max(ans, width * height);
    }
    cout << ans << endl;
    return 0;
}
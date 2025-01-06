#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int heights[n];
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    if (n == 1) {
        cout << heights[0] << endl;
        return 0;
    }
    deque<int> mono_heap;
    int height, width;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        while (!mono_heap.empty() && heights[i] < heights[mono_heap.back()]) {
            height = heights[mono_heap.back()];
            mono_heap.pop_back();
            if (mono_heap.empty()) {
                width = i;
            }
            else {
                width = i - mono_heap.back() - 1;
            }
            ans = max(ans, width * height);
        }
        mono_heap.push_back(i);
    }
    while (!mono_heap.empty()) {
        height = heights[mono_heap.back()];
        mono_heap.pop_back();
        while (!mono_heap.empty() && height == heights[mono_heap.back()]) {
            mono_heap.pop_back();
        }
        if (mono_heap.empty()) {
            width = n;
        }
        else {
            width = n - mono_heap.back() - 1;
        }
        ans = max(ans, width * height);
    }
    cout << ans << endl;
    return 0;
}
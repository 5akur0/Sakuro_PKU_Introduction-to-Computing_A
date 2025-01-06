#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    if (n == 1) {
        cout << heights[0] << endl;
        return 0;
    }
    deque<int> stack;
    for (int i = 0; i < n; ++i) {
        while (!stack.empty() && heights[stack.back()] > heights[i]) {
            int height = heights[stack.back()];
            stack.pop_back();
            int width;
            if (stack.empty()) {
                width = i;
            }
            else {
                width = i - stack.back() - 1;
            }
            ans = max(ans, height * width);
        }
        stack.push_back(i);
    }
    while (!stack.empty()) {
        int height = heights[stack.back()];
        stack.pop_back();
        while (!stack.empty() && heights[stack.back()] == height) {
            stack.pop_back();
        }
        int width;
        if (stack.empty()) {
            width = n;
        }
        else {
            width = n - stack.back() - 1;
        }
        ans = max(ans, height * width);
    }
    cout << ans << endl;
    return 0;
}
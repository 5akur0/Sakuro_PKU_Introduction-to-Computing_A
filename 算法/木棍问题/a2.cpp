#include <bits/stdc++.h>
using namespace std;

bool DFS(const int target, const int n, const vector<int> &sticks, vector<bool> &available, int nowlength, int minindex, int nowLeft) {
    if (nowLeft == 0) {
        return true;
    }
    if (nowlength == target) {
        return DFS(target, n, sticks, available, 0, 0, nowLeft - 1);
    }
    for (int i = minindex; i < n; ++i) {
        if (available[i] && nowlength + sticks[i] <= target) {
            available[i] = false;
            if (DFS(target, n, sticks, available, nowlength + sticks[i], i + 1, nowLeft)) {
                return true;
            }
            available[i] = true;
            if (nowlength == 0) {
                return false;
            }
            while (i + 1 < n && sticks[i + 1] == sticks[i]) {
                ++i;
            }
        }
    }
    return false;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<int> sticks(n);
        vector<bool> available(n, true);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> sticks[i];
            sum += sticks[i];
        }
        sort(sticks.begin(), sticks.end(), [](const int &a, const int &b){
            return a > b;
        });
        for (int L = sticks[0]; L <= sum; ++L) {
            if (sum % L == 0 && DFS(L, n, sticks, available, 0, 0, sum / L)) {
                cout << L << endl;
                break;
            }
        }
    }
}